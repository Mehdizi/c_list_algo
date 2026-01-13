#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int main(void) {
  ldc *src = ldc_vide();
  ldc *dest = ldc_vide();
  ldc_insert_head(src, 1);
  ldc_insert_head(src, 2);
  ldc_insert_head(src, 3);
  ldc_insert_head(dest, 4);
  ldc_insert_head(dest, 5);
  ldc_insert_head(dest, 6);
  ldc_move_head(src, dest);
  ldc_move_head(src, dest);
  ldc_move_head(src, dest);
  ldc_print(src);
  // ldc_move_all_head(src, dest);
  printf("-------------\n");
  ldc_print(src);

}
