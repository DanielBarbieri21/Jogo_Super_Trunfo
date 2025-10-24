#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_CARTAS 27 // 26 estados + Distrito Federal
#define MAX_PLAYERS 4

// Estrutura da carta com dados reais do Brasil
typedef struct {
    char estado[50];
    char sigla[3];
    long long populacao;
    double pib; // em bilhões de reais
    double area; // em km²
    int pontos_turisticos;
    double densidade_populacional;
    char capital[50];
    char regiao[20];
    char bandeira[100]; // caminho para imagem da bandeira
} Carta;

// Estrutura do jogador
typedef struct {
    char nome[50];
    int pontos;
    int cartas_restantes;
    int cartas_ganhas;
} Jogador;

// Estrutura principal da aplicação
typedef struct {
    GtkWidget *window;
    GtkWidget *notebook; // Para abas
    GtkWidget *stack; // Para navegação moderna
    
    // Widgets do jogo
    GtkWidget *combo1, *combo2;
    GtkWidget *entry_estado, *entry_populacao, *entry_pib, *entry_area, *entry_pontos;
    GtkWidget *label_carta, *label_estatisticas;
    GtkWidget *btn_cadastrar, *btn_salvar, *btn_carregar;
    
    // Widgets do placar
    GtkWidget *label_placar[MAX_PLAYERS];
    GtkWidget *label_turno;
    
    // Dados do jogo
    Carta cartas[NUM_CARTAS];
    Jogador jogadores[MAX_PLAYERS];
    int carta_atual;
    int num_jogadores;
    int turno_atual;
    int jogo_ativo;
    
    // Estilo
    GtkCssProvider *css_provider;
} AppData;

AppData app;

// Dados reais dos estados brasileiros (2023)
Carta cartas_iniciais[NUM_CARTAS] = {
    {"Acre", "AC", 906876, 15.5, 164123.040, 10, 0, "Rio Branco", "Norte", "assets/bandeiras/ac.png"},
    {"Alagoas", "AL", 3365351, 60.2, 27778.506, 15, 0, "Maceió", "Nordeste", "assets/bandeiras/al.png"},
    {"Amapá", "AP", 877613, 14.8, 142829.4, 8, 0, "Macapá", "Norte", "assets/bandeiras/ap.png"},
    {"Amazonas", "AM", 4269995, 90.1, 1559167.878, 20, 0, "Manaus", "Norte", "assets/bandeiras/am.png"},
    {"Bahia", "BA", 14930634, 300.5, 564733.177, 30, 0, "Salvador", "Nordeste", "assets/bandeiras/ba.png"},
    {"Ceará", "CE", 9240580, 200.3, 148920.531, 25, 0, "Fortaleza", "Nordeste", "assets/bandeiras/ce.png"},
    {"Distrito Federal", "DF", 3094325, 250.0, 5802.0, 12, 0, "Brasília", "Centro-Oeste", "assets/bandeiras/df.png"},
    {"Espírito Santo", "ES", 4108508, 120.4, 46095.583, 18, 0, "Vitória", "Sudeste", "assets/bandeiras/es.png"},
    {"Goiás", "GO", 7206589, 210.7, 340111.376, 22, 0, "Goiânia", "Centro-Oeste", "assets/bandeiras/go.png"},
    {"Maranhão", "MA", 7153262, 130.9, 331937.450, 14, 0, "São Luís", "Nordeste", "assets/bandeiras/ma.png"},
    {"Mato Grosso", "MT", 3567234, 150.6, 903366.192, 16, 0, "Cuiabá", "Centro-Oeste", "assets/bandeiras/mt.png"},
    {"Mato Grosso do Sul", "MS", 2839188, 110.8, 357145.532, 13, 0, "Campo Grande", "Centro-Oeste", "assets/bandeiras/ms.png"},
    {"Minas Gerais", "MG", 21411923, 600.2, 586522.122, 35, 0, "Belo Horizonte", "Sudeste", "assets/bandeiras/mg.png"},
    {"Pará", "PA", 8777124, 220.5, 1247955.381, 19, 0, "Belém", "Norte", "assets/bandeiras/pa.png"},
    {"Paraíba", "PB", 4059905, 90.3, 56467.242, 17, 0, "João Pessoa", "Nordeste", "assets/bandeiras/pb.png"},
    {"Paraná", "PR", 11597484, 400.8, 199307.922, 28, 0, "Curitiba", "Sul", "assets/bandeiras/pr.png"},
    {"Pernambuco", "PE", 9674793, 250.1, 98311.616, 24, 0, "Recife", "Nordeste", "assets/bandeiras/pe.png"},
    {"Piauí", "PI", 3289290, 70.4, 251577.738, 11, 0, "Teresina", "Nordeste", "assets/bandeiras/pi.png"},
    {"Rio de Janeiro", "RJ", 17463349, 650.9, 43780.172, 40, 0, "Rio de Janeiro", "Sudeste", "assets/bandeiras/rj.png"},
    {"Rio Grande do Norte", "RN", 3560903, 100.2, 52811.047, 16, 0, "Natal", "Nordeste", "assets/bandeiras/rn.png"},
    {"Rio Grande do Sul", "RS", 11422973, 450.7, 281730.223, 27, 0, "Porto Alegre", "Sul", "assets/bandeiras/rs.png"},
    {"Rondônia", "RO", 1815278, 50.6, 237765.376, 9, 0, "Porto Velho", "Norte", "assets/bandeiras/ro.png"},
    {"Roraima", "RR", 652713, 12.3, 224300.506, 7, 0, "Boa Vista", "Norte", "assets/bandeiras/rr.png"},
    {"Santa Catarina", "SC", 7338473, 300.5, 95736.165, 23, 0, "Florianópolis", "Sul", "assets/bandeiras/sc.png"},
    {"São Paulo", "SP", 46649132, 1550.5, 248219.481, 50, 0, "São Paulo", "Sudeste", "assets/bandeiras/sp.png"},
    {"Sergipe", "SE", 2338474, 60.8, 21915.116, 12, 0, "Aracaju", "Nordeste", "assets/bandeiras/se.png"},
    {"Tocantins", "TO", 1607363, 40.9, 277720.520, 10, 0, "Palmas", "Norte", "assets/bandeiras/to.png"}
};

