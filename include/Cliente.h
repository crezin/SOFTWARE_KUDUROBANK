#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <memory>
#include "Conta.h"
#include <limits>
#include <map>

/// Classe que representa um Cliente no sistema banc�rio.
class Cliente {
protected:
    // Atributos protegidos para serem acessados por subclasses ou membros da classe.
    std::string nome;                // Nome do cliente.
    std::string cpf;                 // CPF do cliente.
    std::string endereco;            // Endere�o do cliente.
    std::string numeroTelefone;      // N�mero de telefone do cliente.
    std::string senha;               // Senha do cliente para autentica��o.
    std::vector<std::shared_ptr<Conta>> contas;  // Vetor de smart pointers para as contas do cliente.

public:
    /// Construtor padr�o.
    Cliente() : nome(""), cpf(""), endereco(""), numeroTelefone(""), senha("") {}

    /**
     * Construtor com par�metros.
     * @param nome Nome do cliente.
     * @param cpf CPF do cliente.
     * @param endereco Endere�o do cliente.
     * @param numeroTelefone N�mero de telefone do cliente.
     * @param senha Senha do cliente para autentica��o.
     */
    Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);

    /// Destrutor virtual, permitindo a destrui��o correta de subclasses.
    virtual ~Cliente() = default;

    // M�todos setters
    void setNome(const std::string& nome);               // Define o nome do cliente.
    void setCpf(const std::string& cpf);                 // Define o CPF do cliente.
    void setEndereco(const std::string& endereco);       // Define o endere�o do cliente.
    void setNumeroTelefone(const std::string& numeroTelefone);  // Define o n�mero de telefone do cliente.
    void setSenha(const std::string& senha);             // Define a senha do cliente.

    // M�todos getters
    std::string getNome() const;                         // Retorna o nome do cliente.
    std::string getCpf() const;                          // Retorna o CPF do cliente.
    std::string getEndereco() const;                     // Retorna o endere�o do cliente.
    std::string getNumeroTelefone() const;               // Retorna o n�mero de telefone do cliente.
    std::string getSenha() const;                        // Retorna a senha do cliente.
    std::vector<std::shared_ptr<Conta>>& getContas();    // Retorna uma refer�ncia ao vetor de contas do cliente.

    /**
     * Permite que o cliente realize opera��es em uma conta espec�fica.
     * @param conta A conta na qual o cliente deseja operar.
     * @param clientes Um map que cont�m todos os clientes, necess�rio para opera��es como transfer�ncia.
     */
    void operarConta(std::shared_ptr<Conta> conta, std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    /**
     * Adiciona uma nova conta ao cliente.
     * @param conta A nova conta a ser adicionada.
     */
    void adicionarConta(std::shared_ptr<Conta> conta);

    /**
     * Autentica o cliente com base no n�mero de telefone e senha.
     * @param numeroTelefone O n�mero de telefone do cliente.
     * @param senha A senha do cliente.
     * @return true se a autentica��o for bem-sucedida, false caso contr�rio.
     */
    bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const;

    /**
     * Permite ao cliente selecionar uma conta para operar.
     * @param clientes Um map que cont�m todos os clientes, necess�rio para opera��es como transfer�ncia.
     */
    void selecionarContaEOperar(std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    /**
     * Gera e exibe o extrato da conta a partir de uma data inicial.
     * @param dataInicial A data inicial para gerar o extrato.
     */
    void extrato(time_t dataInicial) const;

    /**
     * Realiza uma transfer�ncia para outra conta pertencente a outro cliente.
     * @param clientes Um map que cont�m todos os clientes, necess�rio para localizar o destinat�rio da transfer�ncia.
     */
    void realizarTransferencia(std::map<std::string, std::shared_ptr<Cliente>>& clientes);
};

#endif // CLIENTE_H

