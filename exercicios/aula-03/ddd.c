#include <stdio.h>

int main() {
  int ddd;
  printf("Informe o código DDD: ");
  scanf("%d", &ddd);

  //       ┌────> variável a ser comparada
  switch (ddd) {
    case 11:
      printf("Valor da conta: R$ 65,00\n");
      break;
    case 32:
      printf("Valor da conta: R$ 60,00\n");
      break;
    case 62:
      printf("Valor da conta: R$ 55,00\n");
      break;
    case 83:
      printf("Valor da conta: R$ 50,00\n");
      break;
    default:
      // └───> caso fora dos indicados
      printf("Não estamos operando nesse estado.\n");
      break;
  }

  return 0;
}
