#include <stdio.h>

int main() {
  /* ---------------------- */
  /* Iterando sobre strings */
  /* ---------------------- */
  
  char nome[] = "Anderson";

  // Usando um valor fixo:

  //                ┌────> Tamanho do texto + '\0' 
  for (int i = 0; i < 9; i++) {
    printf("%c\n", nome[i]);
  }
  // Essa forma é util quando se sabe o tamanho do texto

  /* ----------------------------------------------- */

  // Usando condições:

  char palavra[] = "pneumoultramicroscopicossilicovulcanoconiotico";

  for (int i = 0; palavra[i] != '\0'; i++) {
    printf("%c\n", palavra[i]);
  }

  // É possível alcançar o mesmo resultado com um while
  
  int i = 0;

  while (palavra[i] != '\0') {
    printf("%c\n", palavra[i]);
    i++;
  }

  return 0;
}
