#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
private:
    double taxaJuros; // Taxa de juros da conta poupança

public:
    // Construtor
    ContaPoupanca(const std::string& numero, double saldoInicial, double taxaJuros);

    // Método para aplicar juros
    void aplicarJuros();
};

#endif // CONTAPOUPANCA_H
