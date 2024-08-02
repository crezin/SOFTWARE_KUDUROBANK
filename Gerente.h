#ifndef GERENTE_H
#define GERENTE_H

#include <map>
#include "Cliente.h"

using namespace std;

class Gerente : public Cliente {
private:
    private:
    std::map<std::string, Cliente>& clientes;
    int proximoNumeroConta;

public:
    Gerente(std::map<std::string, Cliente>& clientes);
    void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha) {
	void abrirContaCorrente(const std::string& numeroTelefone, double saldoInicial, double limiteChequeEspecial);
	void abrirContaPoupanca(const std::string& numeroTelefone, double saldoInicial, double taxaJuros);
	bool autenticarGerente(const std::string& senha);
	void operarComoGerente();
	void mostrarMenuGerente();
	
	
	}
};




#endif // GERENTE_H
