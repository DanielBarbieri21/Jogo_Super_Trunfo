# 🇧🇷 Super Trunfo dos Estados do Brasil - Edição Moderna

<div align="center">
  <img src="https://img.shields.io/badge/Version-2.0%20Moderna-brightgreen" alt="Versão">
  <img src="https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-blue" alt="Plataforma">
  <img src="https://img.shields.io/badge/Language-C%20%2B%20GTK%2B3-orange" alt="Linguagem">
  <img src="https://img.shields.io/badge/License-MIT-yellow" alt="Licença">
</div>

<div align="center">
  <h3>🎮 Um jogo digital moderno e interativo sobre os estados brasileiros</h3>
  <p>Desenvolvido com interface gráfica moderna, dados reais e funcionalidades avançadas</p>
</div>

---

## ✨ Características Principais

### 🎨 **Interface Moderna**
- Design responsivo e intuitivo
- Tema visual atrativo com gradientes
- Animações suaves e feedback visual
- Layout organizado em abas

### 📊 **Dados Reais do Brasil**
- 27 cartas (26 estados + Distrito Federal)
- Informações atualizadas de 2023
- População, PIB, área, pontos turísticos
- Densidade populacional calculada automaticamente

### 🛠️ **Funcionalidades Avançadas**
- **Editor de Cartas**: Modifique atributos facilmente
- **Comparador Interativo**: Compare cartas em tempo real
- **Sistema de Salvamento**: Persistência de dados
- **Estatísticas**: Análise completa do Brasil
- **Validação**: Verificação de dados de entrada

---

## 🚀 Instalação Rápida

### Linux (Ubuntu/Debian)
```bash
# Instalar dependências
make install-deps

# Compilar e executar
make
make run
```

### Windows (MSYS2)
```bash
# Instalar dependências
make install-deps-windows

# Compilar e executar
make
make run
```

### Verificar Dependências
```bash
make check-deps
```

---

## 🎮 Como Jogar

### 1. **Editor de Cartas**
- Selecione um estado no menu suspenso
- Edite os atributos conforme necessário
- Clique em "Cadastrar Carta" para salvar
- Visualize informações detalhadas em tempo real

### 2. **Comparador de Cartas**
- Escolha duas cartas diferentes
- Selecione o atributo para comparar:
  - 👥 **População**: Número de habitantes
  - 💰 **PIB**: Produto Interno Bruto
  - 🗺️ **Área**: Extensão territorial
  - 🏛️ **Pontos Turísticos**: Atrações
  - 📊 **Densidade**: Habitantes por km²
- Veja o resultado da comparação

### 3. **Sistema de Salvamento**
- Salve suas modificações com "Salvar Cartas"
- Carregue dados salvos com "Carregar Cartas"
- Dados são persistidos em `cartas_salvas.txt`

---

## 📋 Comandos Disponíveis

| Comando | Descrição |
|---------|-----------|
| `make` | Compilar o jogo |
| `make run` | Executar o jogo |
| `make debug` | Executar em modo debug |
| `make clean` | Limpar arquivos de build |
| `make install` | Instalar no sistema |
| `make package` | Criar pacote de distribuição |
| `make help` | Mostrar ajuda completa |

---

## 🏗️ Estrutura do Projeto

```
Jogo_Super_Trunfo/
├── 📁 assets/                 # Recursos (bandeiras, imagens)
├── 📁 build/                  # Arquivos de compilação
├── 📁 docs/                   # Documentação
├── 📁 Jogo_Super_Trunfo_Fases/ # Versões antigas
├── 📄 super_trunfo_moderno.c  # Código principal moderno
├── 📄 super_trunfo_gui.c      # Versão original
├── 📄 Makefile               # Sistema de build
└── 📄 README.md              # Este arquivo
```

---

## 🎯 Estados Incluídos

| Região | Estados |
|--------|---------|
| **Norte** | Acre, Amapá, Amazonas, Pará, Rondônia, Roraima, Tocantins |
| **Nordeste** | Alagoas, Bahia, Ceará, Maranhão, Paraíba, Pernambuco, Piauí, Rio Grande do Norte, Sergipe |
| **Centro-Oeste** | Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul |
| **Sudeste** | Espírito Santo, Minas Gerais, Rio de Janeiro, São Paulo |
| **Sul** | Paraná, Rio Grande do Sul, Santa Catarina |

---

## 🔧 Requisitos Técnicos

### Sistema Operacional
- **Linux**: Ubuntu 18.04+, Debian 10+, ou equivalente
- **Windows**: Windows 10+ com MSYS2

### Dependências
- **GCC**: Compilador C (versão 7.0+)
- **GTK+3**: Biblioteca gráfica (versão 3.22+)
- **pkg-config**: Gerenciador de dependências

### Recursos Mínimos
- **RAM**: 512 MB
- **Espaço**: 50 MB
- **Resolução**: 1024x768

---

## 🎨 Personalização

### Adicionando Bandeiras
1. Coloque imagens das bandeiras em `assets/bandeiras/`
2. Nomeie os arquivos com a sigla do estado (ex: `sp.png`)
3. Formatos suportados: PNG, JPG, SVG

### Modificando Dados
- Edite o array `cartas_iniciais` em `super_trunfo_moderno.c`
- Atualize informações conforme necessário
- Recompile com `make clean && make`

---

## 🐛 Solução de Problemas

### Erro de Compilação
```bash
# Verificar dependências
make check-deps

# Instalar dependências faltantes
make install-deps
```

### Interface Não Aparece
```bash
# Verificar se GTK+3 está instalado
pkg-config --exists gtk+-3.0

# Reinstalar dependências
sudo apt-get install libgtk-3-dev
```

### Dados Não Salvam
- Verifique permissões de escrita no diretório
- Certifique-se de que o arquivo `cartas_salvas.txt` pode ser criado

---

## 📈 Roadmap Futuro

- [ ] **Modo Multiplayer**: Suporte para 4 jogadores
- [ ] **Sistema de Ranking**: Classificação de jogadores
- [ ] **Temas Visuais**: Múltiplos temas de interface
- [ ] **Efeitos Sonoros**: Música e sons de jogo
- [ ] **Modo Online**: Jogar pela internet
- [ ] **Estatísticas Avançadas**: Gráficos e análises
- [ ] **Modo Educativo**: Informações históricas dos estados

---

## 🤝 Contribuindo

1. **Fork** o projeto
2. Crie uma **branch** para sua feature (`git checkout -b feature/AmazingFeature`)
3. **Commit** suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. **Push** para a branch (`git push origin feature/AmazingFeature`)
5. Abra um **Pull Request**

---

### 👨‍💻 Desenvolvido por Adailton Daniel Oliveira Barbieri
---

## 🙏 Agradecimentos

- **IBGE** - Dados demográficos e econômicos
- **GTK+ Team** - Framework gráfico
- **Comunidade Open Source** - Suporte e feedback

---

<div align="center">
  <p>⭐ Se gostou do projeto, deixe uma estrela! ⭐</p>
</div>
