# MÓDULO 02: Tipos, variáveis e entrada/saída de dados

Vamos conhecer os principais tipos de dados da linguagem C, aprender a declarar e manipular variáveis, entender como representar valores constantes e explorar as operações básicas de entrada e saída de dados.

| Arquivo                              | Conteúdo                                                                             |
| ------------------------------------ | ------------------------------------------------------------------------------------ |
| [`variaveis.c`](variaveis.c)         | Declaração, inicialização e atribuição de variáveis                                  |
| [`tipos.c`](tipos.c)                 | Tipos primitivos e especificadores de formato do `printf()`                          |
| [`constantes.c`](constantes.c)       | Constantes com `const` e macros com `#define`                                        |
| [`saida.c`](saida.c)                 | Saída de dados, precisão, largura e alinhamento                                      |
| [`entrada.c`](entrada.c)             | Entrada de dados com `scanf()`                                                       |
| [`modificadores.c`](modificadores.c) | Modificadores de tipos inteiros e seus especificadores                               |
| [`operadores.c`](operadores.c)       | Operadores aritméticos, de atribuição, incremento, decremento, relacionais e lógicos |

Recomendo estudar os arquivos na seguinte sequência. Ela começa com os conceitos necessários para armazenar valores e avança gradualmente para a leitura, a exibição e a manipulação desses valores.

### 1. Variáveis

O código de [variaveis.c](variaveis.c) mostra como declarar e incializar uma variável.

```c
//┌──────> tipo
int x;
//  └────> nome
```

Para declarar uma variável, é preciso definir o tipo dela e o nome. Mais detalhes sobre tipos serão abordados em [tipos.c](tipos.c). Por enquanto utilizaremos o tipo primitivo int, para representar números inteiros.

A segunda forma de criar uma variável é inicializando junto o valor dela:

```c
//           ┌──────> valor inicial
int idade = 19;
// │      └──────> operador de atribuição
// └────────────> tipo e nome
```

Também é possível declarar múltiplas variáveis de uma só vez, com inicialização e sem incialização:

```c
// Sem inicialização:
int a, b, c;
```

> Dessa forma, não é possível prever o valor inicial que as 3 irão assumir. Elas assumem o que é chamado de lixo de memória.

```c
// Com inicialização:
int nota = 90, pontos = 10;
```

Com inicialização múltipla, duas ou mais variáveis do mesmo tipo podem receber valores individuais. Isso é equivalente a:

```c
int nota = 90;
int pontos = 10;
```

Também é possível utilizar incialização múltipla de forma parcial, definindo apenas os valores das variáveis que se quer ter um valor inicial:

```c
// Com inicialização (parcial)
int n1 = 5, n2, n3 = 7;
```

Isso é o mesmo que:

```c
int n1 = 5;
int n2;
int n3 = 7;
```

### 2.Tipos primitivos

Depois de entender como declarar variáveis, precisamos conhecer os tipos de dados que elas podem armazenar.

O Exemplo presente em [tipos.c](tipos.c) demonstra os chamados tipos primitivos de dados:

| Tipo   | Descrição                                         | Exemplo       |
| ------ | ------------------------------------------------- | ------------- |
| char   | Um caractere ou pequeno valor inteiro             | 'A', '7', '#' |
| int    | Números inteiros                                  | 10, -5, 0     |
| float  | Números de ponto flutuante, com precisão simples. | 1.75f, -3.75f |
| double | Números de ponto flutuante, com precisão dupla.   | 3.14159265359 |

Cada tipo de dado precisa de um código chamado de especificador de formato para ser utilizado no printf.

```c
printf("Nota: %d\n", nota);
printf("Incial: %c\n", inicial);
printf("Nota: %.2f\n", altura);
```

| Especificador | Tipo            |
| ------------- | --------------- |
| %d ou %i      | int             |
| %c            | char            |
| %f            | float ou double |
| %s            | string          |

### 3. Constantes

Constantes são valores que não devem ser modificados durante a execução normal do programa.

Existem duas formas de definir constantes em C: utilizando `const` e `define`. Apesar de possuirem finalidades semelhantes, operam de formas diferentes:

