#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class Transacao {
private:
    std::string tipo; // Tipo de transação (depósito ou saque)
    double valor;     // Valor da transação

public:
    // Construtor
    Transacao(const std::string& tipo, double valor);

    // Métodos get
    std::string getTipo() const;
    double getValor() const;
};

#endif // TRANSACAO_H
