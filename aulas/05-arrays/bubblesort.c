#include <stdio.h>

/* Contexto:
   Bubblesort é um algoritmo de ordenação de vetores,
   cujo objetivo é percorrer um vetor de elementos numéricos desordenados
   comparando cada elemento com seu elemento adjacente.
*/

int main() {
  int vetor[4] = {3,5,2,1};

  // percorre elemento por elemento: 3, 5 e 2
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 4 - i - 1; j++) {
      if (vetor[j] > vetor[j+1]) {
        // troca os elementos de posição
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }

  for(int i = 0; i < 4; i++) {
    printf("%d\n", vetor[i]);
  }

  return 0;
}
