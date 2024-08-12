#ifndef TRANSACAOBANCARIA_H
#define TRANSACAOBANCARIA_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

/**
 * @brief Classe que representa uma transação bancária.
 * 
 * A classe Transacao encapsula as informações de uma transação, como o tipo da transação (depósito, saque, etc.),
 * o valor envolvido e a data em que a transação foi realizada.
 */
class Transacao {
private:
    std::string tipo;   ///< Tipo da transação (ex.: "Depósito", "Saque").
    double valor;       ///< Valor da transação.
    std::time_t data;   ///< Data em que a transação foi realizada.

public:
    /**
     * @brief Construtor da classe Transacao.
     * 
     * @param tipo O tipo da transação (ex.: "Depósito", "Saque").
     * @param valor O valor da transação.
     * @param data A data em que a transação foi realizada.
     */
    Transacao(const std::string& tipo, double valor, time_t data);

    /**
     * @brief Obtém o tipo da transação.
     * 
     * @return Uma string representando o tipo da transação.
     */
    std::string getTipo() const;

    /**
     * @brief Obtém o valor da transação.
     * 
     * @return Um double representando o valor da transação.
     */
    double getValor() const;

    /**
     * @brief Obtém a data da transação.
     * 
     * @return Um std::time_t representando a data da transação.
     */
    std::time_t getData() const;

    /**
     * @brief Obtém a data da transação formatada como string.
     * 
     * @return Uma string contendo a data da transação formatada como "DD/MM/AAAA".
     */
    std::string getDataString() const;
};

#endif // TRANSACAO_H

