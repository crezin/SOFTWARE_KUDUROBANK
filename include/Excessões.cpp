#include <stdexcept>
#include <string>

/**
 * @brief Exce��o para erros relacionados a contas inativas.
 * 
 * A classe `ContaInativaException` � usada para lan�ar exce��es quando uma opera��o 
 * � realizada em uma conta inativa. Ela herda de `std::runtime_error`, que � a classe 
 * base para exce��es que reportam erros em tempo de execu��o.
 */
class ContaInativaException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `ContaInativaException`.
     * 
     * Este construtor inicializa uma nova inst�ncia de `ContaInativaException` com a 
     * mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exce��o.
     */
    explicit ContaInativaException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Exce��o para erros relacionados a saldo insuficiente.
 * 
 * A classe `SaldoInsuficienteException` � usada para lan�ar exce��es quando uma 
 * tentativa de saque ou transfer�ncia � feita, mas o saldo da conta � insuficiente. 
 * Ela herda de `std::runtime_error`.
 */
class SaldoInsuficienteException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `SaldoInsuficienteException`.
     * 
     * Este construtor inicializa uma nova inst�ncia de `SaldoInsuficienteException` 
     * com a mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exce��o.
     */
    explicit SaldoInsuficienteException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Exce��o para erros relacionados a valores inv�lidos.
 * 
 * A classe `ValorInvalidoException` � usada para lan�ar exce��es quando um valor 
 * inv�lido � fornecido em uma opera��o (como um dep�sito, saque ou transfer�ncia). 
 * Ela herda de `std::runtime_error`.
 */
class ValorInvalidoException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `ValorInvalidoException`.
     * 
     * Este construtor inicializa uma nova inst�ncia de `ValorInvalidoException` com a 
     * mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exce��o.
     */
    explicit ValorInvalidoException(const std::string& message)
        : std::runtime_error(message) {}
};

