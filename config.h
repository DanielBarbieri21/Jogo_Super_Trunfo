#ifndef CONFIG_H
#define CONFIG_H

// 🇧🇷 Super Trunfo Brasil - Arquivo de Configuração
// Versão: 2.0 Moderna

// Informações do projeto
#define PROJECT_NAME "Super Trunfo Brasil"
#define PROJECT_VERSION "2.0 Moderna"
#define PROJECT_AUTHOR "Sistema de Build Automatizado"
#define PROJECT_LICENSE "MIT"

// Configurações do jogo
#define NUM_CARTAS 27                    // 26 estados + Distrito Federal
#define MAX_PLAYERS 4                    // Máximo de jogadores
#define MAX_ESTADO_NAME 50               // Tamanho máximo do nome do estado
#define MAX_CAPITAL_NAME 50              // Tamanho máximo do nome da capital
#define MAX_REGIAO_NAME 20               // Tamanho máximo do nome da região
#define MAX_BANDEIRA_PATH 100            // Tamanho máximo do caminho da bandeira

// Configurações da interface
#define WINDOW_WIDTH 1000                // Largura padrão da janela
#define WINDOW_HEIGHT 700                // Altura padrão da janela
#define MIN_WINDOW_WIDTH 800             // Largura mínima da janela
#define MIN_WINDOW_HEIGHT 600            // Altura mínima da janela

// Configurações de arquivo
#define CARDS_FILE "cartas_salvas.txt"   // Arquivo de salvamento
#define CONFIG_FILE "config.ini"         // Arquivo de configuração
#define LOG_FILE "super_trunfo.log"      // Arquivo de log

// Configurações de validação
#define MIN_POPULACAO 1                  // População mínima
#define MAX_POPULACAO 999999999          // População máxima
#define MIN_PIB 0.1                      // PIB mínimo
#define MAX_PIB 99999.9                  // PIB máximo
#define MIN_AREA 1.0                     // Área mínima
#define MAX_AREA 9999999.9               // Área máxima
#define MIN_PONTOS 0                     // Pontos turísticos mínimos
#define MAX_PONTOS 999                   // Pontos turísticos máximos

// Configurações de tema
#define THEME_DEFAULT "modern"           // Tema padrão
#define THEME_DARK "dark"                // Tema escuro
#define THEME_LIGHT "light"              // Tema claro
#define THEME_BRASIL "brasil"            // Tema Brasil

// Configurações de animação
#define ANIMATION_DURATION 300           // Duração das animações (ms)
#define HOVER_EFFECT true                // Efeito hover nos botões
#define SMOOTH_SCROLLING true            // Rolagem suave

// Configurações de debug
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
    #define DEBUG_LOG(fmt, ...) fprintf(stderr, "[LOG] " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
    #define DEBUG_LOG(fmt, ...)
#endif

// Configurações de performance
#define CACHE_SIZE 100                   // Tamanho do cache
#define MAX_HISTORY 50                   // Máximo de histórico
#define AUTO_SAVE_INTERVAL 300          // Intervalo de auto-save (segundos)

// Configurações de rede (futuro)
#define DEFAULT_PORT 8080                // Porta padrão para multiplayer
#define MAX_CONNECTIONS 4                // Máximo de conexões
#define TIMEOUT_SECONDS 30               // Timeout de conexão

// Configurações de acessibilidade
#define HIGH_CONTRAST false              // Alto contraste
#define LARGE_FONTS false                // Fontes grandes
#define SCREEN_READER false              // Suporte a leitor de tela

// Configurações de localização
#define DEFAULT_LANGUAGE "pt_BR"         // Idioma padrão
#define SUPPORTED_LANGUAGES 3            // Número de idiomas suportados
#define LANGUAGE_NAMES {"pt_BR", "en_US", "es_ES"}

// Configurações de estatísticas
#define STATS_UPDATE_INTERVAL 1000      // Intervalo de atualização das estatísticas (ms)
#define MAX_STATS_HISTORY 100            // Máximo de histórico de estatísticas

