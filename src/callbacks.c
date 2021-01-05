#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "capteur.h"

void
on_button1capteursaj_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2ouvrier_aj_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3clientaj_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4troupeauxaj_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5calendrier_aj_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button18entretien_aj_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8supprimer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_supprimer, *equipement_ajouter;	
	equipement_ajouter=lookup_widget (objet_graphique,"equipement_ajouter");
	equipement_supprimer=create_equipement_supprimer();
	gtk_widget_show (equipement_supprimer);
	gtk_widget_hide (equipement_ajouter);
}


void
on_button7afficher_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_ajouter,*treeview1 ,*equipement_afficher;
equipement_ajouter=lookup_widget (objet_graphique,"equipement_ajouter");
gtk_widget_destroy(equipement_ajouter);

equipement_afficher=lookup_widget(objet_graphique,"equipement_afficher");
equipement_afficher=create_equipement_afficher();

gtk_widget_show(equipement_afficher);

treeview1=lookup_widget(equipement_afficher,"treeview1");

afficher_equipement(treeview1);

}


void
on_button6modifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_modifier, *equipement_ajouter;	
	equipement_ajouter=lookup_widget (objet_graphique,"equipement_ajouter");
	equipement_modifier=create_equipement_modifier();
	gtk_widget_show (equipement_modifier);
	gtk_widget_hide (equipement_ajouter);
}


void
on_button16capteursmod_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15ouvriermod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button14clientsmod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13troupeauxmod_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12calendriermod_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button17ajoutermod_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_modifier, *equipement_ajouter;	
	equipement_modifier=lookup_widget (objet_graphique,"equipement_modifier");
	equipement_ajouter=create_equipement_ajouter();
	gtk_widget_show (equipement_ajouter);
	gtk_widget_hide (equipement_modifier);
}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *equipement_modifier,*treeview1 ,*equipement_afficher;
equipement_modifier=lookup_widget (objet_graphique,"equipement_modifier");
gtk_widget_destroy(equipement_modifier);

equipement_afficher=lookup_widget(objet_graphique,"equipement_afficher");
equipement_afficher=create_equipement_afficher();

gtk_widget_show(equipement_afficher);

treeview1=lookup_widget(equipement_afficher,"treeview1");

afficher_equipement(treeview1);

}


void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_modifier, *equipement_supprimer;	
	equipement_modifier=lookup_widget (objet_graphique,"equipement_modifier");
	equipement_supprimer=create_equipement_supprimer();
	gtk_widget_show (equipement_supprimer);
	gtk_widget_hide (equipement_modifier);
}


void
on_button20entretienmod_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button29capteurs_aff_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button28ouvrier_aff_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button27clients_aff_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button26troupeaux_aff_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button25calendrier_aff_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button32ajouter_aff_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_afficher, *equipement_ajouter;	
	equipement_afficher=lookup_widget (objet_graphique,"equipement_afficher");
	equipement_ajouter=create_equipement_ajouter();
	gtk_widget_show (equipement_ajouter);
	gtk_widget_hide (equipement_afficher);

}


void
on_button24modifier_aff_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_afficher, *equipement_modifier;	
	equipement_afficher=lookup_widget (objet_graphique,"equipement_afficher");
	equipement_modifier=create_equipement_modifier();
	gtk_widget_show (equipement_modifier);
	gtk_widget_hide (equipement_afficher);
}


void
on_button22supprimer_aff_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_afficher, *equipement_supprimer;	
	equipement_afficher=lookup_widget (objet_graphique,"equipement_afficher");
	equipement_supprimer=create_equipement_supprimer();
	gtk_widget_show (equipement_supprimer);
	gtk_widget_hide (equipement_afficher);
}


void
on_button30entretien_aff_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button55ajouter_aj_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
equipement t;
GtkWidget *in1,*in2,*in3,*in4,*in5,*in6,*in7,*in8,*in9,*equipement_ajouter;
equipement_ajouter=lookup_widget(objet_graphique,"equipement_ajouter");

in1= lookup_widget(objet_graphique,"numaj");
in2= lookup_widget(objet_graphique,"typeaj");
in3=lookup_widget(objet_graphique,"combobox1");
 if (strcmp("neuf",gtk_combo_box_get_active_text(GTK_COMBO_BOX(in3)))==0)
 t.etat=1; 
   else 
    t.etat=0;

in4=lookup_widget(objet_graphique,"spinbutton4");
in5=lookup_widget(objet_graphique,"spinbutton5");
in6=lookup_widget(objet_graphique,"spinbutton6");
in7=lookup_widget(objet_graphique,"spinbutton1");
in8=lookup_widget(objet_graphique,"spinbutton2");
in9=lookup_widget(objet_graphique,"spinbutton3");

strcpy(t.numdeserie,gtk_entry_get_text(GTK_ENTRY(in1)));
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(in2)));
t.date1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in4));
t.date1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in5));
t.date1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in6));
t.date2.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in7));
t.date2.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in8));
t.date2.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in9));


ajout_equip( t);
}




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* numdeserie;
gchar* type;

equipement t;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&numdeserie,1,&type,-1);

strcpy(t.numdeserie,numdeserie);
strcpy(t.type,type);



supprimer_equip(numdeserie);
afficher_equipement(treeview);

}

}


void
on_button57modifier_mod_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *in1,*in2,*in3,*in4,*in5,*in6,*in7,*in8,*in9,*equipement_modifier;
equipement t2;
char numdeserie[30];
equipement_modifier=lookup_widget(objet_graphique,"equipement_modifier");

