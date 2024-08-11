#ifndef GERENTE_H
#define GERENTE_H

#include <map>
#include "Cliente.h"

class Gerente : public Cliente {
private:
    std::map<std::string, Cliente>& clientes;

public:
    Gerente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha, std::map<std::string, Cliente>& clientes);
    void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
    void abrirContaCorrente(const std::string& numeroTelefone, double saldoInicial, double limiteChequeEspecial);
    void abrirContaPoupanca(const std::string& numeroTelefone, double saldoInicial, double taxaJuros);
    bool autenticarGerente(const std::string& senha) const;
    void operarComoGerente();
    void tornarContaInativa(int numeroConta);
    void excluirCliente(const std::string& cpf);
    void editarDadosCliente(const std::string& cpf);
    std::string getSenha() const;
    

};

#endif // GERENTE_H

