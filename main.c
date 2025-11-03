#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int main(void) {
  // char seq[100] = "acggtatcg";
  // seq_i * seq_info = malloc(sizeof * seq_info);
  // get_info(seq, seq_info);
  // printf("Infos:\n");
  // printf("Sequence : %s\n", seq);
  // printf("Longueur : %zu \n", seq_info -> length);
  // printf("a : %zu \n", seq_info -> nb_a);
  // printf("c : %zu \n", seq_info -> nb_c);
  // printf("g : %zu \n", seq_info -> nb_g);
  // printf("t : %zu \n", seq_info -> nb_t);
  // printf("Taux gc : %f", seq_info -> gc);
  // return EXIT_SUCCESS;

  lsc *p = lsc_vide();
  lsc_insert_head(p, 1);
  lsc_insert_head(p, 3);
  printf("____________\n");
  lsc_print(p);
  printf("____________\n");
  lsc_del_head(p);
  lsc_print(p);
}
