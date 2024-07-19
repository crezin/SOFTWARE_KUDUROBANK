#include <iostream>
#include "Cliente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

int main() {
    // Inicializando um cliente com informações fictícias
    Cliente cliente("João Silva", "123.456.789-00", "Rua A, 123", "(11) 98765-4321", "senha123");

    // Inicia o menu do gerente
    cliente.mostrarOpcaoGerente();
    // Inicia o menu do cliente
    cliente.mostrarOpcaoUsuario();

    return 0;
}
