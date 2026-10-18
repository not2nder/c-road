#include <stdio.h>

int main(void) {
  /* ------------------------------- */
  /* Estruturas de controle de fluxo */
  /* ------------------------------- */

  /* ---------------- */
  /* 1. if-else       */
  /* ---------------- */

  int idade = 18;

  //     ┌──────────────> Condição: verifica se idade >= 18
  if (idade >= 18) {
    printf("Maior de idade\n"); // ──> Executado se a condição for verdadeira
  } else {
    printf("Menor de idade\n"); // ──> Executado se a condição for falsa
  }

  /* ---------------------- */
  /* 2. Múltiplas condições */
  /* ---------------------- */

  int nota = 7;

  //      ┌─────────> Primeira condição
  if (nota >= 7) {
    printf("Aprovado\n");
  }
  //        ┌───────> Verificada se a primeira condição for falsa
  else if (nota >= 4) {
    printf("Recuperação\n");
  }
  // ┌──────────────> Executado se nenhuma condição anterior for verdadeira
  else {
    printf("Reprovado\n");
  }

  /* --------------------- */
  /* 3. Operador ternário  */
  /* --------------------- */

  /*
   * Sintaxe:
   * Condição ? valor se verdadeiro : valor se falso
  */

  printf(idade >= 18 ? "Maior de idade\n" : "Menor de idade\n");

  // Operador ternário múltiplo

  //      ┌────► Condição 1         ┌────► Condição 2                          
  printf(nota >= 7? "Aprovado\n": nota >= 4? "Recuperação\n": "Reprovado\n");    
  //                                                             └───► Último caso

  /* ---------------- */
  /* 4. switch-case   */
  /* ---------------- */

  int dia = 5;

  //       ┌──────────────> Valor que será comparado com os cases
  switch (dia) {
    //       ┌────────────> Caso o valor seja 1
    case 1:
      printf("Segunda-feira\n");
      break; // ──────────> Encerra o switch

    case 2:
      printf("Terça-feira\n");
      break;

    case 3:
      printf("Quarta-feira\n");
      break;

    case 4:
      printf("Quinta-feira\n");
      break;

    case 5:
      printf("Sexta-feira\n");
      break;

    case 6:
      printf("Sábado\n");
      break;

    case 7:
      printf("Domingo\n");
      break;

    // ┌───────────> Executado se nenhum case corresponder ao valor
    default:
      printf("Valor inválido\n");
      break;
  }

  return 0;
}
