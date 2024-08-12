#ifndef GERENTE_H
#define GERENTE_H

#include <map>
#include <memory>
#include "Cliente.h"

class Gerente {
private:
    std::string senha;
    std::map<std::string, std::shared_ptr<Cliente>>& clientes;  // Clientes referenciados por CPF

public:
    Gerente(const std::string& senha, std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);
    void abrirContaCorrente(const std::string& cpf, double saldoInicial, double limiteChequeEspecial);
    void abrirContaPoupanca(const std::string& cpf, double saldoInicial, double taxaJuros);
    bool autenticarGerente(const std::string& senha) const;
    void operarComoGerente();
    void tornarContaInativa(int numeroConta);
    void excluirCliente(const std::string& cpf);
    void editarDadosCliente(const std::string& cpf);
    void carregarClientes(const std::string& arquivoClientes, const std::string& arquivoContas);
    void salvarClientes(const std::string& arquivoClientes, const std::string& arquivoContas);

};

#endif // GERENTE_H

