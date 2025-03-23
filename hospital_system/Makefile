# Diretórios
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
TEST_DIR = test

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -I$(INC_DIR) -std=c++17

# Arquivos fontes e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Nome do executável
EXEC = $(BIN_DIR)/hospital_system

# Nome do arquivo de testes
TEST_EXEC = $(BIN_DIR)/runner

# Regra padrão
all: $(EXEC)

# Regra para compilar o sistema
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✅ Compilação do sistema concluída!"

# Regra para compilar os arquivos .cpp em .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BIN_DIR)
	@echo "🗑️ Arquivos removidos!"

# Executa o sistema
run: $(EXEC)
	@echo "🚀 Executando o sistema..."
	./$(EXEC)

# Executa os testes
test: $(TEST_EXEC)
	@echo "🚀 Executando os testes..."
	./$(TEST_EXEC)

# Compila o código de testes
$(TEST_EXEC): $(wildcard $(TEST_DIR)/*.cpp) $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✅ Compilação dos testes concluída!"

# Força a recompilação do test, independentemente de alterações
force:
	@touch $(TEST_EXEC)

.PHONY: all clean run test force
