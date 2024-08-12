#include "Conta.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Excessões.cpp"

Conta::Conta(int numeroConta, double saldoInicial)
    : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}

int Conta::getNumeroConta() const {
    return numeroConta;
}

void Conta::depositar(double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do depósito deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível depositar.");
    }

    saldo += valor;
    transacoes.push_back(Transacao("Depósito", valor, data));
    std::cout << "Depósito de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
}

bool Conta::sacar(double valor, time_t data) {  // Alterado para retornar bool
    if (valor <= 0) {
        throw std::invalid_argument("O valor do saque deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível sacar.");
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
        throw std::invalid_argument("O valor da transferência deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível realizar a transferência.");
    }

    if (!contaDestino->isAtiva()) {
        throw ContaInativaException("A conta de destino está inativa. Não é possível realizar a transferência.");
    }

    if (saldo < valor) {
        throw SaldoInsuficienteException("Saldo insuficiente para transferência.");
    }

    saldo -= valor;
    contaDestino->saldo += valor;

    Transacao transacaoSaida("Transferência enviada", -valor, data);
    Transacao transacaoEntrada("Transferência recebida", valor, data);

    transacoes.push_back(transacaoSaida);
    contaDestino->transacoes.push_back(transacaoEntrada);

    std::cout << "Transferência de R$ " << valor << " realizada com sucesso na data " << transacaoSaida.getDataString() << "!\n";
    
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

