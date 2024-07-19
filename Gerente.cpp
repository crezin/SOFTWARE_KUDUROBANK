#include "Gerente.h"

Gerente::Gerente(const std::string& nome, const std::string& senha) : nome(nome), senha(senha) {
    token = gerarToken(); // Gera um token ao criar o gerente
}

std::string Gerente::gerarToken() {
    std::srand(std::time(0)); // Inicializa a semente para geração aleatória
    std::string token = "TOKEN_";
    for (int i = 0; i < 8; ++i) {
        token += std::to_string(std::rand() % 10); // Adiciona números aleatórios
    }
    return token;
}

std::string Gerente::getNome() const {
    return nome;
}

std::string Gerente::getToken() const {
    return token;
}

bool Gerente::validarSenha(const std::string& senhaTentativa) const {
    return senha == senhaTentativa;
}

void Gerente::cadastrarGerente(const std::string& nome, const std::string& senha) {
    this->nome = nome;
    this->senha = senha;
    this->token = gerarToken(); // Gera um novo token ao cadastrar
}