#include "Gerente.h"

Gerente::Gerente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha, std::map<std::string, Cliente>& clientes)
        : Cliente(nome, cpf, endereco, numeroTelefone, senha), clientes(clientes), proximoNumeroConta(1) {}



void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha) {
        if (clientes.find(numeroTelefone) == clientes.end()) {
            clientes[numeroTelefone] = Cliente(nome, cpf, endereco, numeroTelefone, senha);
            std::cout << "Cliente cadastrado com sucesso!\n";
        } else {
            std::cout << "Cliente com este numero de telefone ja existe.\n";
        }
    }

void abrirContaCorrente(const std::string& numeroTelefone, double saldoInicial, double limiteChequeEspecial) {
        if (clientes.find(numeroTelefone) != clientes.end()) {
            Conta* novaConta = new ContaCorrente(proximoNumeroConta++, saldoInicial, limiteChequeEspecial);
            clientes[numeroTelefone].adicionarConta(novaConta);
            std::cout << "Conta corrente aberta com sucesso! Numero da conta: " << novaConta->getNumeroConta() << "\n";
        } else {
            std::cout << "Cliente nao encontrado.\n";
        }
    }

void abrirContaPoupanca(const std::string& numeroTelefone, double saldoInicial, double taxaJuros) {
        if (clientes.find(numeroTelefone) != clientes.end()) {
            Conta* novaConta = new ContaPoupanca(proximoNumeroConta++, saldoInicial, taxaJuros);
            clientes[numeroTelefone].adicionarConta(novaConta);
            std::cout << "Conta poupanca aberta com sucesso! Numero da conta: " << novaConta->getNumeroConta() << "\n";
        } else {
            std::cout << "Cliente nao encontrado.\n";
        }
    }
    
std::map<std::string, Cliente> clientes;
Gerente* gerente = nullptr;


void mostrarMenuGerente() {
    std::cout << "------------------------\n";
    std::cout << "1. Cadastrar Cliente\n";
    std::cout << "2. Abrir Conta Corrente\n";
    std::cout << "3. Abrir Conta Poupanca\n";
    std::cout << "4. Sair\n";
    std::cout << "------------------------\n";
}

bool autenticarGerente(const std::string& senha) {
    return senha == "senha_gerente";
}

void operarComoGerente() {
    int opcao;
    do {
        mostrarMenuGerente();
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nome, cpf, endereco, numeroTelefone, senha;
                std::cout << "Digite o nome do cliente: ";
                std::cin >> nome;
                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;
                std::cout << "Digite o endereco do cliente: ";
                std::cin >> endereco;
                std::cout << "Digite o numero de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite a senha do cliente: ";
                std::cin >> senha;
                gerente->cadastrarCliente(nome, cpf, endereco, numeroTelefone, senha);
                break;
            }
            case 2: {
                std::string numeroTelefone;
                double saldoInicial, limiteChequeEspecial;
                std::cout << "Digite o numero de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> saldoInicial;
                std::cout << "Digite o limite de cheque especial: ";
                std::cin >> limiteChequeEspecial;
                gerente->abrirContaCorrente(numeroTelefone, saldoInicial, limiteChequeEspecial);
                break;
            }
            case 3: {
                std::string numeroTelefone;
                double saldoInicial, taxaJuros;
                std::cout << "Digite o numero de telefone do cliente: ";
                std::cin >> numeroTelefone;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> saldoInicial;
                std::cout << "Digite a taxa de juros (em decimal, por exemplo 0.02 para 2%): ";
                std::cin >> taxaJuros;
                gerente->abrirContaPoupanca(numeroTelefone, saldoInicial, taxaJuros);
                break;
            }
            case 4: {
                std::cout << "Saindo...\n";
                break;
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 4);
}