// Configurações de som (futuro)
#define SOUND_ENABLED false              // Som habilitado
#define MUSIC_ENABLED false              // Música habilitada
#define VOLUME_DEFAULT 50                // Volume padrão (0-100)

// Configurações de backup
#define AUTO_BACKUP true                 // Backup automático
#define BACKUP_INTERVAL 3600             // Intervalo de backup (segundos)
#define MAX_BACKUPS 5                    // Máximo de backups

// Configurações de atualização
#define CHECK_UPDATES true               // Verificar atualizações
#define UPDATE_URL "https://github.com/supertrunfobrasil/updates"  // URL de atualizações

// Configurações de privacidade
#define COLLECT_STATS false              // Coletar estatísticas de uso
#define SEND_CRASH_REPORTS false        // Enviar relatórios de crash

// Configurações de desenvolvimento
#define DEVELOPER_MODE false             // Modo desenvolvedor
#define PROFILING_ENABLED false         // Profiling habilitado
#define MEMORY_DEBUG false              // Debug de memória

// Configurações de build
#define BUILD_DATE __DATE__              // Data de build
#define BUILD_TIME __TIME__              // Hora de build
#define BUILD_TYPE "Release"             // Tipo de build

// Configurações de versão
#define VERSION_MAJOR 2                  // Versão principal
#define VERSION_MINOR 0                 // Versão secundária
#define VERSION_PATCH 0                 // Versão de patch
#define VERSION_BUILD 1                 // Número de build

// Macros úteis
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(x, min, max) (MIN(MAX(x, min), max))

// Configurações de string
#define STRING_BUFFER_SIZE 1024         // Tamanho do buffer de string
#define MAX_ERROR_MESSAGE 256           // Tamanho máximo da mensagem de erro

// Configurações de arquivo
#define MAX_FILE_SIZE 10485760          // Tamanho máximo de arquivo (10MB)
#define MAX_LINE_LENGTH 1024            // Tamanho máximo de linha

// Configurações de validação de entrada
#define VALIDATE_INPUT true             // Validar entrada do usuário
#define SANITIZE_INPUT true             // Sanitizar entrada do usuário

// Configurações de segurança
#define MAX_LOGIN_ATTEMPTS 3            // Máximo de tentativas de login
#define SESSION_TIMEOUT 3600            // Timeout de sessão (segundos)

// Configurações de cache
#define CACHE_ENABLED true               // Cache habilitado
#define CACHE_TTL 3600                   // Time to live do cache (segundos)

// Configurações de logging
#define LOG_LEVEL 2                     // Nível de log (0=ERROR, 1=WARN, 2=INFO, 3=DEBUG)
#define LOG_TO_FILE true                // Log para arquivo
#define LOG_TO_CONSOLE true             // Log para console

// Configurações de interface
#define SHOW_TOOLTIPS true              // Mostrar tooltips
#define SHOW_STATUS_BAR true             // Mostrar barra de status
#define SHOW_MENU_BAR true              // Mostrar barra de menu

// Configurações de tema visual
#define USE_GRADIENTS true              // Usar gradientes
#define USE_SHADOWS true                // Usar sombras
#define USE_ANIMATIONS true              // Usar animações

// Configurações de acessibilidade
#define SUPPORT_KEYBOARD_NAVIGATION true // Suporte à navegação por teclado
#define SUPPORT_SCREEN_READER true       // Suporte a leitor de tela
#define SUPPORT_HIGH_CONTRAST true       // Suporte a alto contraste

// Configurações de internacionalização
#define SUPPORT_RTL false               // Suporte a RTL (Right-to-Left)
#define SUPPORT_UNICODE true            // Suporte a Unicode

// Configurações de performance
#define USE_THREADING true              // Usar threading
#define MAX_THREADS 4                  // Máximo de threads
#define THREAD_POOL_SIZE 2             // Tamanho do pool de threads

// Configurações de memória
#define USE_MEMORY_POOL true            // Usar pool de memória
#define MEMORY_POOL_SIZE 1048576        // Tamanho do pool de memória (1MB)

