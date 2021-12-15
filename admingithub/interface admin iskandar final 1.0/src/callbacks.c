#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "support.h"
#include "fonction.h"

int choix_admin=1;int check_etage_admin=0;
int check_jour_admin=0;

//-----------------------------------------------------------------------------------------------------------------///
void
on_ajout_button_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *entry_nom_admin;
GtkWidget *entry_id_admin;

util u;

entry_nom_admin=lookup_widget(button,"entry_nom_admin");
entry_id_admin=lookup_widget(button,"entry_id_admin");

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_admin)));

strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(entry_id_admin)));

switch (choix_admin)
    { case 1: strcpy(u.role,"admin");break;
      case 2: strcpy(u.role,"etudiant");break;
      case 3: strcpy(u.role,"foyer");break;
      case 4: strcpy(u.role,"restau");break;
      case 5: strcpy(u.role,"tech");break;
      case 6: strcpy(u.role,"nutr");break; 
   }
printf("%s  %s   %s",u.nom,u.id,u.role);

ajout("utilisateur.txt",u);
}


//--------------------------------------------------------------------------------------------------------------------------//
void
on_supprime_button_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *entry_id_admin;
GtkWidget *traitment_window_admin;
util u;
traitment_window_admin=lookup_widget(button,"traitment_window_admin");
entry_id_admin=lookup_widget(button,"entry_id");


strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(entry_id_admin)));

printf("%s \n", u.id);
supprime("utilisateur.txt",u);
}

//--------------------------------------------------------------------------------------------------------------------------------------//
void
on_recherche_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *entry_id_admin;
GtkWidget *traitment_window_admin;
GtkWidget  *exist_window_admin;
GtkWidget *not_exist_window_admin;
GtkWidget *treeviewexist;

int exist=0;

util u;
traitment_window_admin=lookup_widget(button,"traitment_window_admin");
entry_id_admin=lookup_widget(button,"entry_id");


strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(entry_id_admin)));


exist=recherche("utilisateur.txt",u);
if (exist==1) {
//remove("exist.txt");
exist_window_admin=lookup_widget(button,"exist_window_admin");
exist_window_admin = create_exist_window_admin();
gtk_widget_show (exist_window_admin);

treeviewexist=lookup_widget(exist_window_admin,"treeviewexist");
affiche("exist.txt",treeviewexist);


}
else {not_exist_window_admin = create_not_exist_window_admin();
             gtk_widget_show (not_exist_window_admin);}

}

//--------------------------------------------------------------------------------------------------------------------------------------//


void
on_modifie_button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *not_exist_window_admin;
GtkWidget *entry_nom_admin ;
GtkWidget *entry_id_admin;
GtkWindow *ajout_window_admin;
GtkWidget *entry_id_ancient_admin;
util u;
int exist;
char id_ancient_admin[30];
ajout_window_admin=lookup_widget(button,"ajout_window_admin");
entry_id_ancient_admin=lookup_widget(button,"entry_id_ancient_admin");
ajout_window_admin=lookup_widget(button,"ajout_window_admin");
entry_nom_admin=lookup_widget(button,"entry_nom_admin");
entry_id_admin=lookup_widget(button,"entry_id_admin");

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_admin)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(entry_id_admin)));
strcpy(id_ancient_admin,gtk_entry_get_text(GTK_ENTRY(entry_id_ancient_admin)));


switch (choix_admin)
    { case 1: strcpy(u.role,"admin");break;
      case 2: strcpy(u.role,"etudiant");break;
      case 3: strcpy(u.role,"foyer");break;
      case 4: strcpy(u.role,"restau");break;
      case 5: strcpy(u.role,"tech");break;
      case 6: strcpy(u.role,"nutr");break; 
   }
printf("%s  %s  %s  %s",u.nom,u.id,id_ancient_admin,u.role);



modifie("utilisateur.txt",u,id_ancient_admin);



}




//--------------------------------------------------------------------------------------------------------------------------------------------//
void
on_refresh_button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *affiche_window;
GtkWidget *w1;
GtkWidget *treeview;

w1=lookup_widget(button,"affiche_window");
affiche_window=create_affiche_window();
gtk_widget_show(affiche_window);
gtk_widget_hide(w1);
treeview=lookup_widget(affiche_window,"treeview");
vider(treeview);
affiche("utilisateur.txt",treeview);*/

