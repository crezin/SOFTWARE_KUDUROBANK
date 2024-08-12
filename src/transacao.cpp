#include "Transacao.h"

/**
 * @brief Construtor da classe Transacao.
 * 
 * Este construtor inicializa uma nova instância de `Transacao` com o tipo, valor e data especificados.
 * Se o valor da transação for negativo, lança uma exceção `std::invalid_argument`.
 * 
 * @param tipo O tipo da transação (ex.: "Depósito", "Saque").
 * @param valor O valor da transação. Deve ser um valor positivo.
 * @param data A data em que a transação foi realizada.
 * 
 * @throws std::invalid_argument Se o valor da transação for negativo.
 */
Transacao::Transacao(const std::string& tipo, double valor, time_t data)
    : tipo(tipo), valor(valor), data(data) {
    if (valor < 0) {
        throw std::invalid_argument("O valor da transação não pode ser negativo.");
    }
}

/**
 * @brief Obtém o tipo da transação.
 * 
 * @return Uma string representando o tipo da transação (ex.: "Depósito", "Saque").
 */
std::string Transacao::getTipo() const {
    return tipo;
}

/**
 * @brief Obtém o valor da transação.
 * 
 * @return Um double representando o valor da transação.
 */
double Transacao::getValor() const {
    return valor;
}

/**
 * @brief Obtém a data da transação.
 * 
 * @return Um std::time_t representando a data da transação.
 */
std::time_t Transacao::getData() const {
    return data;
}

/**
 * @brief Obtém a data da transação formatada como string.
 * 
 * Este método converte a data da transação para uma string no formato "DD/MM/AAAA",
 * utilizando as funções de formatação de data da biblioteca padrão.
 * 
 * @return Uma string contendo a data da transação formatada.
 */
std::string Transacao::getDataString() const {
    std::tm* tm = std::localtime(&data);
    std::ostringstream oss;
    oss << std::put_time(tm, "%d/%m/%Y");
    return oss.str();
}



