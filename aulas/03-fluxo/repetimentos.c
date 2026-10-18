#include <stdio.h>

int main() {
  /* ----------------------- */
  /* Estruturas de Repetição */
  /* ----------------------- */
  
  /* ------ */
  /* 1. for */
  /* ------ */

  /* Sintaxe
     for(inicialização; condição; incremento) {
        --> Código a ser repetido <--
     }
   */

  //   ┌───> Variavel de controle
  //   │                   ┌──────> Incremento
  for(int i = 0; i < 5; i++){
  //               └────> Condição de parada
    printf("Olá!\n");
  }

  /* -------- */
  /* 2. while */
  /* -------- */
  
  /* Sintaxe
      while (condição) {
        --> Código a ser repetido <--
     }
   */

  int i = 0; // Variável de controle
  
  //     ┌───> Condição de parada
  while (i < 5) {
    printf("Valor de i: %d\n", i);
    i++;
  // └────> Incremento manual (importante!!!)
  }

  return 0;
}