// Configurações de rede
#define USE_NETWORKING false            // Usar networking
#define DEFAULT_TIMEOUT 5000            // Timeout padrão (ms)

// Configurações de banco de dados
#define USE_DATABASE false              // Usar banco de dados
#define DATABASE_TYPE "SQLite"          // Tipo de banco de dados

// Configurações de API
#define USE_API false                   // Usar API
#define API_VERSION "v1"                // Versão da API
#define API_BASE_URL "https://api.supertrunfobrasil.com"

// Configurações de analytics
#define USE_ANALYTICS false             // Usar analytics
#define ANALYTICS_ID "UA-XXXXXXXXX-X"   // ID do analytics

// Configurações de crash reporting
#define USE_CRASH_REPORTING false       // Usar crash reporting
#define CRASH_REPORTING_URL "https://crash.supertrunfobrasil.com"

// Configurações de telemetria
#define USE_TELEMETRY false             // Usar telemetria
#define TELEMETRY_ENDPOINT "https://telemetry.supertrunfobrasil.com"

// Configurações de backup
#define USE_CLOUD_BACKUP false           // Usar backup na nuvem
#define CLOUD_BACKUP_PROVIDER "AWS"     // Provedor de backup na nuvem

// Configurações de sincronização
#define USE_SYNC false                  // Usar sincronização
#define SYNC_INTERVAL 300               // Intervalo de sincronização (segundos)

// Configurações de notificações
#define USE_NOTIFICATIONS false         // Usar notificações
#define NOTIFICATION_DURATION 5000      // Duração da notificação (ms)

// Configurações de atualização automática
#define USE_AUTO_UPDATE false           // Usar atualização automática
#define UPDATE_CHECK_INTERVAL 86400     // Intervalo de verificação de atualizações (segundos)

// Configurações de licença
#define REQUIRE_LICENSE false           // Requerer licença
#define LICENSE_SERVER "https://license.supertrunfobrasil.com"

// Configurações de DRM
#define USE_DRM false                   // Usar DRM
#define DRM_PROVIDER "Custom"           // Provedor de DRM

// Configurações de criptografia
#define USE_ENCRYPTION false            // Usar criptografia
#define ENCRYPTION_ALGORITHM "AES-256"  // Algoritmo de criptografia

// Configurações de assinatura digital
#define USE_DIGITAL_SIGNATURE false     // Usar assinatura digital
#define SIGNATURE_ALGORITHM "RSA-2048"   // Algoritmo de assinatura

// Configurações de auditoria
#define USE_AUDIT_LOG false             // Usar log de auditoria
#define AUDIT_LOG_FILE "audit.log"      // Arquivo de log de auditoria

// Configurações de compliance
#define COMPLIANCE_MODE false           // Modo de compliance
#define COMPLIANCE_STANDARD "GDPR"      // Padrão de compliance

// Configurações de privacidade
#define PRIVACY_MODE true               // Modo de privacidade
#define COLLECT_USER_DATA false         // Coletar dados do usuário

// Configurações de acessibilidade
#define ACCESSIBILITY_MODE false        // Modo de acessibilidade
#define SCREEN_READER_SUPPORT false     // Suporte a leitor de tela

// Configurações de localização
#define LOCALIZATION_MODE false         // Modo de localização
#define SUPPORTED_LOCALES 3             // Número de locales suportados

// Configurações de teste
#define TEST_MODE false                 // Modo de teste
#define MOCK_DATA false                 // Usar dados mock

// Configurações de desenvolvimento
#define DEV_MODE false                  // Modo de desenvolvimento
#define DEBUG_MODE false                // Modo de debug

// Configurações de produção
#define PRODUCTION_MODE true            // Modo de produção
#define OPTIMIZE_FOR_SIZE true          // Otimizar para tamanho

// Configurações de distribuição
#define DISTRIBUTION_MODE "standalone"  // Modo de distribuição
#define PACKAGE_FORMAT "tar.gz"         // Formato do pacote

