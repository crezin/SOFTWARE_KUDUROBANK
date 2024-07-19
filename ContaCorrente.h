#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double limiteChequeEspecial;

public:
    ContaCorrente(int numeroConta, double limite);
    bool sacar(double valor) override;
};

#endif // CONTACORRENTE_H