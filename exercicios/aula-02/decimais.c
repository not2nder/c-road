#include <stdio.h>

int main() {
  int d_euler, d_aur;

  const double euler = 2.718281828;
  const double aur = 1.618033988;

  printf("Entre com a quantidade de casas decimais para euler: ");
  scanf("%d", &d_euler);
  
  printf("Entre com a quantidade de casas decimais para áureo: ");
  scanf("%d", &d_aur);

  printf("Valor de euler: %.*lf\n", d_euler, euler);
  printf("Valor de aureo: %.*lf\n", d_aur, aur);

  return 0;
}
