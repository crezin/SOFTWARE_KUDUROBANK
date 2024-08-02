#include "Cliente.h"
#include <iostream>
#include <cstring>

using namespace std;

Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha)
        : nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha) {}

Cliente::~Cliente() {
    for (auto conta : contas) {
        delete conta; // Libera a memÃ³ria das contas
    }
}
    


// MÃ©todos set
void Cliente::setNome(const string& nome) {
    this->nome = nome;
}

void Cliente::setCpf(const string& cpf) {
    this->cpf = cpf;
}

void Cliente::setEndereco(const string& endereco) {
    this->endereco = endereco;
}

void Cliente::setNumeroTelefone(const string& numeroTelefone) {
    this->numeroTelefone = numeroTelefone;
}

void Cliente::setSenha(const string& senha) {
    this->senha = senha; // Armazena a senha diretamente
}

// MÃ©todos get
string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}

string Cliente::getEndereco() const {
    return endereco;
}

string Cliente::getNumeroTelefone() const {
    return numeroTelefone;
}

string Cliente::getSenha() const {
    return senha;
}

// MÃ©todo para validar a senha	
bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) {
    if (clientes.find(numeroTelefone) != clientes.end() && clientes[numeroTelefone].senha == senha) {
        return true;
    }
    return false;
}

// MÃ©todos adicionais
void adicionarConta(Conta* conta) {
        contas.push_back(conta);
    }

// MÃ©todo para cadastrar cliente
void Cliente::cadastrarCliente(const string& nome, const string& cpf, const string& endereco, const string& numeroTelefone, const string& senha) {
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->numeroTelefone = numeroTelefone;
    this->senha = senha; // Armazena a senha
}

void operarConta(Conta* conta) {
    int opcao;
    do {
        mostrarMenu();
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                double valor;
                std::string dataStr;
                std::cout << "Digite o valor do deposito: ";
                std::cin >> valor;
                std::cout << "Digite a data (DD/MM/AAAA): ";
                std::cin >> dataStr;

                std::tm tm = {};
                std::istringstream ss(dataStr);
                ss >> std::get_time(&tm, "%d/%m/%Y");
                time_t data = std::mktime(&tm);

                conta->depositar(valor, data);
                break;
            }
            case 2: {
                double valor;
                std::string dataStr;
                std::cout << "Digite o valor do saque: ";
                std::cin >> valor;
                std::cout << "Digite a data (DD/MM/AAAA): ";
                std::cin >> dataStr;

                std::tm tm = {};
                std::istringstream ss(dataStr);
                ss >> std::get_time(&tm, "%d/%m/%Y");
                time_t data = std::mktime(&tm);

                conta->sacar(valor, data);
                break;
            }
            case 3: {
                std::cout << "Saldo atual: R$ " << conta->getSaldo() << "\n";
                break;
            }
            case 4: {
                conta->mostrarTransacoes();
                break;
            }
            case 5: {
                ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(conta);
                if (cp) {
                    cp->aplicarJuros();
                } else {
                    std::cout << "Aplicar juros só está disponível para contas poupança.\n";
                }
                break;
            }
            case 6: {
                std::cout << "Saindo...\n";
                break;
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 6);
}

void selecionarContaEOperar(Cliente& cliente) {
    std::cout << "Contas disponiveis:\n";
    for (size_t i = 0; i < cliente.contas.size(); ++i) {
        std::cout << i + 1 << ". Numero da conta: " << cliente.contas[i]->getNumeroConta() << "\n";
    }
    int opcao;
    std::cout << "Escolha o numero da conta para operar: ";
    std::cin >> opcao;

    if (opcao > 0 && opcao <= cliente.contas.size()) {
        operarConta(cliente.contas[opcao - 1]);
    } else {
        std::cout << "Opcao invalida.\n";
    }
}

