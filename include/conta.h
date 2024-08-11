#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include <string>
#include "Transacao.h"
#include <ctime>

class Conta {
protected:
    int numeroConta;
    double saldo;
    bool ativa;
    std::vector<Transacao> transacoes;

public:
    Conta(int numeroConta, double saldoInicial);
    virtual ~Conta() = default;


    int getNumeroConta() const;
    virtual void depositar(double valor, time_t data);
    virtual bool sacar(double valor, time_t data);
    double getSaldo() const;
    bool isAtiva() const;
    void tornarInativa();
    void mostrarTransacoes() const;
    bool transferir(Conta* contaDestino, double valor, time_t data);
    const std::vector<Transacao>& getTransacoes() const;
};

#endif // CONTA_H

