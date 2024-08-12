#include "ContaPoupanca.h"
#include <iostream>

ContaPoupanca::ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros)
    : Conta(numeroConta, saldoInicial), taxaJuros(taxaJuros) {}

void ContaPoupanca::aplicarJuros() {
    double juros = saldo * taxaJuros;
    saldo += juros;
    transacoes.push_back(Transacao("Aplicação de Juros", juros, std::time(nullptr)));
    std::cout << "Juros de R$ " << juros << " aplicados com sucesso na data " << transacoes.back().getDataString() << ". Novo saldo: R$ " << saldo << "\n";
}

double ContaPoupanca::getTaxaJuros() const {
    return taxaJuros;
}