// Função para aplicar CSS moderno
void aplicar_css_moderno() {
    app.css_provider = gtk_css_provider_new();
    
    const char *css = 
        "* {"
        "    font-family: 'Segoe UI', 'Roboto', sans-serif;"
        "    font-size: 14px;"
        "}"
        ""
        "window {"
        "    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);"
        "    color: #333;"
        "}"
        ""
        ".card {"
        "    background: rgba(255, 255, 255, 0.95);"
        "    border-radius: 15px;"
        "    padding: 20px;"
        "    margin: 10px;"
        "    box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);"
        "    backdrop-filter: blur(10px);"
        "    border: 1px solid rgba(255, 255, 255, 0.2);"
        "}"
        ""
        "button {"
        "    background: linear-gradient(45deg, #667eea, #764ba2);"
        "    color: white;"
        "    border: none;"
        "    border-radius: 25px;"
        "    padding: 12px 24px;"
        "    font-weight: bold;"
        "    transition: all 0.3s ease;"
        "    box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);"
        "}"
        ""
        "button:hover {"
        "    transform: translateY(-2px);"
        "    box-shadow: 0 6px 20px rgba(0, 0, 0, 0.3);"
        "}"
        ""
        "button:active {"
        "    transform: translateY(0);"
        "}"
        ""
        "entry {"
        "    background: rgba(255, 255, 255, 0.9);"
        "    border: 2px solid transparent;"
        "    border-radius: 10px;"
        "    padding: 10px;"
        "    transition: all 0.3s ease;"
        "}"
        ""
        "entry:focus {"
        "    border-color: #667eea;"
        "    box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);"
        "}"
        ""
        "label {"
        "    color: #333;"
        "    font-weight: 500;"
        "}"
        ""
        ".title {"
        "    font-size: 24px;"
        "    font-weight: bold;"
        "    color: white;"
        "    text-align: center;"
        "    margin: 20px 0;"
        "}"
        ""
        ".subtitle {"
        "    font-size: 18px;"
        "    font-weight: 600;"
        "    color: #555;"
        "    margin: 15px 0 10px 0;"
        "}"
        ""
        ".stats {"
        "    background: linear-gradient(45deg, #f093fb 0%, #f5576c 100%);"
        "    color: white;"
        "    border-radius: 10px;"
        "    padding: 15px;"
        "    margin: 10px 0;"
        "}"
        ""
        ".score {"
        "    background: linear-gradient(45deg, #4facfe 0%, #00f2fe 100%);"
        "    color: white;"
        "    border-radius: 20px;"
        "    padding: 10px 20px;"
        "    font-weight: bold;"
        "    text-align: center;"
        "    margin: 5px;"
        "}";
    
    gtk_css_provider_load_from_data(app.css_provider, css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(app.css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

// Função para atualizar densidade populacional
void atualizar_densidade() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        if (app.cartas[i].area > 0) {
            app.cartas[i].densidade_populacional = (double)app.cartas[i].populacao / app.cartas[i].area;
        }
    }
}

// Função para inicializar dados
void inicializar_dados() {
    memcpy(app.cartas, cartas_iniciais, sizeof(cartas_iniciais));
    atualizar_densidade();
    
    // Inicializar jogadores
    for (int i = 0; i < MAX_PLAYERS; i++) {
        snprintf(app.jogadores[i].nome, 50, "Jogador %d", i + 1);
        app.jogadores[i].pontos = 0;
        app.jogadores[i].cartas_restantes = NUM_CARTAS / MAX_PLAYERS;
        app.jogadores[i].cartas_ganhas = 0;
    }
    
    app.num_jogadores = 2;
    app.turno_atual = 0;
    app.jogo_ativo = 0;
    app.carta_atual = 0;
}

// Função para atualizar exibição da carta
void atualizar_exibicao_carta() {
    char info[500];
    Carta *carta = &app.cartas[app.carta_atual];
    
    snprintf(info, 500, 
        "<span size='large' weight='bold'>%s (%s)</span>\n"
        "<span size='medium'>%s - %s</span>\n\n"
        "👥 <b>População:</b> %'lld habitantes\n"
        "💰 <b>PIB:</b> R$ %.1f bilhões\n"
        "🗺️ <b>Área:</b> %.1f km²\n"
        "🏛️ <b>Pontos Turísticos:</b> %d\n"
        "📊 <b>Densidade:</b> %.1f hab/km²",
        carta->estado, carta->sigla, carta->capital, carta->regiao,
        carta->populacao, carta->pib, carta->area, 
        carta->pontos_turisticos, carta->densidade_populacional);
    
    gtk_label_set_markup(GTK_LABEL(app.label_carta), info);
}

// Função para atualizar estatísticas
void atualizar_estatisticas() {
    char stats[300];
    int total_pop = 0;
    double total_pib = 0;
    double total_area = 0;
    
    for (int i = 0; i < NUM_CARTAS; i++) {
        total_pop += app.cartas[i].populacao;
        total_pib += app.cartas[i].pib;
        total_area += app.cartas[i].area;
    }
    
    snprintf(stats, 300,
        "<span size='large' weight='bold'>📊 Estatísticas do Brasil</span>\n\n"
        "🌍 <b>População Total:</b> %'d habitantes\n"
        "💰 <b>PIB Total:</b> R$ %.1f bilhões\n"
        "🗺️ <b>Área Total:</b> %.1f km²\n"
        "📈 <b>Densidade Média:</b> %.1f hab/km²",
        total_pop, total_pib, total_area, (double)total_pop / total_area);
    
    gtk_label_set_markup(GTK_LABEL(app.label_estatisticas), stats);
}

// Callback para mudança de carta
void on_carta_changed(GtkWidget *combo, gpointer data) {
    app.carta_atual = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));
    
    Carta *carta = &app.cartas[app.carta_atual];
    gtk_entry_set_text(GTK_ENTRY(app.entry_estado), carta->estado);
    
    char temp[30];
    snprintf(temp, 30, "%lld", carta->populacao);
    gtk_entry_set_text(GTK_ENTRY(app.entry_populacao), temp);
    
    snprintf(temp, 30, "%.2lf", carta->pib);
    gtk_entry_set_text(GTK_ENTRY(app.entry_pib), temp);
    
    snprintf(temp, 30, "%.2lf", carta->area);
    gtk_entry_set_text(GTK_ENTRY(app.entry_area), temp);
    
    snprintf(temp, 30, "%d", carta->pontos_turisticos);
    gtk_entry_set_text(GTK_ENTRY(app.entry_pontos), temp);
    
    atualizar_exibicao_carta();
}

