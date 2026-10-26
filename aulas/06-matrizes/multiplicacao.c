#include <stdio.h>

#define LINHAS_A 2
#define COLUNAS_A 3

#define LINHAS_B 3
#define COLUNAS_B 2

int main(void) {
  int matriz_a[LINHAS_A][COLUNAS_A] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  int matriz_b[LINHAS_B][COLUNAS_B] = {
    {7, 8},
    {9, 10},
    {11, 12}
  };

  // Para multiplicar A por B, o número de colunas
  // de A deve ser igual ao número de linhas de B.
  
  // O resultado terá as linhas de A e as colunas de B.
  int resultado[LINHAS_A][COLUNAS_B] = {0};

  for (int i = 0; i < LINHAS_A; i++) {
    for (int j = 0; j < COLUNAS_B; j++) {
      for (int k = 0; k < COLUNAS_A; k++) {
        resultado[i][j] += matriz_a[i][k] * matriz_b[k][j];
      }
    }
  }

  printf("Produto matricial:\n");

  for (int i = 0; i < LINHAS_A; i++) {
    for (int j = 0; j < COLUNAS_B; j++) {
      printf("%d ", resultado[i][j]);
    }

    printf("\n");
  }

  return 0;
}
