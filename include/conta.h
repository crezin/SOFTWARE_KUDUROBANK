#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include <string>
#include <memory>
#include "Transacao.h"
#include <ctime>

/**
 * Classe base para representar uma Conta Bancária.
 * Fornece funcionalidades básicas como sacar, depositar e transferir fundos.
 */
class Conta {
protected:
    int numeroConta;  ///< Número da conta bancária
    double saldo;  ///< Saldo atual da conta
    bool ativa;  ///< Indica se a conta está ativa
    std::vector<Transacao> transacoes;  ///< Histórico de transações da conta

public:
    /**
     * Construtor da classe Conta.
     * Inicializa uma conta com o número da conta e saldo inicial.
     *
     * @param numeroConta O número da conta.
     * @param saldoInicial O saldo inicial da conta.
     */
    Conta(int numeroConta, double saldoInicial);

    /**
     * Destrutor virtual padrão.
     * Necessário para permitir destruição correta de objetos derivados.
     */
    virtual ~Conta() = default;

    /**
     * Obtém o número da conta.
     *
     * @return O número da conta.
     */
    int getNumeroConta() const;

    /**
     * Realiza um saque na conta.
     *
     * @param valor O valor a ser sacado.
     * @param data A data do saque.
     * @return True se o saque foi bem-sucedido, False caso contrário.
     */
    virtual bool sacar(double valor, time_t data);

    /**
     * Realiza um depósito na conta.
     *
     * @param valor O valor a ser depositado.
     * @param data A data do depósito.
     */
    virtual void depositar(double valor, time_t data);

    /**
     * Obtém o saldo atual da conta.
     *
     * @return O saldo atual da conta.
     */
    double getSaldo() const;

    /**
     * Verifica se a conta está ativa.
     *
     * @return True se a conta está ativa, False caso contrário.
     */
    bool isAtiva() const;

    /**
     * Torna a conta inativa.
     */
    void tornarInativa();

    /**
     * Exibe o histórico de transações da conta.
     */
    void mostrarTransacoes() const;

    /**
     * Realiza uma transferência para outra conta.
     *
     * @param contaDestino A conta de destino para a transferência.
     * @param valor O valor a ser transferido.
     * @param data A data da transferência.
     * @return True se a transferência foi bem-sucedida, False caso contrário.
     */
    bool transferir(std::shared_ptr<Conta> contaDestino, double valor, time_t data);

    /**
     * Obtém o histórico de transações da conta.
     *
     * @return Um vetor de transações.
     */
    const std::vector<Transacao>& getTransacoes() const;
};

#endif // CONTA_H





