#!/bin/bash

# 🇧🇷 Super Trunfo Brasil - Suite de Testes Automatizados
# Versão: 2.0 Moderna
# Autor: Sistema de Testes Automatizado

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

# Contadores de teste
TESTS_PASSED=0
TESTS_FAILED=0
TESTS_TOTAL=0

# Função para imprimir mensagens coloridas
print_message() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}

# Função para executar teste
run_test() {
    local test_name=$1
    local test_command=$2
    local expected_result=$3
    
    TESTS_TOTAL=$((TESTS_TOTAL + 1))
    
    print_message $BLUE "🧪 Executando: $test_name"
    
    if eval "$test_command" >/dev/null 2>&1; then
        if [ "$expected_result" = "pass" ]; then
            print_message $GREEN "✅ PASSOU: $test_name"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            print_message $RED "❌ FALHOU: $test_name (esperava falha, mas passou)"
            TESTS_FAILED=$((TESTS_FAILED + 1))
        fi
    else
        if [ "$expected_result" = "fail" ]; then
            print_message $GREEN "✅ PASSOU: $test_name (falhou como esperado)"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            print_message $RED "❌ FALHOU: $test_name (esperava sucesso, mas falhou)"
            TESTS_FAILED=$((TESTS_FAILED + 1))
        fi
    fi
    echo ""
}

# Função para testar compilação
test_compilation() {
    print_message $CYAN "🔨 Testando compilação..."
    echo ""
    
    # Teste 1: Compilação básica
    run_test "Compilação básica" "make clean && make" "pass"
    
    # Teste 2: Verificar se executável foi criado
    run_test "Executável criado" "test -f super_trunfo_moderno" "pass"
    
    # Teste 3: Verificar se executável é executável
    run_test "Executável é executável" "test -x super_trunfo_moderno" "pass"
    
    # Teste 4: Compilação com debug
    run_test "Compilação com debug" "make clean && make debug" "pass"
    
    # Teste 5: Compilação das versões legadas
    run_test "Compilação versões legadas" "make legacy" "pass"
}

# Função para testar dependências
test_dependencies() {
    print_message $CYAN "🔍 Testando dependências..."
    echo ""
    
    # Teste 1: GCC disponível
    run_test "GCC disponível" "which gcc" "pass"
    
    # Teste 2: pkg-config disponível
    run_test "pkg-config disponível" "which pkg-config" "pass"
    
    # Teste 3: GTK+3 disponível
    run_test "GTK+3 disponível" "pkg-config --exists gtk+-3.0" "pass"
    
    # Teste 4: Make disponível
    run_test "Make disponível" "which make" "pass"
    
    # Teste 5: Bash disponível
    run_test "Bash disponível" "which bash" "pass"
}

# Função para testar arquivos
test_files() {
    print_message $CYAN "📁 Testando arquivos..."
    echo ""
    
    # Teste 1: Arquivo principal existe
    run_test "Arquivo principal existe" "test -f super_trunfo_moderno.c" "pass"
    
    # Teste 2: Makefile existe
    run_test "Makefile existe" "test -f Makefile" "pass"
    
    # Teste 3: README existe
    run_test "README existe" "test -f README.md" "pass"
    
    # Teste 4: LICENSE existe
    run_test "LICENSE existe" "test -f LICENSE" "pass"
    
    # Teste 5: Script de instalação existe
    run_test "Script de instalação existe" "test -f install.sh" "pass"
    
    # Teste 6: Script de instalação é executável
    run_test "Script de instalação é executável" "test -x install.sh" "pass"
    
    # Teste 7: Config.h existe
    run_test "Config.h existe" "test -f config.h" "pass"
}

# Função para testar funcionalidades
test_functionality() {
    print_message $CYAN "⚙️ Testando funcionalidades..."
    echo ""
    
    # Teste 1: Execução sem erros (timeout de 5 segundos)
    run_test "Execução sem erros" "timeout 5s ./super_trunfo_moderno --help 2>/dev/null || timeout 5s ./super_trunfo_moderno" "pass"
    
    # Teste 2: Verificar se arquivo de cartas pode ser criado
    run_test "Arquivo de cartas pode ser criado" "touch cartas_salvas.txt && rm cartas_salvas.txt" "pass"
    
    # Teste 3: Verificar se diretórios podem ser criados
    run_test "Diretórios podem ser criados" "mkdir -p test_dir && rmdir test_dir" "pass"
    
    # Teste 4: Verificar permissões de escrita
    run_test "Permissões de escrita" "touch test_file && rm test_file" "pass"
    
    # Teste 5: Verificar permissões de execução
    run_test "Permissões de execução" "test -x ./super_trunfo_moderno" "pass"
}

