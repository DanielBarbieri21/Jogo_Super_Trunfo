#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define NUM_CARTAS 27

typedef struct {
    char estado[50];
    long long populacao;
    double pib;
    double area;
    int pontos_turisticos;
    double densidade_populacional;
} Carta;

// Dados reais dos estados brasileiros
Carta cartas[NUM_CARTAS] = {
    {"Acre", 906876, 15.5, 164123.040, 10, 0},
    {"Alagoas", 3365351, 60.2, 27778.506, 15, 0},
    {"Amapá", 877613, 14.8, 142829.4, 8, 0},
    {"Amazonas", 4269995, 90.1, 1559167.878, 20, 0},
    {"Bahia", 14930634, 300.5, 564733.177, 30, 0},
    {"Ceará", 9240580, 200.3, 148920.531, 25, 0},
    {"Distrito Federal", 3094325, 250.0, 5802.0, 12, 0},
    {"Espírito Santo", 4108508, 120.4, 46095.583, 18, 0},
    {"Goiás", 7206589, 210.7, 340111.376, 22, 0},
    {"Maranhão", 7153262, 130.9, 331937.450, 14, 0},
    {"Mato Grosso", 3567234, 150.6, 903366.192, 16, 0},
    {"Mato Grosso do Sul", 2839188, 110.8, 357145.532, 13, 0},
    {"Minas Gerais", 21411923, 600.2, 586522.122, 35, 0},
    {"Pará", 8777124, 220.5, 1247955.381, 19, 0},
    {"Paraíba", 4059905, 90.3, 56467.242, 17, 0},
    {"Paraná", 11597484, 400.8, 199307.922, 28, 0},
    {"Pernambuco", 9674793, 250.1, 98311.616, 24, 0},
    {"Piauí", 3289290, 70.4, 251577.738, 11, 0},
    {"Rio de Janeiro", 17463349, 650.9, 43780.172, 40, 0},
    {"Rio Grande do Norte", 3560903, 100.2, 52811.047, 16, 0},
    {"Rio Grande do Sul", 11422973, 450.7, 281730.223, 27, 0},
    {"Rondônia", 1815278, 50.6, 237765.376, 9, 0},
    {"Roraima", 652713, 12.3, 224300.506, 7, 0},
    {"Santa Catarina", 7338473, 300.5, 95736.165, 23, 0},
    {"São Paulo", 46649132, 1550.5, 248219.481, 50, 0},
    {"Sergipe", 2338474, 60.8, 21915.116, 12, 0},
    {"Tocantins", 1607363, 40.9, 277720.520, 10, 0}
};

void limpar_tela() {
    system("cls");
}

void pausar() {
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void atualizar_densidade() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        if (cartas[i].area > 0) {
            cartas[i].densidade_populacional = (double)cartas[i].populacao / cartas[i].area;
        }
    }
}

void mostrar_carta(int indice) {
    if (indice < 0 || indice >= NUM_CARTAS) return;
    
    Carta *carta = &cartas[indice];
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    🇧🇷 SUPER TRUNFO BRASIL 🇧🇷                ║\n");
    printf("╠══════════════════════════════════════════════════════════════╣\n");
    printf("║ Estado: %-45s ║\n", carta->estado);
    printf("║ População: %'lld habitantes%25s ║\n", carta->populacao, "");
    printf("║ PIB: R$ %.2lf bilhões%35s ║\n", carta->pib, "");
    printf("║ Área: %.2lf km²%40s ║\n", carta->area, "");
    printf("║ Pontos Turísticos: %d%32s ║\n", carta->pontos_turisticos, "");
    printf("║ Densidade: %.2lf hab/km²%30s ║\n", carta->densidade_populacional, "");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
}

void listar_estados() {
    printf("\n📋 LISTA DE ESTADOS:\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("%2d. %s\n", i + 1, cartas[i].estado);
    }
    printf("═══════════════════════════════════════════════════════════════\n");
}

