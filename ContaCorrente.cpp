#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial)
        : Conta(numeroConta, saldoInicial), limiteChequeEspecial(limiteChequeEspecial) {}


bool sacar(double valor, time_t data) override {
        if (valor <= saldo + limiteChequeEspecial) {
            saldo -= valor;
            transacoes.push_back(Transacao("Saque", valor, data));
            std::cout << "Saque de R$ " << valor << " realizado com sucesso!\n";
            return true;
        } else {
            std::cout << "Saldo insuficiente para saque, mesmo com limite de cheque especial.\n";
            return false;
        }
    }
