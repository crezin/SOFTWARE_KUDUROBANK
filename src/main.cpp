// main.cpp
#include <iostream>
#include <map>
#include <memory>
#include <fstream>
#include <locale>  // Biblioteca para setlocale
#include "Cliente.h"
#include "Gerente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Criptografia.h"

int main() {
    // Configura o locale para o ambiente local, suportando caracteres acentuados
    setlocale(LC_ALL, "");

    std::map<std::string, std::shared_ptr<Cliente>> clientes;  // Mapa para armazenar clientes usando CPF como chave
    Gerente gerente("admin", clientes);  // Instanciação do gerente com senha padrão "admin"

    // Carregar os dados de clientes e contas no início do programa
    gerente.carregarClientes("clientes.txt", "contas.txt");

    while (true) {  // Loop principal para interagir com o usuário
        std::cout << "=== Sistema Bancário ===\n";
        std::cout << "1. Login como Gerente\n";
        std::cout << "2. Login como Cliente\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        int opcao;
        std::cin >> opcao;

        if (opcao == 1) {  // Login como Gerente
            std::string senha;
            std::cout << "Digite a senha do gerente: ";
            senha = getsenha();  // Usando a função getsenha para ocultar a senha

            if (gerente.autenticarGerente(senha)) {  // Verifica a senha do gerente
                std::cout << "Login bem-sucedido!\n";
                gerente.operarComoGerente();  // Inicia as operações disponíveis para o gerente
            } else {
                std::cout << "Senha incorreta.\n";
            }
        } else if (opcao == 2) {  // Login como Cliente
            std::string cpf, senha;
            std::cout << "Digite seu CPF: ";
            std::cin >> cpf;
            std::cout << "Digite sua senha: ";
            senha = getsenha();  // Usando a função getsenha para ocultar a senha

            auto it = clientes.find(cpf);  // Busca o cliente pelo CPF
            if (it != clientes.end() && it->second->getSenha() == senha) {  // Verifica CPF e senha do cliente
                std::cout << "Login bem-sucedido!\n";
                it->second->selecionarContaEOperar(clientes);  // Cliente opera sua conta
            } else {
                std::cout << "CPF ou senha incorretos.\n";
            }
        } else if (opcao == 3) {  // Opção para sair do sistema
            std::cout << "Saindo...\n";
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }

    // Salvar os dados de clientes e contas antes de sair
    gerente.salvarClientes("clientes.txt", "contas.txt");

    return 0;
}
