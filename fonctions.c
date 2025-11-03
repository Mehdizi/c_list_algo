#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

// void get_info(char*seq, seq_i*infos) {
//   infos -> nb_a = 0;
//   infos -> nb_c = 0;
//   infos -> nb_g = 0;
//   infos -> nb_t = 0;
//   infos -> gc = 0;
//   infos -> length = 0;
//   size_t k = 0;
//   while(seq[k] != '\0') {
//     if(seq[k] == 'a') {
//       ++infos -> nb_a;
//     }
//     else if(seq[k] == 'c') {
//       ++infos -> nb_c;
//     }
//     else if(seq[k] == 'g') {
//       ++infos -> nb_g;
//     }
//     else if(seq[k] == 't') {
//       ++infos -> nb_t;
//     }
//     ++k;
//   }
//   infos -> length = k;
//   if(k>0) {
//   infos -> gc = 100* (infos -> nb_c + infos -> nb_g) / (float)k ;
//   }
// }

int lsc_insert_head(lsc *p, int value) {
	lsc_cell * cell = malloc(sizeof * cell);
	if(cell == NULL){
  printf("Erreur malloc ! \n");
  return -1;
}
cell -> value = value;
cell -> next = p -> head;
p -> head = cell;
return 0;
}

lsc*lsc_vide(void) {
	lsc *l = malloc(sizeof *l);
	if (l == NULL){
    printf("Erreur malloc ! \n");
    return NULL;
  }
l -> head = NULL;
return l;
}

bool lsc_est_vide(lsc *p){
	return p -> head == NULL;
}

void lsc_print(lsc *p){
  if (p == NULL)
  {
    printf("la liste est NULL\n");
    return;
  }
  lsc_cell *c = p->head;
  while (c != NULL)
  {
    printf("%d\n", c->value);
    c = c->next;
  }
}

void lsc_del_head(lsc *p){
  printf("délétion en cours...\n");
  if(lsc_est_vide(p)) {
    return;
  }
  else {
    lsc_cell *cellToFree = p->head;
    p->head = p->head->next;
    free(cellToFree);
  };
}

// Il faut faire un pointeur vers la cellule actuelle et un pointeur vers le suivante.
// Comme ca si la suivante c'est la cellule à enlever on a toujours le pointeur d'avant pour repointer vers celui d'après.
void lsc_del_value(lsc *p, int v)
{
  if (lsc_est_vide(p))
  {
    return;
  }
  else if (p->head->value == v)
  {
    lsc_del_head(p);
  }
  else
  {
    lsc_cell *cv = p->head;
    lsc_cell *pv = p->head;

    while (cv->value != v)
    {
      if (cv == NULL)
      {
        return;
      }
      pv = cv;
      cv = cv->next;
    }
    pv->next = cv->next;
    free(cv);
  };
}

void lsc_dispose(lsc **pp)
{
  if (*pp == NULL)
  {
    return;
  }
  lsc_cell *cv = (*pp)->head;
  while (cv != NULL)
  {
    lsc_cell *nv = cv->next;
    free(cv);
    cv = nv;
  }
  free(*pp);
  *pp = NULL;
}

// faire void lsc_dispose(lsc**p)
//  lsc_dispose(&p)
// Il veut que cette fonction donne un p qui est à NULL
