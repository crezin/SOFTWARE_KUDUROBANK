#include "ContaCorrente.h"
#include <iostream>

/**
 * Construtor da classe ContaCorrente.
 * Inicializa uma conta corrente com um número de conta, saldo inicial e limite de cheque especial.
 *
 * @param numeroConta O número da conta corrente.
 * @param saldoInicial O saldo inicial da conta corrente.
 * @param limiteChequeEspecial O limite de cheque especial associado à conta.
 */
ContaCorrente::ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial)
    : Conta(numeroConta, saldoInicial), limiteChequeEspecial(limiteChequeEspecial) {}

/**
 * Realiza um saque na conta corrente, considerando o limite de cheque especial.
 *
 * @param valor O valor a ser sacado. Deve ser positivo e não pode exceder o saldo disponível mais o limite de cheque especial.
 * @param data A data do saque.
 * @return True se o saque foi bem-sucedido; false se o saldo mais o limite de cheque especial forem insuficientes.
 */
bool ContaCorrente::sacar(double valor, time_t data) {
    if (valor <= saldo + limiteChequeEspecial) {  // Verifica se o valor do saque está dentro do saldo disponível, incluindo o limite de cheque especial
        saldo -= valor;  // Deduz o valor do saque do saldo
        transacoes.push_back(Transacao("Saque", valor, data));  // Registra a transação de saque
        std::cout << "Saque de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
        return true;  // Retorna sucesso
    } else {
        std::cout << "Saldo insuficiente para saque, mesmo com limite de cheque especial.\n";
        return false;  // Retorna falha se o saldo e o limite de cheque especial forem insuficientes
    }
}

/**
 * Obtém o limite de cheque especial da conta corrente.
 *
 * @return O limite de cheque especial.
 */
double ContaCorrente::getLimiteChequeEspecial() const {
    return limiteChequeEspecial;
}



