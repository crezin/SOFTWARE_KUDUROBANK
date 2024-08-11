#ifndef TRANSACAOBANCARIA_H
#define TRANSACAOBANCARIA_H

#include <string>
#include <ctime>

class Transacao {
private:
    std::string tipo;
    double valor;
    std::time_t data;

public:
    Transacao(const std::string& tipo, double valor, time_t data);
    std::string getTipo() const;
    double getValor() const;
    std::time_t getData() const;
};

#endif // TRANSACAO_H

