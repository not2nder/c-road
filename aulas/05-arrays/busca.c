#include <stdio.h>

/* Contexto: 
   Busca linear é um algoritmo de busca que se resume a:
   percorrer um vetor, elemento por elemento e comparar
   com um valor que precisa ser encontrado, chamado de chave.
*/

int main() {
  int lista[4] = {83, 11, 55, 84};
  int chave = 11, achado = 0, indice = -1;

  for (int i = 0; i < 4; i++) {
    if (lista[i] == chave) {
      achado = 1;
      indice = i; // Se quiser salvar o índice (opcional)
      break;      // Parar quando achar o elemento
    }
  }

  if (achado) {
    printf("Elemento %d encontrado no índice %d\n", chave, indice);
  }

  // forma alternativa: usando while
  
  int numeros[4] = {2,5,7,3};
  int i = 0;
  achado = 0;
  chave = 7;

  //           ┌────► enquanto estiver percorrendo e não tiver achado
  while (i < 4 && !achado) {
    if (numeros[i] == chave) {
      achado = 1; // Invalida a condição do while e para o loop
    } else {
      i++;
    }
  }

  // A escolha entre os dois depende do nível de legibilidade e estilo de código

  return 0;
}
