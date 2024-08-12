#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

/**
 * Classe ContaCorrente, que herda de Conta.
 * Representa uma conta corrente com limite de cheque especial.
 */
class ContaCorrente : public Conta {
private:
    double limiteChequeEspecial;  // Limite de cheque especial associado à conta corrente

public:
    /**
     * Construtor da classe ContaCorrente.
     * Inicializa uma conta corrente com um número, saldo inicial e limite de cheque especial.
     *
     * @param numeroConta O número da conta.
     * @param saldoInicial O saldo inicial da conta.
     * @param limiteChequeEspecial O limite de cheque especial associado à conta.
     */
    ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial);

    /**
     * Realiza um saque na conta corrente, considerando o limite de cheque especial.
     *
     * @param valor O valor a ser sacado. Deve ser positivo.
     * @param data A data do saque.
     * @return True se o saque foi bem-sucedido.
     * @throws std::invalid_argument Se o valor do saque for negativo ou zero.
     * @throws ContaInativaException Se a conta estiver inativa.
     * @throws SaldoInsuficienteException Se o saldo e o limite de cheque especial forem insuficientes para o saque.
     */
    bool sacar(double valor, time_t data) override;

    /**
     * Obtém o limite de cheque especial da conta corrente.
     *
     * @return O limite de cheque especial.
     */
    double getLimiteChequeEspecial() const;
};

#endif // CONTACORRENTE_H




