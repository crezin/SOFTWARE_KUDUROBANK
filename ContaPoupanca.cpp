
#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(int numeroConta) : Conta(numeroConta) {}

void ContaPoupanca::aplicarJuros(double taxa) {
    saldo += saldo * taxa;
    adicionarTransacao(Transacao("Juros", saldo * taxa));
}