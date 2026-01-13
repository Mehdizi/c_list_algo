#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int ldc_insert_head(ldc *p, int value) {
  ldc_cell *cell = malloc(sizeof *cell);
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
  cell->prev = NULL;
  p->head = cell;
  return 0;
}

int ldc_insert_tail(ldc *p, int value)
{
  if (p->tail == NULL)
  {
    ldc_insert_head(p, value);
    return -1;
  }
  ldc_cell *cell = malloc(sizeof *cell);
  if (cell == NULL)
  {
    printf("Erreur malloc ! \n");
    return -1;
  }
  cell->value = value;
  cell->prev = p->tail;
  p->tail->next = cell;
  cell->next = NULL;
  p->tail = cell;
  return 0;
}

bool ldc_est_vide(ldc *p){
	return p -> head == NULL;
}

ldc*ldc_vide(void) {
	ldc *l = malloc(sizeof *l);
	if (l == NULL){
    printf("Erreur malloc ! \n");
    return NULL;
  }
l -> head = NULL;
l -> tail = NULL;
return l;
}

void ldc_print(ldc *p){
  if (p == NULL)
  {
    return;
  }
  ldc_cell *c = p->head;
  while (c != NULL)
  {
    printf("%d\n", c->value);
    c = c->next;
  }
}

void ldc_del_head(ldc *p){
  if(ldc_est_vide(p)) {
    return;
  }
  if(p->head->next == NULL) {
    p->tail = NULL;
  }
  else {
    ldc_cell *cellToFree = p->head;
    p->head = p->head->next;
    p->head->prev = NULL;
    free(cellToFree);
  };
}

void ldc_del_tail(ldc *p){
  if(ldc_est_vide(p)) {
    return;
  }
  if(p->head->next == NULL) {
    p->tail = NULL;
  }
  else {
    ldc_cell *cellToFree = p->tail;
    p->tail = p->tail->prev;
    p->tail->next = NULL;
    free(cellToFree);
  };
}

void ldc_del_value(ldc *p, int v)
{
  if (ldc_est_vide(p))
  {
    return;
  }
  else if (p->head->value == v)
  {
    ldc_del_head(p);
  }
  else
  {
    ldc_cell *cv = p->head;
    while (cv->value != v)
    {
      if (cv == NULL)
      {
        return;
      }
      cv = cv->next;
    }
    if (p->tail->value == v)
    {
      cv = p->tail;
      p->tail->prev->next = NULL;
      p->tail->prev = NULL;
      p->tail = cv->prev;
      free(cv);
      return;
    }
    cv->next->prev = cv->prev;
    cv->prev->next = cv->next;
    free(cv);
  };
}

void ldc_dispose(ldc **pp)
{
  if (*pp == NULL)
  {
    return;
  }
  ldc_cell *cv = (*pp)->head;
  while (cv != NULL)
  {
    ldc_cell *nv = cv->next;
    cv->prev = NULL;
    free(cv);
    cv = nv;
  }
  free(*pp);
  *pp = NULL;
}

void ldc_del_all_value(ldc *p, int v)
{
  if (p == NULL || ldc_est_vide(p))
  {
    return;
  }
  else
  {
    ldc_cell *cv = p->head;
    while (p->head->value == v && cv != NULL)
    {
      ldc_del_head(p);
      cv = p->head;
    }
    while(p->tail->value == v && cv!=NULL){
      ldc_del_tail(p);
      cv = p->tail;
    }

    if (cv != NULL )
    {
      cv = cv->next;
    }
    while (cv != NULL)
    {
      if (cv->value == v)
      {
        cv->prev->next = cv->next;
        cv->next->prev = cv->prev;
        ldc_cell *newcv = cv->next;
        free(cv);
        cv = newcv;
      }
      else
      {
        cv = cv->next;
      }
    }
  };
}

void ldc_insert_sorted(ldc *p, int v)
{
  if (p == NULL || ldc_est_vide(p) || p->head->value >= v)
  {
    ldc_insert_head(p, v);
    return;
  }
  if (p->tail->value < v)
  {
    ldc_insert_tail(p, v);
    return;
  }
  ldc_cell *newv = malloc(sizeof *newv);
  if (newv == NULL)
  {
    return;
  }
  newv->value = v;
  ldc_cell *cv = p->head;
  while (cv->next != NULL && cv->next->value < v)
  {
    cv = cv->next;
  }
  newv->next = cv->next;
  newv->prev = cv;
  cv->next->prev = newv;
  cv->next = newv;
}

void ldc_move_head(ldc *src, ldc *dest)
{
  
}

void ldc_move_all_head(ldc *src, ldc *dest)
{
  while (src->head != NULL)
  {
    ldc_move_head(src, dest);
  }
}
