#include <stdio.h>

int main() {
  /* --------------------- */
  /* Modificadores de tipo */
  /* --------------------- */

  short int idade = 19;
  long int populacao = 100000L;
  long long int distancia = 9000000000LL;

  signed int temperatura = -10; // Inteiros com sinal (padrão)
  unsigned int moedas = 50;     // Inteiros sem sinal
  
  short ano = 2026;   // Equivalente a "short int"
  unsigned vidas = 7; // Equivalente a "unsigned int"
  int divida = -200;  // Equivalente a "signed int"

  /* ---------------------------- */
  /*  Especificadores para printf */
  /* ---------------------------- */

  /*
  ┌──────┬────────────────────┐
  │ %hd  │ short              │
  │ %ld  │ long               │
  │ %lld │ long long          │
  │ %d   │ int (com sinal)    │
  │ %u   │ unsigned int       │
  │ %hu  │ unsigned short     │
  │ %lu  │ unsigned long      │
  │ %llu │ unsigned long long │
  └──────┴────────────────────┘
  */

  /* 
    Nota: %h é o prefixo do modificador short.
    O "h" vem de "half" = metade
  */

  printf("Idade: %hd\n", idade);
  printf("Populacao: %ld\n", populacao);
  printf("Distancia: %lld\n", distancia);

  printf("Temperatura: %d\n", temperatura);
  printf("Moedas: %u\n", moedas);

  printf("Ano: %hd\n", ano);
  printf("Vidas: %u\n", vidas);
  printf("Divida: %d\n", divida);

  return 0;
}