// Configurações de instalação
#define INSTALL_MODE "user"             // Modo de instalação
#define INSTALL_PREFIX "/usr/local"     // Prefixo de instalação

// Configurações de sistema
#define SYSTEM_MODE "user"              // Modo do sistema
#define SYSTEM_USER "supertrunfo"       // Usuário do sistema

// Configurações de serviço
#define SERVICE_MODE false              // Modo de serviço
#define SERVICE_NAME "supertrunfo"      // Nome do serviço

// Configurações de daemon
#define DAEMON_MODE false               // Modo de daemon
#define DAEMON_PID_FILE "/var/run/supertrunfo.pid"  // Arquivo PID do daemon

// Configurações de log
#define LOG_MODE "file"                 // Modo de log
#define LOG_FILE_PATH "/var/log/supertrunfo.log"    // Caminho do arquivo de log

// Configurações de configuração
#define CONFIG_MODE "file"              // Modo de configuração
#define CONFIG_FILE_PATH "/etc/supertrunfo.conf"    // Caminho do arquivo de configuração

// Configurações de cache
#define CACHE_MODE "memory"             // Modo de cache
#define CACHE_DIRECTORY "/tmp/supertrunfo"          // Diretório de cache

// Configurações de temporário
#define TEMP_MODE "system"              // Modo de temporário
#define TEMP_DIRECTORY "/tmp"           // Diretório temporário

// Configurações de dados
#define DATA_MODE "local"               // Modo de dados
#define DATA_DIRECTORY "./data"         // Diretório de dados

// Configurações de assets
#define ASSETS_MODE "local"             // Modo de assets
#define ASSETS_DIRECTORY "./assets"     // Diretório de assets

// Configurações de recursos
#define RESOURCES_MODE "embedded"       // Modo de recursos
#define RESOURCES_DIRECTORY "./resources"  // Diretório de recursos

// Configurações de plugins
#define PLUGINS_MODE false              // Modo de plugins
#define PLUGINS_DIRECTORY "./plugins"   // Diretório de plugins

// Configurações de extensões
#define EXTENSIONS_MODE false           // Modo de extensões
#define EXTENSIONS_DIRECTORY "./extensions"  // Diretório de extensões

// Configurações de módulos
#define MODULES_MODE false              // Modo de módulos
#define MODULES_DIRECTORY "./modules"    // Diretório de módulos

// Configurações de bibliotecas
#define LIBRARIES_MODE "system"         // Modo de bibliotecas
#define LIBRARIES_DIRECTORY "/usr/lib"  // Diretório de bibliotecas

// Configurações de cabeçalhos
#define HEADERS_MODE "system"           // Modo de cabeçalhos
#define HEADERS_DIRECTORY "/usr/include"  // Diretório de cabeçalhos

// Configurações de binários
#define BINARIES_MODE "system"          // Modo de binários
#define BINARIES_DIRECTORY "/usr/bin"   // Diretório de binários

// Configurações de manuais
#define MANUALS_MODE "system"           // Modo de manuais
#define MANUALS_DIRECTORY "/usr/share/man"  // Diretório de manuais

// Configurações de documentação
#define DOCS_MODE "local"               // Modo de documentação
#define DOCS_DIRECTORY "./docs"         // Diretório de documentação

// Configurações de exemplos
#define EXAMPLES_MODE "local"           // Modo de exemplos
#define EXAMPLES_DIRECTORY "./examples"  // Diretório de exemplos

// Configurações de testes
#define TESTS_MODE "local"              // Modo de testes
#define TESTS_DIRECTORY "./tests"       // Diretório de testes

// Configurações de benchmarks
#define BENCHMARKS_MODE "local"         // Modo de benchmarks
#define BENCHMARKS_DIRECTORY "./benchmarks"  // Diretório de benchmarks

// Configurações de perfis
#define PROFILES_MODE "local"           // Modo de perfis
#define PROFILES_DIRECTORY "./profiles"  // Diretório de perfis

// Configurações de templates
#define TEMPLATES_MODE "local"          // Modo de templates
#define TEMPLATES_DIRECTORY "./templates"  // Diretório de templates

