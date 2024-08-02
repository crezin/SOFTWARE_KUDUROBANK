#include "transacao.h"

Transacao::Transacao(const std::string& tipo, double valor, time_t data) 
	: tipo(tipo), valor(valor), data(data) {}

std::string Transacao::getTipo() const {
    return tipo;
}

double Transacao::getValor() const {
    return valor;
}

std::time_t Transacao::getData() const {
    return data;
}
