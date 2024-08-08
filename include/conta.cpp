#include "conta.h"

Conta::Conta(int numeroConta, double saldoInicial)
        : numeroConta(numeroConta), saldo(saldoInicial), ativa(true) {}
        
virtual ~Conta() = default;
        
int getNumeroConta() const {
        return numeroConta;
    }

void depositar(double valor, time_t data) {
		if (ativa) {
        saldo += valor;
        transacoes.push_back(Transacao("Deposito", valor, data));
        std::cout << "Deposito de R$ " << valor << " realizado com sucesso!\n";
    }   else {
        std::cout << "Conta inativa. Não é possível depositar." << std::endl;
    }
}

virtual bool sacar(double valor, time_t data) {
	if (ativa) {
        if (valor <= saldo) {
            saldo -= valor;
            transacoes.push_back(Transacao("Saque", valor, data));
            std::cout << "Saque de R$ " << valor << " realizado com sucesso!\n";
            return true;
        } else {
            std::cout << "Saldo insuficiente para saque.\n";
            return false;
        } else {
        std::cout << "Conta inativa. Não é possível sacar." << std::endl;
    }
    return false;
}

double Conta::getSaldo() const {
    return saldo;
}

bool Conta::isAtiva() const {
    return ativa;
}

void Conta::tornarInativa() {
    ativa = false;
}

bool Conta::transferir(Conta* contaDestino, double valor, time_t data) {
    if (ativa && contaDestino->isAtiva()) {
        if (saldo < valor) {
            return false; // Saldo insuficiente
        }

        saldo -= valor;
        contaDestino->saldo += valor;

        Transacao transacaoSaida("Transferência enviada", -valor, data);
        Transacao transacaoEntrada("Transferência recebida", valor, data);

        transacoes.push_back(transacaoSaida);
        contaDestino->transacoes.push_back(transacaoEntrada);

        return true;
    } else {
        std::cout << "Uma das contas está inativa. Não é possível realizar a transferência." << std::endl;
        return false;
    }
}

void mostrarTransacoes() const {
        for (const auto& transacao : transacoes) {
            std::cout << "Tipo: " << transacao.getTipo() << ", Valor: R$ " << transacao.getValor() << ", Data: " << std::put_time(std::localtime(&transacao.getData()), "%d/%m/%Y") << "\n";
        }
    }
