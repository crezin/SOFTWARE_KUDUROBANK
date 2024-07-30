#include "ContaPoupanca.h"

// Construtor da classe ContaPoupanca
ContaPoupanca::ContaPoupanca(const std::string& numero, double saldoInicial, double taxaJuros)
        : Conta(numero, saldoInicial), taxaJuros(taxaJuros) {}

// Método para aplicar juros
void ContaPoupanca::aplicarJuros() {
    saldo += saldo * taxaJuros; // Aplica a taxa de juros ao saldo
}
