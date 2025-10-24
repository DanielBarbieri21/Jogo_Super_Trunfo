#!/bin/bash

# 🇧🇷 Super Trunfo Brasil - Script de Instalação Automática
# Versão: 2.0 Moderna
# Autor: Sistema de Build Automatizado

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

# Função para imprimir mensagens coloridas
print_message() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}

# Função para verificar se comando existe
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Função para detectar sistema operacional
detect_os() {
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        if command_exists apt-get; then
            echo "ubuntu"
        elif command_exists yum; then
            echo "centos"
        elif command_exists pacman; then
            echo "arch"
        else
            echo "linux"
        fi
    elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]]; then
        echo "windows"
    else
        echo "unknown"
    fi
}

# Função para instalar dependências no Ubuntu/Debian
install_deps_ubuntu() {
    print_message $BLUE "🔧 Instalando dependências no Ubuntu/Debian..."
    
    sudo apt-get update
    sudo apt-get install -y \
        build-essential \
        pkg-config \
        libgtk-3-dev \
        libglib2.0-dev \
        libcairo2-dev \
        libpango1.0-dev \
        libatk1.0-dev \
        libgdk-pixbuf2.0-dev \
        libgtk-3-dev
    
    if [ $? -eq 0 ]; then
        print_message $GREEN "✅ Dependências instaladas com sucesso!"
    else
        print_message $RED "❌ Erro ao instalar dependências!"
        exit 1
    fi
}

# Função para instalar dependências no CentOS/RHEL
install_deps_centos() {
    print_message $BLUE "🔧 Instalando dependências no CentOS/RHEL..."
    
    sudo yum groupinstall -y "Development Tools"
    sudo yum install -y \
        pkgconfig \
        gtk3-devel \
        glib2-devel \
        cairo-devel \
        pango-devel \
        atk-devel \
        gdk-pixbuf2-devel
    
    if [ $? -eq 0 ]; then
        print_message $GREEN "✅ Dependências instaladas com sucesso!"
    else
        print_message $RED "❌ Erro ao instalar dependências!"
        exit 1
    fi
}

# Função para instalar dependências no Arch Linux
install_deps_arch() {
    print_message $BLUE "🔧 Instalando dependências no Arch Linux..."
    
    sudo pacman -S --noconfirm \
        base-devel \
        pkgconfig \
        gtk3 \
        glib2 \
        cairo \
        pango \
        atk \
        gdk-pixbuf2
    
    if [ $? -eq 0 ]; then
        print_message $GREEN "✅ Dependências instaladas com sucesso!"
    else
        print_message $RED "❌ Erro ao instalar dependências!"
        exit 1
    fi
}

# Função para instalar dependências no Windows (MSYS2)
install_deps_windows() {
    print_message $BLUE "🔧 Instalando dependências no Windows (MSYS2)..."
    
    pacman -S --noconfirm \
        mingw-w64-x86_64-gcc \
        mingw-w64-x86_64-gtk3 \
        mingw-w64-x86_64-pkg-config \
        mingw-w64-x86_64-glib2 \
        mingw-w64-x86_64-cairo \
        mingw-w64-x86_64-pango \
        mingw-w64-x86_64-atk \
        mingw-w64-x86_64-gdk-pixbuf2
    
    if [ $? -eq 0 ]; then
        print_message $GREEN "✅ Dependências instaladas com sucesso!"
    else
        print_message $RED "❌ Erro ao instalar dependências!"
        exit 1
    fi
}

