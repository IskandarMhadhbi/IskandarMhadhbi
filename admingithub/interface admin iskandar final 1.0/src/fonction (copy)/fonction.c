#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

void ajout (char nomfichier[],util u)
{

FILE *f=NULL;
printf(" donner le nom\n");
scanf("%s",u.nom);
do{printf(" donner l'id \n");
scanf("%d",&u.id);fflush(stdin);}while(recherche(nomfichier, u)==1);
do{printf("donner le role \n");
   scanf("%s",u.role);}while((strcmp(u.role,"admin")==0)&& (strcmp(u.role,"tech")==0)&& (strcmp(u.role,"nutr")==0)&& (strcmp(u.role,"foyer")==0)&& (strcmp(u.role,"restau")==0)&& (strcmp(u.role,"etudiant")==0));
fflush(stdin);
f=fopen(nomfichier,"a+");
if (f!=NULL)
fprintf(f,"%s %d %s \n" ,u.nom,u.id,u.role);
fclose(f);
}



void supprime (char nomfichier[],util u)
{
FILE *f=NULL;
FILE *w=NULL;
int b,a,test=0;
char ch1[30],ch2[30] ;
printf("donner l'id utilisateur a supprimer\n");
scanf("%d",&b);
f=fopen("utilisateur.txt","r");
w=fopen("nouveaufichier.txt","a+");
if (f!=NULL)
{
   while(fscanf(f,"%s %d %s \n",ch1,&a,ch2)!=EOF)
       {

         if(a!=b)
             fprintf(w,"%s %d %s\n",ch1,a,ch2);
         else
             test=1;

         }
        }    
        fclose(f);
        fclose(w);
remove("utilisateur.txt");
rename("nouveaufichier.txt","utilisateur.txt");
if (test==0)
{
printf("user not found\n");
}
}


void modifie (char nomfichier[],util u)
 {
        FILE *f=NULL;
        FILE *new=NULL;
        char ch1[30],ch2[30];
        int a,test=0,b;
        printf("donner l'id utilisateur \n");
        scanf("%d",&b);
        f=fopen("utilisateur.txt","r");
        new=fopen("new.txt","a+");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %d  %s\n",ch1,&a,ch2)!=EOF)
            {

                if (a!=b)
                    fprintf(new,"%s %d %s \n",ch1,a,ch2);
                else
                {
                   printf("donner les nouveau donnees\n");
                   scanf("%s %d %s",u.nom,&u.id,u.role);
                   fprintf(new,"%s %d %s\n",u.nom,u.id,u.role);
                   test=1;
                }
            }
        }
        if (test==0)
       { printf("utilisateur non existant\n");
       }
        fclose(f);
        fclose(new);
        remove("utilisateur.txt");
        rename("new.txt","utilisateur.txt");
     }


int recherche  (char nomfichier[],util u)
 {
        FILE *f=NULL;
        char ch1[30],ch2[30];
        int b,a,test=0;
        printf("donner l'id  d'utilisateur de verifier l'existance\n");
        scanf("%d",&b);
        f=fopen("utilisateur.txt","r");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %d %s \n",ch1,&a,ch2)!=EOF){



                if (a==b)
                {
                printf("les donnees :  ");
                printf("nom:%s |id:%d  |role:%s \n ", ch1,a,ch2);   
                test=1;
                }
               
        }
        }
        if (test==0) printf("user not found\n");
        fclose(f);
        return test;
   }

void affiche (char nomfichier[])
{
FILE *f=NULL;
int a;
char ch1[30],ch2[30];
f=fopen("utilisateur.txt","r");
if (f!=NULL)
{
   while(fscanf(f,"%s %d %s \n",ch1,&a,ch2)!=EOF)
{
             printf("|nom| **%s** |id|**%d**|role| **%s**\n",ch1,a,ch2);
}    
}fflush(stdin);
fclose(f);
}

