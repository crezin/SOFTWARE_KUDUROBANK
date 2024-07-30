#include "ContaCorrente.h"

// Construtor da classe ContaCorrente
ContaCorrente::ContaCorrente(const std::string& numero, double saldoInicial, double limite)
        : Conta(numero, saldoInicial), limite(limite) {}

// Sobrescreve o método sacar
bool ContaCorrente::sacar(double valor) {
    if (valor <= (saldo + limite)) {
        saldo -= valor; // Subtrai valor do saldo
        return true;    // Saque bem-sucedido
    }
    return false; // Saldo insuficiente
}
