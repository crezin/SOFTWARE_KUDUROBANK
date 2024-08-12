#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
private:
    double taxaJuros;

public:
    ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros);
    void aplicarJuros();
    double getTaxaJuros() const;
};

#endif // CONTAPOUPANCA_H

