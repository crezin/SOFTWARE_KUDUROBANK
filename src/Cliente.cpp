#include <iomanip>
#include <stdexcept>
#include "Excess�es.cpp"
#include <limits>  // Para std::numeric_limits
#include <map> 
#include "Cliente.h"
#include <iostream>
#include <sstream>
/**
 * Construtor da classe Cliente.
 * Inicializa um cliente com nome, CPF, endere�o, n�mero de telefone e senha.
 *
 * @param nome O nome do cliente.
 * @param cpf O CPF do cliente.
 * @param endereco O endere�o do cliente.
 * @param numeroTelefone O n�mero de telefone do cliente.
 * @param senha A senha do cliente.
 */
Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha)
    : nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha) {}

/**
 * Define o nome do cliente.
 *
 * @param nome O novo nome do cliente.
 */
void Cliente::setNome(const std::string& nome) {
    this->nome = nome;
}

/**
 * Define o CPF do cliente.
 *
 * @param cpf O novo CPF do cliente.
 */
void Cliente::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

/**
 * Define o endere�o do cliente.
 *
 * @param endereco O novo endere�o do cliente.
 */
void Cliente::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

/**
 * Define o n�mero de telefone do cliente.
 *
 * @param numeroTelefone O novo n�mero de telefone do cliente.
 */
void Cliente::setNumeroTelefone(const std::string& numeroTelefone) {
    this->numeroTelefone = numeroTelefone;
}

/**
 * Define a senha do cliente.
 *
 * @param senha A nova senha do cliente.
 */
void Cliente::setSenha(const std::string& senha) {
    this->senha = senha;
}

/**
 * Obt�m o nome do cliente.
 *
 * @return O nome do cliente.
 */
std::string Cliente::getNome() const {
    return nome;
}

/**
 * Obt�m o CPF do cliente.
 *
 * @return O CPF do cliente.
 */
std::string Cliente::getCpf() const {
    return cpf;
}

/**
 * Obt�m o endere�o do cliente.
 *
 * @return O endere�o do cliente.
 */
std::string Cliente::getEndereco() const {
    return endereco;
}

/**
 * Obt�m o n�mero de telefone do cliente.
 *
 * @return O n�mero de telefone do cliente.
 */
std::string Cliente::getNumeroTelefone() const {
    return numeroTelefone;
}

/**
 * Obt�m a senha do cliente.
 *
 * @return A senha do cliente.
 */
std::string Cliente::getSenha() const {
    return senha;
}

/**
 * Obt�m as contas do cliente.
 *
 * @return Um vetor de smart pointers para as contas do cliente.
 */
std::vector<std::shared_ptr<Conta>>& Cliente::getContas() {
    return this->contas;
}

/**
 * Adiciona uma nova conta ao cliente.
 *
 * @param conta A nova conta a ser adicionada ao cliente.
 */
void Cliente::adicionarConta(std::shared_ptr<Conta> conta) {
    contas.push_back(conta);
}

/**
 * Permite ao cliente operar em uma conta espec�fica, realizando opera��es como dep�sito, saque, transfer�ncia, etc.
 *
 * @param conta A conta em que o cliente deseja operar.
 * @param clientes Um map que cont�m todos os clientes, necess�rio para opera��es como transfer�ncia.
 */
