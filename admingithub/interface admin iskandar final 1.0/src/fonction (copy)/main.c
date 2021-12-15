#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <string.h>

int main()
{

util u;
int a,b,menu;
char ch1[30],ch2[30];

do{printf("1-ajout utilisateur \n2-supprimer utilisateur \n3-modifier utilisateur \n4-recherche ulilisateur \n5-affichier les utilisatuer \n0-quitter\n");
   do{printf("select le choix \n ");
      fflush(stdin);
      scanf("%d",&menu);}while((menu<0)&&(menu>5));
   switch (menu)
   {case 1: {ajout ("utilisateur.txt", u); break;}
    case 2: {supprime ("utilisateur.txt", u); break;}
    case 3: {modifie ("utilisateur.txt",u); break;}
    case 4: {recherche ("utilisateur.txt", u); break;}         
    case 5: {affiche ("utilisateur.txt"); break;}
   }
}while (menu!=0);
return 0;
}
