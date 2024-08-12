#ifndef GERENTE_H
#define GERENTE_H

#include <map>
#include <memory>
#include <string>
#include "Cliente.h"

/**
 * A classe Gerente representa um gerente de banco que pode gerenciar clientes e contas bancárias.
 */
class Gerente {
private:
    std::string senha;  ///< Senha do gerente para autenticação
    std::map<std::string, std::shared_ptr<Cliente>>& clientes;  ///< Mapa de clientes, referenciados por CPF

public:
    /**
     * Construtor da classe Gerente.
     * Inicializa um gerente com uma senha e uma referência ao mapa de clientes.
     *
     * @param senha A senha do gerente.
     * @param clientes Referência ao mapa de clientes gerenciados pelo gerente.
     */
    Gerente(const std::string& senha, std::map<std::string, std::shared_ptr<Cliente>>& clientes);

    /**
     * Cadastra um novo cliente no sistema.
     *
     * @param nome O nome do cliente.
     * @param cpf O CPF do cliente.
     * @param endereco O endereço do cliente.
     * @param numeroTelefone O número de telefone do cliente.
     * @param senha A senha do cliente.
     */
    void cadastrarCliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& numeroTelefone, const std::string& senha);

    /**
     * Abre uma nova conta corrente para um cliente existente.
     *
     * @param cpf O CPF do cliente que receberá a conta corrente.
     * @param saldoInicial O saldo inicial da conta corrente.
     * @param limiteChequeEspecial O limite de cheque especial da conta corrente.
     */
    void abrirContaCorrente(const std::string& cpf, double saldoInicial, double limiteChequeEspecial);

    /**
     * Abre uma nova conta poupança para um cliente existente.
     *
     * @param cpf O CPF do cliente que receberá a conta poupança.
     * @param saldoInicial O saldo inicial da conta poupança.
     * @param taxaJuros A taxa de juros da conta poupança.
     */
    void abrirContaPoupanca(const std::string& cpf, double saldoInicial, double taxaJuros);

    /**
     * Autentica o gerente com base na senha fornecida.
     *
     * @param senha A senha fornecida para autenticação.
     * @return True se a senha estiver correta, false caso contrário.
     */
    bool autenticarGerente(const std::string& senha) const;

    /**
     * Permite que o gerente realize várias operações como gerenciar clientes e contas.
     */
    void operarComoGerente();

    /**
     * Torna uma conta inativa, impedindo novas operações.
     *
     * @param numeroConta O número da conta a ser desativada.
     */
    void tornarContaInativa(int numeroConta);

    /**
     * Exclui um cliente do sistema, desde que ele não tenha contas ativas.
     *
     * @param cpf O CPF do cliente a ser excluído.
     */
    void excluirCliente(const std::string& cpf);

    /**
     * Permite ao gerente editar os dados de um cliente existente.
     *
     * @param cpf O CPF do cliente cujos dados serão editados.
     */
    void editarDadosCliente(const std::string& cpf);

    /**
     * Carrega os dados dos clientes e contas de arquivos.
     *
     * @param arquivoClientes O caminho do arquivo que contém os dados dos clientes.
     * @param arquivoContas O caminho do arquivo que contém os dados das contas.
     */
    void carregarClientes(const std::string& arquivoClientes, const std::string& arquivoContas);

    /**
     * Salva os dados dos clientes e contas em arquivos.
     *
     * @param arquivoClientes O caminho do arquivo onde os dados dos clientes serão salvos.
     * @param arquivoContas O caminho do arquivo onde os dados das contas serão salvos.
     */
    void salvarClientes(const std::string& arquivoClientes, const std::string& arquivoContas);
};

#endif // GERENTE_H

