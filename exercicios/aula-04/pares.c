#include <stdio.h>

int main() {
  int n1, n2, soma = 0;
  //      └───> declara os dois números + contador.

  printf("Informe dois números: ");
  scanf("%d %d", &n1, &n2);
  //       └────> escaneia os dois números em uma linha

  // Verifica a ordem dos números para percorrer o intervalo corretamente.

  if (n2 > n1) {
    // Percorre o intervalo de n1 até n2, incluindo os dois extremos.
    for (int i = n1; i <= n2; i++){
      if (i %2 == 0) {
        // Se o número for par, adiciona seu valor ao acumulador.
        soma += i;
      } 
    }
  }
  else {
    // Percorre o intervalo começando de n2.
    for (int i = n2; i <= n1; i++){
      if (i %2 == 0) {
        // mesma lógica
        soma += i;
      } 
    }
  }

  printf("A soma dos números pares entre %d e %d é: %d\n", n1, n2, soma);
  return 0;
}
