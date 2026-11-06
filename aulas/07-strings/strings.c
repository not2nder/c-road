#include <stdio.h>

int main() {
  /* ------------ */
  /* Strings em C */
  /* ------------ */
  
  // Em C não existe um tipo primitivo string
  // Toda string é um vetor de caracteres (char)

  char nome[10] = "Pedro";
  //         └────> Tamanho da string  

  // Os outros espaços serão preenchidos com Null Terminator ('\0').

  char sobrenome[] = "da Silva";
  //             └────> O compilador calcula o tamanho necessário incluindo '\0';

  printf("Nome e sobrenome: %s %s\n", nome, sobrenome);
  //                         └────> o especificador para String é %s 

  /* -------------------- */
  /* Acessando caracteres */
  /* -------------------- */

  // O comportamento de strings é semelhante ao de vetores:

  printf("Primeiro caractere: %c\n", nome[0]);
  printf("Segundo caractere: %c\n", nome[1]);
  printf("Terceiro aractere: %c\n", nome[2]);

  // Modificando caracteres:

  nome[4] = 'a';

  printf("%s\n", nome);

  return 0;
}
