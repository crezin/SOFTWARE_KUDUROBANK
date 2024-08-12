#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include <string>
#include <memory>
#include "Transacao.h"
#include <ctime>

/**
 * Classe base para representar uma Conta Banc�ria.
 * Fornece funcionalidades b�sicas como sacar, depositar e transferir fundos.
 */
class Conta {
protected:
    int numeroConta;  ///< N�mero da conta banc�ria
    double saldo;  ///< Saldo atual da conta
    bool ativa;  ///< Indica se a conta est� ativa
    std::vector<Transacao> transacoes;  ///< Hist�rico de transa��es da conta

public:
    /**
     * Construtor da classe Conta.
     * Inicializa uma conta com o n�mero da conta e saldo inicial.
     *
     * @param numeroConta O n�mero da conta.
     * @param saldoInicial O saldo inicial da conta.
     */
    Conta(int numeroConta, double saldoInicial);

    /**
     * Destrutor virtual padr�o.
     * Necess�rio para permitir destrui��o correta de objetos derivados.
     */
    virtual ~Conta() = default;

    /**
     * Obt�m o n�mero da conta.
     *
     * @return O n�mero da conta.
     */
    int getNumeroConta() const;

    /**
     * Realiza um saque na conta.
     *
     * @param valor O valor a ser sacado.
     * @param data A data do saque.
     * @return True se o saque foi bem-sucedido, False caso contr�rio.
     */
    virtual bool sacar(double valor, time_t data);

    /**
     * Realiza um dep�sito na conta.
     *
     * @param valor O valor a ser depositado.
     * @param data A data do dep�sito.
     */
    virtual void depositar(double valor, time_t data);

    /**
     * Obt�m o saldo atual da conta.
     *
     * @return O saldo atual da conta.
     */
    double getSaldo() const;

    /**
     * Verifica se a conta est� ativa.
     *
     * @return True se a conta est� ativa, False caso contr�rio.
     */
    bool isAtiva() const;

    /**
     * Torna a conta inativa.
     */
    void tornarInativa();

    /**
     * Exibe o hist�rico de transa��es da conta.
     */
    void mostrarTransacoes() const;

    /**
     * Realiza uma transfer�ncia para outra conta.
     *
     * @param contaDestino A conta de destino para a transfer�ncia.
     * @param valor O valor a ser transferido.
     * @param data A data da transfer�ncia.
     * @return True se a transfer�ncia foi bem-sucedida, False caso contr�rio.
     */
    bool transferir(std::shared_ptr<Conta> contaDestino, double valor, time_t data);

    /**
     * Obt�m o hist�rico de transa��es da conta.
     *
     * @return Um vetor de transa��es.
     */
    const std::vector<Transacao>& getTransacoes() const;
};

#endif // CONTA_H





