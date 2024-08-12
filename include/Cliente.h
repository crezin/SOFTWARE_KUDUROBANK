#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <memory>
#include "Conta.h"
#include <limits>
#include <map>

class Cliente {
protected:
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string numeroTelefone;
    std::string senha;
    std::vector<std::shared_ptr<Conta>> contas;  // Usando smart pointers para contas

public:
    Cliente() : nome(""), cpf(""), endereco(""), numeroTelefone(""), senha("") {}
    Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
    virtual ~Cliente() = default;  // Smart pointers cuidam da desalocação de memória

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
    std::vector<std::shared_ptr<Conta>>& getContas();

    void operarConta(std::shared_ptr<Conta> conta, std::map<std::string, std::shared_ptr<Cliente>>& clientes);
    void adicionarConta(std::shared_ptr<Conta> conta);
    bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const;
    void selecionarContaEOperar(std::map<std::string, std::shared_ptr<Cliente>>& clientes);
    void extrato(time_t dataInicial) const;
    void realizarTransferencia(std::map<std::string, std::shared_ptr<Cliente>>& clientes);
};

#endif // CLIENTE_H

