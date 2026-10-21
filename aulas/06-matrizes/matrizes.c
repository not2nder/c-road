#include <stdio.h>

int main() {
  /* ──────── */
  /* Matrizes */
  /* ──────── */

  // Uma variável simples armazena um único valor.
  int nota = 10;

  // Um vetor armazena vários valores em uma dimensão.
  int notas[3] = {7, 8, 9};

  // Uma matriz organiza valores em linhas e colunas.
  int matriz[2][3] = {
      {1, 2, 3},
      {4, 5, 6}
  };

  /* ────────────────────── */
  /* Declaração e estrutura */
  /* ────────────────────── */

  // Sintaxe: tipo nome[linhas][colunas]
  
  //             COLUNAS
  //           0   1   2
  //         ┌───┬───┬───┐
  // LINHA 0 │ 1 │ 2 │ 3 │
  //         ├───┼───┼───┤
  // LINHA 1 │ 4 │ 5 │ 6 │
  //         └───┴───┴───┘

  // Uma matriz é basicamente um array de arrays,
  // portanto, cada linha é um array, com índices próprios

  /* ─────────────────── */
  /* Acessando elementos */
  /* ─────────────────── */

  
  // Sintaxe: nome[linha][coluna]
  printf("Elemento [0][0]: %d\n", matriz[0][0]); // 1
  printf("Elemento [0][2]: %d\n", matriz[0][2]); // 3
  printf("Elemento [1][0]: %d\n", matriz[1][0]); // 4
  printf("Elemento [1][2]: %d\n", matriz[1][2]); // 6

  // Assim como nos vetores, os índices começam em zero.
  // Uma matriz com 2 linhas e 3 colunas possui:
  // - índices de linha: 0 a 1
  // - índices de coluna: 0 a 2

  /* ───────────────────── */
  /* Modificando elementos */
  /* ───────────────────── */

  // Basta informar a linha e a coluna desejadas.
  
  matriz[0][1] = 10; // linha 1, coluna 2.

  printf("Novo valor: %d\n", matriz[0][1]); // 10
  
  /* ────────── */
  /* Iteração */
  /* ────────── */

  // Para percorrer uma matriz inteira, usamos dois laços:
  // - o laço externo percorre as linhas;
  // - o laço interno percorre as colunas.

  for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
          printf("%d ", matriz[i][j]); // Sem \n, para imprimir a linha sem quebras
      }

      printf("\n"); // quebra de linha para cada linha da matriz
  }
  return 0;
}
