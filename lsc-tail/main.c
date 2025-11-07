#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int main(void) {
  lsc *p = lsc_vide();
  lsc_insert_head(p, 5);
  lsc_insert_head(p, 4);
  lsc_insert_head(p, 2);
  lsc_insert_tail(p, 199);
  lsc_insert_tail(p, 23);
  lsc_insert_head(p, 135);
  printf("--------PRINT P-----------\n");
  lsc_print(p);
  printf("-------DELETION 23 et 5-----------\n");
  lsc_del_value(p, 23);
  lsc_del_value(p, 5);
  printf("--------PRINT P-----------\n");
  lsc_print(p);
  printf("--------INSERT 220-----------\n");
  lsc_insert_sorted(p, 220);
  lsc_insert_sorted(p, 122);
  lsc_insert_sorted(p, 3);
  printf("--------PRINT P-----------\n");
  lsc_print(p);
  printf("head : %d tail : %d ", p->head->value, p->tail->value);
}
