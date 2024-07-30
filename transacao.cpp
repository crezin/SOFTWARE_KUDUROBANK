#include "transacao.h"

// Construtor da classe Transacao
Transacao::Transacao(const std::string& tipo, double valor)
        : tipo(tipo), valor(valor) {}

// Método para obter o tipo da transação
std::string Transacao::getTipo() const {
    return tipo;
}

// Método para obter o valor da transação
double Transacao::getValor() const {
    return valor;
}
