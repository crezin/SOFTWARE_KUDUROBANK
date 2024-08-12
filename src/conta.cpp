#include "Conta.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Excess�es.cpp"

Conta::Conta(int numeroConta, double saldoInicial)
    : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}

int Conta::getNumeroConta() const {
    return numeroConta;
}

void Conta::depositar(double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do dep�sito deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. N�o � poss�vel depositar.");
    }

    saldo += valor;
    transacoes.push_back(Transacao("Dep�sito", valor, data));
    std::cout << "Dep�sito de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
}

bool Conta::sacar(double valor, time_t data) {  // Alterado para retornar bool
    if (valor <= 0) {
        throw std::invalid_argument("O valor do saque deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. N�o � poss�vel sacar.");
    }

    if (valor > saldo) {
        throw SaldoInsuficienteException("Saldo insuficiente para saque.");
    }

    saldo -= valor;
    transacoes.push_back(Transacao("Saque", valor, data));
    std::cout << "Saque de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
    return true;  // Sucesso
}

bool Conta::transferir(std::shared_ptr<Conta> contaDestino, double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor da transfer�ncia deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. N�o � poss�vel realizar a transfer�ncia.");
    }

    if (!contaDestino->isAtiva()) {
        throw ContaInativaException("A conta de destino est� inativa. N�o � poss�vel realizar a transfer�ncia.");
    }

    if (saldo < valor) {
        throw SaldoInsuficienteException("Saldo insuficiente para transfer�ncia.");
    }

    saldo -= valor;
    contaDestino->saldo += valor;

    Transacao transacaoSaida("Transfer�ncia enviada", -valor, data);
    Transacao transacaoEntrada("Transfer�ncia recebida", valor, data);

    transacoes.push_back(transacaoSaida);
    contaDestino->transacoes.push_back(transacaoEntrada);

    std::cout << "Transfer�ncia de R$ " << valor << " realizada com sucesso na data " << transacaoSaida.getDataString() << "!\n";
    
    return true;
}

double Conta::getSaldo() const {
    return saldo;
}

bool Conta::isAtiva() const {
    return ativa;
}

void Conta::tornarInativa() {
    ativa = false;
}

void Conta::mostrarTransacoes() const {
    for (const auto& transacao : transacoes) {
        std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor()
                  << ", Data: " << transacao.getDataString() << "\n";
    }
}

const std::vector<Transacao>& Conta::getTransacoes() const {
    return transacoes;
}

