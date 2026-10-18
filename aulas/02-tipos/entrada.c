#include <stdio.h>

int main(void) {
  /* ---------------- */
  /* Entrada de dados */
  /* ---------------- */

  // O comando principal de entrada de dados formatada é scanf().
  // Ele utiliza especificadores de formato e endereços de memória.

  int idade;

  printf("Informe sua idade: ");
  scanf("%d", &idade);
  //      │     └────────> Endereço da variável idade
  //      └──────────────> Especificador do tipo int
  
  // O operador & acessa o endereço da variável na memória
  // O scanf altera o valor nesse endereço para o valor recebido
  
  // O scanf também permite receber mais de um valor de uma vez:
  int n1, n2, n3;

  printf("Informe três notas: ");
  scanf("%d %d %d", &n1, &n2, &n3);

  printf("Notas: %d, %d, %d\n", n1, n2, n3);

  /* --------------------------- */
  /* Especificadores de formato  */
  /* --------------------------- */

  /*
  ┌─────┬─────────────────────────────┐
  │ %d  │ int                         │
  │ %f  │ float (em scanf)            │
  │ %lf │ double (em scanf)           │
  │ %c  │ char                        │
  │ %s  │ sequência de caracteres     │
  └─────┴─────────────────────────────┘
  */

  /* --------------------------- */
  /* Entrada de texto com scanf  */
  /* --------------------------- */

  // O scanf também pode ler texto utilizando %s.
  // Porém, a leitura termina ao encontrar um espaço em branco.

  char nome[50]; // Define uma sequência de até 50 caracteres.

  printf("Informe seu primeiro nome: ");
  scanf("%49s", nome);

  // %49s limita a leitura a 49 caracteres.
  // A string também precisa de espaço para o terminador '\0',
  // que indica o fim do texto em C.
  
  printf("Olá, %s!\n", nome);

  // O scanf com o especificador %s naturalmente não lê sequências com espaços.

  /* --------------------------- */
  /* Entrada de texto com fgets  */
  /* --------------------------- */

  // fgets() permite ler uma linha de texto, incluindo espaços.
  // O tamanho informado limita a quantidade de caracteres lidos.

  /*
    Sintaxe:
    fgets(variavel, tamanho, origem);
   
    variavel: onde o texto será armazenado
    tamanho: quantidade máxima de caracteres a serem lidos, incluindo espaço para o terminador '\0'
    origem: de onde os dados serão lidos (stdin = teclado)
  */

  char frase[100];

  printf("Digite uma frase: ");
  fgets(frase, sizeof(frase), stdin);
  //             └────> Tamanho de frase em bytes (100) 
  
  // sizeof retorna o tamanho, em bytes, de uma variável ou tipo.
  // Como frase possui espaço para 100 elementos char,
  // sizeof(frase) retorna 100.

  // Usamos sizeof para não precisar informar o tamanho manualmente.

  printf("Frase digitada: %s", frase);

  /* ---------------- */
  /* Sobre gets()     */
  /* ---------------- */

  /*
    gets() era utilizada para ler uma linha de texto, mas não
    permitia informar o limite de caracteres que poderiam ser
    armazenados.
   
    Isso poderia causar estouro de memória. Por esse motivo,
    gets() foi removida do padrão C11 e não deve ser utilizada.
   
    Prefira fgets(), que permite informar o limite de leitura.
  */

  return 0;
}

