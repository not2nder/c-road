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

### 6. Modificadores de tipo

Os tipos inteiros possuem variações que permitem representar diferentes faixas de valores. Para isso, utilizamos os modificadores short, long, long long, signed e unsigned.

Os modificadores se dividem em dois grupos:

- **Modificadores de tamanho:** `short`, `long` e `long long`.
- **Modificadores de sinal:** `signed` e `unsigned`.

Os modificadores de tamanho alteram a faixa de valores que um inteiro pode assumir.

| Tipo          | Uso geral                                               | Tamanho comum |
| ------------- | ------------------------------------------------------- | ------------: |
| int           | Inteiros de uso geral                                   |       4 bytes |
| short int     | Inteiros com faixa menor ou igual à de int              |       2 bytes |
| long int      | Inteiros com faixa mínima garantida maior que a de int  |  4 ou 8 bytes |
| long long int | Inteiros com faixa mínima garantida maior que a de long |       8 bytes |

Os tamanhos apresentados são comuns, mas podem variar conforme o sistema e o compilador. Por exemplo, em alguns sistemas, int e long ocupam 4 bytes, enquanto em outros long ocupa 8 bytes.

Os modificadores de sinal determinam quais valores inteiros podem ser representados.

| Modificador | Valores representados       | Exemplo    |
| ----------- | --------------------------- | ---------- |
| `signed`    | Negativos, zero e positivos | -10, 0, 25 |
| `unsigned`  | Zero e positivos            | 0, 10, 25  |

Em C, os tipos inteiros apresentados são signed por padrão quando o sinal não é especificado. Portanto, estas declarações são equivalentes:

```c
int temperatura = -10;
signed int temperatura = -10;
```

Já o tipo unsigned int representa apenas valores não negativos:

```c
unsigned int moedas = 50;
unsigned int pontos = 100;
```

Também podemos combinar os modificadores:

```c
short int idade = 19;
unsigned short int quantidade = 500;
long int populacao = 100000L;
long long int distancia = 9000000000LL;
unsigned long long int total = 10000000000ULL;
```

Quanto maior a quantidade de bits disponível, maior pode ser a faixa de valores representada. Em uma implementação na qual int ocupa 32 bits, por exemplo:

| Tipo         |   Valor mínimo |  Valor máximo |
| ------------ | -------------: | ------------: |
| int          | -2.147.483.648 | 2.147.483.647 |
| unsigned int |              0 | 4.294.967.295 |

Assim como os tipos básicos, suas variações precisam de especificadores adequados ao utilizar printf() e scanf().

| Tipo                   | printf | scanf |
| ---------------------- | ------ | ----- |
| short int              | %hd    | %hd   |
| unsigned short int     | %hu    | %hu   |
| int                    | %d     | %d    |
| unsigned int           | %u     | %u    |
| long int               | %ld    | %ld   |
| unsigned long int      | %lu    | %lu   |
| long long int          | %lld   | %lld  |
| unsigned long long int | %llu   | %llu  |

Utilizar um especificador incompatível com o tipo esperado pode causar comportamento indefinido, portanto é importante prestar atenção a esses detalhes.

#### Quando usar cada tipo?

- `int`: para valores comuns, idades, notas e contadores.
- `short`: quando uma faixa menor for suficiente e houver motivo para escolher essa variante.
- `long` ou `long long`: quando for necessário representar números maiores, verificando os limites disponíveis.
- `unsigned`: quando a faixa sem sinal for adequada ao problema, como em determinadas operações com bits.

Na maioria dos exercícios iniciais, int será suficiente. O mais importante é escolher um tipo que consiga representar os valores necessários.

### 7. Operadores

O arquivo [operadores.c](operadores.c) apresenta os operadores utilizados para calcular valores, modificar variáveis e comparar condições.

#### 7.1 Operadores aritméticos

São utilizados para realizar operações matemáticas.

| Operador | Operação                 |
| -------- | ------------------------ |
| +        | Adição                   |
| -        | Subtração                |
| \*       | Multiplicação            |
| /        | Divisão                  |
| %        | Resto da divisão inteira |

Exemplo:

```c
int a = 10, b = 3;

printf("Soma: %d\n", a + b);
printf("Subtração: %d", a - b);
printf("Multiplicação: %d", a * b);
printf("Divisão: %d\n", a / b);
printf("Resto: %d\n", a % b);
```

Saída:

```bash
Soma: 13
Subtração: 7
Multiplicação: 30
Divisão: 3
Resto: 1
```

Quando os dois valores da divisão são inteiros, a parte fracionária é descartada. Para obter casas decimais, utilize um valor de ponto flutuante:

```c
printf("%d\n", 10 / 3);       // 3
printf("%.2f\n", 10.0 / 3);   // 3.33
```

#### 7.2 Operadores de atribuição

Permitem realizar uma operação com o valor atual de uma variável e atribuir o resultado a ela mesma.

por exemplo:

