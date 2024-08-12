# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Nome do executável
EXECUTABLE = $(BINDIR)/main.exe

# Regras
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist $(OBJDIR) del /Q $(OBJDIR)\*.o 2>nul
	if exist $(BINDIR) del /Q $(BINDIR)\main.exe 2>nul
