#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int lsc_insert_head(lsc *p, int value) {
  lsc_cell *cell = malloc(sizeof *cell);
  if (cell == NULL)
  {
    printf("Erreur malloc ! \n");
    return -1;
  }
  if (p->head == NULL)
  {
    p->tail = cell;
  }
  cell->value = value;
  cell->next = p->head;
  p->head = cell;
  return 0;
}

int lsc_insert_tail(lsc *p, int value)
{
  if (p->tail == NULL)
  {
    lsc_insert_head(p, value);
    return -1;
  }
  lsc_cell *cell = malloc(sizeof *cell);
  if (cell == NULL)
  {
    printf("Erreur malloc ! \n");
    return -1;
  }
  cell->value = value;
  p->tail->next = cell;
  cell->next = NULL;
  p->tail = cell;
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
  if (p->head->next == NULL)
  {
    p->tail = NULL;
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
    if (p->tail->value == v)
    {
      p->tail = pv;
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

void lsc_del_all_value(lsc *p, int v)
{
  if (p == NULL || lsc_est_vide(p))
  {
    return;
  }
  else
  {
    lsc_cell *cv = p->head;
    while (p->head->value == v && cv != NULL)
    {
      lsc_del_head(p);
      cv = p->head;
    }
    lsc_cell *pv = cv;
    if (cv != NULL)
    {
      cv = cv->next;
    }
    while (cv != NULL)
    {
      if (cv->value == v)
      {
        pv->next = cv->next;
        free(cv);
        cv = pv->next;
      }
      else
      {
        pv = cv;
        cv = cv->next;
      }
    }
  };
}

void lsc_insert_sorted(lsc *p, int v)
{
  // VERIFIER SI LA LISTE EST VIDE SI OUI ? AJOUTER LA VALEUR AVEC lsc_insert_head
  if (p == NULL || lsc_est_vide(p) || p->head->value >= v)
  {
    lsc_insert_head(p, v);
    return;
  }
  if (p->tail->value < v)
  {
    lsc_insert_tail(p, v);
    return;
  }

  // CREATION DE LA NOUVELLE CELLULE ET ATTRIBUTION DE LA VALEUR V
  lsc_cell *newv = malloc(sizeof *newv);
  if (newv == NULL)
  {
    return;
  }

  newv->value = v;
  lsc_cell *cv = p->head;
  while (cv->next != NULL && cv->next->value < v)
  {
    cv = cv->next;
  }
  newv->next = cv->next;
  cv->next = newv;
}

void lsc_move_head(lsc *src, lsc *dest)
{
  if (src->head == src->tail)
  {
    dest->tail = NULL;
  }
  lsc_cell *mv = src->head;
  src->head = mv->next;
  mv->next = dest->head;
  dest->head = mv;
}

void lsc_move_all_head(lsc *src, lsc *dest)
{
  src
}
