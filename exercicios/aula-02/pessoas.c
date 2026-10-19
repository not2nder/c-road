#include <stdio.h>

int main() {
  char pessoa1[21]; // 20 caracteres + terminator
  char pessoa2[21];
  char pessoa3[21];

  float altura1, altura2, altura3;

  // Pessoa 1
  printf("Digite seu primeiro nome: ");
  scanf("%20s", pessoa1);

  printf("Digite sua altura: ");
  scanf("%f", &altura1);

  // Pessoa 2
  printf("Digite seu primeiro nome: ");
  scanf("%20s", pessoa2);

  printf("Digite sua altura: ");
  scanf("%f", &altura2); 

  // Pessoa 3
  printf("Digite seu primeiro nome: ");
  scanf("%20s", pessoa3);
  
  printf("Digite sua altura: ");
  scanf("%f", &altura2);
  
  // Tabela
  printf("%-20s%s\n", "Nome", "Altura");
  printf("---------------------------\n");
  printf("%-20s%.2fm\n", pessoa1, altura1);
  printf("%-20s%.2fm\n", pessoa2, altura2);
  printf("%-20s%.2fm\n", pessoa3, altura3);

  return 0;
}
