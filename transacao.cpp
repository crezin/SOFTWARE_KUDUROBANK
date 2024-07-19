#include "transacao.h"

Transacao::Transacao(const std::string& tipo, double valor) : tipo(tipo), valor(valor) {
    data = std::time(nullptr);
}

std::string Transacao::getTipo() const {
    return tipo;
}

double Transacao::getValor() const {
    return valor;
}

std::time_t Transacao::getData() const {
    return data;
}