#include <stdexcept>
#include <string>

/**
 * @brief Exceção para erros relacionados a contas inativas.
 * 
 * A classe `ContaInativaException` é usada para lançar exceções quando uma operação 
 * é realizada em uma conta inativa. Ela herda de `std::runtime_error`, que é a classe 
 * base para exceções que reportam erros em tempo de execução.
 */
class ContaInativaException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `ContaInativaException`.
     * 
     * Este construtor inicializa uma nova instância de `ContaInativaException` com a 
     * mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exceção.
     */
    explicit ContaInativaException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Exceção para erros relacionados a saldo insuficiente.
 * 
 * A classe `SaldoInsuficienteException` é usada para lançar exceções quando uma 
 * tentativa de saque ou transferência é feita, mas o saldo da conta é insuficiente. 
 * Ela herda de `std::runtime_error`.
 */
class SaldoInsuficienteException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `SaldoInsuficienteException`.
     * 
     * Este construtor inicializa uma nova instância de `SaldoInsuficienteException` 
     * com a mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exceção.
     */
    explicit SaldoInsuficienteException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Exceção para erros relacionados a valores inválidos.
 * 
 * A classe `ValorInvalidoException` é usada para lançar exceções quando um valor 
 * inválido é fornecido em uma operação (como um depósito, saque ou transferência). 
 * Ela herda de `std::runtime_error`.
 */
class ValorInvalidoException : public std::runtime_error {
public:
    /**
     * @brief Construtor para `ValorInvalidoException`.
     * 
     * Este construtor inicializa uma nova instância de `ValorInvalidoException` com a 
     * mensagem de erro fornecida.
     * 
     * @param message A mensagem de erro a ser associada a esta exceção.
     */
    explicit ValorInvalidoException(const std::string& message)
        : std::runtime_error(message) {}
};

