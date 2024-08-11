# Definindo o compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Diretórios
SRCDIR = src
INCDIR = include
BINDIR = bin

# Detectando automaticamente todos os arquivos .cpp e .h
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.h)

# Arquivos objeto gerados
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Nome do executável
EXECUTABLE = $(BINDIR)/programa

# Regras
all: $(EXECUTABLE)

# Regra para criar o executável
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful!"

# Regra para compilar arquivos .cpp para .o
$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(BINDIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "Compiled $< into $@"

# Regra para criar o diretório bin
$(BINDIR):
	mkdir -p $(BINDIR)

# Limpar os arquivos objeto e o executável
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
