#include "Gerente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

#include <iostream>

Gerente::Gerente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha, std::map<std::string, Cliente>& clientes)
    : Cliente(nome, cpf, endereco, numeroTelefone, senha), clientes(clientes) {}

void Gerente::cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha) {
    clientes[cpf] = Cliente(nome, cpf, endereco, numeroTelefone, senha);
}

std::string Gerente::getSenha() const {
    return this->senha;
}



void Gerente::abrirContaCorrente(const std::string& numeroTelefone, double saldoInicial, double limiteChequeEspecial) {
    auto it = clientes.find(numeroTelefone);
    if (it != clientes.end()) {
        Conta* novaConta = new ContaCorrente(it->second.getContas().size() + 1, saldoInicial, limiteChequeEspecial);
        it->second.adicionarConta(novaConta);
    } else {
        std::cout << "Cliente não encontrado.\n";
    }
}

void Gerente::abrirContaPoupanca(const std::string& numeroTelefone, double saldoInicial, double taxaJuros) {
    auto it = clientes.find(numeroTelefone);
    if (it != clientes.end()) {
        Conta* novaConta = new ContaPoupanca(it->second.getContas().size() + 1, saldoInicial, taxaJuros);
        it->second.adicionarConta(novaConta);
    } else {
        std::cout << "Cliente não encontrado.\n";
    }
}

bool Gerente::autenticarGerente(const std::string& senha) const {
    return this->getSenha() == senha;
}

void Gerente::operarComoGerente() {
    int opcao;
    do {
        std::cout << "1. Cadastrar Cliente\n";
        std::cout << "2. Abrir Conta Corrente\n";
        std::cout << "3. Abrir Conta Poupança\n";
        std::cout << "4. Tornar Conta Inativa\n";
        std::cout << "5. Excluir Cliente\n";
        std::cout << "6. Editar Dados do Cliente\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nome, cpf, endereco, numeroTelefone, senha;
                std::cout << "Digite o nome do cliente: ";
                std::cin >> nome;
                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;
                std::cout << "Digite o endereço do cliente: ";
                std::cin >> endereco;
                std::cout << "Digite o número de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite a senha do cliente: ";
                std::cin >> senha;
                cadastrarCliente(nome, cpf, endereco, numeroTelefone, senha);
                break;
            }
            case 2: {
                std::string numeroTelefone;
                double saldoInicial, limiteChequeEspecial;
                std::cout << "Digite o número de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> saldoInicial;
                std::cout << "Digite o limite de cheque especial: ";
                std::cin >> limiteChequeEspecial;
                abrirContaCorrente(numeroTelefone, saldoInicial, limiteChequeEspecial);
                break;
            }
            case 3: {
                std::string numeroTelefone;
                double saldoInicial, taxaJuros;
                std::cout << "Digite o número de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> saldoInicial;
                std::cout << "Digite a taxa de juros: ";
                std::cin >> taxaJuros;
                abrirContaPoupanca(numeroTelefone, saldoInicial, taxaJuros);
                break;
            }
            case 4: {
                int numeroConta;
                std::cout << "Digite o número da conta para tornar inativa: ";
                std::cin >> numeroConta;
                tornarContaInativa(numeroConta);
                break;
            }
            case 5: {
                std::string cpf;
                std::cout << "Digite o CPF do cliente a ser excluído: ";
                std::cin >> cpf;
                excluirCliente(cpf);
                break;
            }
            case 6: {
                std::string cpf;
                std::cout << "Digite o CPF do cliente para editar os dados: ";
                std::cin >> cpf;
                editarDadosCliente(cpf);
                break;
            }
            case 7:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 7);
}

void Gerente::tornarContaInativa(int numeroConta) {
    // Iterando sobre o map clientes sem usar structured bindings
    for (auto& cliente_pair : clientes) {
        const auto& cpf_local = cliente_pair.first; // Renomeando para evitar conflito com o membro cpf da classe Cliente
        Cliente& cliente_local = cliente_pair.second; // Renomeando para evitar conflito com o nome "cliente"

        // Aqui você pode realizar operações usando cpf_local e cliente_local
        // Por exemplo, marcar a conta como inativa
        for (Conta* conta : cliente_local.getContas()) {
            if (conta->getNumeroConta() == numeroConta) { // Usando -> para acessar métodos de Conta*
                conta->tornarInativa(); // Usando -> para acessar métodos de Conta*
                std::cout << "Conta " << numeroConta << " do cliente com CPF " << cpf_local << " foi marcada como inativa." << std::endl;
                return;
            }
        }
    }
    std::cout << "Conta " << numeroConta << " não encontrada." << std::endl;
}


void Gerente::excluirCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        if (it->second.getContas().empty()) {
            clientes.erase(it);
            std::cout << "Cliente com CPF " << cpf << " foi excluído.\n";
        } else {
            std::cout << "Cliente com CPF " << cpf << " possui contas ativas e não pode ser excluído.\n";
        }
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado.\n";
    }
}

void Gerente::editarDadosCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        Cliente& cliente = it->second;
        int opcao;
        std::cout << "1. Editar Nome\n";
        std::cout << "2. Editar Endereço\n";
        std::cout << "3. Editar Número de Telefone\n";
        std::cout << "4. Editar Senha\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        std::string novoValor;
        switch (opcao) {
            case 1:
                std::cout << "Digite o novo nome: ";
                std::cin.ignore();
                std::getline(std::cin, novoValor);
                cliente.setNome(novoValor);
                break;
            case 2:
                std::cout << "Digite o novo endereço: ";
                std::cin.ignore();
                std::getline(std::cin, novoValor);
                cliente.setEndereco(novoValor);
                break;
            case 3:
                std::cout << "Digite o novo número de telefone: ";
                std::cin >> novoValor;
                cliente.setNumeroTelefone(novoValor);
                break;
            case 4:
                std::cout << "Digite a nova senha: ";
                std::cin >> novoValor;
                cliente.setSenha(novoValor);
                break;
            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado.\n";
    }
}