// Configurações de schemas
#define SCHEMAS_MODE "local"            // Modo de schemas
#define SCHEMAS_DIRECTORY "./schemas"   // Diretório de schemas

// Configurações de validação
#define VALIDATION_MODE "strict"        // Modo de validação
#define VALIDATION_LEVEL 3              // Nível de validação

// Configurações de sanitização
#define SANITIZATION_MODE "strict"      // Modo de sanitização
#define SANITIZATION_LEVEL 3            // Nível de sanitização

// Configurações de segurança
#define SECURITY_MODE "strict"          // Modo de segurança
#define SECURITY_LEVEL 3                // Nível de segurança

// Configurações de privacidade
#define PRIVACY_MODE "strict"           // Modo de privacidade
#define PRIVACY_LEVEL 3                 // Nível de privacidade

// Configurações de acessibilidade
#define ACCESSIBILITY_MODE "strict"     // Modo de acessibilidade
#define ACCESSIBILITY_LEVEL 3           // Nível de acessibilidade

// Configurações de usabilidade
#define USABILITY_MODE "strict"         // Modo de usabilidade
#define USABILITY_LEVEL 3               // Nível de usabilidade

// Configurações de performance
#define PERFORMANCE_MODE "optimized"    // Modo de performance
#define PERFORMANCE_LEVEL 3             // Nível de performance

// Configurações de qualidade
#define QUALITY_MODE "high"             // Modo de qualidade
#define QUALITY_LEVEL 3                 // Nível de qualidade

// Configurações de confiabilidade
#define RELIABILITY_MODE "high"         // Modo de confiabilidade
#define RELIABILITY_LEVEL 3             // Nível de confiabilidade

// Configurações de disponibilidade
#define AVAILABILITY_MODE "high"        // Modo de disponibilidade
#define AVAILABILITY_LEVEL 3            // Nível de disponibilidade

// Configurações de escalabilidade
#define SCALABILITY_MODE "high"         // Modo de escalabilidade
#define SCALABILITY_LEVEL 3             // Nível de escalabilidade

// Configurações de manutenibilidade
#define MAINTAINABILITY_MODE "high"     // Modo de manutenibilidade
#define MAINTAINABILITY_LEVEL 3         // Nível de manutenibilidade

// Configurações de portabilidade
#define PORTABILITY_MODE "high"         // Modo de portabilidade
#define PORTABILITY_LEVEL 3             // Nível de portabilidade

// Configurações de compatibilidade
#define COMPATIBILITY_MODE "high"       // Modo de compatibilidade
#define COMPATIBILITY_LEVEL 3           // Nível de compatibilidade

// Configurações de interoperabilidade
#define INTEROPERABILITY_MODE "high"    // Modo de interoperabilidade
#define INTEROPERABILITY_LEVEL 3        // Nível de interoperabilidade

// Configurações de integração
#define INTEGRATION_MODE "high"         // Modo de integração
#define INTEGRATION_LEVEL 3             // Nível de integração

// Configurações de extensibilidade
#define EXTENSIBILITY_MODE "high"       // Modo de extensibilidade
#define EXTENSIBILITY_LEVEL 3           // Nível de extensibilidade

// Configurações de flexibilidade
#define FLEXIBILITY_MODE "high"         // Modo de flexibilidade
#define FLEXIBILITY_LEVEL 3             // Nível de flexibilidade

// Configurações de adaptabilidade
#define ADAPTABILITY_MODE "high"        // Modo de adaptabilidade
#define ADAPTABILITY_LEVEL 3            // Nível de adaptabilidade

// Configurações de customização
#define CUSTOMIZATION_MODE "high"       // Modo de customização
#define CUSTOMIZATION_LEVEL 3           // Nível de customização

// Configurações de personalização
#define PERSONALIZATION_MODE "high"     // Modo de personalização
#define PERSONALIZATION_LEVEL 3         // Nível de personalização

