/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *equipement_ajouter;
  GtkWidget *equipement_modifier;
  GtkWidget *equipement_afficher;
  GtkWidget *equipement_supprimer;
  GtkWidget *capteurs_alarmants;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  equipement_ajouter = create_equipement_ajouter ();
  gtk_widget_show (equipement_ajouter);
  /*equipement_modifier = create_equipement_modifier ();
  gtk_widget_show (equipement_modifier);
  equipement_afficher = create_equipement_afficher ();
  gtk_widget_show (equipement_afficher);
  equipement_supprimer = create_equipement_supprimer ();
  gtk_widget_show (equipement_supprimer);*/
  capteurs_alarmants = create_capteurs_alarmants ();
  gtk_widget_show (capteurs_alarmants);

  gtk_main ();
  return 0;
}

