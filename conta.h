#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include "transacao.h"

class Conta {
protected:
    int numeroConta;
    double saldo;
    std::vector<Transacao> transacoes;

public:
    Conta(int numeroConta);
    virtual ~Conta() {}
    virtual void depositar(double valor);
    virtual bool sacar(double valor);
    double getSaldo() const;
    void adicionarTransacao(const Transacao& transacao);
};

#endif // CONTA_H