// Callback para cadastrar carta
void on_cadastrar_carta(GtkWidget *button, gpointer data) {
    const char *estado = gtk_entry_get_text(GTK_ENTRY(app.entry_estado));
    const char *pop_str = gtk_entry_get_text(GTK_ENTRY(app.entry_populacao));
    const char *pib_str = gtk_entry_get_text(GTK_ENTRY(app.entry_pib));
    const char *area_str = gtk_entry_get_text(GTK_ENTRY(app.entry_area));
    const char *pontos_str = gtk_entry_get_text(GTK_ENTRY(app.entry_pontos));
    
    // Validação
    if (strlen(estado) == 0 || atoll(pop_str) <= 0 || atof(pib_str) <= 0 || 
        atof(area_str) <= 0 || atoi(pontos_str) < 0) {
        
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "❌ Valores inválidos!\n\nCertifique-se de que todos os campos estão preenchidos corretamente.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    // Atualizar dados
    strncpy(app.cartas[app.carta_atual].estado, estado, 49);
    app.cartas[app.carta_atual].estado[49] = '\0';
    app.cartas[app.carta_atual].populacao = atoll(pop_str);
    app.cartas[app.carta_atual].pib = atof(pib_str);
    app.cartas[app.carta_atual].area = atof(area_str);
    app.cartas[app.carta_atual].pontos_turisticos = atoi(pontos_str);
    
    atualizar_densidade();
    atualizar_exibicao_carta();
    atualizar_estatisticas();
    
    // Feedback visual
    gtk_button_set_label(GTK_BUTTON(button), "✅ Salvo!");
    g_timeout_add(1000, (GSourceFunc)gtk_button_set_label, "💾 Cadastrar Carta");
}

// Callback para comparação
void on_comparar(GtkWidget *button, gpointer data) {
    const char *atributo = (const char *)data;
    int idx1 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo1));
    int idx2 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo2));
    
    if (idx1 == idx2) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, 
            "⚠️ Selecione cartas diferentes!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    double attr1, attr2;
    Carta *carta1 = &app.cartas[idx1];
    Carta *carta2 = &app.cartas[idx2];
    
    if (strcmp(atributo, "População") == 0) { 
        attr1 = carta1->populacao; 
        attr2 = carta2->populacao; 
    }
    else if (strcmp(atributo, "PIB") == 0) { 
        attr1 = carta1->pib; 
        attr2 = carta2->pib; 
    }
    else if (strcmp(atributo, "Área") == 0) { 
        attr1 = carta1->area; 
        attr2 = carta2->area; 
    }
    else if (strcmp(atributo, "Pontos") == 0) { 
        attr1 = carta1->pontos_turisticos; 
        attr2 = carta2->pontos_turisticos; 
    }
    else if (strcmp(atributo, "Densidade") == 0) { 
        attr1 = carta1->densidade_populacional; 
        attr2 = carta2->densidade_populacional; 
    }
    else return;
    
    char resultado[400];
    const char *vencedor;
    const char *emoji;
    
    if (attr1 > attr2) {
        vencedor = carta1->estado;
        emoji = "🏆";
    } else if (attr2 > attr1) {
        vencedor = carta2->estado;
        emoji = "🏆";
    } else {
        vencedor = "Empate!";
        emoji = "🤝";
    }
    
    snprintf(resultado, 400,
        "<span size='large' weight='bold'>%s Comparação de %s</span>\n\n"
        "<span size='medium'>%s: %.2lf</span>\n"
        "<span size='medium'>%s: %.2lf</span>\n\n"
        "<span size='large' weight='bold'>%s %s</span>",
        emoji, atributo,
        carta1->estado, attr1,
        carta2->estado, attr2,
        emoji, vencedor);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", resultado);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Callback para salvar
