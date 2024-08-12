#include "ContaCorrente.h"
#include <iostream>

/**
 * Construtor da classe ContaCorrente.
 * Inicializa uma conta corrente com um n�mero de conta, saldo inicial e limite de cheque especial.
 *
 * @param numeroConta O n�mero da conta corrente.
 * @param saldoInicial O saldo inicial da conta corrente.
 * @param limiteChequeEspecial O limite de cheque especial associado � conta.
 */
ContaCorrente::ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial)
    : Conta(numeroConta, saldoInicial), limiteChequeEspecial(limiteChequeEspecial) {}

/**
 * Realiza um saque na conta corrente, considerando o limite de cheque especial.
 *
 * @param valor O valor a ser sacado. Deve ser positivo e n�o pode exceder o saldo dispon�vel mais o limite de cheque especial.
 * @param data A data do saque.
 * @return True se o saque foi bem-sucedido; false se o saldo mais o limite de cheque especial forem insuficientes.
 */
bool ContaCorrente::sacar(double valor, time_t data) {
    if (valor <= saldo + limiteChequeEspecial) {  // Verifica se o valor do saque est� dentro do saldo dispon�vel, incluindo o limite de cheque especial
        saldo -= valor;  // Deduz o valor do saque do saldo
        transacoes.push_back(Transacao("Saque", valor, data));  // Registra a transa��o de saque
        std::cout << "Saque de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
        return true;  // Retorna sucesso
    } else {
        std::cout << "Saldo insuficiente para saque, mesmo com limite de cheque especial.\n";
        return false;  // Retorna falha se o saldo e o limite de cheque especial forem insuficientes
    }
}

/**
 * Obt�m o limite de cheque especial da conta corrente.
 *
 * @return O limite de cheque especial.
 */
double ContaCorrente::getLimiteChequeEspecial() const {
    return limiteChequeEspecial;
}



