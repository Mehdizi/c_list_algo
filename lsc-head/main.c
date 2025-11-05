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

  // lsc *p = lsc_vide();
  lsc *src = lsc_vide();
  lsc_insert_head(src, 1);
  lsc_insert_head(src, 2);
  lsc_insert_head(src, 3);
  lsc *dest = lsc_vide();
  lsc_insert_head(dest, 4);
  lsc_insert_head(dest, 5);
  lsc_insert_head(dest, 6);

  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 3);
  // lsc_insert_head(p, 4);
  // printf("____________\n");
  // lsc_print(p);
  // printf("____________\n");
  // lsc_del_value(p, 4);
  // printf("____________\n");
  // lsc_print(p);
  // printf("____________\n");
  // lsc_dispose(&p);
  // printf("____________\n");
  // lsc_print(p);
  // printf("____________\n");
  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 2);
  // lsc_insert_head(p, 1);
  // printf("____________\n");
  // lsc_print(p);
  // printf("____________\n");
  // lsc_del_all_value(p, 2);
  // printf("____________\n");
  // lsc_print(p);
  // lsc_insert_sorted(p, 5);
  // lsc_insert_sorted(p, 6);
  // lsc_insert_sorted(p, 8);
  // lsc_insert_sorted(p, 9);
  // lsc_insert_sorted(p, 1);
  // lsc_insert_sorted(p, 3);
  // lsc_insert_sorted(p, 12);
  // lsc_print(p);
  lsc_move_head(src, dest);
  lsc_print(dest);
  printf("Move Head__________\n");
  lsc_print(src);
  printf("Move All __________\n");
  lsc_move_all_head(src, dest);
  lsc_print(dest);
  printf("__________\n");
  lsc_print(src);
}
