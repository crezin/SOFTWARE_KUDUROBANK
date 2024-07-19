#ifndef GERENTE_H
#define GERENTE_H

#include <string>
#include <cstdlib>
#include <ctime>

class Gerente {
private:
    std::string nome;
    std::string senha;
    std::string token;

    std::string gerarToken();

public:
    Gerente(const std::string& nome, const std::string& senha);
    std::string getNome() const;
    std::string getToken() const;
    bool validarSenha(const std::string& senhaTentativa) const;
    void cadastrarGerente(const std::string& nome, const std::string& senha);
};

#endif // GERENTE_H
