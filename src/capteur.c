#include "capteur.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

enum
{

TID,
TJOUR,
TMOIS,
TANNEE,
TVAL,
};


void afficher_capteurs_temp(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVAL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("temperature.txt","r");
//t=fopen("tempdse.txt","w");
if (f==NULL)
return;

else 
{
f=fopen("temperature.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;

//fprintf(t,"%d %d %d %d %f\n",ident,jour,mois,annee,valeur);
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TID,ident,TJOUR,jour,TMOIS,mois,TANNEE,annee,TVAL,valeur,-1);
}

fclose (f);
//fclose (t);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


enum
{

TID1,
TJOUR1,
TMOIS1,
TANNEE1,
TVAL1,
};

void afficher_capteurs_hum(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TID1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOUR1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOIS1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEE1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVAL1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("humidite.txt","r");
//t=fopen("tempdse.txt","w");
if (f==NULL)
return;

else 
{
f=fopen("humidite.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;


gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TID1,ident,TJOUR1,jour,TMOIS1,mois,TANNEE1,annee,TVAL1,valeur,-1);
}

fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


void chercher_alamantes_temp(int j,int m, int a)
{

capt c;
 FILE *f=NULL,*g=NULL;
 g=fopen("Alarm_temp.txt","w");
 f=fopen("temperature.txt","r");

  if(f==NULL)
  return;
 else
 {
  while(fscanf(f, "%d %d %d %d %f\n",&c.id,&c.jour,&c.mois,&c.annee,&c.valeur)!=EOF)
  {
if((a==c.annee)&&(m==c.mois)&&(c.jour==j)){
   if(c.valeur<0 || c.valeur>45 )
    {
     if(g==NULL)
      {
       return;
      }
     else
      {
       fprintf(g,"%d %d %d %d %.2f\n",c.id,c.jour,c.mois,c.annee,c.valeur);
      }
    }
    }
 }
  fclose(f);
  fclose(g);
 }
}

void chercher_alamantes_humid(int jr,int mo, int an)
{

capt c;
 FILE *f=NULL,*g=NULL;
 g=fopen("Alarm_hum.txt","w");
 f=fopen("humidite.txt","r");

  if(f==NULL)
  return;
 else
 {
  while(fscanf(f, "%d %d %d %d %f\n",&c.id,&c.jour,&c.mois,&c.annee,&c.valeur)!=EOF)
  {
if((an==c.annee)&&(mo==c.mois)&&(c.jour==jr)){
   if(c.valeur<20 || c.valeur>150 )
    {
     if(g==NULL)
      {
       return;
      }
     else
      {
       fprintf(g,"%d %d %d %d %.2f\n",c.id,c.jour,c.mois,c.annee,c.valeur);
      }
    }
    }
 }
  fclose(f);
  fclose(g);
 }
}



enum
{

TID3,
TJOUR3,
TMOIS3,
TANNEE3,
TVAL3,
};




void afficher_capteurs_temp_alarm(GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TID3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOUR3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOIS3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVAL3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("Alarm_temp.txt","r");

if (f==NULL)
return;

else 
{
f=fopen("Alarm_temp.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;


gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TID3,ident,TJOUR3,jour,TMOIS3,mois,TANNEE3,annee,TVAL3,valeur,-1);
}

fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}



}


enum
{

TIDH,
TJOURH,
TMOISH,
TANNEEH,
TVALH,
};


void afficher_capteurs_hum_alarm(GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TIDH,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOURH,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOISH,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEEH,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVALH,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("Alarm_hum.txt","r");

if (f==NULL)
return;

else 
{
f=fopen("Alarm_hum.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;


gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TIDH,ident,TJOURH,jour,TMOISH,mois,TANNEEH,annee,TVALH,valeur,-1);
}

fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}



}



void chercher_plus_alamantes_temp()
{

capt c;
 FILE *f=NULL,*g=NULL;
 g=fopen("Alarm_temp_plus.txt","w");
 f=fopen("temperature.txt","r");
int id ;
  if(f==NULL)
  return;
 else
 {
  while(fscanf(f, "%d %d %d %d %f\n",&c.id,&c.jour,&c.mois,&c.annee,&c.valeur)!=EOF)
  {
if((c.id==3)||(c.id==5)||(c.id==7)){
   if(c.valeur<0 || c.valeur>45 )
    {
     if(g==NULL)
      {
       return;
      }
     else
      {
       fprintf(g,"%d %d %d %d %.2f\n",c.id,c.jour,c.mois,c.annee,c.valeur);
      }
    }
    }
 }
  fclose(f);
  fclose(g);
 }
}




void afficher_capteurs_temp_plus_alarm(GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TID3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOUR3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOIS3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVAL3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("Alarm_temp_plus.txt","r");

if (f==NULL)
return;

else 
{
f=fopen("Alarm_temp_plus.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;


gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TID3,ident,TJOUR3,jour,TMOIS3,mois,TANNEE3,annee,TVAL3,valeur,-1);
}

fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}



}






void chercher_plus_alamantes_hum()
{

capt c;
 FILE *f=NULL,*g=NULL;
 g=fopen("Alarm_hum_plus.txt","w");
 f=fopen("humidite.txt","r");
int id ;
  if(f==NULL)
  return;
 else
 {
  while(fscanf(f, "%d %d %d %d %f\n",&c.id,&c.jour,&c.mois,&c.annee,&c.valeur)!=EOF)
  {
if((c.id==3)||(c.id==5)||(c.id==7)){
   if( c.valeur>100 )
    {
     if(g==NULL)
      {
       return;
      }
     else
      {
       fprintf(g,"%d %d %d %d %.2f\n",c.id,c.jour,c.mois,c.annee,c.valeur);
      }
    }
    }
 }
  fclose(f);
  fclose(g);
 }
}




void afficher_capteurs_hum_plus_alarm(GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

int ident;
int jour ,mois , annee ;
float valeur ;


alarmant a;
store=NULL;
FILE *f,*t;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",TID3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",TJOUR3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",TMOIS3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",TANNEE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",TVAL3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(5,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);

f=fopen("Alarm_hum_plus.txt","r");

if (f==NULL)
return;

else 
{
f=fopen("Alarm_hum_plus.txt","r");
while(fscanf(f,"%d %d %d %d %f",&a.id,&a.jo,&a.mo,&a.an,&a.val)!=EOF)
{




ident=a.id;
jour=a.jo;
mois=a.mo;
annee=a.an;
valeur=a.val;


gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TID3,ident,TJOUR3,jour,TMOIS3,mois,TANNEE3,annee,TVAL3,valeur,-1);
}

fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}



}

/*

void marquedef()
{
FILE *f=fopen("capteur.txt","r");
FILE *fc=fopen("marquedef.txt","a+");
capteur c;
if(f==NULL)
return;

else
{
while(fscanf(f,"%d %s %f %f %s %d %d %d %s",&c.id,c.type,&c.Vmax,&c.Vmin,c.etat,&c.d.jour,&c.d.mois,&c.d.annee,c.emplacement)!=EOF)
if(strcmp(c.etat,"PANNE")==0)
{
 fprintf(fc,"%d %s %.2f %.2f %s %d %d %d %s\n",c.id,c.type,c.Vmax,c.Vmin,c.etat,c.d.jour,c.d.mois,c.d.annee,c.emplacement);
                  
}
}

 fclose(f);
 fclose(fc);
}
*/
