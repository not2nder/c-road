#include <stdio.h>

int main() {
  int numero;

  // inicializa os contadores:
  int impares = 0, pares = 0;
  int positivos = 0, negativos = 0;

  do {
    // recebe o número
    printf("Informe um número: ");
    scanf("%d", &numero);

    // Verifica a paridade do número.
    if (numero %2 == 0 && numero != 0) {
    //                   └────> desconsidera o zero.
      pares++;
    } else if (numero != 0) {
    //                 └────> desconsidera o zero novamente.
      impares++;
    }

    // Verifica o sinal do número.
    if (numero > 0) {
      positivos++;
    } else {
      negativos++;
    }

    // O laço continua enquanto o usuário não informar zero.
  } while (numero != 0);

  printf("Impares: %d; Pares: %d\n", impares, pares);
  printf("positivos: %d; Negativos: %d\n", positivos, negativos);

  return 0;
}
