#include "conta.h"

// Construtor da classe Conta
Conta::Conta(const std::string& numero, double saldoInicial)
        : numeroConta(numero), saldo(saldoInicial) {}

// Método para depositar valor na conta
void Conta::depositar(double valor) {
    saldo += valor; // Adiciona valor ao saldo
}

// Método para sacar valor da conta
bool Conta::sacar(double valor) {
    if (valor <= saldo) {
        saldo -= valor; // Subtrai valor do saldo
        return true;    // Saque bem-sucedido
    }
    return false; // Saldo insuficiente
}

// Método para obter o saldo da conta
double Conta::getSaldo() const {
    return saldo; // Retorna o saldo atual
}

// Método para obter o número da conta
std::string Conta::getNumeroConta() const {
    return numeroConta; // Retorna o número da conta
}

// Método para adicionar transação
void Conta::adicionarTransacao(const Transacao& transacao) {
    transacoes.push_back(transacao); // Adiciona a transação ao histórico
}