GtkWidget *affiche_window_admin;
GtkWidget *treeview;
GtkWidget *w1;

w1=lookup_widget(button,"affiche_window_admin");
w1= create_affiche_window_admin();
gtk_widget_show (w1);

affiche_window_admin=lookup_widget(button,"affiche_window_admin");

treeview=lookup_widget(affiche_window_admin,"treeview_admin");
affiche("utilisateur.txt",treeview);




treeview=lookup_widget(w1,"treeview");
gtk_widget_show(w1);
affiche("utilisateur.txt",treeview);
gtk_widget_hide(affiche_window_admin);


}
//-------------------------------------------------------------------------------------------------------------------------------//





//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void
on_nutr_radio_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=6;
}


void
on_tech_radio_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=5;
}


void
on_restau_radio_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=4;
}


void
on_foyer_radio_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=3;
}


void
on_etudiant_radio_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=2;
}


void
on_admin_radio_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  choix_admin=1;
}

//---------------------------------------------------------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* role;
util u;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&role,-1);
strcpy(u.id,id);
strcpy(u.nom,nom);
strcpy(u.role,role);
supprime("utilisateur.txt",u);
affiche("utilisateur.txt",treeview);

}

}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//




void
on_menu_modifie_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_window_admin;

ajout_window_admin = create_ajout_window_admin();
gtk_widget_show (ajout_window_admin);



GtkWidget *menu_window_admin;
menu_window_admin=lookup_widget(button,"menu_window_admin");

}


void
on_menu_ajout_button_admin_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_window_admin;

ajout_window_admin = create_ajout_window_admin();
gtk_widget_show (ajout_window_admin);




GtkWidget *menu_window_admin;
menu_window_admin=lookup_widget(button,"menu_window_admin");
//gtk_widget_hide(menu_window_admin);
}


void
on_menu_supprime_button_admin_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *traitment_window_admin;

traitment_window_admin = create_traitment_window_admin();
gtk_widget_show (traitment_window_admin);

GtkWidget *menu_window_admin;
menu_window_admin=lookup_widget(button,"menu_window_admin");

}


void
on_menu_recherche_button_admin_clicked (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *traitment_window_admin;

traitment_window_admin = create_traitment_window_admin();
gtk_widget_show (traitment_window_admin);


GtkWidget *menu_window_admin;
menu_window_admin=lookup_widget(button,"menu_window_admin");


}


void
on_menu_affiche_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche_window_admin;
GtkWidget *treeview;
GtkWidget *menu_window_admin;


affiche_window_admin=lookup_widget(button,"affiche_window_admin");
affiche_window_admin = create_affiche_window_admin();
gtk_widget_show (affiche_window_admin);

treeview=lookup_widget(affiche_window_admin,"treeview");
affiche("utilisateur.txt",treeview);
//-----//
/*window1=lookup_widget(button,"window1");
window1 = create_window1();
gtk_widget_show (window1);

treeview1=lookup_widget(window1,"treeview1");
affichepanne("panneE.txt",treeview1);*/

//--//

menu_window_admin=lookup_widget(button,"menu_window_admin");


}








//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


void
on_return_ajout_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_window_admin;
menu_window_admin = create_menu_window_admin ();
 gtk_widget_show (menu_window_admin);

GtkWidget *ajout_window_admin;
ajout_window_admin=lookup_widget(button,"ajout_window_admin");
gtk_widget_hide(ajout_window_admin);
}


void
on_return_traitment_button_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_window_admin;
menu_window_admin = create_menu_window_admin ();
 gtk_widget_show (menu_window_admin);

GtkWidget *traitment_window_admin;
traitment_window_admin=lookup_widget(button,"traitment_window_admin");
gtk_widget_hide(traitment_window_admin);
}


void
on_return_affiche_button_admin_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_window_admin;
menu_window_admin = create_menu_window_admin ();
 gtk_widget_show (menu_window_admin);

