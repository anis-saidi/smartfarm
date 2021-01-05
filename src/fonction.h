#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{ int jour ;
  int mois ;
  int annee ;
}date;




typedef struct 
{ char numdeserie[30];
  char type[30];
  int etat;
  date date1;
  date date2;
  
}equipement;

void  ajout_equip(equipement t);
void supprimer_equip(char *numdeserie);
void modifier_equip(char numdeserie[30], equipement t2);
void afficher_equipement(GtkWidget *liste) ;
void trfiltre(GtkWidget *liste, char num[30]);
#endif
