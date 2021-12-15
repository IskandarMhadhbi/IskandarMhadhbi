
#ifndef FONCTION_H_
#define FONCTION_H_
#include <gtk/gtk.h>

typedef struct utilisateur{char nom[30] ;
                           char id[30];
                           char role[10];}util;
typedef struct panne{char jour[20];
                     char heure[20];
                     char etage[5];
                     char valeur[20];}eau;


void ajout (char nomfichier[],util u); 
void supprime (char nomfichier[],util u); 
void modifie (char nomfichier[],util u,char id_ancient[]); 
int recherche (char nomfichier[],util u);        
void affiche (char nomfichier[],GtkWidget *KLtreeview);

void affichepanne (char nomfichier[],GtkWidget *KLtreeview);
void panneetage(char nomfichier1[],char nomfichier2[],int etageadmin);
void pannejour(char nomfichier1[],char nomfichier2[],int jouradmin);


#endif





