#include "Conta.h"
#include <iostream>
#include <iomanip>


Conta::Conta(int numeroConta, double saldoInicial)
    : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}

int Conta::getNumeroConta() const {
    return numeroConta;
}



void Conta::depositar(double valor, time_t data) {
    if (ativa) {
        saldo += valor;
        transacoes.push_back(Transacao("Deposito", valor, data));
        std::cout << "Deposito de R$ " << valor << " realizado com sucesso!\n";
    } else {
        std::cout << "Conta inativa. N�o � poss�vel depositar." << std::endl;
    }
}

bool Conta::sacar(double valor, time_t data) {
    if (ativa) {
        if (valor <= saldo) {
            saldo -= valor;
            transacoes.push_back(Transacao("Saque", valor, data));
            std::cout << "Saque de R$ " << valor << " realizado com sucesso!\n";
            return true;
        } else {
            std::cout << "Saldo insuficiente para saque.\n";
            return false;
        }
    } else {
        std::cout << "Conta inativa. N�o � poss�vel sacar." << std::endl;
    }
    return false;
}

const std::vector<Transacao>& Conta::getTransacoes() const { // Adicione a qualifica��o de classe Conta::
    return transacoes;
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
        time_t data = transacao.getData();  // Armazena o valor retornado por getData() em uma vari�vel tempor�ria
        std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor()
                  << ", Data: " << std::put_time(std::localtime(&data), "%d/%m/%Y") << "\n";
    }
}


bool Conta::transferir(Conta* contaDestino, double valor, time_t data) {
    if (ativa && contaDestino->isAtiva()) {
        if (saldo < valor) {
            return false; // Saldo insuficiente
        }

        saldo -= valor;
        contaDestino->saldo += valor;

        Transacao transacaoSaida("Transfer�ncia enviada", -valor, data);
        Transacao transacaoEntrada("Transfer�ncia recebida", valor, data);

        transacoes.push_back(transacaoSaida);
        contaDestino->transacoes.push_back(transacaoEntrada);

        return true;
    } else {
        std::cout << "Uma das contas est� inativa. N�o � poss�vel realizar a transfer�ncia." << std::endl;
        return false;
    }
}

