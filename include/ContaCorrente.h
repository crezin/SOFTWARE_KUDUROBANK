#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double limiteChequeEspecial;

public:
    ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial);
    bool sacar(double valor, time_t data) override;
};

#endif // CONTACORRENTE_H

