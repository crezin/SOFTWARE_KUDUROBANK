#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Conta.h"
#include <map>
#include "Transacao.h"

class Cliente {
protected:
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string numeroTelefone;
    std::string senha;
    std::vector<Conta*> contas;
    std::map<std::string, Cliente> clientes;

public:
	Cliente()
        : nome(""), cpf(""), endereco(""), numeroTelefone(""), senha("") {}
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
    std::vector<Conta*>& getContas();
    

	void operarConta(Conta* conta);
    void adicionarConta(Conta* conta);
    bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const;
    void selecionarContaEOperar();
    void extrato(time_t dataInicial) const; // Função const para indicar que não altera o estado do objeto

    friend bool autenticarCliente(const std::map<std::string, Cliente>& clientes, const std::string& numeroTelefone, const std::string& senha);
};

#endif // CLIENTE_H

