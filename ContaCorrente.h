#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double limite; // Limite da conta corrente

public:
    // Construtor
    ContaCorrente(const std::string& numero, double saldoInicial, double limite);

    // Sobrescreve o método sacar
    bool sacar(double valor) override;
};

#endif // CONTACORRENTE_H
