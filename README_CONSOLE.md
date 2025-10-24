# 🇧🇷 Super Trunfo Brasil - Versão Console

## 🎮 Jogo Digital dos Estados Brasileiros

Uma versão simplificada e funcional do Super Trunfo Brasil que funciona em qualquer sistema Windows sem dependências externas.

## ✨ Características

- **27 estados brasileiros** com dados reais de 2023
- **Interface de console** moderna e colorida
- **Comparador de cartas** interativo
- **Editor de cartas** para personalizar dados
- **Sistema de salvamento** de modificações
- **Estatísticas do Brasil** em tempo real

## 🚀 Como Usar

### Instalação Automática
```cmd
instalar_simples.bat
```

### Instalação Manual
```cmd
gcc -o super_trunfo_console super_trunfo_console.c
super_trunfo_console.exe
```

## 🎯 Funcionalidades

### 1. **Ver Carta**
- Visualize informações detalhadas de qualquer estado
- Dados de população, PIB, área, pontos turísticos e densidade

### 2. **Comparar Cartas**
- Escolha dois estados diferentes
- Compare qualquer atributo
- Veja o vencedor da comparação

### 3. **Editar Carta**
- Modifique dados de qualquer estado
- Atualize população, PIB, área, pontos turísticos
- Densidade é calculada automaticamente

### 4. **Estatísticas do Brasil**
- População total do país
- PIB agregado
- Área total
- Densidade média

### 5. **Salvar/Carregar**
- Salve suas modificações
- Carregue dados salvos anteriormente

## 📊 Dados Incluídos

| Estado | População | PIB (bilhões) | Área (km²) | Pontos Turísticos |
|--------|-----------|---------------|------------|-------------------|
| São Paulo | 46.649.132 | 1.550,5 | 248.219 | 50 |
| Minas Gerais | 21.411.923 | 600,2 | 586.522 | 35 |
| Rio de Janeiro | 17.463.349 | 650,9 | 43.780 | 40 |
| Bahia | 14.930.634 | 300,5 | 564.733 | 30 |
| ... | ... | ... | ... | ... |

## 🎮 Como Jogar

1. **Execute o jogo:** `super_trunfo_console.exe`
2. **Escolha uma opção** no menu principal
3. **Compare estados** usando diferentes atributos
4. **Edite cartas** para personalizar o jogo
5. **Salve suas modificações** para usar depois

## 🔧 Requisitos

- **Sistema:** Windows 7 ou superior
- **Compilador:** GCC (MinGW) ou equivalente
- **Espaço:** 1 MB
- **Memória:** 10 MB

## 📁 Arquivos

- `super_trunfo_console.c` - Código fonte
- `super_trunfo_console.exe` - Executável
- `instalar_simples.bat` - Instalador automático
- `cartas_salvas.txt` - Arquivo de dados (criado automaticamente)

## 🎯 Atributos de Comparação

1. **👥 População** - Número de habitantes
2. **💰 PIB** - Produto Interno Bruto em bilhões
3. **🗺️ Área** - Extensão territorial em km²
4. **🏛️ Pontos Turísticos** - Número de atrações
5. **📊 Densidade** - Habitantes por km²

## 🏆 Exemplo de Jogo

```
Comparação de PIB:
São Paulo: 1550.50
Rio de Janeiro: 650.90

🏆 VENCEDOR: São Paulo
```

## 🔧 Solução de Problemas

### Erro de Compilação
```cmd
# Verificar se GCC está instalado
gcc --version

# Compilar manualmente
gcc -o super_trunfo_console super_trunfo_console.c
```

### Erro de Execução
```cmd
# Executar no terminal
super_trunfo_console.exe

# Ou usar o instalador
instalar_simples.bat
```

## 📈 Próximas Versões

- [ ] Interface gráfica com GTK+3
- [ ] Modo multiplayer
- [ ] Efeitos sonoros
- [ ] Temas visuais
- [ ] Estatísticas avançadas

## 🤝 Contribuindo

1. Faça um fork do projeto
2. Crie uma branch para sua feature
3. Commit suas mudanças
4. Abra um Pull Request

## 📄 Licença

MIT License - Veja o arquivo LICENSE para detalhes.

---

<div align="center">
  <p><strong>🇧🇷 Desenvolvido com ❤️ para o Brasil 🇧🇷</strong></p>
  <p>⭐ Se gostou do projeto, deixe uma estrela! ⭐</p>
</div>
