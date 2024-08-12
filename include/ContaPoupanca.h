#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

/**
 * Classe ContaPoupanca.
 * Representa uma conta poupan�a, que herda da classe base Conta.
 */
class ContaPoupanca : public Conta {
private:
    double taxaJuros;  // Taxa de juros aplicada � conta poupan�a

public:
    /**
     * Construtor da classe ContaPoupanca.
     * Inicializa uma conta poupan�a com um n�mero de conta, saldo inicial e taxa de juros.
     *
     * @param numeroConta O n�mero da conta poupan�a.
     * @param saldoInicial O saldo inicial da conta poupan�a.
     * @param taxaJuros A taxa de juros associada � conta poupan�a.
     */
    ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros);

    /**
     * Aplica juros ao saldo da conta poupan�a com base na taxa de juros.
     * O valor dos juros � adicionado ao saldo da conta.
     */
    void aplicarJuros();

    /**
     * Obt�m a taxa de juros da conta poupan�a.
     *
     * @return A taxa de juros associada � conta poupan�a.
     */
    double getTaxaJuros() const;
};

#endif // CONTAPOUPANCA_H

