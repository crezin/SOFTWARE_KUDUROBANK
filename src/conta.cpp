#include "Conta.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Excessões.cpp"  // Inclui a implementação das exceções personalizadas

/**
 * Construtor da classe Conta.
 * Inicializa uma conta com um número e um saldo inicial.
 *
 * @param numeroConta O número da conta.
 * @param saldoInicial O saldo inicial da conta.
 */
Conta::Conta(int numeroConta, double saldoInicial)
    : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}

/**
 * Obtém o número da conta.
 *
 * @return O número da conta.
 */
int Conta::getNumeroConta() const {
    return numeroConta;
}

/**
 * Realiza um depósito na conta.
 *
 * @param valor O valor a ser depositado. Deve ser positivo.
 * @param data A data do depósito.
 * @throws std::invalid_argument Se o valor do depósito for negativo ou zero.
 * @throws ContaInativaException Se a conta estiver inativa.
 */
void Conta::depositar(double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do depósito deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível depositar.");
    }

    saldo += valor;
    transacoes.push_back(Transacao("Depósito", valor, data));
    std::cout << "Depósito de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
}

/**
 * Realiza um saque na conta.
 *
 * @param valor O valor a ser sacado. Deve ser positivo.
 * @param data A data do saque.
 * @return True se o saque foi bem-sucedido.
 * @throws std::invalid_argument Se o valor do saque for negativo ou zero.
 * @throws ContaInativaException Se a conta estiver inativa.
 * @throws SaldoInsuficienteException Se o saldo for insuficiente para o saque.
 */
bool Conta::sacar(double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do saque deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível sacar.");
    }

    if (valor > saldo) {
        throw SaldoInsuficienteException("Saldo insuficiente para saque.");
    }

    saldo -= valor;
    transacoes.push_back(Transacao("Saque", valor, data));
    std::cout << "Saque de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
    return true;  // Sucesso
}

/**
 * Realiza uma transferência de fundos para outra conta.
 *
 * @param contaDestino A conta de destino para a transferência.
 * @param valor O valor a ser transferido. Deve ser positivo.
 * @param data A data da transferência.
 * @return True se a transferência foi bem-sucedida.
 * @throws std::invalid_argument Se o valor da transferência for negativo ou zero.
 * @throws ContaInativaException Se a conta ou a conta de destino estiver inativa.
 * @throws SaldoInsuficienteException Se o saldo for insuficiente para a transferência.
 */
bool Conta::transferir(std::shared_ptr<Conta> contaDestino, double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor da transferência deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. Não é possível realizar a transferência.");
    }

    if (!contaDestino->isAtiva()) {
        throw ContaInativaException("A conta de destino está inativa. Não é possível realizar a transferência.");
    }

    if (saldo < valor) {
        throw SaldoInsuficienteException("Saldo insuficiente para transferência.");
    }

    saldo -= valor;
    contaDestino->saldo += valor;

    Transacao transacaoSaida("Transferência enviada", -valor, data);
    Transacao transacaoEntrada("Transferência recebida", valor, data);

    transacoes.push_back(transacaoSaida);
    contaDestino->transacoes.push_back(transacaoEntrada);

    std::cout << "Transferência de R$ " << valor << " realizada com sucesso na data " << transacaoSaida.getDataString() << "!\n";
    
    return true;
}

/**
 * Obtém o saldo atual da conta.
 *
 * @return O saldo atual da conta.
 */
double Conta::getSaldo() const {
    return saldo;
}

/**
 * Verifica se a conta está ativa.
 *
 * @return True se a conta estiver ativa, False caso contrário.
 */
bool Conta::isAtiva() const {
    return ativa;
}

/**
 * Torna a conta inativa, impedindo operações como saques e depósitos.
 */
void Conta::tornarInativa() {
    ativa = false;
}

/**
 * Exibe o histórico de transações da conta.
 */
void Conta::mostrarTransacoes() const {
    for (const auto& transacao : transacoes) {
        std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor()
                  << ", Data: " << transacao.getDataString() << "\n";
    }
}

/**
 * Obtém o histórico de transações da conta.
 *
 * @return Um vetor constante contendo as transações da conta.
 */
const std::vector<Transacao>& Conta::getTransacoes() const {
    return transacoes;
}


