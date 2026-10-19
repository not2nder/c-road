#include <stdio.h>

int main() {
  /* ---------------- */
  /* Vetores (arrays) */
  /* ---------------- */

  // Variáveis simples: armazenam apenas um dado
  int nota = 10;

  // Arrays: armazenam mais de um dado
  int notas[4] = {10, 7, 9, 8};

  /* ---------- */
  /* Declaração */
  /* ---------- */

  //     ┌────> nome
  //     │            ┌────► elementos armazenados 
  int medias[4] = {7, 7, 8, 9};
  //         └────► tamanho (Número de elementos)
  
  // Assim como tipos simples, arrays podem ser declarados sem incialização

  int numeros[5]; // Não inicializa os valores (podem ser qualquer cois)
  int vetor[5] = {1,2,3}; // Inicializa os 3 primeiros elementos 

  /* ------------------- */
  /* Acessando elementos */
  /* ------------------- */

  /* Sintaxe básica: vetor[índice]
   
    Cada índice, enumerados de 0 a n-1 representam uma posição do vetor.
    Sendo n o número de elementos do vetor.

              ┌───┬───┬───┬───┬───┐
    ELEMENTOS │ 6 │ 7 │ 9 │ 8 │...│
              └─┬─┴─┬─┴─┬─┴─┬─┴───┘
                v   v   v   v      
    INDICES     0   1   2   3      

    Se um vetor tem tamanho 5, os índices serão enumerados de 0 a 4.
  */

  printf("Elemento n° 1: %d\n", notas[0]);
  printf("Elemento n° 2: %d\n", notas[1]);
  printf("Elemento n° 3: %d\n", notas[2]);

  /* --------------------- */
  /* Modificando elementos */
  /* --------------------- */

  // Basta atribuir o novo valor ao índice desejado
  
  //         ┌────► Novo valor
  notas[0] = 6;
  //    └────► Posição a ser alterada

  // Notas = {6, 7, 9, 8}
  
  // Isso ajuda a preencher vetores vazios ou substituir valores por meio de scanf:
  
  printf("Informe sua nota: ");
  scanf("%d", &notas[0]);
  //             └────► Endereço da posição a ser alterada. 

  /* -------- */
  /* Iteração */
  /* -------- */

  // Iterar é percorrer os elementos de um vetor
  // Isso pode ser feito por meio de laços de repetição:

  //          ┌────► Sempre começar de 0
  //          │      ┌────► Tamanho fixo do vetor
  for(int i = 0; i < 4; i++) {
    printf("Elemento na posição %d: %d\n", i, notas[i]);
    //                                              └────► Atualiza a posição a cada loop.
  }

  // Se quiser preencher um vetor inteiro do zero:
  for(int i = 0; i < 5; i++) {
    int num;

    printf("Informe um número: ");
    scanf("%d", &num);
    vetor[i] = num;
  }

  // Forma 2:
  for(int i = 0; i < 5; i++) {
    scanf("%d", &vetor[i]);
    //             └────► Passa o endereço direto da posição do vetor.   
  }

  return 0;
}
