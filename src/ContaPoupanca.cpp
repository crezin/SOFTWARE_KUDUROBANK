#include "ContaPoupanca.h"
#include <iostream>

/**
 * Construtor da classe ContaPoupanca.
 * Inicializa uma conta poupança com um número de conta, saldo inicial e taxa de juros.
 *
 * @param numeroConta O número da conta poupança.
 * @param saldoInicial O saldo inicial da conta poupança.
 * @param taxaJuros A taxa de juros associada à conta poupança.
 */
ContaPoupanca::ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros)
    : Conta(numeroConta, saldoInicial), taxaJuros(taxaJuros) {}

/**
 * Aplica juros ao saldo da conta poupança com base na taxa de juros.
 * O valor dos juros é calculado, adicionado ao saldo e registrado como uma transação.
 */
void ContaPoupanca::aplicarJuros() {
    // Calcula os juros com base no saldo atual e na taxa de juros
    double juros = saldo * taxaJuros;
    // Adiciona o valor dos juros ao saldo
    saldo += juros;
    // Registra a aplicação de juros como uma transação
    transacoes.push_back(Transacao("Aplicação de Juros", juros, std::time(nullptr)));
    // Exibe uma mensagem indicando o valor dos juros aplicados e o novo saldo da conta
    std::cout << "Juros de R$ " << juros << " aplicados com sucesso na data " 
              << transacoes.back().getDataString() << ". Novo saldo: R$ " << saldo << "\n";
}

/**
 * Obtém a taxa de juros da conta poupança.
 *
 * @return A taxa de juros associada à conta poupança.
 */
double ContaPoupanca::getTaxaJuros() const {
    return taxaJuros;
}


