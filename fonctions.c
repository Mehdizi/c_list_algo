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
  lsc_cell *c = p->head;
  while (c != NULL)
  {
    printf("%d\n", c->value);
    c = c->next;
  }
}

void lsc_del_head(lsc *p){
  if(lsc_est_vide(p)) {
    return;
  }
  else {
    lsc_cell *cellToFree = p->head;
    p->head = p->head->next;
    free(cellToFree);
  };
}

