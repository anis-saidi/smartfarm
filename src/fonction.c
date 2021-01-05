#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>
enum
{ 
	ENUMDESERIE,
	ETYPE ,
	EETAT ,
       	TJ ,
	TM ,
	TA ,
	NJ ,
	NM ,
	NA ,
	COLUMNS ,
};

void  ajout_equip(equipement t) 
	
{    FILE *f=NULL;
    f=fopen("equipement.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d %d %d \n",t.numdeserie,t.type,t.etat,t.date1.jour,t.date1.mois,t.date1.annee,t.date2.jour,t.date2.mois,t.date2.annee);
        fclose(f);
    }
    else
        printf("not founded");
}

void supprimer_equip(char *numdeserie ) 
{
    FILE *f=NULL;
    FILE *tmp=NULL;
    equipement t1;
    f=fopen("equipement.txt","r");
    tmp=fopen("tmp.txt","w");
    if(f!=NULL)
    {
    while(fscanf(f,"%s %s %d %d %d %d %d %d %d  \n",t1.numdeserie,t1.type,&t1.etat,&t1.date1.jour,&t1.date1.mois,&t1.date1.annee,&t1.date2.jour,&t1.date2.mois,&t1.date2.annee)!=EOF)
       {
      if (strcmp(t1.numdeserie, numdeserie) != 0)
        {
          fprintf(tmp,"%s %s %d %d %d %d %d %d %d \n",t1.numdeserie,t1.type,t1.etat,t1.date1.jour,t1.date1.mois,t1.date1.annee,t1.date2.jour,t1.date2.mois,t1.date2.annee );
        }

       }
        fclose(f);
        fclose(tmp);
        remove("equipement.txt");
        rename("tmp.txt","equipement.txt");

    }
    else
        printf("not founded");
}
/*
void modifier_equip(char *numdeserie ,equipement t2)
{
    supprimer_equip(numdeserie);
    ajout_equip( t2);
}

*/
void modifier_equip(char numdeserie[30] ,equipement t2) 
{
FILE *f;
    FILE *tmp;
    equipement t1;
date date1 ;
date date2 ;
    f=fopen("equipement.txt","r");
    tmp=fopen("tmp.txt","w");
    
       while(fscanf(f,"%s %s %d %d %d %d %d %d %d  \n",t1.numdeserie,t1.type,&t1.etat,&t1.date1.jour,&t1.date1.mois,&t1.date1.annee,&t1.date2.jour,&t1.date2.mois,&t1.date2.annee)!=EOF)
       {
        if (strcmp(t1.numdeserie,numdeserie)!=0)
        
          fprintf(tmp,"%s %s %d %d %d %d %d %d %d  \n",t1.numdeserie,t1.type,t1.etat,t1.date1.jour,t1.date1.mois,t1.date1.annee,t1.date2.jour,t1.date2.mois,t1.date2.annee);
        

       }
  fprintf(tmp,"%s %s %d %d %d %d %d %d %d  \n",numdeserie,t2.type,t2.etat,t2.date1.jour,t2.date1.mois,t2.date1.annee,t2.date2.jour,t2.date2.mois,t2.date2.annee);
        
        
        fclose(f);
        fclose(tmp);
        remove("equipement.txt");
        rename("tmp.txt","equipement.txt");
       
   
}

