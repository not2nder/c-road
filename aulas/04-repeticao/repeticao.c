#include <stdio.h>

int main() {
  /* ----------------------- */
  /* Estruturas de Repetição */
  /* ----------------------- */

  /* ------ */
  /* 1. for */
  /* ------ */

  /* Sintaxe:
     for (inicialização; condição; atualização) {
       --> Código a ser repetido <--
     }
   */

  //   ┌───> Variável de controle
  //   │              ┌──────> Incremento
  //   │              │
  for (int i = 0; i < 5; i++) {
  //               └────> Condição de parada
    printf("Olá!\n");
    //       └────> Instrução a ser repetida
  }

  /* -------- */
  /* 2. while */
  /* -------- */

  /* Sintaxe:
     while (condição) {
       --> Código a ser repetido <--
     }
   */

  int i = 0;

  //     ┌───> Condição de parada
  while (i < 5) {
    printf("Valor de i: %d\n", i);

    i++;
  //  └── Incremento manual (importante!!!)
  //  é o mesmo que: i += 1 ou i = i + 1 
  }

  /* ------------ */
  /* 3. do while */
  /* ------------ */

  /* Sintaxe:
     do {
       --> Código a ser repetido <--
     } while (condição);
   */

  i = 0;

  // O bloco é executado antes da verificação da condição
  do {
    printf("Valor de i: %d\n", i);
    i++;
  } while (i < 5); // A condição é verificada ao final

  // while: verifica, depois executa
  // do-while: executa depois verifica

  return 0;
}

