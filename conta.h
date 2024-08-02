#ifndef CONTA_H
#define CONTA_H
using namespace std;
#include <vector>
#include "transacao.h"
#include <ctime>

class Conta {
protected:
    int numeroConta;
    double saldo;
    std::vector<Transacao> transacoes;

public:
    Conta(int numeroConta, double saldoInicial);
    virtual ~Conta() = default;
    
    int getNumeroConta() const;
    virtual void depositar(double valor, time_t data);
    virtual bool sacar(double valor, time_t data);
    double getSaldo() const;
    void mostrarTransacoes() const;
};

#endif // CONTA_H
