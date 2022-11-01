#include <stdio.h>

#include <gtk/gtk.h>

static void on_btn_clicked(GtkWidget *widget, gpointer data)
{
    g_print("button clicked.\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget * window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "ae executor");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    GtkWidget *bt_1 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(window), bt_1);

    GtkWidget *btn_1 = gtk_button_new_with_label("hello world");
    g_signal_connect(btn_1, "clicked", G_CALLBACK(on_btn_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(bt_1), btn_1);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    // create a new application.
    app = gtk_application_new("com.ae.executor", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return 0;
}