void Cliente::operarConta(std::shared_ptr<Conta> conta, std::map<std::string, std::shared_ptr<Cliente>>& clientes) {
    int opcao;
    do {
        std::cout << "\nOpera��es dispon�veis:\n";
        std::cout << "1. Dep�sito\n";
        std::cout << "2. Saque\n";
        std::cout << "3. Transfer�ncia\n";
        std::cout << "4. Verificar Saldo\n";
        std::cout << "5. Mostrar Transa��es\n";
        std::cout << "6. Extrato\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma op��o: ";
        std::cin >> opcao;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Certifique-se de que <limits> est� inclu�do
            std::cout << "Entrada inv�lida. Tente novamente.\n";
            continue;
        }

        try {
            switch (opcao) {
                case 1: {
                    double valor;
                    std::string dataStr;
                    std::cout << "Digite o valor do dep�sito: ";
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
                    realizarTransferencia(clientes);
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
                case 7:
                    std::cout << "Saindo...\n";
                    break;
                default:
                    std::cout << "Op��o inv�lida. Tente novamente.\n";
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

/**
 * Permite ao cliente selecionar uma de suas contas para operar.
 *
 * @param clientes Um map que cont�m todos os clientes, necess�rio para opera��es como transfer�ncia.
 */
void Cliente::selecionarContaEOperar(std::map<std::string, std::shared_ptr<Cliente>>& clientes) {
    std::cout << "Contas dispon�veis:\n";
    for (size_t i = 0; i < contas.size(); ++i) {
        std::cout << i + 1 << ". N�mero da conta: " << contas[i]->getNumeroConta() << "\n";
    }
    int opcao;
    std::cout << "Escolha o n�mero da conta para operar: ";
    std::cin >> opcao;

    if (opcao > 0 && static_cast<std::size_t>(opcao) <= contas.size()) {
        std::shared_ptr<Conta> conta = contas[opcao - 1];
        operarConta(conta, clientes);  // Corrigido: passe ambos os argumentos
    } else {
        std::cout << "Op��o inv�lida.\n";
    }
}

/**
 * Exibe o extrato das transa��es realizadas nas contas do cliente a partir de uma data espec�fica.
 *
 * @param dataInicial A data inicial para filtrar as transa��es a serem exibidas no extrato.
 */
void Cliente::extrato(time_t dataInicial) const {
    for (const auto& conta : contas) {
        std::cout << "Extrato da conta: " << conta->getNumeroConta() << std::endl;
        for (const auto& transacao : conta->getTransacoes()) {
            if (transacao.getData() >= dataInicial) {
                std::cout << "Tipo: " << transacao.getTipo()
                          << ", Valor: " << transacao.getValor()
                          << ", Data: " << transacao.getDataString() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

/**
 * Realiza uma transfer�ncia de uma conta do cliente para uma conta de outro cliente.
 *
 * @param clientes Um map que cont�m todos os clientes, necess�rio para localizar o destinat�rio da transfer�ncia.
 */
void Cliente::realizarTransferencia(std::map<std::string, std::shared_ptr<Cliente>>& clientes) {
    std::string cpfDestino;
    int numeroContaDestino;
    double valor;
    std::string dataStr;

    std::cout << "Digite o CPF do benefici�rio: ";
    std::cin >> cpfDestino;

    auto it = clientes.find(cpfDestino);
    if (it == clientes.end()) {
        std::cout << "Benefici�rio n�o encontrado.\n";
        return;
    }

    std::cout << "Digite o n�mero da conta de destino: ";
    std::cin >> numeroContaDestino;

    std::shared_ptr<Conta> contaDestino = nullptr;
    for (const auto& conta : it->second->getContas()) {
        if (conta->getNumeroConta() == numeroContaDestino) {
            contaDestino = conta;
            break;
        }
    }

    if (!contaDestino) {
        std::cout << "Conta de destino n�o encontrada.\n";
        return;
    }

    std::cout << "Digite o valor da transfer�ncia: ";
    std::cin >> valor;

    if (valor <= 0) {
        std::cout << "Erro: O valor da transfer�ncia deve ser positivo.\n";
        return;
    }

    std::cout << "Digite a data (DD/MM/AAAA): ";
    std::cin >> dataStr;

    std::tm tm = {};
    std::istringstream ss(dataStr);
    ss >> std::get_time(&tm, "%d/%m/%Y");
    time_t data = std::mktime(&tm);
    
    std::cout << "Valor inserido para transfer�ncia: " << valor << std::endl;

    if (!contas.empty()) {
        std::shared_ptr<Conta> contaSelecionada = contas.front();  // Exemplo de sele��o de conta
        try {
            if (contaSelecionada->transferir(contaDestino, valor, data)) {
                std::cout << "Transfer�ncia realizada com sucesso!\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao realizar a transfer�ncia: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Nenhuma conta selecionada para realizar a transfer�ncia.\n";
    }
}



