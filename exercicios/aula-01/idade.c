#include <stdio.h>

int main() {
  int nascimento = 2006;
  int idade = 20;

  // caso não tenha feito aniversário:
  // idade++;

  int ano_atual = nascimento + idade;

  printf("%d\n", ano_atual);

  return 0;
}
