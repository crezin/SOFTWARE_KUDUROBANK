CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDE = -Iinclude
SRC = src/main.cpp src/Transacao.cpp src/Conta.cpp src/ContaCorrente.cpp src/ContaPoupanca.cpp src/Cliente.cpp src/Gerente.cpp
OBJ = $(SRC:.cpp=.o)
BIN = bin/programa

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean