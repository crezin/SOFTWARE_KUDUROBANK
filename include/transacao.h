#ifndef TRANSACAOBANCARIA_H
#define TRANSACAOBANCARIA_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

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
    std::string getDataString() const;  // Adicionando um método para obter a data formatada como string
};

#endif // TRANSACAO_H

