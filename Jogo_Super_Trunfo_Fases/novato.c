#include <gtk/gtk.h>
#include <string.h>

#define NUM_CARTAS 27 // 26 estados + Distrito Federal

typedef struct {
    char estado[50];
    long long populacao;
    double pib;
    double area;
    int pontos_turisticos;
    double densidade_populacional;
} Carta;

// Dados iniciais fictícios para os 27 estados/DF
Carta cartas[NUM_CARTAS] = {
    {"Acre", 900000, 15.5, 164123, 10, 0},
    {"Alagoas", 3300000, 60.2, 27778, 15, 0},
    {"Amapá", 850000, 14.8, 142829, 8, 0},
    {"Amazonas", 4200000, 90.1, 1559167, 20, 0},
    {"Bahia", 14800000, 300.5, 564733, 30, 0},
    {"Ceará", 9100000, 200.3, 148921, 25, 0},
    {"Distrito Federal", 3000000, 250.0, 5802, 12, 0},
    {"Espírito Santo", 4000000, 120.4, 46095, 18, 0},
    {"Goiás", 7100000, 210.7, 340112, 22, 0},
    {"Maranhão", 7000000, 130.9, 331937, 14, 0},
    {"Mato Grosso", 3500000, 150.6, 903366, 16, 0},
    {"Mato Grosso do Sul", 2800000, 110.8, 357145, 13, 0},
    {"Minas Gerais", 21100000, 600.2, 586522, 35, 0},
    {"Pará", 8600000, 220.5, 1247955, 19, 0},
    {"Paraíba", 4000000, 90.3, 56467, 17, 0},
    {"Paraná", 11500000, 400.8, 199307, 28, 0},
    {"Pernambuco", 9500000, 250.1, 98312, 24, 0},
    {"Piauí", 3200000, 70.4, 251577, 11, 0},
    {"Rio de Janeiro", 17200000, 650.9, 43780, 40, 0},
    {"Rio Grande do Norte", 3500000, 100.2, 52797, 16, 0},
    {"Rio Grande do Sul", 11300000, 450.7, 281730, 27, 0},
    {"Rondônia", 1800000, 50.6, 237765, 9, 0},
    {"Roraima", 600000, 12.3, 224300, 7, 0},
    {"Santa Catarina", 7200000, 300.5, 95736, 23, 0},
    {"São Paulo", 46000000, 1550.5, 248209, 50, 0},
    {"Sergipe", 2300000, 60.8, 21915, 12, 0},
    {"Tocantins", 1600000, 40.9, 277423, 10, 0}
};

// Estrutura para armazenar widgets
typedef struct {
    GtkWidget *window;
    GtkWidget *combo1, *combo2; // Seleção de cartas para comparar
} AppWidgets;

AppWidgets app;

void atualizar_densidade() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        if (cartas[i].area > 0) {
            cartas[i].densidade_populacional = (double)cartas[i].populacao / cartas[i].area;
        }
    }
}

void on_compare_clicked(GtkWidget *button, gpointer data) {
    const char *atributo = (const char *)data;
    int idx1 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo1));
    int idx2 = gtk_combo_box_get_active(GTK_COMBO_BOX(app.combo2));
    if (idx1 == idx2) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Selecione cartas diferentes!");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    double attr1, attr2;
    if (strcmp(atributo, "População") == 0) { attr1 = cartas[idx1].populacao; attr2 = cartas[idx2].populacao; }
    else if (strcmp(atributo, "PIB") == 0) { attr1 = cartas[idx1].pib; attr2 = cartas[idx2].pib; }
    else if (strcmp(atributo, "Área") == 0) { attr1 = cartas[idx1].area; attr2 = cartas[idx2].area; }
    else if (strcmp(atributo, "Pontos") == 0) { attr1 = cartas[idx1].pontos_turisticos; attr2 = cartas[idx2].pontos_turisticos; }
    else if (strcmp(atributo, "Densidade") == 0) { attr1 = cartas[idx1].densidade_populacional; attr2 = cartas[idx2].densidade_populacional; }
    else return;

    char resultado[200];
    if (attr1 > attr2) {
        snprintf(resultado, 200, "%s vence!", cartas[idx1].estado);
    } else if (attr2 > attr1) {
        snprintf(resultado, 200, "%s vence!", cartas[idx2].estado);
    } else {
        snprintf(resultado, 200, "Empate!");
    }

    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app.window), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", resultado);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    atualizar_densidade();

    app.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app.window), "Super Trunfo - Nível Novato");
    gtk_window_set_default_size(GTK_WINDOW(app.window), 400, 300);
    g_signal_connect(app.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(app.window), grid);

    // Combo box para selecionar carta 1
    app.combo1 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo1), cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo1), 0);
    gtk_grid_attach(GTK_GRID(grid), app.combo1, 0, 0, 1, 1);

    // Combo box para selecionar carta 2
    app.combo2 = gtk_combo_box_text_new();
    for (int i = 0; i < NUM_CARTAS; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(app.combo2), cartas[i].estado);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app.combo2), 1);
    gtk_grid_attach(GTK_GRID(grid), app.combo2, 1, 0, 1, 1);

    // Botões de comparação
    GtkWidget *btn_pop = gtk_button_new_with_label("Comparar População");
    GtkWidget *btn_pib = gtk_button_new_with_label("Comparar PIB");
    GtkWidget *btn_area = gtk_button_new_with_label("Comparar Área");
    GtkWidget *btn_pontos = gtk_button_new_with_label("Comparar Pontos Turísticos");
    GtkWidget *btn_densidade = gtk_button_new_with_label("Comparar Densidade");

    gtk_grid_attach(GTK_GRID(grid), btn_pop, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_pib, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_area, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_pontos, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_densidade, 1, 2, 1, 1);

    g_signal_connect(btn_pop, "clicked", G_CALLBACK(on_compare_clicked), "População");
    g_signal_connect(btn_pib, "clicked", G_CALLBACK(on_compare_clicked), "PIB");
    g_signal_connect(btn_area, "clicked", G_CALLBACK(on_compare_clicked), "Área");
    g_signal_connect(btn_pontos, "clicked", G_CALLBACK(on_compare_clicked), "Pontos");
    g_signal_connect(btn_densidade, "clicked", G_CALLBACK(on_compare_clicked), "Densidade");

    gtk_widget_show_all(app.window);
    gtk_main();

    return 0;
}