```c
int pontos = 10;

pontos += 5;
pontos -= 3;
pontos *= 2;
```

É o mesmo que:

```c
pontos = pontos + 5;
pontos = pontos - 3;
pontos = pontos * 2;
```

Esses operadores são úteis para atualizar contadores, acumular valores e modificar variáveis sem precisar repetir seu nome em uma expressão de atribuição.

#### 7.3. Incremento e decremento

Os operadores `++` e `--` aumentam ou diminuem o valor de uma variável inteira em uma unidade.

| Operador | Nome           | Efeito                                                |
| -------- | -------------- | ----------------------------------------------------- |
| `++x`    | Pré-incremento | Incrementa `x` antes de produzir o valor da expressão |
| `x++`    | Pós-incremento | Produz o valor atual de `x` e depois o incrementa     |
| `--x`    | Pré-decremento | Decrementa `x` antes de produzir o valor da expressão |
| `x--`    | Pós-decremento | Produz o valor atual de `x` e depois o decrementa     |

Observe a diferença:

```c
int x = 5;

printf("%d\n", ++x);  // 6: incrementa antes de usar o valor
printf("%d\n", x++);  // 6: usa o valor atual e depois incrementa
printf("%d\n", x);    // 7: valor após o pós-incremento
```

Quando utilizados como instruções isoladas, `x++` e `++x` produzem o mesmo efeito final sobre a variável. A diferença importa quando o valor da expressão também é utilizado em outra operação.

Esses operadores são muito comuns em contadores e laços de repetição, como `for` e `while`.

#### 7.4. Operadores relacionais

Comparam dois valores e verificam se determinada relação é verdadeira ou falsa.

| Operador | Significado      | Exemplo | Resultado |
| -------- | ---------------- | ------- | --------- |
| ==       | Igual a          | 5 == 5  | 1         |
| !=       | Diferente de     | 5 != 3  | 1         |
| >        | Maior que        | 5 > 3   | 1         |
| <        | Menor que        | 5 < 3   | 0         |
| >=       | Maior ou igual a | 5 >= 5  | 1         |
| <=       | Menor ou igual a | 3 <= 5  | 1         |

Em C, expressões relacionais produzem `1` quando são verdadeiras e `0` quando são falsas.

```c
int idade = 19;

printf("%d\n", idade >= 18);  // 1: verdadeiro
printf("%d\n", idade < 18);   // 0: falso
```

Esses operadores serão utilizados frequentemente em estruturas condicionais, como `if` e `switch`, e em expressões de controle dos laços de repetição.

> **Atenção:** = e == possuem funções diferentes. O primeiro atribui um valor a uma variável; o segundo compara dois valores.

```c
int x = 5;     // Atribui 5 a x
printf("%d\n", x == 5);  // Compara x com 5
```

#### 7.5. Operadores lógicos

Permitem combinar condições ou inverter seu resultado. Em C, são três os principais operadores lógicos:

| Operador | Nome       | Funcionamento                                          |
| -------- | ---------- | ------------------------------------------------------ |
| `&&`     | E lógico   | Verdadeiro quando ambas as condições são verdadeiras   |
| `\|\|`   | OU lógico  | Verdadeiro quando pelo menos uma condição é verdadeira |
| `!`      | NÃO lógico | Inverte o resultado lógico de uma condição             |

Considere as seguintes condições:

```c
int idade = 19;
int tem_ingresso = 1;

printf("%d\n", idade >= 18 && tem_ingresso); // 1
printf("%d\n", idade < 18 || tem_ingresso);  // 1
printf("%d\n", !(idade >= 18));              // 0
```

No primeiro caso, ambas as condições são verdadeiras, então o resultado é `1`. No segundo, basta que uma delas seja verdadeira. No terceiro, o operador `!` inverte o resultado da condição.

Podemos resumir o comportamento dos operadores lógicos com a tabela abaixo, considerando `1` como verdadeiro e `0` como falso:

|   A |   B | A && B | A \|\| B |
| --: | --: | -----: | -------: |
|   0 |   0 |      0 |        0 |
|   0 |   1 |      0 |        1 |
|   1 |   0 |      0 |        1 |
|   1 |   1 |      1 |        1 |

O operador `!` funciona com apenas uma condição: `!0` resulta em `1`, enquanto `!1` resulta em `0`.

**Curiosidade:** em C, qualquer valor diferente de zero é considerado verdadeiro em uma condição, enquanto zero é considerado falso. Os operadores relacionais e lógicos produzem `0` ou `1`, mas as condições não precisam ser expressas exclusivamente por esses números.

## 💡 Recomendações de estudo

- Leia um arquivo por vez e execute os exemplos no seu ambiente.
- Antes de executar, tente prever a saída de cada instrução.
- Altere os valores das variáveis e observe como os resultados mudam.
- Experimente criar exemplos próprios, em vez de apenas reproduzir os apresentados.
- Consulte os comentários do código para identificar a função de cada parte e utilize este README para revisar os conceitos.
