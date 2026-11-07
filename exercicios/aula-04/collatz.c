#include <stdio.h>

int main() {
  int num;
  printf("Informe um inteiro positivo: ");
  scanf("%d", &num);

  // Imprime o número inicial antes de iniciar a sequência.
  printf("%d ", num);

  do {  
    // Verifica se o número atual é par ou ímpar.
    if (num % 2 == 0) {
      // Números pares são divididos por 2.
      num /= 2; 
    }
    else {
      // Números ímpares são multiplicados por 3 e somados a 1.
      num = (num * 3) + 1;
    }
    
    // Imprime o novo valor após cada operação.
    printf("%d ", num);
  }

  // Repete o processo até que o número atual seja igual a 1.
  while (num != 1);

  printf("\n");

  return 0;
}
