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
  //     │            ┌────► elementos armazenados
  int medias[4] = {7, 7, 8, 9};
  //         └────► tamanho (quantidade de elementos)

  // Arrays podem ser declarados sem inicialização.
  // Nesse caso, os elementos de um array local têm valores indeterminados.

  int numeros[5];
  int vetor[5] = {1, 2, 3}; // Os elementos restantes começam em zero

  int lista[5] = {0};       // Todos os elementos começam em zero

  /* ─────────────────── */
  /* Acessando elementos */
  /* ─────────────────── */

  /* Sintaxe básica: vetor[índice]

    Os índices de um array começam em 0 e vão até n - 1,
    sendo n a quantidade de elementos.

              ┌───┬───┬───┬───┐
    ELEMENTOS │ 6 │ 7 │ 9 │ 8 │
              └─┬─┴─┬─┴─┬─┴─┬─┘
                v   v   v   v
    ÍNDICES     0   1   2   3

    Se um vetor tem tamanho 5, os índices vão de 0 a 4.
    Acessar um índice fora desses limites causa comportamento indefinido.
  */

  printf("Elemento 1: %d\n", notas[0]);
  printf("Elemento 2: %d\n", notas[1]);
  printf("Elemento 3: %d\n", notas[2]);

  /* ───────────────────── */
  /* Modificando elementos */
  /* ───────────────────── */

  // Basta atribuir o novo valor ao índice desejado.

  //         ┌────► Novo valor
  notas[0] = 6;
  //    └────► Posição a ser alterada

  // Notas = {6, 7, 9, 8}

  // Também podemos modificar um elemento com scanf().

  printf("Informe sua nota: ");
  scanf("%d", &notas[0]);
  //             └────► Endereço da posição a ser alterada

  /* ──────── */
  /* Iteração */
  /* ──────── */

  // Iterar é percorrer os elementos de um array.
  // Isso pode ser feito por meio de laços de repetição.

  //          ┌────► Começa no índice 0
  //          │      ┌────► Percorre os 4 elementos
  for (int i = 0; i < 4; i++) {
    printf("Elemento na posição %d: %d\n", i, notas[i]);
    //                                              └────► Acessa o elemento da posição atual
  }

  // Preenchendo um array com valores informados pelo usuário:
  for (int i = 0; i < 5; i++) {
    printf("Informe um número: ");
    scanf("%d", &vetor[i]);
    //             └────► Endereço da posição a ser preenchida
  }

  /* ─────────────────────── */
  /* Quantidade de elementos */
  /* ─────────────────────── */

  // Diferente do Python, C não possui um método len()
  // para obter diretamente a quantidade de elementos de um array.
  // Podemos calcular essa quantidade usando sizeof:
  
  int quantidade = sizeof(notas) / sizeof(notas[0]);

  // sizeof(notas)     -> tamanho total do array em bytes
  // sizeof(notas[0])  -> tamanho de um elemento em bytes
  
  // Dividindo o tamanho total pelo tamanho de um elemento, obtemos a quantidade de elementos.

  printf("Quantidade de elementos: %d\n", quantidade);

  // Também podemos usar esse cálculo no laço de repetição:
  for (int i = 0; i < quantidade; i++) {
    printf("%d\n", notas[i]);
  }

  return 0;
}
