#ifndef __FONCTIONS__
#define __FONCTIONS__
#include <stdio.h> 

typedef struct seq_i {
  size_t nb_a, nb_c, nb_g, nb_t;
  float gc;
  size_t length;
} seq_i;

typedef struct ldc_cell {
	int value;
	struct ldc_cell*next;
  struct ldc_cell*prev;
} ldc_cell;

typedef struct ldc {
	ldc_cell * head;
  ldc_cell * tail;
}ldc;

/* ldc_insert_head : Prend une ldc et une valeur en paramètre.
  Créer une nouvelle cellule, lui attribu la valeur donnée et l'ajoute en début de chaîne.
  return -1 si erreur allocation mémoire lors de la création de la cellule
  return 0 si l'opération est réussie
 */
int ldc_insert_head(ldc *p, int value);

/* ldc_insert_tail : Prend une ldc et une valeur en paramètre.
  Créer une nouvelle cellule, lui attribu la valeur donnée et l'ajoute en fin de chaîne.
  return -1 si erreur allocation mémoire lors de la création de la cellule
  return 0 si l'opération est réussie
 */
int ldc_insert_tail(ldc *p, int value);

/* ldc_est_vide : Prend une ldc en paramètre
return TRUE si la liste est vide
*/
bool ldc_est_vide(ldc *p);

/* Initialise une ldc vide*/
ldc*ldc_vide(void);

/* ldc_vide : Prend une ldc en paramètre.
  Renvoi la valeur de chaque cellules.
 */
void ldc_print(ldc *p);

/* ldc_print : Prend une ldc en paramètre.
  Supprime la cellule en tête de liste
 */
void ldc_del_head(ldc *p);

/* ldc_print : Prend une ldc en paramètre.
  Supprime la cellule en queue de liste
 */
void ldc_del_tail(ldc *p);

/* ldc_del_value : Prend une ldc en paramètre et une valeur.
  Parcours la liste et supprime la première cellule égale à la valeur
 */
void ldc_del_value(ldc *p, int v);

/* ldc_dispose : Prend un pointeur de ldc en paramètre.
  Supprime la ldc et ses cellules
 */
void ldc_dispose(ldc **pp);

/* ldc_del_all_value : Prend une ldc en paramètre et une valeur.
  Dans la liste, supprime toutes les cellules égale à la valeur
 */
void ldc_del_all_value(ldc *p, int v);

/* ldc_insert_sorted : Prend une ldc vide ou déjà ordonné de façon croissante en paramètre et une valeur (v).
  Ajoute une cellule (valeur = v) à sa position dans l'ordre croissant dans la ldc
 */
void ldc_insert_sorted(ldc *p, int v);

/* ldc_move_head : Prend deux ldc en paramètre.
  transfert la première cellule de la ldc "dest" à la ldc "src"
 */
void ldc_move_head(ldc *src, ldc *dest);

/* ldc_move_all_head : Prend deux ldc en paramètre.
  transfert toutes les cellule de la ldc "src" à la ldc "dest"
  en transférant les cellules dans l'ordre de tête vers queue de la "src"
 */
void ldc_move_all_head(ldc *src, ldc *dest);



#endif
