#include <stdio.h>

int main() {
  /* ---------------------- */
  /* Operadores Aritméticos */
  /* ---------------------- */

  int a = 10, b = 3;

  printf("Soma: %d\n", a + b);
  printf("Subtração: %d\n", a - b);
  printf("Multiplicação: %d\n", a * b);
  printf("Divisão: %d\n", a / b);
  printf("Resto: %d\n", a % b);
  
  /* ------------------------ */
  /* Operadores de Atribuição */
  /* ------------------------ */

  int numero = 10;

  numero += 5; // adiciona 5 ao número
  numero -= 5; // subtrai 5 do número
  numero *= 5; // multiplica o número por 5
  numero /= 5; // divide o número por 5
  numero %= 5; // tira o resto da divisão

  /* ----------------------- */
  /* Incremento e decremento */
  /* ----------------------- */

  int contador = 0;

  contador++; // Incrementa em 1 (contador += 1)
  printf("%d\n", contador);
  contador--; // Decrementa em 1 (contador -= 1)
  printf("%d\n", contador);

  /* O incremento e decremento isolados funcionam da mesma forma,
   * mas em uma expressão, possuem comportamento diferente */

  printf("Pré incremento: %d\n", ++contador); // Incrementa e depois imprime 
  printf("Pré decremento: %d\n", --contador); // Decrementa e depois imprime
  
  printf("Pré incremento: %d\n", contador++); // Imprime depois incrementa
  printf("Pré decremento: %d\n", contador--); // Imprime depois decrementa
  

  /* ---------------------- */
  /* Operadores relacionais */
  /* ---------------------- */

  printf("A igual a B: %d\n", a == b);
  printf("A diferente de B: %d\n", a != b);
  printf("A maior que B: %d\n", a > b);
  printf("A menor que B: %d\n", a < b);
  printf("A maior igual a B: %d\n", a >= b);
  printf("A menor igual a B: %d\n", a <= b);

  /* A saída de expressões lógicas resulta em 1 ou 0 (verdadeiro ou falso) */

  /* ---------------------- */
  /* Operadores logicos     */
  /* ---------------------- */

  /*
  ┌─────┬───────────┐
  │ &&  │E (AND)    │
  │ ||  │OU (OR)    │
  │ !   │NÃO (NOT)  │
  └─────┴───────────┘
  */

  printf("E logico: %d\n",  (a > 0) && (b > 0)); // 1 E 1  = 1
  printf("OU logico: %d\n", (a > 0) || (b < 0)); // 1 OU 1 = 1
  printf("NÃO logico: %d\n", !(a > 0));          // NOT 1  = 0

  return 0;
}
