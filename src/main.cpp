#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <memory>
#include "Transacao.h"
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Cliente.h"
#include "Gerente.h"


bool autenticarCliente(const std::map<std::string, Cliente>& clientes, const std::string& numeroTelefone, const std::string& senha) {
    auto it = clientes.find(numeroTelefone);
    if (it != clientes.end() && it->second.autenticarCliente(numeroTelefone, senha)) {
        return true;
    }
    return false;
}

bool autenticarGerente(const std::string& senha, Gerente* gerente) {
    return gerente->autenticarGerente(senha);
}


void operarComoGerente(Gerente& gerente) {
    gerente.operarComoGerente();
}

    int main() {
    std::map<std::string, Cliente> clientes;
    Gerente* gerente = new Gerente("Gerente", "000.000.000-00", "Endereco Gerente", "0000-0000", "senha_gerente", clientes);

    std::string tipoUsuario;
    std::cout << "Você deseja fazer login como 'gerente' ou 'cliente'?: ";
    std::cin >> tipoUsuario;

    if (tipoUsuario == "gerente") {
        std::string senhaGerente;
        std::cout << "Digite a senha do gerente: ";
        std::cin >> senhaGerente;
        if (autenticarGerente(senhaGerente, gerente)) { // Passa o ponteiro gerente
            operarComoGerente(*gerente);
        } else {
            std::cout << "Senha do gerente incorreta.\n";
        }
    } else if (tipoUsuario == "cliente") {
        std::string numeroTelefone, senha;
        std::cout << "Digite o número de telefone: ";
        std::cin >> numeroTelefone;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        auto it = clientes.find(numeroTelefone);
        if (it != clientes.end() && autenticarCliente(clientes, numeroTelefone, senha)) {
            it->second.selecionarContaEOperar();
        } else {
            std::cout << "Autenticação falhou. Número de telefone ou senha incorretos.\n";
        }
    } else {
        std::cout << "Tipo de usuário inválido.\n";
    }

    delete gerente; // Libera a memória alocada para gerente
    return 0;
}


