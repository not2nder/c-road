#include <stdio.h>

int main() {
  /* ---------------- */
  /* Entrada de dados */
  /* ---------------- */

  // O comando principal de entrada de dados é o scanf()
  // para ele funcionar, precisa de um especificador e um endereço de memória

  int idade;
  printf("Informe sua idade: ");
  scanf("%d", &idade);
  //      │     └────────> Endereço da variável idade
  //      └──────────────> Especificador do tipo int
  
  // O operador & acessa o endereço da variável na memória
  // O scanf altera o valor nesse endereço para o valor recebido
  
  // O scanf também permite receber mais de um valor de uma vez:
  int n1, n2, n3;

  printf("Informe 3 notas: ");
  scanf("%d %d %d", &n1, &n2, &n3);
  printf("%d, %d, %d\n", n1,n2, n3);

  /* --------------------------- */
  /* Especificadores de formato  */
  /* --------------------------- */

  // Assim como o printf, o scanf também tem seus especificafores:

  /*
  ┌─────┬───────────────┐
  │ %d  │ int           │
  │ %f  │ float         │
  │ %lf │ double        │
  │ %c  │ char          │
  └─────┴───────────────┘
  */

  return 0;
}
