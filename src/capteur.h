#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include <gtk/gtk.h>



typedef struct {
int id ;
int jo ;
int mo;
int an;
float val;
}alarmant ;


typedef struct
{
int id;
int jour;
int mois ;
int annee;
float valeur;
}capt;

void afficher_capteurs_temp(GtkWidget *liste);
void afficher_capteurs_hum(GtkWidget *liste);

void chercher_alamantes_temp(int j,int m, int a);
void chercher_alamantes_humid(int jr,int mo, int an);

void afficher_capteurs_temp_alarm(GtkWidget *liste);
void afficher_capteurs_hum_alarm(GtkWidget *liste);


void afficher_capteurs_temp_plus_alarm(GtkWidget *liste);
void chercher_plus_alamantes_temp();

void afficher_capteurs_hum_plus_alarm(GtkWidget *liste);
void chercher_plus_alamantes_hum();

void marquedef();
#endif // GESTION_H_INCLUDED
