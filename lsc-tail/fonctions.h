#ifndef __FONCTIONS__
#define __FONCTIONS__
#include <stdio.h> 

typedef struct seq_i {
  size_t nb_a, nb_c, nb_g, nb_t;
  float gc;
  size_t length;
} seq_i;

typedef struct lsc_cell {
	int value;
	struct lsc_cell*next;
} lsc_cell;

typedef struct lsc {
	lsc_cell * head;
  lsc_cell *tail;
}lsc;

/* lsc_insert_head : Prend une lsc et une valeur en paramètre.
  Créer une nouvelle cellule, lui attribu la valeur donnée et l'ajoute en début de chaîne.
 */
int lsc_insert_head(lsc *p, int value);
/* lsc_insert_tail : Prend une lsc et une valeur en paramètre.
  Créer une nouvelle cellule, lui attribu la valeur donnée et l'ajoute en fin de chaîne.
 */
int lsc_insert_tail(lsc *p, int value);
/* lsc_est_vide : Prend une lsc en paramètre et renvoi TRUE si la liste est vide */
bool lsc_est_vide(lsc *p);
/* Initialise une lsc vide*/
lsc*lsc_vide(void);
/* lsc_vide : Prend une lsc en paramètre.
  Renvoi la valeur de chaque cellules.
 */
void lsc_print(lsc *p);
/* lsc_print : Prend une lsc en paramètre.
  Supprime la cellule en tête de liste
 */
void lsc_del_head(lsc *p);
/* lsc_del_value : Prend une lsc en paramètre et une valeur.
  Supprime la première cellule de la liste égale à la valeur
 */
void lsc_del_value(lsc *p, int v);
/* lsc_dispose : Prend un pointeur de lsc en paramètre.
  Supprime la lsc et ses cellules
 */
void lsc_dispose(lsc **pp);
/* lsc_del_all_value : Prend une lsc en paramètre et une valeur.
  Supprime toutes les cellules égale à la valeur
 */
void lsc_del_all_value(lsc *p, int v);
/* lsc_insert_sorted : Prend une lsc en paramètre et une valeur (v).
  Ajoute une cellule (valeur = v) à sa position dans l'ordre croissant dans la lsc
 */
void lsc_insert_sorted(lsc *p, int v);
/* lsc_move_head : Prend deux lsc en paramètre.
  transfert la première cellule de la lsc "dest" à la lsc "src"
 */
void lsc_move_head(lsc *src, lsc *dest);
/* lsc_move_all_head : Prend deux lsc en paramètre.
  transfert toutes les cellule de la lsc "dest" à la lsc "src"
  en transférant les cellules dans l'ordre de tête vers queue de la "dest"
 */
void lsc_move_all_head(lsc *src, lsc *dest);

// void get_info(char*seq, seq_i*infos);

#endif