- `const`: declara um objeto com um tipo definido cujo valor não pode ser alterado normalmente.
- `#define`: é uma constante simbólica (também chamada de macro) que substitui um nome por um conteúdo durante a etapa de pré-processamento, antes da compilação. Diferentemente de const, não declara uma variável nem um objeto: o pré-processador realiza uma substituição de texto no código.

Antes do pré processamento:

```c
#define ANO 2026
int main() {
    printf("ANO: %d\n", ANO);
}
```

Depois do pré processamento:

```c
int main() {
    printf("ANO: %d\n", 2026);
}
```

### 4. Exibição e formatação de dados

O comando principal para saída de dados é o `printf()`. Ele imprime uma mensagem de texto no terminal.

```c
printf("Olá\n");
```

Além de imprimir textos soltos, é possível utilizar o printf para mostrar valores associados a variáveis, utilizados ao longo do código. Para isso, usa-se um código de formatação chamado de especificadores de tipo, como visto anteriormente:

```c
int idade = 19;
printf("Sua idade: %d anos.\n", idade);
//                  │              └────> variável
//                  └──> especificador do tipo int
```

Para números que possuem casas decimais, é possível definir a formatação desses números, especificando quantas casas decimais mostrar na saída:

```c
double pi = 3.14159265359;

printf("2 casas decimais: %.2f\n", pi);
printf("9 casas decimais: %.9f\n", pi);
//                          │└───────> especificador
//                          └────────> n° de casas decimais
```

Para números inteiros, é possível controlar a largura mínima do número mostrado:

```c
printf("%8d\n", 40);
//       └──> largura (8)
```

Como o número de casas especificadas no exemplo acima é 8 e o número 40 possui 2 dígitos, o resultado será o seguinte:

```bash
        40
```

Também é possível preencher esses espaços vazios com 0s no lugar dos espaços. Basta colocar um 0 ao lado do número que representa a largura mínima:

```c
printf("%08d\n", 40);
//       │└─────> largura (8)
//       └──────> preencher com zeros
```

O resultado será:

```bash
00000040
```

Também dá para definir para qual lado o texto será alinhado quando houver largura mínima. Por padrão, o texto é alinhado para a direita. Para alinhar para a esquerda, usa-se o caractere `-` para especificar o alinhamento:

```c
printf("|%10d|\n", 40);  // Alinhado à direita
printf("|%-10d|\n", 40); // Alinhado à esquerda
```

Resultado:

```bash
|        40|
|40        |
```

O mesmo pode ser feito com strings:

```c
printf("|%10s|\n", "Oi");
printf("|%-10s|\n", "Oi");
```

Resultado:

```bash
|        Oi|
|Oi        |
```

### 5. Leitura de dados

O comando principal para entrada de dados via terminal é o scanf(). Para ele funcionar, precisa de um especificador de tipo e um endereço de memória, associando o valor recebido ao endereço fornecido.

```c
int idade;
printf("Informe sua idade: ");
scanf("%d", &idade);
//      │     └─────> Endereço da variável idade
//      └───────────> Especificador do tipo int
```

O operador &, também chamado de operador de endereço, retorna o endereço de memória de uma variável (um código hexadecimal). Para utilizá-lo basta usar ele ao lado do nome da variável que se deseja acessar:

```c
int idade = 19;
printf("%p\n", &idade);
//       │     └───────────> Operador de endereço
//       └──────> Especificador para endereço
```

O resultado será algo como:

```bash
0x7ffe821348f4
```

Isso será util quando for aprender sobre ponteiros.

O `scanf` também permite receber vários valores de uma só vez:

```c
int n1, n2, n3;

printf("Informe 3 notas: ");
scanf("%d %d %d", &n1, &n2, &n3);
printf("%d, %d, %d\n", n1,n2, n3);i
```

Os especificadores de tipo para o scanf são:

| Especificador | Tipo   |
| ------------- | ------ |
| %d            | int    |
| %f            | float  |
| %lf           | double |
| %c            | char   |
| %s            | string |

É importante observar que os especificadores de leitura nem sempre são iguais aos de saída. Por exemplo, para ler um `float`, utilizamos `%f`; para ler um `double`, utilizamos `%lf`.
