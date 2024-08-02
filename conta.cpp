#include "Conta.h"

Conta::Conta(int numeroConta, double saldoInicial)
        : numeroConta(numeroConta), saldo(saldoInicial) {}
        
virtual ~Conta() = default;
        
int getNumeroConta() const {
        return numeroConta;
    }

void depositar(double valor, time_t data) {
        saldo += valor;
        transacoes.push_back(Transacao("Deposito", valor, data));
        std::cout << "Deposito de R$ " << valor << " realizado com sucesso!\n";
    }

virtual bool sacar(double valor, time_t data) {
        if (valor <= saldo) {
            saldo -= valor;
            transacoes.push_back(Transacao("Saque", valor, data));
            std::cout << "Saque de R$ " << valor << " realizado com sucesso!\n";
            return true;
        } else {
            std::cout << "Saldo insuficiente para saque.\n";
            return false;
        }
    }

double Conta::getSaldo() const {
    return saldo;
}

void mostrarTransacoes() const {
        for (const auto& transacao : transacoes) {
            std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor() << ", Data: " << std::put_time(std::localtime(&transacao.getData()), "%d/%m/%Y") << "\n";
        }
    }
