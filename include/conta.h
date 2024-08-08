#ifndef CONTA_H
#define CONTA_H
using namespace std;
#include <vector>
#include "transacao.h"
#include <ctime>

class Conta {
protected:
    int numeroConta;
    double saldo;
    bool ativa;  // Adicionando um atributo para indicar se a conta está ativa
    std::vector<Transacao> transacoes;

public:
    Conta(int numeroConta, double saldoInicial);
    virtual ~Conta() = default;
    
    int getNumeroConta() const;
    virtual void depositar(double valor, time_t data);
    virtual bool sacar(double valor, time_t data);
    double getSaldo() const;
    bool isAtiva() const;  // Método para verificar se a conta está ativa
    void tornarInativa();  // Método para tornar a conta inativa
    void mostrarTransacoes() const;
    bool transferir(Conta* contaDestino, double valor, time_t data);	
};

#endif // CONTA_H
