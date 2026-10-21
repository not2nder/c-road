#include <stdio.h>

int main() {
  /* ───────────────── */
  /* Vetores (arrays) */
  /* ───────────────── */

  // Variável simples: armazena um único valor
  int nota = 10;

  // Array: armazena vários elementos do mesmo tipo
  int notas[4] = {10, 7, 9, 8};

  /* ────────── */
  /* Declaração */
  /* ────────── */

  //     ┌────> nome
  //     │            ┌────► elementos
  int medias[4] = {7, 7, 8, 9};
  //         │
  //         └────► tamanho (quantidade de elementos)

  // Elementos de arrays sem inicialização
  // possuem valores indeterminados.
  int numeros[5];

  int vetor[5] = {1, 2, 3}; // Os elementos restantes começam em zero
  int lista[5] = {0};       // Já aqui, todos os elementos começam em zero

  /* ─────────────────── */
  /* Acessando elementos */
  /* ─────────────────── */

  /*
    Sintaxe: vetor[índice]

    Os índices começam em 0 e vão até n - 1,
    sendo n a quantidade de elementos.

              ┌───┬───┬───┬───┐
    ELEMENTOS │ 6 │ 7 │ 9 │ 8 │
              └─┬─┴─┬─┴─┬─┴─┬─┘
                v   v   v   v
    ÍNDICES     0   1   2   3

    Um array de 5 elementos possui índices de 0 a 4.
  */

  printf("Elemento 1: %d\n", notas[0]);
  printf("Elemento 2: %d\n", notas[1]);
  printf("Elemento 3: %d\n", notas[2]);

  // O índice também pode ser uma variável ou expressão.
  int i = 1;

  printf("Elemento atual: %d\n", notas[i]);        // Índice 1: valor 7
  printf("Próximo elemento: %d\n", notas[i + 1]);  // Índice 2: valor 9
  printf("Elemento anterior: %d\n", notas[i - 1]); // Índice 0: valor 10

  // O índice calculado precisa estar dentro dos limites do array.
  // Acessar uma posição inválida causa comportamento indefinido.

  /* ───────────────────── */
  /* Modificando elementos */
  /* ───────────────────── */

  //         ┌────► Novo valor
  notas[0] = 6;
  //    └────► Posição a ser alterada
  
  // notas = {6, 7, 9, 8}

  /* ------------------------------------------- */

  // Também podemos modificar elementos com scanf().
  printf("Informe sua nota: ");
  scanf("%d", &notas[0]);
  //             └────► Endereço da posição a ser alterada

  /* ──────── */
  /* Iteração */
  /* ──────── */

  // Percorrendo os elementos com um laço
  for (int i = 0; i < 4; i++) {
    printf("Elemento na posição %d: %d\n", i, notas[i]);
  }

  // Preenchendo um array com valores informados pelo usuário
  for (int i = 0; i < 5; i++) {
    printf("Informe um número: ");
    scanf("%d", &vetor[i]);
  }

  /* ─────────────────────── */
  /* Quantidade de elementos */
  /* ─────────────────────── */

  // sizeof retorna o tamanho em bytes.
  int quantidade = sizeof(notas) / sizeof(notas[0]);

  /* Exemplo: se cada int ocupa 4 bytes:
     
     sizeof(notas)    -> 4 elementos * 4 bytes = 16 bytes
     sizeof(notas[0]) -> 1 elemento = 4 bytes
     
     16 / 4 = 4 elementos
  */

  printf("Quantidade de elementos: %d\n", quantidade);

  // Podemos utilizar essa quantidade para percorrer o array.
  for (int i = 0; i < quantidade; i++) {
    printf("%d\n", notas[i]);
  }

  return 0;
}
