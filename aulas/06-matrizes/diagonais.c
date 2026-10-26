#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main(void) {
  int matriz[LINHAS][COLUNAS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  /* ────────────────── */
  /* Diagonal principal */
  /* ────────────────── */

  // A diagonal principal contém os elementos em que
  // o índice da linha é igual ao índice da coluna.
  // Regra: i == j

  printf("Diagonal principal:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      // Condição de impressão
      if (i == j) {
        printf("%d ", matriz[i][j]);
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  /* ───────────────────── */
  /* Diagonal secundária */
  /* ───────────────────── */

  // Em uma matriz quadrada de ordem n, a diagonal
  // secundária satisfaz i + j == n - 1.

  // Como a matriz é quadrada, podemos usar COLUNAS - 1.
  // Regra: i + j == COLUNAS - 1

  printf("\nDiagonal secundaria:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (i + j == COLUNAS - 1) {
        printf("%d ", matriz[i][j]);
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  /* ───────────── */
  /* Linha central */
  /* ───────────── */

  // Para uma quantidade ímpar de linhas, LINHAS / 2
  // identifica a linha central.
  // Com 3 linhas: 3 / 2 = 1 (divisão inteira).

  printf("\nLinha central:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (i == LINHAS / 2) {
        printf("%d ", matriz[i][j]);
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  /* ──── */
  /* Cruz */
  /* ──── */

  // A cruz reúne a linha central e a coluna central.
  // O operador || significa OU lógico.

  // Basta que uma das condições seja verdadeira
  // para que o elemento seja impresso.

  printf("\nCruz:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (i == LINHAS / 2 || j == COLUNAS / 2) {
        printf("%d ", matriz[i][j]);
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  return 0;
}
