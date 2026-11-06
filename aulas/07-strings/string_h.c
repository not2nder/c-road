#include <stdio.h>
#include <string.h>
//        └────> biblioteca com funções dedicadas a strings

int main() {

  /* -------- */
  /* string.h */  
  /* -------- */
  
  // Tamanho de uma string:

  char nome[10] = "Ana";

  // O operador sizeof informa o tamanho do vetor em bytes:

  printf("Tamanho (bytes): %zu\n", sizeof(nome)); // 10

  // O ideal para contar os caracteres é usar a função strlen:

  printf("Tamanho (caracteres): %zu\n", strlen(nome)); // 3

  return 0;
} 
