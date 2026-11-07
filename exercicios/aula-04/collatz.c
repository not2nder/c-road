#include <stdio.h>

int main() {
  int num;
  printf("Informe um inteiro positivo: ");
  scanf("%d", &num);

  printf("%d ", num);
  do {  
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = (num * 3) + 1;
    }
    
    printf("%d ", num);
  }

  while (num != 1);

  printf("\n");

  return 0;
}