void comparar_cartas() {
    int carta1, carta2, atributo;
    
    printf("\n⚔️ COMPARADOR DE CARTAS\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    listar_estados();
    
    printf("\nSelecione a primeira carta (1-%d): ", NUM_CARTAS);
    scanf("%d", &carta1);
    carta1--;
    
    if (carta1 < 0 || carta1 >= NUM_CARTAS) {
        printf("❌ Carta inválida!\n");
        pausar();
        return;
    }
    
    printf("\nSelecione a segunda carta (1-%d): ", NUM_CARTAS);
    scanf("%d", &carta2);
    carta2--;
    
    if (carta2 < 0 || carta2 >= NUM_CARTAS) {
        printf("❌ Carta inválida!\n");
        pausar();
        return;
    }
    
    if (carta1 == carta2) {
        printf("❌ Selecione cartas diferentes!\n");
        pausar();
        return;
    }
    
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. PIB\n");
    printf("3. Área\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade\n");
    printf("Opção: ");
    scanf("%d", &atributo);
    
    Carta *c1 = &cartas[carta1];
    Carta *c2 = &cartas[carta2];
    double val1, val2;
    const char *nome_atributo;
    
    switch (atributo) {
        case 1:
            val1 = c1->populacao;
            val2 = c2->populacao;
            nome_atributo = "População";
            break;
        case 2:
            val1 = c1->pib;
            val2 = c2->pib;
            nome_atributo = "PIB";
            break;
        case 3:
            val1 = c1->area;
            val2 = c2->area;
            nome_atributo = "Área";
            break;
        case 4:
            val1 = c1->pontos_turisticos;
            val2 = c2->pontos_turisticos;
            nome_atributo = "Pontos Turísticos";
            break;
        case 5:
            val1 = c1->densidade_populacional;
            val2 = c2->densidade_populacional;
            nome_atributo = "Densidade";
            break;
        default:
            printf("❌ Opção inválida!\n");
            pausar();
            return;
    }
    
    printf("\n🏆 RESULTADO DA COMPARAÇÃO\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("Atributo: %s\n", nome_atributo);
    printf("%s: %.2lf\n", c1->estado, val1);
    printf("%s: %.2lf\n", c2->estado, val2);
    printf("\n");
    
    if (val1 > val2) {
        printf("🏆 VENCEDOR: %s\n", c1->estado);
    } else if (val2 > val1) {
        printf("🏆 VENCEDOR: %s\n", c2->estado);
    } else {
        printf("🤝 EMPATE!\n");
    }
    
    pausar();
}

void editar_carta() {
    int indice;
    
    printf("\n✏️ EDITOR DE CARTAS\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    listar_estados();
    
    printf("\nSelecione a carta para editar (1-%d): ", NUM_CARTAS);
    scanf("%d", &indice);
    indice--;
    
    if (indice < 0 || indice >= NUM_CARTAS) {
        printf("❌ Carta inválida!\n");
        pausar();
        return;
    }
    
    Carta *carta = &cartas[indice];
    
    printf("\n📋 Editando: %s\n", carta->estado);
    printf("═══════════════════════════════════════════════════════════════\n");
    
    printf("Estado atual: %s\n", carta->estado);
    printf("Novo nome (ou Enter para manter): ");
    getchar(); // Limpar buffer
    char novo_nome[50];
    fgets(novo_nome, 50, stdin);
    novo_nome[strcspn(novo_nome, "\n")] = 0; // Remover quebra de linha
    
    if (strlen(novo_nome) > 0) {
        strncpy(carta->estado, novo_nome, 49);
        carta->estado[49] = '\0';
    }
    
    printf("População atual: %lld\n", carta->populacao);
    printf("Nova população: ");
    long long nova_pop;
    if (scanf("%lld", &nova_pop) == 1 && nova_pop > 0) {
        carta->populacao = nova_pop;
    }
    
    printf("PIB atual: %.2lf\n", carta->pib);
    printf("Novo PIB: ");
    double novo_pib;
    if (scanf("%lf", &novo_pib) == 1 && novo_pib > 0) {
        carta->pib = novo_pib;
    }
    
    printf("Área atual: %.2lf\n", carta->area);
    printf("Nova área: ");
    double nova_area;
    if (scanf("%lf", &nova_area) == 1 && nova_area > 0) {
        carta->area = nova_area;
    }
    
    printf("Pontos turísticos atuais: %d\n", carta->pontos_turisticos);
    printf("Novos pontos turísticos: ");
    int novos_pontos;
    if (scanf("%d", &novos_pontos) == 1 && novos_pontos >= 0) {
        carta->pontos_turisticos = novos_pontos;
    }
    
    atualizar_densidade();
    
    printf("\n✅ Carta atualizada com sucesso!\n");
    mostrar_carta(indice);
    pausar();
}

void salvar_cartas() {
    FILE *arquivo = fopen("cartas_salvas.txt", "w");
    if (arquivo == NULL) {
        printf("❌ Erro ao salvar arquivo!\n");
        pausar();
        return;
    }
    
    for (int i = 0; i < NUM_CARTAS; i++) {
        fprintf(arquivo, "%s;%lld;%.2lf;%.2lf;%d;%.2lf\n",
                cartas[i].estado, cartas[i].populacao, cartas[i].pib,
                cartas[i].area, cartas[i].pontos_turisticos, cartas[i].densidade_populacional);
    }
    fclose(arquivo);
    
    printf("✅ Cartas salvas com sucesso em 'cartas_salvas.txt'!\n");
    pausar();
}

void carregar_cartas() {
    FILE *arquivo = fopen("cartas_salvas.txt", "r");
    if (arquivo == NULL) {
        printf("❌ Arquivo 'cartas_salvas.txt' não encontrado!\n");
        pausar();
        return;
    }
    
    int i = 0;
    while (fscanf(arquivo, "%49[^;];%lld;%lf;%lf;%d;%lf\n",
                  cartas[i].estado, &cartas[i].populacao, &cartas[i].pib,
                  &cartas[i].area, &cartas[i].pontos_turisticos, &cartas[i].densidade_populacional) == 6) {
        i++;
        if (i >= NUM_CARTAS) break;
    }
    fclose(arquivo);
    
    printf("✅ %d cartas carregadas com sucesso!\n", i);
    pausar();
}

void mostrar_estatisticas() {
    long long total_pop = 0;
    double total_pib = 0;
    double total_area = 0;
    int total_pontos = 0;
    
    for (int i = 0; i < NUM_CARTAS; i++) {
        total_pop += cartas[i].populacao;
        total_pib += cartas[i].pib;
        total_area += cartas[i].area;
        total_pontos += cartas[i].pontos_turisticos;
    }
    
    printf("\n📊 ESTATÍSTICAS DO BRASIL\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("🌍 População Total: %'lld habitantes\n", total_pop);
    printf("💰 PIB Total: R$ %.2lf bilhões\n", total_pib);
    printf("🗺️ Área Total: %.2lf km²\n", total_area);
    printf("🏛️ Total de Pontos Turísticos: %d\n", total_pontos);
    printf("📈 Densidade Média: %.2lf hab/km²\n", (double)total_pop / total_area);
    printf("═══════════════════════════════════════════════════════════════\n");
    
    pausar();
}

void menu_principal() {
    int opcao;
    
    while (1) {
        limpar_tela();
        
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                🇧🇷 SUPER TRUNFO BRASIL 🇧🇷                  ║\n");
        printf("║                    Edição Moderna v2.0                      ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        
        printf("\n📋 MENU PRINCIPAL:\n");
        printf("═══════════════════════════════════════════════════════════════\n");
        printf("1. 🎯 Ver Carta\n");
        printf("2. ⚔️ Comparar Cartas\n");
        printf("3. ✏️ Editar Carta\n");
        printf("4. 📊 Estatísticas do Brasil\n");
        printf("5. 💾 Salvar Cartas\n");
        printf("6. 📂 Carregar Cartas\n");
        printf("7. 📋 Listar Todos os Estados\n");
        printf("0. 🚪 Sair\n");
        printf("═══════════════════════════════════════════════════════════════\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                int indice;
                printf("\nSelecione uma carta (1-%d): ", NUM_CARTAS);
                scanf("%d", &indice);
                indice--;
                if (indice >= 0 && indice < NUM_CARTAS) {
                    mostrar_carta(indice);
                    pausar();
                } else {
                    printf("❌ Carta inválida!\n");
                    pausar();
                }
                break;
            }
            case 2:
                comparar_cartas();
                break;
            case 3:
                editar_carta();
                break;
            case 4:
                mostrar_estatisticas();
                break;
            case 5:
                salvar_cartas();
                break;
            case 6:
                carregar_cartas();
                break;
            case 7:
                listar_estados();
                pausar();
                break;
            case 0:
                printf("\n🇧🇷 Obrigado por jogar Super Trunfo Brasil! 🇧🇷\n");
                printf("Desenvolvido com ❤️ para o Brasil!\n");
                exit(0);
            default:
                printf("❌ Opção inválida!\n");
                pausar();
        }
    }
}

int main() {
    // Configurar codificação UTF-8 no Windows
    system("chcp 65001 > nul");
    
    // Inicializar dados
    atualizar_densidade();
    
    // Mostrar boas-vindas
    limpar_tela();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                🇧🇷 SUPER TRUNFO BRASIL 🇧🇷                  ║\n");
    printf("║                    Edição Moderna v2.0                      ║\n");
    printf("║                                                              ║\n");
    printf("║  🎮 Um jogo digital sobre os estados brasileiros            ║\n");
    printf("║  📊 Dados reais e atualizados de 2023                      ║\n");
    printf("║  🏆 Compare atributos e descubra o vencedor!                ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    
    printf("\nCarregando dados dos 27 estados brasileiros...\n");
    printf("✅ Dados carregados com sucesso!\n");
    
    pausar();
    
    // Iniciar menu principal
    menu_principal();
    
    return 0;
}
