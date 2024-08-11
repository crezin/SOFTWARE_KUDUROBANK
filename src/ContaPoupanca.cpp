#include "ContaPoupanca.h"
#include <iostream>


ContaPoupanca::ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros)
    : Conta(numeroConta, saldoInicial), taxaJuros(taxaJuros) {}

void ContaPoupanca::aplicarJuros() {
    double juros = saldo * taxaJuros;
    saldo += juros;
    std::cout << "Juros de R$ " << juros << " aplicados. Novo saldo: R$ " << saldo << "\n";
}