void on_salvar(GtkWidget *button, gpointer data) {
    FILE *arquivo = fopen("cartas_salvas.txt", "w");
    if (arquivo == NULL) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "❌ Erro ao salvar arquivo!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    for (int i = 0; i < NUM_CARTAS; i++) {
        fprintf(arquivo, "%s;%s;%lld;%.2lf;%.2lf;%d;%.2lf;%s;%s\n",
                app.cartas[i].estado, app.cartas[i].sigla, app.cartas[i].populacao, 
                app.cartas[i].pib, app.cartas[i].area, app.cartas[i].pontos_turisticos,
                app.cartas[i].densidade_populacional, app.cartas[i].capital, app.cartas[i].regiao);
    }
    fclose(arquivo);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
        "✅ Cartas salvas com sucesso!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Callback para carregar
void on_carregar(GtkWidget *button, gpointer data) {
    FILE *arquivo = fopen("cartas_salvas.txt", "r");
    if (arquivo == NULL) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "❌ Arquivo não encontrado!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    int i = 0;
    while (fscanf(arquivo, "%49[^;];%2[^;];%lld;%lf;%lf;%d;%lf;%49[^;];%19[^\n]\n",
                  app.cartas[i].estado, app.cartas[i].sigla, &app.cartas[i].populacao, 
                  &app.cartas[i].pib, &app.cartas[i].area, &app.cartas[i].pontos_turisticos,
                  &app.cartas[i].densidade_populacional, app.cartas[i].capital, app.cartas[i].regiao) == 9) {
        i++;
        if (i >= NUM_CARTAS) break;
    }
    fclose(arquivo);
    
    atualizar_exibicao_carta();
    atualizar_estatisticas();
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
        "✅ %d cartas carregadas!", i);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Função para criar a interface principal
