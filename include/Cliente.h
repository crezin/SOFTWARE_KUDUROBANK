#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "conta.h"

class Cliente{
private:
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string numeroTelefone;
    std::string senha;
    std::vector<Conta*> contas;

public:
    Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
    ~Cliente();

    void setNome(const std::string& nome);
    void setCpf(const std::string& cpf);
    void setEndereco(const std::string& endereco);
    void setNumeroTelefone(const std::string& numeroTelefone);
    void setSenha(const std::string& senha);

    std::string getNome() const;
    std::string getCpf() const;
    std::string getEndereco() const;
    std::string getNumeroTelefone() const;
    std::string getSenha() const;

    void adicionarConta(Conta* conta);
    void mostrarMenu() const;
    bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const;
    void operarConta(Conta* conta);
    void selecionarContaEOperar();
    void extrato(time_t dataInicial) const;
};

#endif // CLIENTE_H
