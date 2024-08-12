#include "Transacao.h"

/**
 * @brief Construtor da classe Transacao.
 * 
 * Este construtor inicializa uma nova inst�ncia de `Transacao` com o tipo, valor e data especificados.
 * Se o valor da transa��o for negativo, lan�a uma exce��o `std::invalid_argument`.
 * 
 * @param tipo O tipo da transa��o (ex.: "Dep�sito", "Saque").
 * @param valor O valor da transa��o. Deve ser um valor positivo.
 * @param data A data em que a transa��o foi realizada.
 * 
 * @throws std::invalid_argument Se o valor da transa��o for negativo.
 */
Transacao::Transacao(const std::string& tipo, double valor, time_t data)
    : tipo(tipo), valor(valor), data(data) {
    if (valor < 0) {
        throw std::invalid_argument("O valor da transa��o n�o pode ser negativo.");
    }
}

/**
 * @brief Obt�m o tipo da transa��o.
 * 
 * @return Uma string representando o tipo da transa��o (ex.: "Dep�sito", "Saque").
 */
std::string Transacao::getTipo() const {
    return tipo;
}

/**
 * @brief Obt�m o valor da transa��o.
 * 
 * @return Um double representando o valor da transa��o.
 */
double Transacao::getValor() const {
    return valor;
}

/**
 * @brief Obt�m a data da transa��o.
 * 
 * @return Um std::time_t representando a data da transa��o.
 */
std::time_t Transacao::getData() const {
    return data;
}

/**
 * @brief Obt�m a data da transa��o formatada como string.
 * 
 * Este m�todo converte a data da transa��o para uma string no formato "DD/MM/AAAA",
 * utilizando as fun��es de formata��o de data da biblioteca padr�o.
 * 
 * @return Uma string contendo a data da transa��o formatada.
 */
std::string Transacao::getDataString() const {
    std::tm* tm = std::localtime(&data);
    std::ostringstream oss;
    oss << std::put_time(tm, "%d/%m/%Y");
    return oss.str();
}



