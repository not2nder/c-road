#include <stdio.h>

#define ORDEM 3

int main(void) {
  /* ─────────── */
  /* Matriz Nula */
  /* ─────────── */

  // Todos os elementos são inicializados com zero.
  int nula[ORDEM][ORDEM] = {0};

  printf("Matriz nula:\n");

  for (int i = 0; i < ORDEM; i++) {
    for (int j = 0; j < ORDEM; j++) {
      printf("%d ", nula[i][j]);
    }

    printf("\n");
  }

  /* ───────────────── */
  /* Matriz identidade */
  /* ───────────────── */

  // A diagonal principal contém 1; os demais
  // elementos contêm 0.
  int identidade[ORDEM][ORDEM] = {0};

  // Basta apenas 1 for para a diagonal principal
  for (int i = 0; i < ORDEM; i++) {
    identidade[i][i] = 1;
  }

  printf("\nMatriz identidade:\n");

  for (int i = 0; i < ORDEM; i++) {
    for (int j = 0; j < ORDEM; j++) {
      printf("%d ", identidade[i][j]);
    }

    printf("\n");
  }

  /* ───────────────── */
  /* Matriz transposta */
  /* ───────────────── */

  // A transposta troca linhas por colunas.
  int original[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  int transposta[3][2];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      transposta[j][i] = original[i][j];
      //          │  
      //          └────> troca de índices
    }
  }

  printf("\nMatriz original:\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", original[i][j]);
    }

    printf("\n");
  }

  printf("\nMatriz transposta:\n");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", transposta[i][j]);
    }

    printf("\n");
  }

  return 0;
}
