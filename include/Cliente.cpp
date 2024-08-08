#include "Cliente.h"
#include "ContaPoupanca.h"
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha)
        : nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha) {}

Cliente::~Cliente() {
    for (auto conta : contas) {
        delete conta;
    }
}

// Métodos set
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
    this->senha = senha;
}

// Métodos get
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

bool Cliente::autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const {
    return this->numeroTelefone == numeroTelefone && this->senha == senha;
}

void Cliente::adicionarConta(Conta* conta) {
    contas.push_back(conta);
}

void Cliente::extrato(time_t dataInicial) const {
    for (const auto& conta : contas) {
        std::cout << "Extrato da conta: " << conta->getNumeroConta() << std::endl;
        for (const auto& transacao : conta->getTransacoes()) {
            if (transacao.getData() >= dataInicial) {
                std::cout << "Tipo: " << transacao.getTipo()
                          << ", Valor: " << transacao.getValor()
                          << ", Data: " << ctime(&transacao.getData());
            }
        }
        std::cout << std::endl;
    }
}

void Cliente::mostrarMenu() const {
    std::cout << "1. Depositar\n";
    std::cout << "2. Sacar\n";
    std::cout << "3. Verificar saldo\n";
    std::cout << "4. Mostrar transações\n";
    std::cout << "5. Aplicar juros (para contas poupança)\n";
    std::cout << "6. Ver extrato\n";
    std::cout << "7. Sair\n";
}

void Cliente::operarConta(Conta* conta) {
    int opcao;
    do {
        mostrarMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                double valor;
                std::string dataStr;
                std::cout << "Digite o valor do depósito: ";
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
                std::string dataStr;
                std::cout << "Digite a data inicial (DD/MM/AAAA): ";
                std::cin >> dataStr;

                std::tm tm = {};
                std::istringstream ss(dataStr);
                ss >> std::get_time(&tm, "%d/%m/%Y");
                time_t dataInicial = std::mktime(&tm);

                extrato(dataInicial);
                break;
            }
            case 7: {
                std::cout << "Saindo...\n";
                break;
            }
            default: {
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 7);
}

void Cliente::selecionarContaEOperar() {
    std::cout << "Contas disponíveis:\n";
    for (size_t i = 0; i < contas.size(); ++i) {
        std::cout << i + 1 << ". Número da conta: " << contas[i]->getNumeroConta() << "\n";
    }
    int opcao;
    std::cout << "Escolha o número da conta para operar: ";
    std::cin >> opcao;

    if (opcao > 0 && opcao <= contas.size()) {
        operarConta(contas[opcao - 1]);
    } else {
        std::cout << "Opção inválida.\n";
    }
}
