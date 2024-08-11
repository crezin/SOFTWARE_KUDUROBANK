#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
private:
    double taxaJuros;

public:
    ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros);
    void aplicarJuros();
};

#endif // CONTAPOUPANCA_H

