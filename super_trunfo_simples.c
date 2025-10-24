#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct {
    GtkWidget *window;
    GtkWidget *combo1, *combo2;
    GtkWidget *entry_estado, *entry_populacao, *entry_pib, *entry_area, *entry_pontos;
    GtkWidget *label_carta;
    int carta_atual;
} AppWidgets;

AppWidgets app;

void atualizar_densidade() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        if (cartas[i].area > 0) {
            cartas[i].densidade_populacional = (double)cartas[i].populacao / cartas[i].area;
        }
    }
}

void atualizar_label() {
    char info[300];
    snprintf(info, 300, "Carta: %s\nPopulação: %lld\nPIB: %.2lf bilhões\nÁrea: %.2lf km²\nPontos Turísticos: %d\nDensidade: %.2lf hab/km²",
             cartas[app.carta_atual].estado, cartas[app.carta_atual].populacao, cartas[app.carta_atual].pib,
             cartas[app.carta_atual].area, cartas[app.carta_atual].pontos_turisticos,
             cartas[app.carta_atual].densidade_populacional);
    gtk_label_set_text(GTK_LABEL(app.label_carta), info);
}

void on_combo_changed(GtkWidget *combo, gpointer data) {
    app.carta_atual = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));
    gtk_entry_set_text(GTK_ENTRY(app.entry_estado), cartas[app.carta_atual].estado);
    
    char temp[30];
    snprintf(temp, 30, "%lld", cartas[app.carta_atual].populacao);
    gtk_entry_set_text(GTK_ENTRY(app.entry_populacao), temp);
    
    snprintf(temp, 30, "%.2lf", cartas[app.carta_atual].pib);
    gtk_entry_set_text(GTK_ENTRY(app.entry_pib), temp);
    
    snprintf(temp, 30, "%.2lf", cartas[app.carta_atual].area);
    gtk_entry_set_text(GTK_ENTRY(app.entry_area), temp);
    
    snprintf(temp, 30, "%d", cartas[app.carta_atual].pontos_turisticos);
    gtk_entry_set_text(GTK_ENTRY(app.entry_pontos), temp);
    
    atualizar_label();
}

