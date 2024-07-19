#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(int numeroConta, double limite)
        : Conta(numeroConta), limiteChequeEspecial(limite) {}

bool ContaCorrente::sacar(double valor) {
    if (valor <= (saldo + limiteChequeEspecial)) {
        saldo -= valor;
        adicionarTransacao(Transacao("Saque", valor));
        return true;
    }
    return false;
}