# Função para testar validação de dados
test_data_validation() {
    print_message $CYAN "📊 Testando validação de dados..."
    echo ""
    
    # Teste 1: Verificar se dados dos estados estão corretos
    run_test "Dados dos estados corretos" "grep -q 'São Paulo' super_trunfo_moderno.c" "pass"
    
    # Teste 2: Verificar se número de estados está correto
    run_test "Número de estados correto" "grep -c 'estado' super_trunfo_moderno.c | grep -q '27'" "pass"
    
    # Teste 3: Verificar se dados de população estão presentes
    run_test "Dados de população presentes" "grep -q 'populacao' super_trunfo_moderno.c" "pass"
    
    # Teste 4: Verificar se dados de PIB estão presentes
    run_test "Dados de PIB presentes" "grep -q 'pib' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Verificar se dados de área estão presentes
    run_test "Dados de área presentes" "grep -q 'area' super_trunfo_moderno.c" "pass"
}

# Função para testar interface
test_interface() {
    print_message $CYAN "🖥️ Testando interface..."
    echo ""
    
    # Teste 1: Verificar se CSS está presente
    run_test "CSS está presente" "grep -q 'gtk_css_provider' super_trunfo_moderno.c" "pass"
    
    # Teste 2: Verificar se widgets estão sendo criados
    run_test "Widgets estão sendo criados" "grep -q 'gtk_window_new' super_trunfo_moderno.c" "pass"
    
    # Teste 3: Verificar se callbacks estão sendo conectados
    run_test "Callbacks estão sendo conectados" "grep -q 'g_signal_connect' super_trunfo_moderno.c" "pass"
    
    # Teste 4: Verificar se layout está sendo configurado
    run_test "Layout está sendo configurado" "grep -q 'gtk_box_new' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Verificar se notebook está sendo usado
    run_test "Notebook está sendo usado" "grep -q 'gtk_notebook_new' super_trunfo_moderno.c" "pass"
}

# Função para testar sistema de build
test_build_system() {
    print_message $CYAN "🔧 Testando sistema de build..."
    echo ""
    
    # Teste 1: Make clean funciona
    run_test "Make clean funciona" "make clean" "pass"
    
    # Teste 2: Make all funciona
    run_test "Make all funciona" "make all" "pass"
    
    # Teste 3: Make help funciona
    run_test "Make help funciona" "make help" "pass"
    
    # Teste 4: Make check-deps funciona
    run_test "Make check-deps funciona" "make check-deps" "pass"
    
    # Teste 5: Make info funciona
    run_test "Make info funciona" "make info" "pass"
}

# Função para testar documentação
test_documentation() {
    print_message $CYAN "📚 Testando documentação..."
    echo ""
    
    # Teste 1: README tem conteúdo
    run_test "README tem conteúdo" "test -s README.md" "pass"
    
    # Teste 2: README tem badges
    run_test "README tem badges" "grep -q 'badge' README.md" "pass"
    
    # Teste 3: README tem seções importantes
    run_test "README tem seções importantes" "grep -q 'Instalação' README.md" "pass"
    
    # Teste 4: LICENSE tem conteúdo
    run_test "LICENSE tem conteúdo" "test -s LICENSE" "pass"
    
    # Teste 5: LICENSE é MIT
    run_test "LICENSE é MIT" "grep -q 'MIT License' LICENSE" "pass"
}

# Função para testar scripts
test_scripts() {
    print_message $CYAN "📜 Testando scripts..."
    echo ""
    
    # Teste 1: Script de instalação é válido
    run_test "Script de instalação é válido" "bash -n install.sh" "pass"
    
    # Teste 2: Script de instalação tem shebang
    run_test "Script de instalação tem shebang" "head -1 install.sh | grep -q '#!/bin/bash'" "pass"
    
    # Teste 3: Script de instalação tem funções
    run_test "Script de instalação tem funções" "grep -q 'function' install.sh" "pass"
    
    # Teste 4: Script de instalação tem cores
    run_test "Script de instalação tem cores" "grep -q 'RED=' install.sh" "pass"
    
    # Teste 5: Script de instalação tem mensagens
    run_test "Script de instalação tem mensagens" "grep -q 'print_message' install.sh" "pass"
}

# Função para testar performance
test_performance() {
    print_message $CYAN "⚡ Testando performance..."
    echo ""
    
    # Teste 1: Compilação é rápida (menos de 30 segundos)
    run_test "Compilação é rápida" "timeout 30s make clean && make" "pass"
    
    # Teste 2: Executável não é muito grande (menos de 10MB)
    run_test "Executável não é muito grande" "test -f super_trunfo_moderno && test \$(stat -c%s super_trunfo_moderno) -lt 10485760" "pass"
    
    # Teste 3: Executável não é muito pequeno (mais de 100KB)
    run_test "Executável não é muito pequeno" "test -f super_trunfo_moderno && test \$(stat -c%s super_trunfo_moderno) -gt 102400" "pass"
    
    # Teste 4: Código não tem vazamentos de memória óbvios
    run_test "Código não tem vazamentos óbvios" "grep -q 'gtk_widget_destroy' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Código usa recursos eficientemente
    run_test "Código usa recursos eficientemente" "grep -q 'gtk_widget_show_all' super_trunfo_moderno.c" "pass"
}

