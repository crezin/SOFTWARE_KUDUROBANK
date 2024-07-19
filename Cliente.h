#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Conta.h"
#include "Gerente.h"

class Cliente {
private:
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string numeroTelefone;
    std::string senha; // Armazena a senha
    std::vector<Conta*> contas;
    Gerente* gerente;

public:
    // Adicionando a senha ao construtor
    Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
    ~Cliente();

    // Métodos set e get
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

    // Métodos adicionais
    void adicionarConta(Conta* conta);
    std::vector<Conta*> getContas() const;
    bool validarSenha(const std::string& senhaTentativa) const;

    void mostrarOpcaoGerente();
    void mostrarOpcaoUsuario();
    void cadastrarGerente(const std::string& nome, const std::string& senha);
    void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
};

#endif // CLIENTE_H
