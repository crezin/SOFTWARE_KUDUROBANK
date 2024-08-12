#include "Transacao.h"

Transacao::Transacao(const std::string& tipo, double valor, time_t data)
    : tipo(tipo), valor(valor), data(data) {
    if (valor < 0) {
        throw std::invalid_argument("O valor da transação não pode ser negativo.");
    }
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

std::string Transacao::getDataString() const {
    std::tm* tm = std::localtime(&data);
    std::ostringstream oss;
    oss << std::put_time(tm, "%d/%m/%Y");
    return oss.str();
}


