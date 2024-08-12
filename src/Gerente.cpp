#include "Gerente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include "Excessões.cpp"
#include <fstream>
#include <sstream>

Gerente::Gerente(const std::string& senha, std::map<std::string, std::shared_ptr<Cliente>>& clientes)
    : senha(senha), clientes(clientes) {}

void Gerente::cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha) {
    clientes[cpf] = std::make_shared<Cliente>(nome, cpf, endereco, numeroTelefone, senha);
}



void Gerente::abrirContaCorrente(const std::string& cpf, double saldoInicial, double limiteChequeEspecial) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        std::shared_ptr<Conta> novaConta = std::make_shared<ContaCorrente>(it->second->getContas().size() + 1, saldoInicial, limiteChequeEspecial);
        it->second->adicionarConta(novaConta);

        if (!novaConta->getTransacoes().empty()) {
            std::cout << "Conta Corrente criada com sucesso na data " << novaConta->getTransacoes().back().getDataString() << "!\n";
        } else {
            std::cout << "Conta Corrente criada, mas sem transações registradas.\n";
        }

        // Adicione uma mensagem de depuração aqui
        std::cout << "Finalizando abertura de conta corrente. Fluxo continua.\n";
    } else {
        std::cout << "Cliente não encontrado.\n";
    }
}




void Gerente::abrirContaPoupanca(const std::string& cpf, double saldoInicial, double taxaJuros) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        std::shared_ptr<Conta> novaConta = std::make_shared<ContaPoupanca>(it->second->getContas().size() + 1, saldoInicial, taxaJuros);
        it->second->adicionarConta(novaConta);

        if (!novaConta->getTransacoes().empty()) {
            std::cout << "Conta Poupança criada com sucesso na data " << novaConta->getTransacoes().back().getDataString() << "!\n";
        } else {
            std::cout << "Conta Poupança criada, mas sem transações registradas.\n";
        }

        // Adicione uma mensagem de depuração aqui
        std::cout << "Finalizando abertura de conta poupança. Fluxo continua.\n";
    } else {
        std::cout << "Cliente não encontrado.\n";
    }
}

bool Gerente::autenticarGerente(const std::string& senha) const {
    return this->senha == senha;
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

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Tente novamente.\n";
            continue;
        }

        try {
            switch (opcao) {
                case 1: {
                    std::string nome, cpf, endereco, numeroTelefone, senha;
                    std::cout << "Digite o nome do cliente: ";
                    std::cin.ignore();
                    std::getline(std::cin, nome);
                    std::cout << "Digite o CPF do cliente: ";
                    std::getline(std::cin, cpf);
                    std::cout << "Digite o endereço do cliente: ";
                    std::getline(std::cin, endereco);
                    std::cout << "Digite o número de telefone do cliente: ";
                    std::getline(std::cin, numeroTelefone);
                    std::cout << "Digite a senha do cliente: ";
                    std::getline(std::cin, senha);
                    cadastrarCliente(nome, cpf, endereco, numeroTelefone, senha);
                    break;
                }
                case 2: {
                    std::string cpf;
                    double saldoInicial, limiteChequeEspecial;
                    std::cout << "Digite o CPF do cliente: ";
                    std::cin >> cpf;
                    std::cout << "Digite o saldo inicial: ";
                    std::cin >> saldoInicial;
                    std::cout << "Digite o limite de cheque especial: ";
                    std::cin >> limiteChequeEspecial;
                    abrirContaCorrente(cpf, saldoInicial, limiteChequeEspecial);
                    break;
                }
                case 3: {
                    std::string cpf;
                    double saldoInicial, taxaJuros;
                    std::cout << "Digite o CPF do cliente: ";
                    std::cin >> cpf;
                    std::cout << "Digite o saldo inicial: ";
                    std::cin >> saldoInicial;
                    std::cout << "Digite a taxa de juros: ";
                    std::cin >> taxaJuros;
                    abrirContaPoupanca(cpf, saldoInicial, taxaJuros);
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
        } catch (const ValorInvalidoException& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const ContaInativaException& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const SaldoInsuficienteException& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro desconhecido: " << e.what() << std::endl;
        }
    } while (opcao != 7);
}
 
void Gerente::tornarContaInativa(int numeroConta) {
    for (auto& cliente_pair : clientes) {
        std::shared_ptr<Cliente> cliente_local = cliente_pair.second;
        for (auto& conta : cliente_local->getContas()) {
            if (conta->getNumeroConta() == numeroConta) {
                conta->tornarInativa();
                std::cout << "Conta " << numeroConta << " do cliente com CPF " << cliente_pair.first << " foi marcada como inativa em " << conta->getTransacoes().back().getDataString() << ".\n";
                return;
            }
        }
    }
    std::cout << "Conta " << numeroConta << " não encontrada.\n";
}

