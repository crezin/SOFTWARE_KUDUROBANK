#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <vector>
#include "Transacao.h" // Inclui a classe Transacao

class Conta {
protected:
    std::string numeroConta; // Número da conta
    double saldo;            // Saldo da conta
    std::vector<Transacao> transacoes; // Histórico de transações

public:
    // Construtor
    Conta(const std::string& numero, double saldoInicial);

    // Métodos para acessar e modificar o saldo
    virtual void depositar(double valor);
    virtual bool sacar(double valor);
    double getSaldo() const;
    std::string getNumeroConta() const;

    // Método para adicionar transação
    void adicionarTransacao(const Transacao& transacao);
};

#endif // CONTA_H
