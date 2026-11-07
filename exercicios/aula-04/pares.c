#include <stdio.h>

int main() {
  int n1, n2, soma = 0;

  printf("Informe dois números: ");
  scanf("%d %d", &n1, &n2);

  if (n2 > n1) {
    for (int i = n1; i <= n2; i++){
      if (i %2 == 0) {
        soma += i;
      } 
    }
  }
  else {
    for (int i = n2; i >= n1; i--){
      if (i %2 == 0) {
        soma += i;
      } 
    }
  }

  printf("A soma dos números pares entre %d e %d é: %d\n", n1, n2, soma);
  return 0;
}
