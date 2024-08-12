#include <stdexcept>
#include <string>

class ContaInativaException : public std::runtime_error {
public:
    explicit ContaInativaException(const std::string& message)
        : std::runtime_error(message) {}
};

class SaldoInsuficienteException : public std::runtime_error {
public:
    explicit SaldoInsuficienteException(const std::string& message)
        : std::runtime_error(message) {}
};

class ValorInvalidoException : public std::runtime_error {
public:
    explicit ValorInvalidoException(const std::string& message)
        : std::runtime_error(message) {}
};

