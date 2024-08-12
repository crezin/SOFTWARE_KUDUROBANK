#include <iostream>
#include <map>
#include <memory>
#include <fstream> 
#include "Cliente.h"
#include "Gerente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

/**
 * @brief Função principal do sistema bancário.
 * 
 * Esta função inicializa o sistema bancário, permitindo que o usuário faça login como gerente ou cliente.
 * Os dados dos clientes e das contas são carregados a partir de arquivos de texto ao iniciar o programa,
 * e são salvos novamente ao fechar o programa.
 * 
 * @return int Retorna 0 se o programa for encerrado corretamente.
 */
int main() {
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
            std::cin >> senha;

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
            std::cin >> senha;

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



