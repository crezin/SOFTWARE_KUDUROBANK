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
    
void Gerente::tornarContaInativa(int numeroConta) {
    for (auto& [cpf, cliente] : clientes) {
        for (auto& conta : cliente.contas) {
            if (conta->getNumeroConta() == numeroConta) {
                conta->tornarInativa();
                std::cout << "Conta " << numeroConta << " foi tornada inativa.\n";
                return;
            }
        }
    }
    std::cout << "Conta " << numeroConta << " não encontrada.\n";
}

void Gerente::excluirCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        clientes.erase(it);
        std::cout << "Cliente com CPF " << cpf << " foi excluído.\n";
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado.\n";
    }
}

void Gerente::editarDadosCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        Cliente& cliente = it->second;
        int opcao;
        std::cout << "Editar:\n";
        std::cout << "1. Nome\n";
        std::cout << "2. Endereço\n";
        std::cout << "3. Número de Telefone\n";
        std::cout << "4. Senha\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        std::string novoValor;
        switch (opcao) {
            case 1: {
                std::cout << "Digite o novo nome: ";
                std::cin.ignore();
                std::getline(std::cin, novoValor);
                cliente.setNome(novoValor);
                break;
            }
            case 2: {
                std::cout << "Digite o novo endereço: ";
                std::cin.ignore();
                std::getline(std::cin, novoValor);
                cliente.setEndereco(novoValor);
                break;
            }
            case 3: {
                std::cout << "Digite o novo número de telefone: ";
                std::cin >> novoValor;
                cliente.setNumeroTelefone(novoValor);
                break;
            }
            case 4: {
                std::cout << "Digite a nova senha: ";
                std::cin >> novoValor;
                cliente.setSenha(novoValor);
                break;
            }
            default: {
                std::cout << "Opcao invalida.\n";
                break;
            }
        }
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado.\n";
    }
}

std::map<std::string, Cliente> clientes;
Gerente* gerente = nullptr;


void mostrarMenuGerente() {
    std::cout << "------------------------\n";
    std::cout << "1. Cadastrar Cliente\n";
    std::cout << "2. Abrir Conta Corrente\n";
    std::cout << "3. Abrir Conta Poupanca\n";
    std::cout << "4. Tornar Conta Inativa\n";
    std::cout << "5. Excluir Cliente\n";
    std::cout << "6. Editar Dados do Cliente\n";
    std::cout << "7. Sair\n";
    std::cout << "------------------------\n";
}

bool Gerente::autenticarGerente(const std::string& senha) {
    return this->getSenha() == senha;
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
                int numeroConta;	
                std::cout << "Digite o numero da conta para tornar inativa: ";
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
            case 7: {
                std::cout << "Saindo...\n";
                break;
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 7);
}