void afficher_equipement(GtkWidget *liste) 
{

   
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter iter;
   GtkListStore *store;
   
   char numdeserie[30];
   char type[30];
   char etat[30];
   char tjour[30];
   char tmois[30];
   char tannee[30];
   char njour[30];
   char nmois[30];
   char nannee[30];
   equipement t ;
   store=NULL;
   FILE*f ;
   store=gtk_tree_view_get_model(liste);
   if (store==NULL)
   {  
   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("numéro de serie",renderer,"text",ENUMDESERIE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("jour d'achat",renderer,"text",TJ,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("mois d'achat",renderer,"text",TM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("annee d'achat",renderer,"text",TA,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("jour d'entretien",renderer,"text",NJ,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("mois d'entretien",renderer,"text",NM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("annee d'entretien",renderer,"text",NA,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
 
f=fopen("equipement.txt","r");
   if (f==NULL)
   {
return;
   }
   else
   {
	f = fopen("equipement.txt","a+") ;
     while((fscanf(f,"%s %s %d %d %d %d %d %d %d \n",t.numdeserie,t.type,&t.etat,&t.date1.jour,&t.date1.mois,&t.date1.annee,&t.date2.jour,&t.date2.mois,&t.date2.annee)!=EOF))
   { 
      strcpy(numdeserie,t.numdeserie);
      strcpy(type,t.type);
     sprintf(tjour,"%d",t.date1.jour);
     sprintf(tmois,"%d",t.date1.mois);
     sprintf(tannee,"%d",t.date1.annee);
     sprintf(njour,"%d",t.date2.jour);
     sprintf(nmois,"%d",t.date2.mois);
     sprintf(nannee,"%d",t.date2.annee);
         
    if(t.etat==1)
      strcpy(etat,"neuf");
     else if (t.etat==0)
       strcpy(etat,"occasion");
      else strcpy(etat,"en panne");
     
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store,&iter,ENUMDESERIE,numdeserie,ETYPE,type,EETAT,etat,TJ,tjour,TM,tmois,TA,tannee,NJ,njour,NM,nmois,NA,nannee,-1);
     }

    
  fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  g_object_unref (store);
    }
    }
/*
int capteurs_alarmants(int valeurs) 
{

FILE *f=NULL;
f=fopen("temperature.txt","r");




}

*/

void trfiltre(GtkWidget *liste,char  num[30])
{
GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter iter;
   GtkListStore *store;
   
   char numdeserie[30];
   char type[30];
   char etat[30];
   char tjour[30];
   char tmois[30];
   char tannee[30];
   char njour[30];
   char nmois[30];
   char nannee[30];
   equipement t ;
   store=NULL;
   FILE*f ;
   store=gtk_tree_view_get_model(liste);
   if (store==NULL)
   {  
   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("numéro de serie",renderer,"text",ENUMDESERIE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
   column= gtk_tree_view_column_new_with_attributes("jour d'achat",renderer,"text",TJ,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("mois d'achat",renderer,"text",TM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("annee d'achat",renderer,"text",TA,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("jour d'entretien",renderer,"text",NJ,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("mois d'entretien",renderer,"text",NM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
   renderer= gtk_cell_renderer_text_new ();
  column= gtk_tree_view_column_new_with_attributes("annee d'entretien",renderer,"text",NA,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
 }
f=fopen("equipement.txt","r");
   if (f==NULL)
   {
return;
   }
   else
   {
	f = fopen("equipement.txt","r") ;
     while((fscanf(f,"%s %s %d %d %d %d %d %d %d \n",t.numdeserie,t.type,&t.etat,&t.date1.jour,&t.date1.mois,&t.date1.annee,&t.date2.jour,&t.date2.mois,&t.date2.annee)!=EOF))
   { 
        if(strcmp(t.numdeserie,num)==0)
      {
      strcpy(numdeserie,t.numdeserie);
      strcpy(type,t.type);
     sprintf(tjour,"%d",t.date1.jour);
     sprintf(tmois,"%d",t.date1.mois);
     sprintf(tannee,"%d",t.date1.annee);
     sprintf(njour,"%d",t.date2.jour);
     sprintf(nmois,"%d",t.date2.mois);
     sprintf(nannee,"%d",t.date2.annee);
         
    if(t.etat==1)
      strcpy(etat,"neuf");
     else if (t.etat==0)
       strcpy(etat,"occasion");
      else strcpy(etat,"en panne");
     
      //gtk_list_store_append(store, &iter);
      //gtk_list_store_set(store,&iter,ENUMDESERIE,numdeserie,ETYPE,type,EETAT,etat,TJ,tjour,TM,tmois,TA,tannee,NJ,njour,NM,nmois,NA,nannee,-1);
     } }gtk_list_store_append(store, &iter);
      gtk_list_store_set(store,&iter,ENUMDESERIE,numdeserie,ETYPE,type,EETAT,etat,TJ,tjour,TM,tmois,TA,tannee,NJ,njour,NM,nmois,NA,nannee,-1);

    
  fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  g_object_unref (store);
    }
    }





