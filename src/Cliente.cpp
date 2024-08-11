#include "Cliente.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>

Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha)
    : nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha) {}

Cliente::~Cliente() {
    for (auto conta : contas) {
        delete conta; // Libera a memória das contas
    }
}

void Cliente::setNome(const std::string& nome) {
    this->nome = nome;
}

void Cliente::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

void Cliente::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

void Cliente::setNumeroTelefone(const std::string& numeroTelefone) {
    this->numeroTelefone = numeroTelefone;
}

void Cliente::setSenha(const std::string& senha) {
    this->senha = senha; // Armazena a senha diretamente
}

std::vector<Conta*>& Cliente::getContas() { // Corrigido para retornar um vetor de ponteiros
    return this->contas;
}


std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getCpf() const {
    return cpf;
}

std::string Cliente::getEndereco() const {
    return endereco;
}

std::string Cliente::getNumeroTelefone() const {
    return numeroTelefone;
}

std::string Cliente::getSenha() const {
    return senha;
}

void Cliente::adicionarConta(Conta* conta) {
    contas.push_back(conta);
}



void Cliente::selecionarContaEOperar() {
    std::cout << "Contas disponíveis:\n";
    for (size_t i = 0; i < contas.size(); ++i) {
        std::cout << i + 1 << ". Número da conta: " << contas[i]->getNumeroConta() << "\n";
    }
    int opcao;
    std::cout << "Escolha o número da conta para operar: ";
    std::cin >> opcao;

    if (opcao > 0 && static_cast<std::size_t>(opcao) <= contas.size()) {
        Conta* conta = contas[opcao - 1];
        operarConta(conta);
    } else {
        std::cout << "Opção inválida.\n";
    }
}

void Cliente::operarConta(Conta* conta) {
    int opcao;
    do {
        std::cout << "\nOperações disponíveis:\n";
        std::cout << "1. Depósito\n";
        std::cout << "2. Saque\n";
        std::cout << "3. Transferência\n";
        std::cout << "4. Verificar Saldo\n";
        std::cout << "5. Mostrar Transações\n";
        std::cout << "6. Extrato\n";
        std::cout << "7. Sair\n";
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
                int numeroContaDestino;
                double valor;
                std::string dataStr;
                std::cout << "Digite o número da conta de destino: ";
                std::cin >> numeroContaDestino;
                std::cout << "Digite o valor da transferência: ";
                std::cin >> valor;
                std::cout << "Digite a data (DD/MM/AAAA): ";
                std::cin >> dataStr;

                std::tm tm = {};
                std::istringstream ss(dataStr);
                ss >> std::get_time(&tm, "%d/%m/%Y");
                time_t data = std::mktime(&tm);

                Conta* contaDestino = nullptr;
                for (auto& cliente : clientes) {
                    for (auto& contaCli : cliente.second.getContas()) {
                        if (contaCli->getNumeroConta() == numeroContaDestino) {
                            contaDestino = contaCli;
                            break;
                        }
                    }
                    if (contaDestino) break;
                }

                if (contaDestino) {
                    conta->transferir(contaDestino, valor, data);
                } else {
                    std::cout << "Conta de destino não encontrada.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Saldo atual: R$ " << conta->getSaldo() << "\n";
                break;
            }
            case 5: {
                conta->mostrarTransacoes();
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

std::string format_time(time_t time);

void Cliente::extrato(time_t dataInicial) const {
    for (const auto& conta : contas) {
        std::cout << "Extrato da conta: " << conta->getNumeroConta() << std::endl;
        for (const auto& transacao : conta->getTransacoes()) {
            if (transacao.getData() >= dataInicial) {
                std::cout << "Tipo: " << transacao.getTipo()
                          << ", Valor: " << transacao.getValor()
                          << ", Data: " << format_time(transacao.getData()) << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

bool autenticarCliente(const std::map<std::string, Cliente>& clientes, const std::string& numeroTelefone, const std::string& senha) {
    auto it = clientes.find(numeroTelefone);
    if (it != clientes.end() && it->second.autenticarCliente(numeroTelefone, senha)) {
        return true;
    }
    return false;
}


