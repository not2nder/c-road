#include <stdio.h>

int main() {
  float media = 0; // contador da média

  for (int i = 0; i < 4; i++) {
    float nota;
    printf("Informe a nota %d: ", i);
    scanf("%f", &nota);

    media += nota;
    //     └───> soma a nota à média a cada repetição
  }

  media /= 4;
  //    └───> divide o somatório por 4
  //    (Também poderia estar dentro do for)

  if (media >= 7.0) {
    // Caso a média deja 7:
    printf("Aprovado por média\n");
  }
  else if (media >= 4.0) { 
    // Caso a media seja menor que 7, mas maior 4:
    printf("Na prova final\n");
  }
  else {
    // Último caso:
    printf("Reprovado");
  }

  return 0;
}