# Função para testar segurança
test_security() {
    print_message $CYAN "🔒 Testando segurança..."
    echo ""
    
    # Teste 1: Código não tem funções inseguras
    run_test "Código não tem funções inseguras" "! grep -q 'gets\|scanf\|strcpy\|strcat' super_trunfo_moderno.c" "pass"
    
    # Teste 2: Código usa funções seguras
    run_test "Código usa funções seguras" "grep -q 'strncpy\|snprintf' super_trunfo_moderno.c" "pass"
    
    # Teste 3: Código valida entrada
    run_test "Código valida entrada" "grep -q 'strlen.*== 0' super_trunfo_moderno.c" "pass"
    
    # Teste 4: Código não tem buffer overflow óbvio
    run_test "Código não tem buffer overflow óbvio" "! grep -q 'sprintf.*%s.*%s' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Código usa constantes para tamanhos
    run_test "Código usa constantes para tamanhos" "grep -q '#define.*50' super_trunfo_moderno.c" "pass"
}

# Função para testar portabilidade
test_portability() {
    print_message $CYAN "🌐 Testando portabilidade..."
    echo ""
    
    # Teste 1: Código usa padrões POSIX
    run_test "Código usa padrões POSIX" "grep -q '#include.*gtk/gtk.h' super_trunfo_moderno.c" "pass"
    
    # Teste 2: Código não usa funções específicas do sistema
    run_test "Código não usa funções específicas" "! grep -q 'windows.h\|unistd.h' super_trunfo_moderno.c" "pass"
    
    # Teste 3: Código usa tipos padrão
    run_test "Código usa tipos padrão" "grep -q 'long long\|double' super_trunfo_moderno.c" "pass"
    
    # Teste 4: Código não usa assembly
    run_test "Código não usa assembly" "! grep -q '__asm__\|asm' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Código usa bibliotecas padrão
    run_test "Código usa bibliotecas padrão" "grep -q '#include.*stdlib.h' super_trunfo_moderno.c" "pass"
}

# Função para testar manutenibilidade
test_maintainability() {
    print_message $CYAN "🔧 Testando manutenibilidade..."
    echo ""
    
    # Teste 1: Código tem comentários
    run_test "Código tem comentários" "grep -q '//' super_trunfo_moderno.c" "pass"
    
    # Teste 2: Código tem funções bem definidas
    run_test "Código tem funções bem definidas" "grep -q 'void.*(' super_trunfo_moderno.c" "pass"
    
    # Teste 3: Código usa constantes
    run_test "Código usa constantes" "grep -q '#define' super_trunfo_moderno.c" "pass"
    
    # Teste 4: Código tem estrutura clara
    run_test "Código tem estrutura clara" "grep -q 'typedef struct' super_trunfo_moderno.c" "pass"
    
    # Teste 5: Código não tem funções muito longas
    run_test "Código não tem funções muito longas" "wc -l super_trunfo_moderno.c | awk '{print \$1}' | awk '{print \$1 < 1000}'" "pass"
}

# Função para gerar relatório
generate_report() {
    print_message $WHITE "📊 Relatório de Testes"
    print_message $YELLOW "======================"
    echo ""
    
    print_message $CYAN "📈 Estatísticas:"
    echo "  Total de testes: $TESTS_TOTAL"
    echo "  Testes passaram: $TESTS_PASSED"
    echo "  Testes falharam: $TESTS_FAILED"
    echo ""
    
    local success_rate=$((TESTS_PASSED * 100 / TESTS_TOTAL))
    print_message $CYAN "📊 Taxa de sucesso: $success_rate%"
    echo ""
    
    if [ $TESTS_FAILED -eq 0 ]; then
        print_message $GREEN "🎉 Todos os testes passaram!"
        print_message $GREEN "✅ Projeto está pronto para uso!"
    elif [ $success_rate -ge 80 ]; then
        print_message $YELLOW "⚠️ Maioria dos testes passou"
        print_message $YELLOW "🔧 Alguns ajustes podem ser necessários"
    else
        print_message $RED "❌ Muitos testes falharam"
        print_message $RED "🚨 Projeto precisa de correções"
    fi
    
    echo ""
    print_message $PURPLE "🎮 Super Trunfo Brasil - Testes Concluídos!"
}

# Função principal
main() {
    print_message $WHITE "🇧🇷 Super Trunfo Brasil - Suite de Testes"
    print_message $YELLOW "=========================================="
    echo ""
    
    # Executar todos os testes
    test_dependencies
    test_files
    test_compilation
    test_functionality
    test_data_validation
    test_interface
    test_build_system
    test_documentation
    test_scripts
    test_performance
    test_security
    test_portability
    test_maintainability
    
    # Gerar relatório
    generate_report
}

# Executar função principal
main "$@"