GtkWidget *affiche_window_admin;
affiche_window_admin=lookup_widget(button,"affiche_window_admin");
gtk_widget_hide(affiche_window_admin);



}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void
on_treeviewexist_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeviewpanne_row_activated         (GtkTreeView     *treeviewpanneadmin,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jour;
gchar* heure;
gchar* etage;
gchar* valeur;
eau p;
GtkTreeModel *model=gtk_tree_view_get_model(treeviewpanneadmin);

if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&heure,2,&etage,3,&valeur,-1);

}}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/*void
on_panne_button_admin_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeviewpanne;
GtkWidget *panne_window_admin;


panne_window_admin=lookup_widget(button,"panne_window_admin");
panne_window_admin = create_panne_window_admin();
gtk_widget_show (panne_window_admin);
//treeviewpanne=lookup_widget(panne_window_admin,"treeviewpanne");
//affichePANNE("debit.txt",treeviewpanne);


}*/







void
on_menu_panne_button_admin_clicked     (GtkWidget       *object,
                                        gpointer         user_data)
{
GtkWidget *panne_recherche_window_admin;
GtkWidget *combobox_admin;


panne_recherche_window_admin = create_panne_recherche_window_admin();
gtk_widget_show (panne_recherche_window_admin);

combobox_admin=lookup_widget(object,"combobox_admin");
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_admin),1);


}


void
on_return_panne_button_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *panne_recherche_window_admin;
panne_recherche_window_admin = create_panne_recherche_window_admin();
gtk_widget_show (panne_recherche_window_admin);*/


//open choix de recherche panne window
GtkWidget *panne_window_admin;
panne_window_admin=lookup_widget(button,"panne_window_admin");
gtk_widget_hide(panne_window_admin);




}


void
on_panne_button_admin_clicked          (GtkWidget  *object,
                                        gpointer         user_data)
{
//open treeview de panne window

GtkWidget *panne_window_admin;
GtkWidget *treeviewpanneadmin;
GtkWidget *spinbutton_admin;
GtkWidget *combobox_admin;
GtkWidget *window1_admin;
GtkWidget *treeview1_admin;


int jour;
char etage[5];


spinbutton_admin=lookup_widget(object,"spinbutton_admin");
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_admin));

/*panne_window_admin = create_panne_window_admin();
gtk_widget_show (panne_window_admin);*/

if (check_etage_admin==0){printf("etage not checked\n");}
if(check_jour_admin==0){printf("jour not checked\n");}

                   
if((check_etage_admin==1)&&(check_jour_admin==0)){printf("etage checked \n");
combobox_admin=lookup_widget(object,"combobox_admin");
strcpy(etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_admin)));

printf("%d \n ",atoi(etage));
panneetage("debit.txt","panneE.txt",atoi(etage));

window1_admin=lookup_widget(object,"window1_admin");
window1_admin = create_window1_admin();
gtk_widget_show (window1_admin);

treeview1_admin=lookup_widget(window1_admin,"treeview1_admin");
affichepanne("panneE.txt",treeview1_admin);


/*panne_window_admin=lookup_widget(object,"panne_window_admin");
panne_window_admin= create_panne_window_admin();
gtk_widget_show (panne_window_admin);

treeviewpanneadmin=lookup_widget(panne_window_admin,"treeviewpanneadmin");
affiche("utilisateur.txt",treeviewpanneadmin);*/
         }
if((check_jour_admin==1)&&(check_etage_admin==0)){printf("jour checked\n");


printf("jour equals= %d \n",jour);
pannejour("debit.txt","panneJ.txt",jour);

window1_admin=lookup_widget(object,"window1_admin");
window1_admin = create_window1_admin();
gtk_widget_show (window1_admin);

treeview1_admin=lookup_widget(window1_admin,"treeview1_admin");
affichepanne("panneJ.txt",treeview1_admin);

/*panne_window_admin=lookup_widget(button,"panne_window_admin");
panne_window_admin = create_panne_window_admin();
gtk_widget_show (panne_window_admin);*/
/*treeviewpanne=lookup_widget(panne_window_admin,"treeviewpanne");
printf("avant affichepanne");*/
//affichepanne("panneh.txt",treeviewpanne);
}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//



void
on_checkbutton_jour_admin_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

check_jour_admin=1;
else check_jour_admin=0;
}




void
on_checkbutton_etage_admin_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

check_etage_admin=1;
else check_etage_admin=0;

}




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

