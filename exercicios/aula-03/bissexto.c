#include <stdio.h>

/* 
 Um ano é bissexto quando:
  É divisivel por 400 OU é divisivel por 4 E NÃO por 100
*/

int main() {
  int ano;
  printf("Informe o ano: ");
  scanf("%d", &ano);

  printf(
      //     ┌────> Divisível por 400             ┌────> Não divisivel por 100 
      // ────┴─────                         ──────┴────── 
      (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 !=0)? "Ano bissexto\n": "Ano Não bissexto\n"
      //                   ─────┬──────
      //                        └────> Divisível por 4  
  );

  // Forma resumida (sem comentários):
  /*
  printf((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)? "bissexto\n": "Não bissexto\n");
  */

  return 0;
}
