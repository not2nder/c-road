#include <stdio.h>

int main() {
  /* ------------------ */
  /*  Tipos Primitivos  */
  /* ------------------ */

  int    nota    =   10; // Tipo inteiro (1,2,3,4,...)
  char   inicial =  'A'; // Letras (a,b,c,d,...z)
  float  altura  = 1.70; // Ponto flutuante (6 a 7 dígitos de precisão)
  double pi      = 3.141592653589; // Ponto flutuante (15 a 16 dígitos de precisão)

  // Imprimindo valores
  printf("%d\n", nota);
  //       │       └─────> variável
  //       └────────> especificador
  
  /* --------------------------- */
  /* Especificadores para printf */
  /* --------------------------- */
  
  /* 
  ┌────┬──────────────────────┐
  │ %c │ caractere (char)     │
  │ %d │ inteiros (com sinal) │
  │ %f │ Ponto flutuante      │
  │ %s │ String               │
  └────┴──────────────────────┘
  */

  printf("Nota: %d\n",   nota);
  printf("Incial: %c\n", inicial);
  printf("Nota: %.2f\n", altura); // A notação %.2f especifica as casas decimais impressas (2)
  printf("Pi: %.12f\n", pi);

  return 0;
}
