#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double limiteChequeEspecial;

public:
    ContaCorrente(int numeroConta, double saldoInicial, double limiteChequeEspecial);
    bool sacar(double valor, time_t data) override;  // Tipo de retorno compat�vel com a classe base	
	double getLimiteChequeEspecial() const;   
};

#endif // CONTACORRENTE_H



