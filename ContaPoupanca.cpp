#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"
#include "ContaPoupanca.h"


class ContaPoupanca : public Conta {
public:
    ContaPoupanca(int numeroConta);
    void aplicarJuros(double taxa);
};

#endif // CONTAPOUPANCA_H

ContaPoupanca::ContaPoupanca(int numeroConta) : Conta(numeroConta) {

}
