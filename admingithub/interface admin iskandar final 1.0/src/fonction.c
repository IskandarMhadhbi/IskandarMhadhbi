#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>
enum{

ID , NOM, ROLE,COLUMNS
};
enum{JOUR,HEURE,ETAGE,VALEUR,COLUMNS2,};



void ajout (char nomfichier[],util u)
{

FILE *f=NULL;
f=fopen(nomfichier,"a+");
if (f!=NULL)
fprintf(f,"%s %s %s \n" ,u.nom,u.id,u.role);
printf(" %s  %s  %s   \n",u.nom,u.id,u.role); 
fclose(f);

}



void supprime (char nomfichier[],util u)
{
FILE *f=NULL;
FILE *w=NULL;

char ch1[30],ch2[30],ch_id[30] ;

f=fopen("utilisateur.txt","r");
w=fopen("nouveaufichier.txt","a+");
printf("%s",u.id);
if (f!=NULL)
{
   while(fscanf(f,"%s %s %s \n",ch1,ch_id,ch2)!=EOF)
       {

         if(strcmp(u.id,ch_id)!=0)
             fprintf(w,"%s %s %s\n",ch1,ch_id,ch2);
        
         
        }    
        fclose(f);
        fclose(w);
remove("utilisateur.txt");
rename("nouveaufichier.txt","utilisateur.txt");
}
}



void modifie (char nomfichier[],util u,char id_ancient[])
 {
        FILE *f=NULL;
        FILE *new=NULL;
        char ch1[30],ch2[30],ch_id[30];//,id_ancient[30];
        

        f=fopen("utilisateur.txt","r");
        new=fopen("new.txt","a+");
        printf("  %s  %s  %s  %s  \n",u.nom,u.id,id_ancient,u.role);
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s  %s\n",ch1,ch_id,ch2)!=EOF)
            {

                if (strcmp(id_ancient,ch_id)!=0)
                    fprintf(new,"%s %s %s \n",ch1,ch_id,ch2);
                else
                {
                   printf("donner les nouveau donnees\n");
                   
                   fprintf(new,"%s %s %s\n",u.nom,u.id,u.role);
                 
                }
            }
        }
        
        fclose(f);
        fclose(new);
        remove("utilisateur.txt");
        rename("new.txt","utilisateur.txt");
     }





int recherche  (char nomfichier[],util u)
 {
        FILE *w=NULL;
        FILE *f=NULL;
        char ch1[30],ch2[30],ch_id[30];
        int b,a,test=0;
        //printf("donner l'id  d'utilisateur de verifier l'existance\n");
       // scanf("%d",&b);
        f=fopen("utilisateur.txt","r");
        w=fopen("exist.txt","w");
        if(f!=NULL) 
        {
            while(fscanf(f,"%s %s %s \n",ch1,ch_id,ch2)!=EOF && test==0){

                if (strcmp(u.id,ch_id)==0)
                {
                printf("les donnees :  ");
                printf("nom:%s |id:%s  |role:%s \n ", ch1,ch_id,ch2);   
                test=1;
	        
		if (w!=NULL){
                fprintf(w,"%s %s %s \n" ,ch1,ch_id,ch2);}
                }
               
        }
        }
        if (test==0) printf("user not found\n");
        fclose(f);fclose(w);
        return test;
   }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


void affiche (char nomfichier[],GtkWidget *KLtreeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
//gtk_list_store_clear(KLtreeview);

util u;
 store=NULL;
store=gtk_tree_view_get_model(KLtreeview);
FILE *f=NULL;

char ch1[30],ch2[30],ch_id[30];
char id[30];
char nom[30];
char role[30];
if(store==NULL)
{


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


f=fopen(nomfichier,"r");
if (f!=NULL)
{
   f=fopen(nomfichier,"a+");
   while(fscanf(f,"%s %s %s \n",nom,id,role)!=EOF)
{
             gtk_list_store_append(store,&iter);
             gtk_list_store_set(store,&iter,NOM,nom,ID,id,ROLE,role,-1);
  
}    
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(KLtreeview),GTK_TREE_MODEL(store));
g_object_unref(store);
}}

//------------------------------------------------------------------------------------------------------------------------------------------------------//


void vider(GtkWidget *KLtreeview)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id[30];
char nom[30];
char role[30];


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(KLtreeview);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);}


gtk_tree_view_set_model(GTK_TREE_VIEW(KLtreeview),GTK_TREE_MODEL(store));
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_append_column(GTK_TREE_VIEW(KLtreeview),column);

/*store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id,NOM,nom,ROLE,role,-1);
gtk_tree_view_set_model(GTK_TREE_VIEW(KLtreeview),GTK_TREE_MODEL(store));
g_object_unref(store);*/


}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void pannejour(char nomfichier1[],char nomfichier2[],int jouradmin){

FILE *f=NULL;
FILE *w=NULL;

char ch1[30],ch2[30],ch3[30],ch4[30];


f=fopen(nomfichier1,"r");
w=fopen(nomfichier2,"w");

printf("jour admin est %d \n",jouradmin);


  if(f!=NULL) 
        {
            while(fscanf(f,"%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF ){

                if ( jouradmin==atoi(ch1) && (atoi(ch4)<0||atoi(ch4)>30))
                {
		 fprintf(w,"%s %s %s %s \n",ch1,ch2,ch3,ch4);
                 
                } 
                }


fclose(f);fclose(w);
}
}





void panneetage(char nomfichier1[],char nomfichier2[],int etageadmin){
FILE *f=NULL;
FILE *w=NULL;

char ch1[30],ch2[30],ch3[30],ch4[30];


f=fopen(nomfichier1,"r");
w=fopen(nomfichier2,"w");

printf("etage admin est %d \n",etageadmin);


  if(f!=NULL) 
        {
            while(fscanf(f,"%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF ){

                if ( etageadmin==atoi(ch3) && (atoi(ch4)<0||atoi(ch4)>30))
                {
		 fprintf(w,"%s %s %s %s \n",ch1,ch2,ch3,ch4);
                 
                } 
                }


fclose(f);fclose(w);
}

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------


void affichepanne (char nomfichier[],GtkWidget *treeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char jour[20];
char heure[20];
char etage[20];
char valeur[20];


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview);


if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);


store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen(nomfichier,"r");
if (f!=NULL)
{
   f=fopen(nomfichier,"a+");
   while(fscanf(f,"%s %s %s %s \n",jour,heure,etage,valeur)!=EOF)
{          
        
         gtk_list_store_append(store,&iter);
         gtk_list_store_set(store,&iter,JOUR,jour,HEURE,heure,ETAGE,etage,VALEUR,valeur,-1);
}    

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}