// Configurações de configuração
#define CONFIGURATION_MODE "high"       // Modo de configuração
#define CONFIGURATION_LEVEL 3           // Nível de configuração

// Configurações de parametrização
#define PARAMETERIZATION_MODE "high"    // Modo de parametrização
#define PARAMETERIZATION_LEVEL 3        // Nível de parametrização

// Configurações de ajuste
#define TUNING_MODE "high"              // Modo de ajuste
#define TUNING_LEVEL 3                  // Nível de ajuste

// Configurações de otimização
#define OPTIMIZATION_MODE "high"        // Modo de otimização
#define OPTIMIZATION_LEVEL 3            // Nível de otimização

// Configurações de melhoria
#define IMPROVEMENT_MODE "high"         // Modo de melhoria
#define IMPROVEMENT_LEVEL 3             // Nível de melhoria

// Configurações de evolução
#define EVOLUTION_MODE "high"          // Modo de evolução
#define EVOLUTION_LEVEL 3              // Nível de evolução

// Configurações de desenvolvimento
#define DEVELOPMENT_MODE "high"        // Modo de desenvolvimento
#define DEVELOPMENT_LEVEL 3            // Nível de desenvolvimento

// Configurações de crescimento
#define GROWTH_MODE "high"             // Modo de crescimento
#define GROWTH_LEVEL 3                 // Nível de crescimento

// Configurações de expansão
#define EXPANSION_MODE "high"          // Modo de expansão
#define EXPANSION_LEVEL 3              // Nível de expansão

// Configurações de ampliação
#define AMPLIFICATION_MODE "high"      // Modo de ampliação
#define AMPLIFICATION_LEVEL 3          // Nível de ampliação

// Configurações de aumento
#define INCREASE_MODE "high"           // Modo de aumento
#define INCREASE_LEVEL 3               // Nível de aumento

// Configurações de incremento
#define INCREMENT_MODE "high"          // Modo de incremento
#define INCREMENT_LEVEL 3              // Nível de incremento

// Configurações de progresso
#define PROGRESS_MODE "high"           // Modo de progresso
#define PROGRESS_LEVEL 3               // Nível de progresso

// Configurações de avanço
#define ADVANCE_MODE "high"            // Modo de avanço
#define ADVANCE_LEVEL 3                // Nível de avanço

// Configurações de progressão
#define PROGRESSION_MODE "high"        // Modo de progressão
#define PROGRESSION_LEVEL 3            // Nível de progressão

// Configurações de evolução
#define EVOLUTION_MODE "high"          // Modo de evolução
#define EVOLUTION_LEVEL 3              // Nível de evolução

// Configurações de desenvolvimento
#define DEVELOPMENT_MODE "high"        // Modo de desenvolvimento
#define DEVELOPMENT_LEVEL 3            // Nível de desenvolvimento

// Configurações de crescimento
#define GROWTH_MODE "high"             // Modo de crescimento
#define GROWTH_LEVEL 3                 // Nível de crescimento

// Configurações de expansão
#define EXPANSION_MODE "high"          // Modo de expansão
#define EXPANSION_LEVEL 3              // Nível de expansão

// Configurações de ampliação
#define AMPLIFICATION_MODE "high"      // Modo de ampliação
#define AMPLIFICATION_LEVEL 3          // Nível de ampliação

// Configurações de aumento
#define INCREASE_MODE "high"           // Modo de aumento
#define INCREASE_LEVEL 3               // Nível de aumento

// Configurações de incremento
#define INCREMENT_MODE "high"          // Modo de incremento
#define INCREMENT_LEVEL 3              // Nível de incremento

// Configurações de progresso
#define PROGRESS_MODE "high"           // Modo de progresso
#define PROGRESS_LEVEL 3               // Nível de progresso

// Configurações de avanço
#define ADVANCE_MODE "high"            // Modo de avanço
#define ADVANCE_LEVEL 3                // Nível de avanço

// Configurações de progressão
#define PROGRESSION_MODE "high"        // Modo de progressão
#define PROGRESSION_LEVEL 3            // Nível de progressão

#endif // CONFIG_H
