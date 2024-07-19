# Regra principal
app: main.o Cliente.o conta.o ContaCorrente.o ContaPoupanca.o transacao.o Gerente.o
	g++ main.o Cliente.o conta.o ContaCorrente.o ContaPoupanca.o transacao.o Gerente.o -o main

# Regras para compilar os arquivos objeto
main.o: main.cpp
	g++  main.cpp -c

Cliente.o: Cliente.cpp
	g++  Cliente.cpp -c

conta.o: conta.cpp
	g++  conta.cpp -c

ContaCorrente.o: ContaCorrente.cpp
	g++  ContaCorrente.cpp -c

ContaPoupanca.o: ContaPoupanca.cpp
	g++  ContaPoupanca.cpp -c

transacao.o: transacao.cpp
	g++  transacao.cpp -c

Gerente.o: Gerente.cpp
	g++  Gerente.cpp -c

# Limpeza
#clean:
#	rm -f *.o main