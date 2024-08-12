#include <iostream>
#include <map>
#include <memory>
#include <fstream> 
#include "Cliente.h"
#include "Gerente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

int main() {
    std::map<std::string, std::shared_ptr<Cliente>> clientes;
    Gerente gerente("admin", clientes);

    // Carregar os dados no início
    gerente.carregarClientes("clientes.txt", "contas.txt");

    while (true) {  // Loop principal para interagir com o usuário
        std::cout << "=== Sistema Bancário ===\n";
        std::cout << "1. Login como Gerente\n";
        std::cout << "2. Login como Cliente\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        int opcao;
        std::cin >> opcao;

        if (opcao == 1) {
            std::string senha;
            std::cout << "Digite a senha do gerente: ";
            std::cin >> senha;

            if (gerente.autenticarGerente(senha)) {
                std::cout << "Login bem-sucedido!\n";
                gerente.operarComoGerente();
            } else {
                std::cout << "Senha incorreta.\n";
            }
        } else if (opcao == 2) {
            std::string cpf, senha;
            std::cout << "Digite seu CPF: ";
            std::cin >> cpf;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;

            auto it = clientes.find(cpf);
            if (it != clientes.end() && it->second->getSenha() == senha) {
                std::cout << "Login bem-sucedido!\n";
                it->second->selecionarContaEOperar(clientes);  // Passa o map de clientes
            } else {
                std::cout << "CPF ou senha incorretos.\n";
            }
        } else if (opcao == 3) {
            std::cout << "Saindo...\n";
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }

    // Salvar os dados antes de sair
    gerente.salvarClientes("clientes.txt", "contas.txt");

    return 0;
}



