#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <memory>
#include "Conta.h"
#include <limits>
#include <map>

/// Classe que representa um Cliente no sistema bancário.
class Cliente {
protected:
    // Atributos protegidos para serem acessados por subclasses ou membros da classe.
    std::string nome;                // Nome do cliente.
    std::string cpf;                 // CPF do cliente.
    std::string endereco;            // Endereço do cliente.
    std::string numeroTelefone;      // Número de telefone do cliente.
    std::string senha;               // Senha do cliente para autenticação.
    std::vector<std::shared_ptr<Conta>> contas;  // Vetor de smart pointers para as contas do cliente.

public:
    /// Construtor padrão.
    Cliente() : nome(""), cpf(""), endereco(""), numeroTelefone(""), senha("") {}

    /**
     * Construtor com parâmetros.
     * @param nome Nome do cliente.
     * @param cpf CPF do cliente.
     * @param endereco Endereço do cliente.
     * @param numeroTelefone Número de telefone do cliente.
     * @param senha Senha do cliente para autenticação.
     */
    Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);

    /// Destrutor virtual, permitindo a destruição correta de subclasses.
    virtual ~Cliente() = default;

    // Métodos setters
    void setNome(const std::string& nome);               // Define o nome do cliente.
    void setCpf(const std::string& cpf);                 // Define o CPF do cliente.
    void setEndereco(const std::string& endereco);       // Define o endereço do cliente.
    void setNumeroTelefone(const std::string& numeroTelefone);  // Define o número de telefone do cliente.
    void setSenha(const std::string& senha);             // Define a senha do cliente.

    // Métodos getters
    std::string getNome() const;                         // Retorna o nome do cliente.
    std::string getCpf() const;                          // Retorna o CPF do cliente.
    std::string getEndereco() const;                     // Retorna o endereço do cliente.
    std::string getNumeroTelefone() const;               // Retorna o número de telefone do cliente.
    std::string getSenha() const;                        // Retorna a senha do cliente.
    std::vector<std::shared_ptr<Conta>>& getContas();    // Retorna uma referência ao vetor de contas do cliente.

    /**
     * Permite que o cliente realize operações em uma conta específica.
     * @param conta A conta na qual o cliente deseja operar.
     * @param clientes Um map que contém todos os clientes, necessário para operações como transferência.
     */
    void operarConta(std::shared_ptr<Conta> conta, std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    /**
     * Adiciona uma nova conta ao cliente.
     * @param conta A nova conta a ser adicionada.
     */
    void adicionarConta(std::shared_ptr<Conta> conta);

    /**
     * Autentica o cliente com base no número de telefone e senha.
     * @param numeroTelefone O número de telefone do cliente.
     * @param senha A senha do cliente.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticarCliente(const std::string& numeroTelefone, const std::string& senha) const;

    /**
     * Permite ao cliente selecionar uma conta para operar.
     * @param clientes Um map que contém todos os clientes, necessário para operações como transferência.
     */
    void selecionarContaEOperar(std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    /**
     * Gera e exibe o extrato da conta a partir de uma data inicial.
     * @param dataInicial A data inicial para gerar o extrato.
     */
    void extrato(time_t dataInicial) const;

    /**
     * Realiza uma transferência para outra conta pertencente a outro cliente.
     * @param clientes Um map que contém todos os clientes, necessário para localizar o destinatário da transferência.
     */
    void realizarTransferencia(std::map<std::string, std::shared_ptr<Cliente>>& clientes);
};

#endif // CLIENTE_H

