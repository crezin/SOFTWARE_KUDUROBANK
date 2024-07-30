#include "Gerente.h"

// Construtor da classe Gerente
Gerente::Gerente(const std::string& nome, const std::string& senha)
        : nome(nome), senha(senha) {}

// Método para obter o nome do gerente
std::string Gerente::getNome() const {
    return nome;
}

// Método para validar a senha do gerente
bool Gerente::validarSenha(const std::string& senhaTentativa) const {
    return senha == senhaTentativa; // Compara a senha armazenada com a senha tentada
}
