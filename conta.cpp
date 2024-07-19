#include "Conta.h"

Conta::Conta(int numeroConta) : numeroConta(numeroConta), saldo(0.0) {}

void Conta::depositar(double valor) {
    saldo += valor;
    adicionarTransacao(Transacao("Depósito", valor));
}

bool Conta::sacar(double valor) {
    if (valor <= saldo) {
        saldo -= valor;
        adicionarTransacao(Transacao("Saque", valor));
        return true;
    }
    return false;
}

double Conta::getSaldo() const {
    return saldo;
}

void Conta::adicionarTransacao(const Transacao& transacao) {
    transacoes.push_back(transacao);
}