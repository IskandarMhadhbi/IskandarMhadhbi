
#ifndef FONCTION_H_
#define FONCTION_H_


typedef struct utilisateur{char nom[30] ;
                           int id;
                           char role[10];}util;

void ajout (char nomfichier[],util u); 
void supprime (char nomfichier[],util u); 
void modifie (char nomfichier[],util u); 
int recherche (char nomfichier[],util u);        
void affiche (char nomfichier[]);



#endif