# Função para verificar dependências
check_dependencies() {
    print_message $BLUE "🔍 Verificando dependências..."
    
    local missing_deps=()
    
    if ! command_exists gcc; then
        missing_deps+=("gcc")
    fi
    
    if ! command_exists pkg-config; then
        missing_deps+=("pkg-config")
    fi
    
    if ! pkg-config --exists gtk+-3.0; then
        missing_deps+=("gtk+-3.0")
    fi
    
    if [ ${#missing_deps[@]} -eq 0 ]; then
        print_message $GREEN "✅ Todas as dependências estão instaladas!"
        return 0
    else
        print_message $YELLOW "⚠️ Dependências faltando: ${missing_deps[*]}"
        return 1
    fi
}

# Função para compilar o projeto
compile_project() {
    print_message $BLUE "🔨 Compilando Super Trunfo Brasil..."
    
    if [ -f "Makefile" ]; then
        make clean
        make
        if [ $? -eq 0 ]; then
            print_message $GREEN "✅ Compilação concluída com sucesso!"
        else
            print_message $RED "❌ Erro na compilação!"
            exit 1
        fi
    else
        print_message $RED "❌ Makefile não encontrado!"
        exit 1
    fi
}

# Função para criar diretórios necessários
create_directories() {
    print_message $BLUE "📁 Criando diretórios necessários..."
    
    mkdir -p assets/bandeiras
    mkdir -p build
    mkdir -p docs
    
    print_message $GREEN "✅ Diretórios criados!"
}

# Função para instalar no sistema
install_system() {
    print_message $BLUE "📦 Instalando no sistema..."
    
    if [ -f "super_trunfo_moderno" ]; then
        sudo cp super_trunfo_moderno /usr/local/bin/
        sudo chmod +x /usr/local/bin/super_trunfo_moderno
        
        # Criar atalho no desktop (Linux)
        if [[ "$OSTYPE" == "linux-gnu"* ]]; then
            cat > ~/Desktop/SuperTrunfoBrasil.desktop << EOF
[Desktop Entry]
Version=1.0
Type=Application
Name=Super Trunfo Brasil
Comment=Jogo dos Estados Brasileiros
Exec=/usr/local/bin/super_trunfo_moderno
Icon=applications-games
Terminal=false
Categories=Game;Education;
EOF
            chmod +x ~/Desktop/SuperTrunfoBrasil.desktop
        fi
        
        print_message $GREEN "✅ Instalado com sucesso!"
        print_message $CYAN "🎮 Execute com: super_trunfo_moderno"
    else
        print_message $RED "❌ Executável não encontrado!"
        exit 1
    fi
}

# Função para mostrar informações do projeto
show_info() {
    print_message $WHITE "🇧🇷 Super Trunfo Brasil - Edição Moderna"
    echo ""
    print_message $CYAN "📋 Informações do Projeto:"
    echo "  Versão: 2.0 Moderna"
    echo "  Linguagem: C com GTK+3"
    echo "  Plataforma: Linux, Windows (MSYS2)"
    echo "  Estados: 27 (26 estados + DF)"
    echo ""
    print_message $CYAN "🎮 Funcionalidades:"
    echo "  • Interface moderna e responsiva"
    echo "  • Editor de cartas avançado"
    echo "  • Comparador interativo"
    echo "  • Dados reais do Brasil"
    echo "  • Sistema de salvamento"
    echo "  • Estatísticas em tempo real"
    echo ""
}

# Função principal
main() {
    print_message $WHITE "🇧🇷 Super Trunfo Brasil - Instalação Automática"
    print_message $YELLOW "================================================"
    echo ""
    
    # Mostrar informações
    show_info
    
    # Detectar sistema operacional
    local os=$(detect_os)
    print_message $BLUE "🖥️ Sistema detectado: $os"
    echo ""
    
    # Verificar dependências
    if ! check_dependencies; then
        print_message $YELLOW "📦 Instalando dependências..."
        
        case $os in
            "ubuntu")
                install_deps_ubuntu
                ;;
            "centos")
                install_deps_centos
                ;;
            "arch")
                install_deps_arch
                ;;
            "windows")
                install_deps_windows
                ;;
            *)
                print_message $RED "❌ Sistema operacional não suportado!"
                print_message $YELLOW "💡 Instale manualmente:"
                echo "  - GCC (compilador C)"
                echo "  - GTK+3 (biblioteca gráfica)"
                echo "  - pkg-config (gerenciador de dependências)"
                exit 1
                ;;
        esac
    fi
    
    # Criar diretórios
    create_directories
    
    # Compilar projeto
    compile_project
    
    # Perguntar se quer instalar no sistema
    echo ""
    read -p "📦 Deseja instalar no sistema? (y/n): " -n 1 -r
    echo ""
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        install_system
    else
        print_message $CYAN "🎮 Execute com: ./super_trunfo_moderno"
    fi
    
    echo ""
    print_message $GREEN "🎉 Instalação concluída com sucesso!"
    print_message $PURPLE "🎮 Divirta-se jogando Super Trunfo Brasil!"
    echo ""
}

# Verificar se está sendo executado como root
if [[ $EUID -eq 0 ]]; then
    print_message $RED "❌ Não execute este script como root!"
    print_message $YELLOW "💡 Execute como usuário normal, o script pedirá sudo quando necessário."
    exit 1
fi

# Executar função principal
main "$@"
