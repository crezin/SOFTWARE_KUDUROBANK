#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Conta.h" // Inclua o cabeçalho da classe Conta
#include "Gerente.h" // Inclua o cabeçalho da classe Gerente
using namespace std;

class Cliente {
private:
    string nome;    // Nome do cliente
    string cpf;     // CPF do cliente
    string endereco; // Endereço do cliente
    string numeroTelefone; // Número de telefone do cliente
    string senha;   // Senha do cliente
    Gerente* gerente;    // Ponteiro para o gerente associado ao cliente
    vector<Conta*> contas; // Contas associadas ao cliente

public:
    // Construtor
    Cliente();
    ~Cliente();

    // Métodos set
    void setNome(const string& nome);
    void setCpf(const string& cpf);
    void setEndereco(const string& endereco);
    void setNumeroTelefone(const string& numeroTelefone);
    void setSenha(const string& senha);

    // Métodos get
    string getNome() const;
    string getCpf() const;
    string getEndereco() const;
    string getNumeroTelefone() const;
    string getSenha() const;

    // Método para validar a senha
    bool validarSenha(const string& senhaTentativa) const;

    // Método para adicionar conta
    void adicionarConta(Conta* conta);
    vector<Conta*> getContas() const;

    // Métodos de interação
    void mostrarOpcaoUsuario();  // Exibe opções para o cliente
    void cadastrarGerente(const string& nome, const string& senha); // Cadastra um gerente
    void cadastrarCliente(const string& nome, const string& cpf, const string& endereco, const string& numeroTelefone, const string& senha); // Cadastra um cliente
};

#endif // CLIENTE_H