in1= lookup_widget(objet_graphique,"nummo");
in2= lookup_widget(objet_graphique,"typemod");
in3=lookup_widget(objet_graphique,"combobox2");
 if (strcmp("neuf",gtk_combo_box_get_active_text(GTK_COMBO_BOX(in3)))==0)
 t2.etat=1; 
   else if (strcmp("occasion",gtk_combo_box_get_active_text(GTK_COMBO_BOX(in3)))==0)
   t2.etat=0;
   else 
    t2.etat=2;

in4=lookup_widget(objet_graphique,"spinbutton7");
in5=lookup_widget(objet_graphique,"spinbutton8");
in6=lookup_widget(objet_graphique,"spinbutton9");
in7=lookup_widget(objet_graphique,"spinbutton10");
in8=lookup_widget(objet_graphique,"spinbutton11");
in9=lookup_widget(objet_graphique,"spinbutton12");

strcpy(numdeserie,gtk_entry_get_text(GTK_ENTRY(in1)));
strcpy(t2.type,gtk_entry_get_text(GTK_ENTRY(in2)));
t2.date1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in4));
t2.date1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in5));
t2.date1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in6));
t2.date2.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in7));
t2.date2.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in8));
t2.date2.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(in9));


modifier_equip(numdeserie , t2) ;

}


void
on_button56supprimer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *equipement_supprimer;
GtkWidget *windowsup;
windowsup=create_equipement_supprimer();
char numdeserie[30] ;
equipement t;

input1=lookup_widget(objet_graphique,"numsupp");
strcpy(numdeserie,gtk_entry_get_text(GTK_ENTRY(input1))); 
supprimer_equip(numdeserie);


}


void
on_button34affichersupp_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *equipement_supprimer,*treeview1 ,*equipement_afficher;
equipement_supprimer=lookup_widget (objet_graphique,"equipement_supprimer");
gtk_widget_destroy(equipement_supprimer);

equipement_afficher=lookup_widget(objet_graphique,"equipement_afficher");
equipement_afficher=create_equipement_afficher();

gtk_widget_show(equipement_afficher);

treeview1=lookup_widget(equipement_afficher,"treeview1");

afficher_equipement(treeview1);


}


void
on_button35modifiersupp_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_supprimer, *equipement_modifier;	
	equipement_supprimer=lookup_widget (objet_graphique,"equipement_supprimer");
	equipement_modifier=create_equipement_modifier();
	gtk_widget_show (equipement_modifier);
	gtk_widget_hide (equipement_supprimer);
}


void
on_button43ajoutersupp_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *equipement_supprimer, *equipement_ajouter;	
	equipement_supprimer=lookup_widget (objet_graphique,"equipement_supprimer");
	equipement_ajouter=create_equipement_ajouter();
	gtk_widget_show (equipement_ajouter);
	gtk_widget_hide (equipement_supprimer);
}


void
on_button44_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *equipement_afficher, *entryfiltre, *treeview1,*liste;
  char numdeserie[30];

  entryfiltre = lookup_widget(objet_graphique, "entryfiltre");
  strcpy(numdeserie, gtk_entry_get_text(GTK_ENTRY(entryfiltre)));
  equipement_afficher = lookup_widget(objet_graphique, "equipement_afficher");
  //gtk_widget_destroy(equipement_afficher);
  //equipement_afficher = create_equipement_afficher();
  //gtk_widget_show(equipement_afficher);
/* 
 treeview1 = lookup_widget(equipement_afficher, "treeview1");
*/
  liste = lookup_widget(objet_graphique, "treeview1");
  trfiltre(liste, numdeserie);
  
}

////////////////////////////////////////

void
on_button45hum_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
int jourt,moist,anneet;

GtkWidget *treeview1,*treeview3,*t7al,*tsakker,*ja,*ma,*aa;

ja= lookup_widget(objet,"ja");
ma= lookup_widget(objet,"ma");
aa= lookup_widget(objet,"aa");


jourt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ja));
moist=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ma));
anneet=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aa));

chercher_alamantes_temp(jourt,moist,anneet);

t7al=create_capteurs_alarmants();
gtk_widget_show (t7al);



tsakker=lookup_widget(objet,"capteurs_alarmants");
gtk_widget_destroy (tsakker);



treeview3=lookup_widget(t7al,"treeview2");
afficher_capteurs_temp_alarm(treeview3);


treeview1=lookup_widget(t7al,"treeview3");
afficher_capteurs_hum(treeview1);




}


void
on_button43temp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
int jourt,moist,anneet;

GtkWidget *treeview2,*treeview3,*t7al,*tsakker,*ja,*ma,*aa;

ja= lookup_widget(objet,"spinbutton10");
ma= lookup_widget(objet,"spinbutton11");
aa= lookup_widget(objet,"spinbutton12");


jourt=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ja));
moist=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ma));
anneet=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aa));

chercher_alamantes_humid(jourt,moist,anneet);

t7al=create_capteurs_alarmants();
gtk_widget_show (t7al);



tsakker=lookup_widget(objet,"capteurs_alarmants");
gtk_widget_destroy (tsakker);

treeview3=lookup_widget(t7al,"treeview3");
afficher_capteurs_hum_alarm(treeview3);

treeview2=lookup_widget(t7al,"treeview2");
afficher_capteurs_temp(treeview2);



}


void
on_button46plus_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2,*treeview1,*t7al,*tsakker,*ja,*ma,*aa;

chercher_plus_alamantes_temp();
chercher_plus_alamantes_hum();
t7al=create_capteurs_alarmants();
gtk_widget_show (t7al);



tsakker=lookup_widget(objet,"capteurs_alarmants");
gtk_widget_destroy (tsakker);


treeview1=lookup_widget(t7al,"treeview3");
afficher_capteurs_hum_plus_alarm(treeview1);

treeview2=lookup_widget(t7al,"treeview2");
afficher_capteurs_temp_plus_alarm(treeview2);

}

