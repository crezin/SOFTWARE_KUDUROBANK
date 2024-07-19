#include "Cliente.h"
#include <iostream>
#include <cstring>

using namespace std;

Cliente::Cliente(const std::string &nome, const std::string &cpf, const std::string &endereco,
                 const std::string &numeroTelefone, const std::string &senha): nome(nome), cpf(cpf), endereco(endereco), numeroTelefone(numeroTelefone), senha(senha), gerente(nullptr) {}

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
    return senha == senhaTentativa;
}

// Métodos adicionais
void Cliente::adicionarConta(Conta* conta) {
    contas.push_back(conta);
}

vector<Conta*> Cliente::getContas() const {
    return contas;
}

void Cliente::mostrarOpcaoGerente() {
    // Código anterior para gerenciar opções do gerente
}

void Cliente::cadastrarGerente(const string& nome, const string& senha) {
    if (gerente != nullptr) {
        delete gerente; // Libera a memória se já houver um gerente
    }
    gerente = new Gerente(nome, senha); // Cria um novo gerente
}

// Método para cadastrar cliente
void Cliente::cadastrarCliente(const string& nome, const string& cpf, const string& endereco, const string& numeroTelefone, const string& senha) {
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->numeroTelefone = numeroTelefone;
    this->senha = senha; // Armazena a senha
}

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
            string nome, cpf, endereco, numeroTelefone, senha;
            cout << "Digite seu nome: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, nome);
            cout << "Digite seu CPF: ";
            cin >> cpf;
            cout << "Digite seu endereço: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, endereco);
            cout << "Digite seu número de telefone: ";
            cin >> numeroTelefone;
            cout << "Digite sua senha: ";
            cin >> senha;

            // Método para cadastrar o cliente
            cadastrarCliente(nome, cpf, endereco, numeroTelefone, senha);
            cout << "Cadastro realizado com sucesso!" << endl;
            return(mostrarOpcaoUsuario());
        }
        case 2: {
            string senhaTentativa;
            cout << "Digite sua senha: ";
            cin >> senhaTentativa;

            if (validarSenha(senhaTentativa)) {
                cout << "Login realizado com sucesso!" << endl;
                // Aqui você pode adicionar a lógica para acessar a conta do cliente
            } else {
                cout << "Senha incorreta!" << endl;
            }
            break;
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
