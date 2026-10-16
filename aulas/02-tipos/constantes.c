#include <stdio.h>

#define PI 3.14159
#define ANO 2026

int main() {
  
  const int limite = 100;

  printf("PI: %.5f\n", PI);
  printf("ANO: %d\n", ANO);
  printf("Limite: %d\n", limite);

  /*
    const: declara uma variável com tipo definido
    cujo valor não pode ser alterado normalmente.

    #define: cria uma macro, que substitui um nome
    por um texto antes da compilação.
  
    Durante a compilação:
      printf("%d\n", ANO) ──> printf("%d\n", 2026)
  */

  return 0;
}