void criar_interface() {
    // Janela principal
    app.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app.window), "🇧🇷 Super Trunfo Brasil - Edição Moderna");
    gtk_window_set_default_size(GTK_WINDOW(app.window), 1000, 700);
    gtk_window_set_resizable(GTK_WINDOW(app.window), TRUE);
    g_signal_connect(app.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Container principal
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(app.window), main_box);
    
    // Título
    GtkWidget *title_label = gtk_label_new("🇧🇷 Super Trunfo dos Estados do Brasil");
    gtk_label_set_markup(GTK_LABEL(title_label), 
        "<span size='xx-large' weight='bold' color='white'>🇧🇷 Super Trunfo dos Estados do Brasil</span>");
    gtk_widget_set_name(title_label, "title");
    gtk_box_pack_start(GTK_BOX(main_box), title_label, FALSE, FALSE, 10);
    
    // Notebook para abas
    app.notebook = gtk_notebook_new();
    gtk_box_pack_start(GTK_BOX(main_box), app.notebook, TRUE, TRUE, 0);
    
    // === ABA 1: EDITOR DE CARTAS ===
    GtkWidget *editor_frame = gtk_frame_new("📝 Editor de Cartas");
    gtk_widget_set_name(editor_frame, "card");
    
    GtkWidget *editor_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    gtk_container_add(GTK_CONTAINER(editor_frame), editor_box);
    gtk_container_set_border_width(GTK_CONTAINER(editor_box), 20);
    
    // Painel esquerdo - Controles
    GtkWidget *controls_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(editor_box), controls_box, FALSE, FALSE, 0);
    
    // Seleção de carta
    GtkWidget *carta_label = gtk_label_new("🎯 Selecione uma carta:");
    gtk_widget_set_name(carta_label, "subtitle");
    gtk_box_pack_start(GTK_BOX(controls_box), carta_label, FALSE, FALSE, 5);
    
    app.combo1 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo1), app.cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo1), 0);
    gtk_box_pack_start(GTK_BOX(controls_box), app.combo1, FALSE, FALSE, 5);
    g_signal_connect(app.combo1, "changed", G_CALLBACK(on_carta_changed), NULL);
    
    // Campos de entrada
    GtkWidget *estado_label = gtk_label_new("🏛️ Estado:");
    gtk_box_pack_start(GTK_BOX(controls_box), estado_label, FALSE, FALSE, 5);
    app.entry_estado = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(controls_box), app.entry_estado, FALSE, FALSE, 5);
    
    GtkWidget *pop_label = gtk_label_new("👥 População:");
    gtk_box_pack_start(GTK_BOX(controls_box), pop_label, FALSE, FALSE, 5);
    app.entry_populacao = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(controls_box), app.entry_populacao, FALSE, FALSE, 5);
    
    GtkWidget *pib_label = gtk_label_new("💰 PIB (bilhões R$):");
    gtk_box_pack_start(GTK_BOX(controls_box), pib_label, FALSE, FALSE, 5);
    app.entry_pib = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(controls_box), app.entry_pib, FALSE, FALSE, 5);
    
    GtkWidget *area_label = gtk_label_new("🗺️ Área (km²):");
    gtk_box_pack_start(GTK_BOX(controls_box), area_label, FALSE, FALSE, 5);
    app.entry_area = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(controls_box), app.entry_area, FALSE, FALSE, 5);
    
    GtkWidget *pontos_label = gtk_label_new("🏛️ Pontos Turísticos:");
    gtk_box_pack_start(GTK_BOX(controls_box), pontos_label, FALSE, FALSE, 5);
    app.entry_pontos = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(controls_box), app.entry_pontos, FALSE, FALSE, 5);
    
    // Botões
    app.btn_cadastrar = gtk_button_new_with_label("💾 Cadastrar Carta");
    gtk_box_pack_start(GTK_BOX(controls_box), app.btn_cadastrar, FALSE, FALSE, 10);
    g_signal_connect(app.btn_cadastrar, "clicked", G_CALLBACK(on_cadastrar_carta), NULL);
    
    app.btn_salvar = gtk_button_new_with_label("💾 Salvar Cartas");
    gtk_box_pack_start(GTK_BOX(controls_box), app.btn_salvar, FALSE, FALSE, 5);
    g_signal_connect(app.btn_salvar, "clicked", G_CALLBACK(on_salvar), NULL);
    
    app.btn_carregar = gtk_button_new_with_label("📂 Carregar Cartas");
    gtk_box_pack_start(GTK_BOX(controls_box), app.btn_carregar, FALSE, FALSE, 5);
    g_signal_connect(app.btn_carregar, "clicked", G_CALLBACK(on_carregar), NULL);
    
    // Painel direito - Exibição da carta
    GtkWidget *display_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(editor_box), display_box, TRUE, TRUE, 0);
    
    GtkWidget *carta_display_label = gtk_label_new("📋 Informações da Carta:");
    gtk_widget_set_name(carta_display_label, "subtitle");
    gtk_box_pack_start(GTK_BOX(display_box), carta_display_label, FALSE, FALSE, 5);
    
    app.label_carta = gtk_label_new("");
    gtk_widget_set_name(app.label_carta, "stats");
    gtk_label_set_justify(GTK_LABEL(app.label_carta), GTK_JUSTIFY_LEFT);
    gtk_box_pack_start(GTK_BOX(display_box), app.label_carta, TRUE, TRUE, 0);
    
    // Estatísticas
    GtkWidget *stats_label = gtk_label_new("📊 Estatísticas Gerais:");
    gtk_widget_set_name(stats_label, "subtitle");
    gtk_box_pack_start(GTK_BOX(display_box), stats_label, FALSE, FALSE, 5);
    
    app.label_estatisticas = gtk_label_new("");
    gtk_widget_set_name(app.label_estatisticas, "stats");
    gtk_label_set_justify(GTK_LABEL(app.label_estatisticas), GTK_JUSTIFY_LEFT);
    gtk_box_pack_start(GTK_BOX(display_box), app.label_estatisticas, TRUE, TRUE, 0);
    
    gtk_notebook_append_page(GTK_NOTEBOOK(app.notebook), editor_frame, gtk_label_new("📝 Editor"));
    
    // === ABA 2: COMPARADOR ===
    GtkWidget *comparador_frame = gtk_frame_new("⚔️ Comparador de Cartas");
    gtk_widget_set_name(comparador_frame, "card");
    
    GtkWidget *comparador_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_container_add(GTK_CONTAINER(comparador_frame), comparador_box);
    gtk_container_set_border_width(GTK_CONTAINER(comparador_box), 20);
    
    // Seleção de cartas para comparar
    GtkWidget *selecao_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    gtk_box_pack_start(GTK_BOX(comparador_box), selecao_box, FALSE, FALSE, 10);
    
    GtkWidget *carta1_label = gtk_label_new("🎯 Carta 1:");
    gtk_widget_set_name(carta1_label, "subtitle");
    gtk_box_pack_start(GTK_BOX(selecao_box), carta1_label, FALSE, FALSE, 5);
    
    app.combo1 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo1), app.cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo1), 0);
    gtk_box_pack_start(GTK_BOX(selecao_box), app.combo1, FALSE, FALSE, 5);
    
    GtkWidget *carta2_label = gtk_label_new("🎯 Carta 2:");
    gtk_widget_set_name(carta2_label, "subtitle");
    gtk_box_pack_start(GTK_BOX(selecao_box), carta2_label, FALSE, FALSE, 5);
    
    app.combo2 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo2), app.cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo2), 1);
    gtk_box_pack_start(GTK_BOX(selecao_box), app.combo2, FALSE, FALSE, 5);
    
    // Botões de comparação
    GtkWidget *botoes_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(comparador_box), botoes_box, FALSE, FALSE, 10);
    
    GtkWidget *btn_pop = gtk_button_new_with_label("👥 Comparar População");
    GtkWidget *btn_pib = gtk_button_new_with_label("💰 Comparar PIB");
    GtkWidget *btn_area = gtk_button_new_with_label("🗺️ Comparar Área");
    GtkWidget *btn_pontos = gtk_button_new_with_label("🏛️ Comparar Pontos");
    GtkWidget *btn_densidade = gtk_button_new_with_label("📊 Comparar Densidade");
    
    gtk_box_pack_start(GTK_BOX(botoes_box), btn_pop, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(botoes_box), btn_pib, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(botoes_box), btn_area, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(botoes_box), btn_pontos, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(botoes_box), btn_densidade, TRUE, TRUE, 5);
    
    g_signal_connect(btn_pop, "clicked", G_CALLBACK(on_comparar), "População");
    g_signal_connect(btn_pib, "clicked", G_CALLBACK(on_comparar), "PIB");
    g_signal_connect(btn_area, "clicked", G_CALLBACK(on_comparar), "Área");
    g_signal_connect(btn_pontos, "clicked", G_CALLBACK(on_comparar), "Pontos");
    g_signal_connect(btn_densidade, "clicked", G_CALLBACK(on_comparar), "Densidade");
    
    gtk_notebook_append_page(GTK_NOTEBOOK(app.notebook), comparador_frame, gtk_label_new("⚔️ Comparador"));
    
    // Inicializar exibição
    on_carta_changed(app.combo1, NULL);
    atualizar_estatisticas();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    
    // Inicializar dados
    inicializar_dados();
    
    // Aplicar CSS moderno
    aplicar_css_moderno();
    
    // Criar interface
    criar_interface();
    
    // Mostrar janela
    gtk_widget_show_all(app.window);
    
    // Executar loop principal
    gtk_main();
    
    return 0;
}
