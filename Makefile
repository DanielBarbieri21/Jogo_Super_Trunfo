# Makefile para Super Trunfo Brasil - Edição Moderna
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -g
GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`
LDFLAGS = $(GTK_FLAGS)

# Nome do executável
TARGET = super_trunfo_moderno
SOURCE = super_trunfo_moderno.c

# Diretórios
SRC_DIR = .
BUILD_DIR = build
ASSETS_DIR = assets
DOCS_DIR = docs

# Arquivos de origem
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Cores para output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[1;37m
NC = \033[0m # No Color

# Regra padrão
all: setup $(TARGET)

# Criar diretórios necessários
setup:
	@echo "$(BLUE)🔧 Configurando ambiente de build...$(NC)"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(ASSETS_DIR)
	@mkdir -p $(DOCS_DIR)
	@echo "$(GREEN)✅ Ambiente configurado!$(NC)"

# Compilar o executável principal
$(TARGET): $(OBJECTS)
	@echo "$(BLUE)🔨 Compilando Super Trunfo Moderno...$(NC)"
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "$(GREEN)✅ Compilação concluída!$(NC)"
	@echo "$(CYAN)🎮 Execute com: ./$(TARGET)$(NC)"

# Compilar arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)📦 Compilando $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar versões antigas (compatibilidade)
legacy: setup
	@echo "$(BLUE)🔨 Compilando versões legadas...$(NC)"
	$(CC) $(CFLAGS) super_trunfo_gui.c -o super_trunfo_gui $(LDFLAGS)
	$(CC) $(CFLAGS) Jogo_Super_Trunfo_Fases/aventureiro.c -o aventureiro $(LDFLAGS)
	$(CC) $(CFLAGS) Jogo_Super_Trunfo_Fases/mestre.c -o mestre $(LDFLAGS)
	$(CC) $(CFLAGS) Jogo_Super_Trunfo_Fases/novato.c -o novato $(LDFLAGS)
	@echo "$(GREEN)✅ Versões legadas compiladas!$(NC)"

# Instalar dependências (Ubuntu/Debian)
install-deps:
	@echo "$(BLUE)📦 Instalando dependências...$(NC)"
	@sudo apt-get update
	@sudo apt-get install -y build-essential pkg-config libgtk-3-dev
	@echo "$(GREEN)✅ Dependências instaladas!$(NC)"

# Instalar dependências (Windows/MSYS2)
install-deps-windows:
	@echo "$(BLUE)📦 Instalando dependências no Windows...$(NC)"
	@echo "Execute no MSYS2:"
	@echo "pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gtk3 mingw-w64-x86_64-pkg-config"

# Criar assets (bandeiras dos estados)
create-assets:
	@echo "$(BLUE)🎨 Criando assets...$(NC)"
	@mkdir -p $(ASSETS_DIR)/bandeiras
	@echo "$(GREEN)✅ Diretório de assets criado!$(NC)"
	@echo "$(YELLOW)💡 Adicione as imagens das bandeiras em $(ASSETS_DIR)/bandeiras/$(NC)"

# Executar o jogo
run: $(TARGET)
	@echo "$(PURPLE)🎮 Iniciando Super Trunfo Brasil...$(NC)"
	./$(TARGET)

# Executar com debug
debug: CFLAGS += -DDEBUG -g3
debug: $(TARGET)
	@echo "$(PURPLE)🐛 Iniciando em modo debug...$(NC)"
	gdb ./$(TARGET)

# Limpar arquivos de build
clean:
	@echo "$(BLUE)🧹 Limpando arquivos de build...$(NC)"
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)
	rm -f super_trunfo_gui
	rm -f aventureiro mestre novato
	rm -f *.exe
	@echo "$(GREEN)✅ Limpeza concluída!$(NC)"

# Limpar tudo (incluindo assets)
distclean: clean
	@echo "$(BLUE)🧹 Limpeza completa...$(NC)"
	rm -rf $(ASSETS_DIR)
	rm -rf $(DOCS_DIR)
	rm -f cartas_salvas.txt
	rm -f cartas.txt
	@echo "$(GREEN)✅ Limpeza completa concluída!$(NC)"

# Criar documentação
docs:
	@echo "$(BLUE)📚 Gerando documentação...$(NC)"
	@echo "# Super Trunfo Brasil - Documentação" > $(DOCS_DIR)/README.md
	@echo "" >> $(DOCS_DIR)/README.md
	@echo "## Compilação" >> $(DOCS_DIR)/README.md
	@echo "\`\`\`bash" >> $(DOCS_DIR)/README.md
	@echo "make" >> $(DOCS_DIR)/README.md
	@echo "\`\`\`" >> $(DOCS_DIR)/README.md
	@echo "" >> $(DOCS_DIR)/README.md
	@echo "## Execução" >> $(DOCS_DIR)/README.md
	@echo "\`\`\`bash" >> $(DOCS_DIR)/README.md
	@echo "make run" >> $(DOCS_DIR)/README.md
	@echo "\`\`\`" >> $(DOCS_DIR)/README.md
	@echo "$(GREEN)✅ Documentação criada em $(DOCS_DIR)/README.md$(NC)"

# Verificar dependências
check-deps:
	@echo "$(BLUE)🔍 Verificando dependências...$(NC)"
	@pkg-config --exists gtk+-3.0 && echo "$(GREEN)✅ GTK+3 encontrado$(NC)" || echo "$(RED)❌ GTK+3 não encontrado$(NC)"
	@which gcc > /dev/null && echo "$(GREEN)✅ GCC encontrado$(NC)" || echo "$(RED)❌ GCC não encontrado$(NC)"
	@which pkg-config > /dev/null && echo "$(GREEN)✅ pkg-config encontrado$(NC)" || echo "$(RED)❌ pkg-config não encontrado$(NC)"

# Testar compilação
test: clean all
	@echo "$(BLUE)🧪 Testando compilação...$(NC)"
	@test -f $(TARGET) && echo "$(GREEN)✅ Teste passou!$(NC)" || echo "$(RED)❌ Teste falhou!$(NC)"

# Criar pacote de distribuição
package: all
	@echo "$(BLUE)📦 Criando pacote de distribuição...$(NC)"
	@mkdir -p dist
	@cp $(TARGET) dist/
	@cp README.md dist/
	@cp -r $(ASSETS_DIR) dist/ 2>/dev/null || true
	@echo "$(GREEN)✅ Pacote criado em dist/$(NC)"

# Instalar no sistema
install: $(TARGET)
	@echo "$(BLUE)📦 Instalando Super Trunfo Brasil...$(NC)"
	@sudo cp $(TARGET) /usr/local/bin/
	@sudo chmod +x /usr/local/bin/$(TARGET)
	@echo "$(GREEN)✅ Instalado com sucesso!$(NC)"
	@echo "$(CYAN)🎮 Execute com: super_trunfo_moderno$(NC)"

# Desinstalar
uninstall:
	@echo "$(BLUE)🗑️ Desinstalando Super Trunfo Brasil...$(NC)"
	@sudo rm -f /usr/local/bin/$(TARGET)
	@echo "$(GREEN)✅ Desinstalado com sucesso!$(NC)"

# Mostrar ajuda
help:
	@echo "$(WHITE)🇧🇷 Super Trunfo Brasil - Makefile$(NC)"
	@echo ""
	@echo "$(CYAN)Comandos disponíveis:$(NC)"
	@echo "  $(YELLOW)make$(NC)           - Compilar o jogo"
	@echo "  $(YELLOW)make run$(NC)        - Executar o jogo"
	@echo "  $(YELLOW)make debug$(NC)      - Executar em modo debug"
	@echo "  $(YELLOW)make legacy$(NC)     - Compilar versões antigas"
	@echo "  $(YELLOW)make clean$(NC)       - Limpar arquivos de build"
	@echo "  $(YELLOW)make install$(NC)    - Instalar no sistema"
	@echo "  $(YELLOW)make uninstall$(NC)  - Desinstalar"
	@echo "  $(YELLOW)make package$(NC)    - Criar pacote de distribuição"
	@echo "  $(YELLOW)make docs$(NC)       - Gerar documentação"
	@echo "  $(YELLOW)make help$(NC)       - Mostrar esta ajuda"
	@echo ""
	@echo "$(CYAN)Dependências:$(NC)"
	@echo "  $(YELLOW)make install-deps$(NC)     - Instalar dependências (Linux)"
	@echo "  $(YELLOW)make install-deps-windows$(NC) - Instalar dependências (Windows)"
	@echo "  $(YELLOW)make check-deps$(NC)       - Verificar dependências"

# Regras que não são arquivos
.PHONY: all setup legacy install-deps install-deps-windows create-assets run debug clean distclean docs check-deps test package install uninstall help

# Mostrar informações do projeto
info:
	@echo "$(WHITE)🇧🇷 Super Trunfo Brasil - Edição Moderna$(NC)"
	@echo ""
	@echo "$(CYAN)📋 Informações do Projeto:$(NC)"
	@echo "  $(YELLOW)Versão:$(NC) 2.0 Moderna"
	@echo "  $(YELLOW)Linguagem:$(NC) C com GTK+3"
	@echo "  $(YELLOW)Plataforma:$(NC) Linux, Windows (MSYS2)"
	@echo "  $(YELLOW)Estados:$(NC) 27 (26 estados + DF)"
	@echo ""
	@echo "$(CYAN)🎮 Funcionalidades:$(NC)"
	@echo "  • Interface moderna e responsiva"
	@echo "  • Editor de cartas avançado"
	@echo "  • Comparador interativo"
	@echo "  • Dados reais do Brasil"
	@echo "  • Sistema de salvamento"
	@echo "  • Estatísticas em tempo real"
