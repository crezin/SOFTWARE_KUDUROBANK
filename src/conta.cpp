#include "Conta.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Excess�es.cpp"  // Inclui a implementa��o das exce��es personalizadas

/**
 * Construtor da classe Conta.
 * Inicializa uma conta com um n�mero e um saldo inicial.
 *
 * @param numeroConta O n�mero da conta.
 * @param saldoInicial O saldo inicial da conta.
 */
Conta::Conta(int numeroConta, double saldoInicial)
    : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}

/**
 * Obt�m o n�mero da conta.
 *
 * @return O n�mero da conta.
 */
int Conta::getNumeroConta() const {
    return numeroConta;
}

/**
 * Realiza um dep�sito na conta.
 *
 * @param valor O valor a ser depositado. Deve ser positivo.
 * @param data A data do dep�sito.
 * @throws std::invalid_argument Se o valor do dep�sito for negativo ou zero.
 * @throws ContaInativaException Se a conta estiver inativa.
 */
void Conta::depositar(double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do dep�sito deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. N�o � poss�vel depositar.");
    }

    saldo += valor;
    transacoes.push_back(Transacao("Dep�sito", valor, data));
    std::cout << "Dep�sito de R$ " << valor << " realizado com sucesso na data " << transacoes.back().getDataString() << "!\n";
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
        throw ContaInativaException("Conta inativa. N�o � poss�vel sacar.");
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
 * Realiza uma transfer�ncia de fundos para outra conta.
 *
 * @param contaDestino A conta de destino para a transfer�ncia.
 * @param valor O valor a ser transferido. Deve ser positivo.
 * @param data A data da transfer�ncia.
 * @return True se a transfer�ncia foi bem-sucedida.
 * @throws std::invalid_argument Se o valor da transfer�ncia for negativo ou zero.
 * @throws ContaInativaException Se a conta ou a conta de destino estiver inativa.
 * @throws SaldoInsuficienteException Se o saldo for insuficiente para a transfer�ncia.
 */
bool Conta::transferir(std::shared_ptr<Conta> contaDestino, double valor, time_t data) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor da transfer�ncia deve ser positivo.");
    }

    if (!ativa) {
        throw ContaInativaException("Conta inativa. N�o � poss�vel realizar a transfer�ncia.");
    }

    if (!contaDestino->isAtiva()) {
        throw ContaInativaException("A conta de destino est� inativa. N�o � poss�vel realizar a transfer�ncia.");
    }

    if (saldo < valor) {
        throw SaldoInsuficienteException("Saldo insuficiente para transfer�ncia.");
    }

    saldo -= valor;
    contaDestino->saldo += valor;

    Transacao transacaoSaida("Transfer�ncia enviada", -valor, data);
    Transacao transacaoEntrada("Transfer�ncia recebida", valor, data);

    transacoes.push_back(transacaoSaida);
    contaDestino->transacoes.push_back(transacaoEntrada);

    std::cout << "Transfer�ncia de R$ " << valor << " realizada com sucesso na data " << transacaoSaida.getDataString() << "!\n";
    
    return true;
}

/**
 * Obt�m o saldo atual da conta.
 *
 * @return O saldo atual da conta.
 */
double Conta::getSaldo() const {
    return saldo;
}

/**
 * Verifica se a conta est� ativa.
 *
 * @return True se a conta estiver ativa, False caso contr�rio.
 */
bool Conta::isAtiva() const {
    return ativa;
}

/**
 * Torna a conta inativa, impedindo opera��es como saques e dep�sitos.
 */
void Conta::tornarInativa() {
    ativa = false;
}

/**
 * Exibe o hist�rico de transa��es da conta.
 */
void Conta::mostrarTransacoes() const {
    for (const auto& transacao : transacoes) {
        std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor()
                  << ", Data: " << transacao.getDataString() << "\n";
    }
}

/**
 * Obt�m o hist�rico de transa��es da conta.
 *
 * @return Um vetor constante contendo as transa��es da conta.
 */
const std::vector<Transacao>& Conta::getTransacoes() const {
    return transacoes;
}