void on_cadastrar_clicked(GtkWidget *button, gpointer data) {
    const char *estado = gtk_entry_get_text(GTK_ENTRY(app.entry_estado));
    const char *pop_str = gtk_entry_get_text(GTK_ENTRY(app.entry_populacao));
    const char *pib_str = gtk_entry_get_text(GTK_ENTRY(app.entry_pib));
    const char *area_str = gtk_entry_get_text(GTK_ENTRY(app.entry_area));
    const char *pontos_str = gtk_entry_get_text(GTK_ENTRY(app.entry_pontos));
    
    if (strlen(estado) == 0 || atoll(pop_str) <= 0 || atof(pib_str) <= 0 || 
        atof(area_str) <= 0 || atoi(pontos_str) < 0) {
        
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "Valores inválidos! Verifique os dados.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    strncpy(cartas[app.carta_atual].estado, estado, 49);
    cartas[app.carta_atual].estado[49] = '\0';
    cartas[app.carta_atual].populacao = atoll(pop_str);
    cartas[app.carta_atual].pib = atof(pib_str);
    cartas[app.carta_atual].area = atof(area_str);
    cartas[app.carta_atual].pontos_turisticos = atoi(pontos_str);
    
    atualizar_densidade();
    atualizar_label();
}

void on_compare_clicked(GtkWidget *button, gpointer data) {
    const char *atributo = (const char *)data;
    int idx1 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo1));
    int idx2 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo2));
    
    if (idx1 == idx2) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, 
            "Selecione cartas diferentes!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    double attr1, attr2;
    if (strcmp(atributo, "População") == 0) { 
        attr1 = cartas[idx1].populacao; 
        attr2 = cartas[idx2].populacao; 
    }
    else if (strcmp(atributo, "PIB") == 0) { 
        attr1 = cartas[idx1].pib; 
        attr2 = cartas[idx2].pib; 
    }
    else if (strcmp(atributo, "Área") == 0) { 
        attr1 = cartas[idx1].area; 
        attr2 = cartas[idx2].area; 
    }
    else if (strcmp(atributo, "Pontos") == 0) { 
        attr1 = cartas[idx1].pontos_turisticos; 
        attr2 = cartas[idx2].pontos_turisticos; 
    }
    else if (strcmp(atributo, "Densidade") == 0) { 
        attr1 = cartas[idx1].densidade_populacional; 
        attr2 = cartas[idx2].densidade_populacional; 
    }
    else return;
    
    char resultado[300];
    const char *vencedor;
    
    if (attr1 > attr2) {
        vencedor = cartas[idx1].estado;
    } else if (attr2 > attr1) {
        vencedor = cartas[idx2].estado;
    } else {
        vencedor = "Empate!";
    }
    
    snprintf(resultado, 300,
        "Comparação de %s:\n\n%s: %.2lf\n%s: %.2lf\n\nVencedor: %s",
        atributo, cartas[idx1].estado, attr1, cartas[idx2].estado, attr2, vencedor);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", resultado);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_salvar_clicked(GtkWidget *button, gpointer data) {
    FILE *arquivo = fopen("cartas_salvas.txt", "w");
    if (arquivo == NULL) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "Erro ao salvar arquivo!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    for (int i = 0; i < NUM_CARTAS; i++) {
        fprintf(arquivo, "%s;%lld;%.2lf;%.2lf;%d;%.2lf\n",
                cartas[i].estado, cartas[i].populacao, cartas[i].pib,
                cartas[i].area, cartas[i].pontos_turisticos, cartas[i].densidade_populacional);
    }
    fclose(arquivo);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
        "Cartas salvas com sucesso!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_carregar_clicked(GtkWidget *button, gpointer data) {
    FILE *arquivo = fopen("cartas_salvas.txt", "r");
    if (arquivo == NULL) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "Arquivo não encontrado!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
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
    
    on_combo_changed(app.combo1, NULL);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), 
        GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
        "%d cartas carregadas!", i);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    atualizar_densidade();
    
    app.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app.window), "🇧🇷 Super Trunfo Brasil - Edição Moderna");
    gtk_window_set_default_size(GTK_WINDOW(app.window), 800, 600);
    g_signal_connect(app.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(app.window), grid);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    
    // Título
    GtkWidget *title = gtk_label_new("🇧🇷 Super Trunfo dos Estados do Brasil");
    gtk_widget_set_name(title, "title");
    gtk_grid_attach(GTK_GRID(grid), title, 0, 0, 4, 1);
    
    // Seleção de carta
    GtkWidget *carta_label = gtk_label_new("Selecione uma carta:");
    gtk_grid_attach(GTK_GRID(grid), carta_label, 0, 1, 1, 1);
    
    app.combo1 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo1), cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo1), 0);
    gtk_grid_attach(GTK_GRID(grid), app.combo1, 1, 1, 1, 1);
    g_signal_connect(app.combo1, "changed", G_CALLBACK(on_combo_changed), NULL);
    
    // Campos de entrada
    GtkWidget *estado_label = gtk_label_new("Estado:");
    gtk_grid_attach(GTK_GRID(grid), estado_label, 0, 2, 1, 1);
    app.entry_estado = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), app.entry_estado, 1, 2, 1, 1);
    
    GtkWidget *pop_label = gtk_label_new("População:");
    gtk_grid_attach(GTK_GRID(grid), pop_label, 0, 3, 1, 1);
    app.entry_populacao = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), app.entry_populacao, 1, 3, 1, 1);
    
    GtkWidget *pib_label = gtk_label_new("PIB (bilhões):");
    gtk_grid_attach(GTK_GRID(grid), pib_label, 0, 4, 1, 1);
    app.entry_pib = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), app.entry_pib, 1, 4, 1, 1);
    
    GtkWidget *area_label = gtk_label_new("Área (km²):");
    gtk_grid_attach(GTK_GRID(grid), area_label, 0, 5, 1, 1);
    app.entry_area = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), app.entry_area, 1, 5, 1, 1);
    
    GtkWidget *pontos_label = gtk_label_new("Pontos Turísticos:");
    gtk_grid_attach(GTK_GRID(grid), pontos_label, 0, 6, 1, 1);
    app.entry_pontos = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), app.entry_pontos, 1, 6, 1, 1);
    
    // Botão cadastrar
    GtkWidget *btn_cadastrar = gtk_button_new_with_label("💾 Cadastrar Carta");
    gtk_grid_attach(GTK_GRID(grid), btn_cadastrar, 0, 7, 2, 1);
    g_signal_connect(btn_cadastrar, "clicked", G_CALLBACK(on_cadastrar_clicked), NULL);
    
    // Exibição da carta
    app.label_carta = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), app.label_carta, 2, 1, 2, 6);
    on_combo_changed(app.combo1, NULL);
    
    // Comparador
    GtkWidget *comp_label = gtk_label_new("Comparar Cartas:");
    gtk_grid_attach(GTK_GRID(grid), comp_label, 0, 8, 2, 1);
    
    app.combo2 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo2), cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo2), 1);
    gtk_grid_attach(GTK_GRID(grid), app.combo2, 2, 8, 1, 1);
    
    // Botões de comparação
    GtkWidget *btn_pop = gtk_button_new_with_label("👥 População");
    GtkWidget *btn_pib = gtk_button_new_with_label("💰 PIB");
    GtkWidget *btn_area = gtk_button_new_with_label("🗺️ Área");
    GtkWidget *btn_pontos = gtk_button_new_with_label("🏛️ Pontos");
    GtkWidget *btn_densidade = gtk_button_new_with_label("📊 Densidade");
    
    gtk_grid_attach(GTK_GRID(grid), btn_pop, 0, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_pib, 1, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_area, 2, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_pontos, 3, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_densidade, 0, 10, 1, 1);
    
    g_signal_connect(btn_pop, "clicked", G_CALLBACK(on_compare_clicked), "População");
    g_signal_connect(btn_pib, "clicked", G_CALLBACK(on_compare_clicked), "PIB");
    g_signal_connect(btn_area, "clicked", G_CALLBACK(on_compare_clicked), "Área");
    g_signal_connect(btn_pontos, "clicked", G_CALLBACK(on_compare_clicked), "Pontos");
    g_signal_connect(btn_densidade, "clicked", G_CALLBACK(on_compare_clicked), "Densidade");
    
    // Botões de arquivo
    GtkWidget *btn_salvar = gtk_button_new_with_label("💾 Salvar");
    GtkWidget *btn_carregar = gtk_button_new_with_label("📂 Carregar");
    gtk_grid_attach(GTK_GRID(grid), btn_salvar, 1, 10, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_carregar, 2, 10, 1, 1);
    g_signal_connect(btn_salvar, "clicked", G_CALLBACK(on_salvar_clicked), NULL);
    g_signal_connect(btn_carregar, "clicked", G_CALLBACK(on_carregar_clicked), NULL);
    
    gtk_widget_show_all(app.window);
    gtk_main();
    
    return 0;
}
