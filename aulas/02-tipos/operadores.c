#include <stdio.h>

int main() {
  /* ---------------------- */
  /* Operadores Aritméticos */
  /* ---------------------- */

  int a = 10, b = 3;

  /*
  ┌───┬───────────────┐
  │ + │ Soma          │
  │ - │ Subtração     │
  │ * │ Multiplicação │
  │ / │ Divisão       │
  │ % │ Resto         │
  └───┴───────────────┘
  */

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
  numero /= 5; // divide o número por 2
  numero %= 5; // tira o resto da divisão

  /* ----------------------- */
  /* Incremento e decremento */
  /* ----------------------- */

  int contador = 0;

  contador++; // O mesmo que contador = contador+1 ou contador+=1
  contador--; // O mesmo que contador = contador-1 ou contador-=1

  /* ---------------------- */
  /* Operadores relacionais */
  /* ---------------------- */

  /*
  ┌─────┬─────────────────┐
  │ ==  │ Igual           │
  │ !=  │ Diferente       │
  │ >   │ Maior           │
  │ <   │ Menor           │
  │ >=  │ Maior ou igual  │
  │ <=  │ Menor ou igual  │
  └─────┴─────────────────┘
  */

  printf("a == b: %d\n", a == b);
  printf("a != b: %d\n", a != b);
  printf("a > b: %d\n", a > b);
  printf("a < b: %d\n", a < b);
  printf("a >= b: %d\n", a >= b);
  printf("a <= b: %d\n", a <= b);

  /* Nota: A saída das expressões sempre será 0 ou 1 (true ou false)*/

  /* ---------------------- */
  /* Operadores logicos     */
  /* ---------------------- */

  /*
  ┌─────┬───────────┐
  │ &&  │ E (AND)   │
  │ ||  │ OU (OR)   │
  │ !   │ NOT       │
  └─────┴───────────┘
  */

  printf("E logico: %d\n", (a > 0) && (b > 0)); // 1 E 1 = 1
  printf("OU logico: %d\n", (a > 0) || (b < 0)); // 1 OU 1 = 1
  printf("NÃO logico: %d\n", !(a > 0)); // NÃO 1 = 0

  return 0;
}
