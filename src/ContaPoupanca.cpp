#include "ContaPoupanca.h"
#include <iostream>

/**
 * Construtor da classe ContaPoupanca.
 * Inicializa uma conta poupan�a com um n�mero de conta, saldo inicial e taxa de juros.
 *
 * @param numeroConta O n�mero da conta poupan�a.
 * @param saldoInicial O saldo inicial da conta poupan�a.
 * @param taxaJuros A taxa de juros associada � conta poupan�a.
 */
ContaPoupanca::ContaPoupanca(int numeroConta, double saldoInicial, double taxaJuros)
    : Conta(numeroConta, saldoInicial), taxaJuros(taxaJuros) {}

/**
 * Aplica juros ao saldo da conta poupan�a com base na taxa de juros.
 * O valor dos juros � calculado, adicionado ao saldo e registrado como uma transa��o.
 */
void ContaPoupanca::aplicarJuros() {
    // Calcula os juros com base no saldo atual e na taxa de juros
    double juros = saldo * taxaJuros;
    // Adiciona o valor dos juros ao saldo
    saldo += juros;
    // Registra a aplica��o de juros como uma transa��o
    transacoes.push_back(Transacao("Aplica��o de Juros", juros, std::time(nullptr)));
    // Exibe uma mensagem indicando o valor dos juros aplicados e o novo saldo da conta
    std::cout << "Juros de R$ " << juros << " aplicados com sucesso na data " 
              << transacoes.back().getDataString() << ". Novo saldo: R$ " << saldo << "\n";
}

/**
 * Obt�m a taxa de juros da conta poupan�a.
 *
 * @return A taxa de juros associada � conta poupan�a.
 */
double ContaPoupanca::getTaxaJuros() const {
    return taxaJuros;
}


