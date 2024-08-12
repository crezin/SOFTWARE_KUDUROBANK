#ifndef TRANSACAOBANCARIA_H
#define TRANSACAOBANCARIA_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

/**
 * @brief Classe que representa uma transa��o banc�ria.
 * 
 * A classe Transacao encapsula as informa��es de uma transa��o, como o tipo da transa��o (dep�sito, saque, etc.),
 * o valor envolvido e a data em que a transa��o foi realizada.
 */
class Transacao {
private:
    std::string tipo;   ///< Tipo da transa��o (ex.: "Dep�sito", "Saque").
    double valor;       ///< Valor da transa��o.
    std::time_t data;   ///< Data em que a transa��o foi realizada.

public:
    /**
     * @brief Construtor da classe Transacao.
     * 
     * @param tipo O tipo da transa��o (ex.: "Dep�sito", "Saque").
     * @param valor O valor da transa��o.
     * @param data A data em que a transa��o foi realizada.
     */
    Transacao(const std::string& tipo, double valor, time_t data);

    /**
     * @brief Obt�m o tipo da transa��o.
     * 
     * @return Uma string representando o tipo da transa��o.
     */
    std::string getTipo() const;

    /**
     * @brief Obt�m o valor da transa��o.
     * 
     * @return Um double representando o valor da transa��o.
     */
    double getValor() const;

    /**
     * @brief Obt�m a data da transa��o.
     * 
     * @return Um std::time_t representando a data da transa��o.
     */
    std::time_t getData() const;

    /**
     * @brief Obt�m a data da transa��o formatada como string.
     * 
     * @return Uma string contendo a data da transa��o formatada como "DD/MM/AAAA".
     */
    std::string getDataString() const;
};

#endif // TRANSACAO_H

