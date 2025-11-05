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

int lsc_insert_head(lsc *p, int value);
bool lsc_est_vide(lsc *p);
lsc*lsc_vide(void);
void lsc_print(lsc *p);
void lsc_del_head(lsc *p);
void lsc_del_value(lsc *p, int v);
void lsc_dispose(lsc **pp);
void lsc_del_all_value(lsc *p, int v);

// void get_info(char*seq, seq_i*infos);

#endif
