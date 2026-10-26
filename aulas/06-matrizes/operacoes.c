#include <stdio.h>

#define LINHAS 2
#define COLUNAS 2

int main(void) {
  int matriz_a[LINHAS][COLUNAS] = {
    {8, 7},
    {4, 1}
  };

  int matriz_b[LINHAS][COLUNAS] = {
    {5, 3},
    {2, 9}
  };

  int resultado[LINHAS][COLUNAS];

  // Nas operações elemento a elemento, utilizamos
  // os mesmos índices nas duas matrizes.

  /* ────── */
  /* Adição */
  /* ────── */

  printf("Adição:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      // Soma os elementos que ocupam a mesma posição.
      resultado[i][j] = matriz_a[i][j] + matriz_b[i][j];

      printf("%02d ", resultado[i][j]);
    }
    printf("\n");
  }

  /* ───────── */
  /* Subtração */
  /* ───────── */

  printf("\nSubtração:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      resultado[i][j] = matriz_a[i][j] - matriz_b[i][j];
      printf("%02d ", resultado[i][j]);
    }
    printf("\n");
  }

  /* ───────────────────────── */
  /* Multiplicação por escalar */
  /* ───────────────────────── */

  // Um escalar é um único valor numérico.
  // Aqui, cada elemento de A é multiplicado por k.
  int k = 3;

  printf("\nMultiplicacao por escalar (%d):\n", k);

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      resultado[i][j] = matriz_a[i][j] * k;
      printf("%02d ", resultado[i][j]);
    }
    printf("\n");
  }

  /* ───────────────────────────────── */
  /* Multiplicação elemento a elemento */
  /* ───────────────────────────────── */

  // Esta operação multiplica os elementos correspondentes.
  // Ela NÃO é a multiplicação matricial convencional.

  printf("\nMultiplicacao elemento a elemento:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      resultado[i][j] = matriz_a[i][j] * matriz_b[i][j];
      printf("%02d ", resultado[i][j]);
    }
    printf("\n");
  }

  return 0;
}

