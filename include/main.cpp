#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <memory>
#include "transacao.h"
#include "conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Cliente.h"
#include "Gerente.h"

bool autenticarCliente(const std::map<std::string, Cliente>& clientes, const std::string& numeroTelefone, const std::string& senha);
bool autenticarGerente(const std::string& senha);
void operarComoGerente(Gerente& gerente);

int main() {
    std::map<std::string, Cliente> clientes;
    auto gerente = std::make_unique<Gerente>("Gerente", "000.000.000-00", "Endereco Gerente", "0000-0000", "senha_gerente", clientes);

    std::string tipoUsuario;
    std::cout << "Voce deseja fazer login como 'gerente' ou 'cliente'?: ";
    std::cin >> tipoUsuario;

    if (tipoUsuario == "gerente") {
        std::string senhaGerente;
        std::cout << "Digite a senha do gerente: ";
        std::cin >> senhaGerente;
        if (autenticarGerente(senhaGerente)) {
            operarComoGerente(*gerente);
        } else {
            std::cout << "Senha do gerente incorreta.\n";
        }
    } else if (tipoUsuario == "cliente") {
        std::string numeroTelefone, senha;
        std::cout << "Digite o numero de telefone: ";
        std::cin >> numeroTelefone;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        if (autenticarCliente(clientes, numeroTelefone, senha)) {
            clientes[numeroTelefone].selecionarContaEOperar();
        } else {
            std::cout << "Autenticacao falhou. Numero de telefone ou senha incorretos.\n";
        }
    } else {
        std::cout << "Tipo de usuario invalido.\n";
    }

    // Limpar memória alocada dinamicamente
    for (auto& [numero, cliente] : clientes) {
        for (auto* conta : cliente.contas) {
            delete conta;
        }
    }

    return 0;
}
