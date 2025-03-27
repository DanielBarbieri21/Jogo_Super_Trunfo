# Super Trunfo dos Estados do Brasil 
Bem-vindo ao Super Trunfo dos Estados do Brasil , um jogo digital inspirado no clássico Super Trunfo, desenvolvido em C com interface gráfica usando a biblioteca GTK+ 3.0. Este projeto representa os 26 estados do Brasil mais o Distrito Federal (27 cartas no total), permitindo que dois jogadores comparem atributos como população, PIB, área, pontos turísticos e densidade populacional. O jogo suporta edição de cartas, comparação interativa e salvamento/carregamento de dados em arquivo.

# Funcionalidades
Cartas Pré-carregadas: 27 cartas representando todos os estados brasileiros e o Distrito Federal com valores fictícios iniciais.
Interface Gráfica: Desenvolvida com GTK+ 3.0, inclui menus suspensos, campos de entrada e botões para interação.
Edição de Cartas: Permite ajustar os atributos de cada carta.
Comparação: Compare atributos entre duas cartas selecionadas e veja o resultado em um diálogo.
# Persistência: Salve e carregue as cartas em um arquivo cartas.txt.
# Requisitos
Sistema Operacional: Windows (testado no Windows 10/11 com MSYS2).
Ferramentas:
GCC (compilador C).
MSYS2 (para instalar GTK+ e dependências no Windows).
GTK+ 3.0 (biblioteca gráfica).
Instalação no Windows
1. Instalar o MSYS2
Baixe o instalador em msys2.org (msys2-x86_64-latest.exe).
Instale em C:\msys64 (ou outro diretório de sua escolha).
Abra o terminal "MSYS2 MSYS" e atualize o sistema:

Uma janela gráfica será aberta com a interface do jogo.
Como Jogar com 2 Jogadores
Regras
Cada jogador controla um conjunto de cartas.
Em cada turno, um jogador escolhe um atributo para comparar, e o maior valor vence.
O vencedor do turno "leva" a carta do oponente (anote os pontos manualmente).
O jogo continua até que os jogadores decidam parar ou todas as cartas sejam disputadas.
Passo a Passo
Divisão das Cartas:
Jogador 1: Controla as primeiras 13 cartas (Acre a Mato Grosso do Sul).
Jogador 2: Controla as últimas 14 cartas (Minas Gerais a Tocantins).
Anote isso em um papel ou memorize.
Iniciar o Jogo:
Execute ./super_trunfo_gui para abrir a interface.
Turno do Jogador 1:
No primeiro menu suspenso (esquerda), selecione uma carta sua (ex.: "Acre").
(Opcional) Edite os campos (estado, população, etc.) e clique em "Cadastrar Carta".
Anuncie o atributo a comparar (ex.: "Vamos comparar PIB!").
Turno do Jogador 2:
No segundo menu suspenso (abaixo do primeiro), selecione uma carta sua (ex.: "São Paulo").
(Opcional) Edite a carta usando o primeiro menu e "Cadastrar Carta" antes de selecioná-la no segundo menu.
Comparar:
Clique no botão correspondente ao atributo escolhido (ex.: "Comparar PIB").
Um diálogo mostrará o resultado (ex.: "São Paulo: 1550,5 vs. Acre: 15,5 - Carta 2 vence!").
Anotar o Resultado:
Se "Carta 1" vencer, Jogador 1 ganha 1 ponto.
Se "Carta 2" vencer, Jogador 2 ganha 1 ponto.
Se empatar, ninguém pontua.
Anote os pontos em um papel.
Próximo Turno:
Troque os papéis: Jogador 2 escolhe o atributo e a carta no primeiro menu, Jogador 1 responde no segundo.
Repita os passos 3 a 6.
Finalizar:
Continue até decidirem parar ou todas as cartas serem disputadas.
Alguns os pontos para determinar o vencedor.
Salvar Progresso:
Clique em "Salvar Cartas" para gravar os dados editados em cartas.txt.
Na próxima vez, use "Carregar Cartas" para retomar.
Exemplo de Turno
Jogador 1: Seleciona "Bahia" (PIB: 300.5), anuncia "PIB".
Jogador 2: Seleciona "São Paulo" (PIB: 1550.5).
Ação: Clique em "Comparar PIB".
Resultado: "São Paulo vence!" → Jogador 2 ganha 1 ponto.

## Sinta-se à vontade para abrir issues ou enviar pull requests
