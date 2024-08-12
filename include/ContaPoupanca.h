#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

/**
 * Classe ContaPoupanca.
 * Representa uma conta poupança, que herda da classe base Conta.
 */
class ContaPoupanca : public Conta {
private:
    double taxaJuros;  // Taxa de juros aplicada à conta poupança

public:
    /**
     * Construtor da classe ContaPoupanca.
     * Inicializa uma conta poupança com um número de conta, saldo inicial e taxa de juros.
     *
     * @param numeroConta O número da conta poupança.
     * @param saldoInicial O saldo inicial da conta poupança.
     * @param taxaJuros A taxa de juros associada à conta poupança.
     */
    ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros);

    /**
     * Aplica juros ao saldo da conta poupança com base na taxa de juros.
     * O valor dos juros é adicionado ao saldo da conta.
     */
    void aplicarJuros();

    /**
     * Obtém a taxa de juros da conta poupança.
     *
     * @return A taxa de juros associada à conta poupança.
     */
    double getTaxaJuros() const;
};

#endif // CONTAPOUPANCA_H

