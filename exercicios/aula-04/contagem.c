#include <stdio.h>

int main() {
  int numero;
  int impares = 0, pares = 0;
  int positivos = 0, negativos = 0;

  do {
    printf("Informe um número: ");
    scanf("%d", &numero);

    if (numero %2 == 0 && numero != 0) {
      pares++;
    }
    else if (numero != 0) {
      impares++;
    }

    if (numero > 0) {
      positivos++;
    } else {
      negativos++;
    }

  } while (numero != 0);

  printf("Impares: %d; Pares: %d\n", impares, pares);
  printf("positivos: %d; Negativos: %d\n", positivos, negativos);

  return 0;
}
