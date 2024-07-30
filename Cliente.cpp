#include "Cliente.h"
#include <iostream>
#include <conio.h> // Para _getch() em Windows

using namespace std;
// Construtor da classe Cliente
Cliente::Cliente()
        : nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha), gerente(nullptr) {}
//deletando as contas caso o programa acabe
Cliente::~Cliente() {
    for (auto conta : contas) {
        delete conta; // Libera a memória das contas
    }
    delete gerente; // Libera a memória do gerente
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
    this->senha = senha; // Armazena a senha diretamente
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

// Método para validar a senha
bool Cliente::validarSenha(const string& senhaTentativa) const {
    return senha == senhaTentativa; // Compara a senha armazenada com a senha tentada
}

// Método para adicionar conta
void Cliente::adicionarConta(Conta* conta) {
    contas.push_back(conta);
}

vector<Conta*> Cliente::getContas() const {
    return contas;
}

// Método para mostrar opções do gerente
void Cliente::mostrarOpcaoGerente() {
    int opcao1;
    cout << "  _   _   _   _   _   _   _   _   _   _  \n"
            " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n"
            "( k | u | d | u | r | o |   b | a | n | k )\n"
            " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << endl;
    cout << "BEM VINDO AO MÓDULO DO GERENTE!!!!\n";
    cout << "1. entra no modo cliente \n";
    cout << "2.sair sem apaga nada \n";
    cout << "66. Sair e apaga todas contas criadas no banco\n";
    cin >> opcao1;

    switch (opcao1) {

        case 1: {
            string nomeGerente, senhaGerente, senhaTentativa;
            cout << "NOME DO GERENTE: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, nomeGerente);
            cout << "SENHA: ";
            char ch;
            while ((ch = _getch()) != '\r') { // '\r' é o Enter
                senhaTentativa.push_back(ch);
                cout << "*"; // Exibe o caractere digitado
            }
            cout << endl;

            // Aqui você deve ter um objeto Gerente para validar a senha
            // Exemplo: se você tiver um gerente previamente cadastrado
            if (gerente != nullptr && gerente->validarSenha(senhaGerente)) {
                cout << "Login realizado com sucesso!" << endl;
            } else {
                cout << "Senha inválida!" << endl;
            }
            break;
        }
        case 2:
            cout << "Saindo." << endl;

            exit(0);
        case 66:
            ~Cliente();
            cout << "apagando todos os dados desse banco...";

        default:
            cout << "Opção inválida. Tente novamente." << endl;
    }
}

// Método para cadastrar cliente
void Cliente::cadastrarCliente(const string& nome, const string& cpf, const string& endereco, const string& numeroTelefone, const string& senha) {
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->numeroTelefone = numeroTelefone;
    this->senha = senha; // Armazena a senha
}

// Método para mostrar opções do cliente
void Cliente::mostrarOpcaoUsuario() {
    int opcao;
    cout << "  _   _   _   _   _   _   _   _   _   _  \n"
            " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n"
            "( k | u | d | u | r | o |   b | a | n | k )\n"
            " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << endl;
    cout << "BEM VINDO AO MÓDULO DO CLIENTE!!!!\n";
    cout << "1. Cadastrar\n";
    cout << "2. Fazer login\n";
    cout << "3. Retirar extrato bancário\n";
    cout << "4. Sair\n";
    cin >> opcao;

    switch (opcao) {
        case 1: {
            string senhaTentativa, nome, cpf, endereco, numeroTelefone, senha;
            cout << "Digite seu nome: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, nome);
            cout << "Digite seu CPF (11 caracteres): ";
            cin >> cpf;

            // Validação do CPF
            if (cpf.length() != 11) {
                cout << "CPF inválido. Deve ter 11 caracteres." << endl;
                return; // Retorna ao menu
            }

            cout << "Digite seu endereço: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, endereco);
            cout << "Digite seu número de telefone: ";
            cin >> numeroTelefone;
            cout << "Digite sua senha: ";
            char ch;
            while ((ch = _getch()) != '\r') { // '\r' é o Enter
                senhaTentativa.push_back(ch);
                cout << "*"; // Exibe o caractere digitado
            }
            cout << endl;


            // Método para cadastrar o cliente
            cadastrarCliente(nome, cpf, endereco, numeroTelefone, senha);
            cout << "Cadastro realizado com sucesso!" << endl;
            return mostrarOpcaoUsuario(); // Retorna ao menu
        }
        case 2: {
            string senhaTentativa;
            cout << "Digite sua senha: ";

            // Ocultar a entrada da senha*
            senhaTentativa.clear();
            char ch;
            while ((ch = _getch()) != '\r') { // '\r' é o Enter
                senhaTentativa.push_back(ch);
                cout << "*"; // Exibe o caractere digitado
            }
            cout << endl;

            if (validarSenha(senhaTentativa)) {
                cout << "Login realizado com sucesso!" << endl;
                // Aqui você pode adicionar a lógica para acessar a conta do cliente

            } else {
                cout << "Senha incorreta!" << endl;
            }
            return; // Retorna ao menu
        }
        case 3:
            cout << "Retirando extrato bancário..." << endl;
            // Aqui você pode implementar a lógica para mostrar o extrato
            break;
        case 4:
            cout << "Saindo." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
    }
}
void Cliente::cadastrarGerente(const string& nome, const string& senha) {
    if (gerente != nullptr) {
        delete gerente; // Libera a memória se já houver um gerente
    }
    gerente = new Gerente(nome, senha); // Cria um novo gerente
}
