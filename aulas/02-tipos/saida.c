#include <stdio.h>

int main() {
  /* -------------- */
  /* Saída de Dados */
  /* -------------- */
  
  // O comando principal de saída é o printf()
  printf("Olá!\n");

  // Para exibir valores associados a variáveis, usamos especificadores, que começam com %
  int idade = 19;
  printf("Sua idade é %d anos.\n", idade);
  //                   │              └──────> variável associada ao especificador
  //                   └─────────────────────> especificador do tipo int

  /* ---------------------- */
  /* Precisão e alinhamento */
  /* ---------------------- */
  
  double pi = 3.14159265359;

  // Para pontos flutuantes (float/double) é possível controlar o número de casas decimais
  printf("PI com 2 casas decimais: %.2f\n", pi);
  printf("PI com 9 casas decimais: %.9f\n", pi);
  //                                 │└──────────> especificador de ponto flutuante
  //                                 └───────────> número de casas decimais

  // Para números inteiros, é possível controlar a largura mínima:
  printf("%8d\n", 40);
  //       └─────────> número de casas (8)
  
  printf("%08d\n", 40);
  //       │└─────────> número de casas (8)
  //       └────────────────> preencher com zeros

  // Também é possível definir o alinhamento (esquerda ou direita)
  printf("|%10d|\n", 40);  // Alinhado à direita
  printf("|%-10d|\n", 40); // Alinhado à esquerda

  // O mesmo se aplica para Strings:
  printf("|%10s|\n", "Oi");
  printf("|%-10s|\n", "Oi");

  return 0;
}