void Gerente::excluirCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);
    if (it != clientes.end()) {
        if (it->second->getContas().empty()) {
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
        std::shared_ptr<Cliente> cliente = it->second;
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
                cliente->setNome(novoValor);
                break;
            case 2:
                std::cout << "Digite o novo endereço: ";
                std::cin.ignore();
                std::getline(std::cin, novoValor);
                cliente->setEndereco(novoValor);
                break;
            case 3:
                std::cout << "Digite o novo número de telefone: ";
                std::cin >> novoValor;
                cliente->setNumeroTelefone(novoValor);
                break;
            case 4:
                std::cout << "Digite a nova senha: ";
                std::cin >> novoValor;
                cliente->setSenha(novoValor);
                break;
            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado.\n";
    }
}

void Gerente::carregarClientes(const std::string& arquivoClientes, const std::string& arquivoContas) {
    std::ifstream inClientes(arquivoClientes);
    std::ifstream inContas(arquivoContas);

    if (!inClientes.is_open()) {
        std::cerr << "Erro ao abrir " << arquivoClientes << " para carregar os dados." << std::endl;
        return;
    }

    if (!inContas.is_open()) {
        std::cerr << "Erro ao abrir " << arquivoContas << " para carregar os dados." << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(inClientes, linha)) {
        std::istringstream iss(linha);
        std::string cpf, nome, endereco, telefone, senha;
        iss >> cpf >> nome >> endereco >> telefone >> senha;

        auto cliente = std::make_shared<Cliente>(nome, cpf, endereco, telefone, senha);
        clientes[cpf] = cliente;

        std::cout << "Carregando cliente: " << cpf << " - " << nome << std::endl;
    }

    while (std::getline(inContas, linha)) {
        std::istringstream iss(linha);
        std::string cpf, tipoConta;
        int numeroConta;
        double saldo, limiteOuTaxa;

        iss >> cpf >> numeroConta >> saldo >> tipoConta >> limiteOuTaxa;

        auto it = clientes.find(cpf);
        if (it != clientes.end()) {
            std::shared_ptr<Conta> novaConta;
            if (tipoConta == "corrente") {
                novaConta = std::make_shared<ContaCorrente>(numeroConta, saldo, limiteOuTaxa);
                std::cout << "Carregando conta corrente: " << numeroConta 
                          << " com saldo: " << saldo 
                          << " e limite cheque especial: " << limiteOuTaxa << std::endl;
            } else if (tipoConta == "poupanca") {
                novaConta = std::make_shared<ContaPoupanca>(numeroConta, saldo, limiteOuTaxa);
                std::cout << "Carregando conta poupanca: " << numeroConta 
                          << " com saldo: " << saldo 
                          << " e taxa de juros: " << limiteOuTaxa << std::endl;
            }

            it->second->adicionarConta(novaConta);
        }
    }

    std::cout << "Dados carregados com sucesso!" << std::endl;
}

void Gerente::salvarClientes(const std::string& arquivoClientes, const std::string& arquivoContas) {
    std::cout << "Salvando dados nos arquivos " << arquivoClientes << " e " << arquivoContas << "..." << std::endl;

    std::ofstream outClientes(arquivoClientes);
    std::ofstream outContas(arquivoContas);

    if (!outClientes.is_open()) {
        std::cerr << "Erro ao abrir " << arquivoClientes << " para salvar os dados." << std::endl;
        return;
    }

    if (!outContas.is_open()) {
        std::cerr << "Erro ao abrir " << arquivoContas << " para salvar os dados." << std::endl;
        return;
    }

    for (const auto& pair : clientes) {
        std::shared_ptr<Cliente> cliente = pair.second;
        outClientes << cliente->getCpf() << " "
                    << cliente->getNome() << " "
                    << cliente->getEndereco() << " "
                    << cliente->getNumeroTelefone() << " "
                    << cliente->getSenha() << std::endl;

        std::cout << "Salvando cliente: " << cliente->getCpf() << " - " << cliente->getNome() << std::endl;

        for (const auto& conta : cliente->getContas()) {
            outContas << cliente->getCpf() << " "
                      << conta->getNumeroConta() << " "
                      << conta->getSaldo() << " "
                      << (dynamic_cast<ContaCorrente*>(conta.get()) ? "corrente" : "poupanca") << " ";

            if (auto* cc = dynamic_cast<ContaCorrente*>(conta.get())) {
                outContas << cc->getLimiteChequeEspecial() << std::endl;
                std::cout << "Salvando conta corrente: " << conta->getNumeroConta() 
                          << " com saldo: " << conta->getSaldo() 
                          << " e limite cheque especial: " << cc->getLimiteChequeEspecial() << std::endl;
            } else if (auto* cp = dynamic_cast<ContaPoupanca*>(conta.get())) {
                outContas << cp->getTaxaJuros() << std::endl;
                std::cout << "Salvando conta poupanca: " << conta->getNumeroConta() 
                          << " com saldo: " << conta->getSaldo() 
                          << " e taxa de juros: " << cp->getTaxaJuros() << std::endl;
            }
        }
    }

    std::cout << "Dados salvos com sucesso!" << std::endl;
}

	

