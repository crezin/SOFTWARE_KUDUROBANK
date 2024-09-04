# Sistema Bancário

Este projeto é um sistema bancário desenvolvido em C++ que permite a gestão de clientes, contas e transações. O sistema possui funcionalidades para o gerente e os clientes, incluindo login, operações bancárias e registro de transações.

## Estrutura do Projeto

### Arquivos Principais

1. **`main.cpp`**
   - Ponto de entrada do sistema. 
   - Permite login como gerente ou cliente e apresenta um menu de opções.
   - Carrega e salva dados de clientes e contas a partir de arquivos de texto.

2. **`Conta.h` / `Conta.cpp`**
   - Define a classe `Conta`, que representa uma conta bancária.
   - Implementa funcionalidades como depósito, saque, transferência e consulta de saldo.
   - Mantém um histórico de transações.

3. **`Transacao.h` / `Transacao.cpp`**
   - Define a classe `Transacao`, que representa uma transação realizada em uma conta.
   - Contém informações sobre o tipo, valor e data da transação, além de métodos para obter esses dados.

4. **`Cliente.h` / `Cliente.cpp`**
   - Define a classe `Cliente`, que representa um cliente do banco.
   - Gerencia informações do cliente e permite que ele opere suas contas.
   - Implementa métodos para login e seleção de contas.

5. **`Gerente.h` / `Gerente.cpp`**
   - Define a classe `Gerente`, que representa o gerente do banco.
   - Permite a autenticação do gerente e a realização de operações administrativas, como gerenciar clientes e contas.

6. **`ContaCorrente.h` / `ContaCorrente.cpp`**
   - Define a classe `ContaCorrente`, que herda de `Conta`.
   - Implementa características específicas para contas correntes, como limites de saque.

7. **`ContaPoupanca.h` / `ContaPoupanca.cpp`**
   - Define a classe `ContaPoupanca`, que herda de `Conta`.
   - Implementa características específicas para contas de poupança, como rendimento de juros.

8. **`Criptografia.h` / `Criptografia.cpp`**
   - Implementa métodos para criptografar e descriptografar senhas de clientes e gerentes.

### Exceções Personalizadas

- **`Excecoes.cpp`**
   - Define exceções personalizadas para tratar erros específicos, como saldo insuficiente e contas inativas.

## Funcionamento

- **Login**: O sistema oferece opções de login para gerentes e clientes. Após autenticação, os usuários podem realizar operações bancárias.
- **Operações Bancárias**: Os clientes podem depositar, sacar e transferir fundos, além de visualizar seu histórico de transações.
- **Gerenciamento**: O gerente pode gerenciar clientes e contas, incluindo a capacidade de carregar e salvar dados.

## Compilação e Execução

Para compilar o projeto, use um compilador C++ compatível, como `g++`. Exemplo de comando:

```bash
g++ -o sistema_bancario main.cpp Conta.cpp Transacao.cpp Cliente.cpp Gerente.cpp ContaCorrente.cpp ContaPoupanca.cpp Criptografia.cpp
