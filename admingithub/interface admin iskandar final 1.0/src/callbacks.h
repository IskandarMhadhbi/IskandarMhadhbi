#include <gtk/gtk.h>


void
on_ajout_button_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprime_button_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifie_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_refresh_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_window_button_enter                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_nutr_radio_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_tech_radio_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_restau_radio_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_foyer_radio_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_etudiant_radio_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_admin_radio_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajout_check_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_supprime_check_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifie_check_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_recherche_check_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_affiche_check_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifie_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_check_activate            (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_modifie_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_ajout_button_admin_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_supprime_button_admin_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_recherche_button_admin_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_affiche_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_ajout_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_traitment_button_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_affiche_button_admin_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewexist_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewpanne_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affiche_panne_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);


void
on_menu_panne_button_admin_clicked     (GtkWidget *object,
                                        gpointer         user_data);

void
on_return_panne_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_panne_button_admin_clicked          (GtkWidget       *object,
                                        gpointer         user_data);

void
on_checkbutton_jour_admin_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_heure_admin_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_jour_admin_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_etage_admin_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
