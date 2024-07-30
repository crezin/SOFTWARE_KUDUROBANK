#ifndef GERENTE_H
#define GERENTE_H

#include <string>

class Gerente {
private:
    std::string nome;    // Nome do gerente
    std::string senha;   // Senha do gerente

public:
    // Construtor que armazena nome e senha
    Gerente(const std::string& nome, const std::string& senha);

    // Método para obter o nome do gerente
    std::string getNome() const;

    // Método para validar a senha do gerente
    bool validarSenha(const std::string& senhaTentativa) const;
};

#endif // GERENTE_H
