#include <stdio.h>

int main() {
  int matriz_a[2][2] = {
    {8,7},
    {4,1}
  };

  int matriz_b[2][2] = {
    {5,3},
    {2,9}
  };

  // Operações entre matrizes quadradas se resumem a:
  // operar entre 2 matrizes de tamanho igual utilizando os mesmos índices

  /*
    Soma, subtração e multiplicação elemento a elemento:
    
    A + B = │ 8 + 5 7 + 3 │ = │ 13 10 │
            │ 4 + 2 1 + 9 │   │  6 10 │

    As operações são realizadas entre elementos
    que ocupam a mesma posição nas duas matrizes.
  */

  // Soma:
  printf("Soma das matrizes: \n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      //                         ┌────> elemento da matriz A
      //                         │  
      printf("%02d ", matriz_a[i][j] + matriz_b[i][j]);
      //                                          │  
      //               elemento da matriz B <─────┘ 
      
      // Ambos os elementos se encontram na mesma posição,
      // portanto, são acessados pelo mesmo índice
    }
    printf("\n");
  }

  // O princípio se aplica a outras operações:
  printf("Subtracação de matrizes: \n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%02d ", matriz_a[i][j] - matriz_b[i][j]);
      //                             │
      //                             └────> mudança apenas no operador 
    }
    printf("\n");
  }

  printf("Multiplicação de matrizes: \n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%02d ", matriz_a[i][j] * matriz_b[i][j]);
    }
    printf("\n");
  }

  // Multiplicação por por Escalar:
  // se resume a multiplicar os elementos individuais por um valor K

  int k = 3;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%02d ", matriz_a[i][j] * k);
    }
    printf("\n");
  }

  /* --------------------------------- */
  /* Armazenando operações de matrizes */
  /* --------------------------------- */

  int matriz_c[2][2];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matriz_c[i][j] = matriz_a[i][j] * matriz_b[i][j];
    }
  }

  return 0;
}
