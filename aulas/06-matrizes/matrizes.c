#include <stdio.h>

#define LINHAS 2
#define COLUNAS 3

int main(void) {
  /* ──────── */
  /* Matrizes */
  /* ──────── */

  // Variável simples: armazena um único valor.
  int nota = 10;

  // Vetor: armazena vários valores em uma dimensão.
  int notas[3] = {7, 8, 9};

  // Matriz: organiza valores em linhas e colunas.
  int matriz[LINHAS][COLUNAS] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  /* ────────────────────── */
  /* Declaração e estrutura */
  /* ────────────────────── */

  // Sintaxe: tipo nome[linhas][colunas]

  // Uma matriz bidimensional pode ser entendida como
  // um array cujos elementos são outros arrays.

  //             COLUNAS
  //           0   1   2
  //         ┌───┬───┬───┐
  // LINHA 0 │ 1 │ 2 │ 3 │
  //         ├───┼───┼───┤
  // LINHA 1 │ 4 │ 5 │ 6 │
  //         └───┴───┴───┘

  /* ─────────────────── */
  /* Acessando elementos */
  /* ─────────────────── */

  // Sintaxe: nome[linha][coluna]
  printf("Elemento [0][0]: %d\n", matriz[0][0]); // 1
  printf("Elemento [0][2]: %d\n", matriz[0][2]); // 3
  printf("Elemento [1][0]: %d\n", matriz[1][0]); // 4
  printf("Elemento [1][2]: %d\n", matriz[1][2]); // 6

  // Os índices sempre começam em zero.

  /* ───────────────────── */
  /* Modificando elementos */
  /* ───────────────────── */

  // matriz[0][1] representa a primeira linha, segunda coluna.
  matriz[0][1] = 10;

  printf("\nNovo valor: %d\n", matriz[0][1]);

  /* ─────────────────── */
  /* Percorrendo a matriz */
  /* ─────────────────── */

  // Usa-se dois laços for:
  // O laço externo (i) percorre as linhas.
  // O laço interno (j) percorre as colunas de cada linha.

  printf("\nMatriz:\n");

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n"); // quebra de linha após cada linha
  }

  /* ───────────────────── */
  /* Preenchendo a matriz */
  /* ───────────────────── */

  int tabela[2][2];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Linha %d, coluna %d: ", i, j);
      scanf("%d", &tabela[i][j]);
    }
  }

  printf("\nTabela preenchida:\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", tabela[i][j]);
    }

    printf("\n");
  }

  return 0;
}

