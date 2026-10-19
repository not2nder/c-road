# Sintaxe da linguagem C

Este guia apresenta os principais elementos da sintaxe de C e explica como eles se organizam em um programa.

Se você já estudou Python, vai perceber algumas diferenças importantes. Se está começando agora, não se preocupe: os exemplos apresentam os conceitos gradualmente.

Você não precisa memorizar tudo de uma vez. Use este documento como material de consulta durante os estudos.

## 1. Estrutura básica de um programa

Vamos começar com um programa simples:

```c
#include <stdio.h>

int main(void) {
    printf("Olá, mundo!\n");
    return 0;
}
```

Cada parte possui uma função:

- `#include <stdio.h>`: permite utilizar recursos de entrada e saída, como `printf()`.
- `int main(void)`: declara a função principal, por onde a execução começa.
- `{` e `}`: delimitam o bloco de código da função.
- `printf()`: exibe uma mensagem no terminal.
- `return 0;`: indica que o programa terminou com sucesso.

## 2. C e Python

As duas linguagens possuem variáveis, condições, repetições e funções, mas escrevem esses elementos de maneiras diferentes.

### 2.1. Blocos de código

No Python, a indentação determina os blocos. Em C, essa função é desempenhada pelas chaves `{}`.

Python:

```python
idade = 18

if idade >= 18:
    print("Maior de idade")
```

C:

```c
int idade = 18;

if (idade >= 18) {
    printf("Maior de idade\n");
}
```

Em C, a indentação serve principalmente para facilitar a leitura: são as chaves que delimitam os blocos.

Isso significa que o código abaixo, embora mal formatado, continua válido em C:

```c
if (idade >= 18) {
printf("Maior de idade\n");
}
```

O programa pode funcionar, mas a falta de indentação dificulta a leitura. Por isso, mesmo que o compilador não dependa dela para reconhecer os blocos, nós devemos utilizá-la para organizar o código.

### 2.2. Variáveis e ponto e vírgula

Em Python, normalmente basta atribuir um valor a uma variável

```python
idade = 18
```

Em C, toda variável tem que ter seu tipo definido.

```c
int idade = 18;
```

Além disso, a maioria das instruções simples em C termina com ponto e vírgula (`;`):

```c
int idade = 18;        // declara a variável idade
printf("%d\n", idade); // imprime um texto
```

O ponto e vírgula encerra a instrução, mas não deve ser colocado indiscriminadamente depois de qualquer elemento do programa.

## 3. Os símbolos mais importantes

| Símbolo | Função                                                                         |
| ------- | ------------------------------------------------------------------------------ |
| `;`     | Encerra a maioria das instruções e declarações.                                |
| `{ }`   | Delimitam blocos de código e podem agrupar valores na inicialização de arrays. |
| `( )`   | Aparecem em condições, expressões e chamadas de funções.                       |
| `[ ]`   | São utilizados para declarar arrays e acessar seus elementos.                  |
| `,`     | Separa argumentos, parâmetros e outros elementos.                              |
| `"`     | Delimita strings, como `"Olá!"`.                                               |
| `'`     | Delimita constantes de caractere, como `'A'`.                                  |
| `#`     | Inicia diretivas do pré-processador, como `#include` e `#define`.              |

Observe alguns desses símbolos em conjunto:

```c
int numeros[3] = {10, 20, 30};

if (numeros[0] > 5) {
    printf("%d\n", numeros[0]);
}
```

- `[]` aparece na declaração e no acesso ao array.
- `{}` agrupa os valores iniciais do array e delimita o bloco do `if`.
- `()` delimita a condição e os argumentos da chamada de `printf()`.

## 4. Diferentes estilos de escrita

A sintaxe define as regras que o código precisa respeitar. A formatação determina como organizamos esse código visualmente.

Por exemplo, este programa é válido, mesmo com tudo em uma única linha:

```c
#include <stdio.h>
int main(void) { printf("Olá, mundo!\n"); return 0; }
```

Entretanto, separar as instruções facilita a leitura:

```c
#include <stdio.h>

int main(void) {
    printf("Olá, mundo!\n");
    return 0;
}
```

Também existem diferentes convenções para posicionar as chaves.

**Chave na mesma linha:**

```c
if (idade >= 18) {
    printf("Maior de idade\n");
} else {
    printf("Menor de idade\n");
}
```

**Chave na linha seguinte:**

```c
if (idade >= 18)
{
    printf("Maior de idade\n");
}
else
{
    printf("Menor de idade\n");
}
```

As duas versões são válidas e possuem o mesmo comportamento. O importante é manter um padrão consistente no código.

Também podemos distribuir uma chamada de função ou uma expressão por várias linhas:

```c
printf(
    "Olá, mundo!\n"
);
```

```c
int resultado = primeiro_valor
              + segundo_valor
              + terceiro_valor;
```

As quebras de linha ajudam a organizar o código sem necessariamente alterar seu significado.

C também concatena strings literais adjacentes automaticamente:

```c
printf("Olá, "
       "mundo!\n");
```

Isso equivale a:

```c
printf("Olá, mundo!\n");
```

**Atenção:** a quebra de linha no código-fonte não é a mesma coisa que `\n`, que representa uma quebra de linha na saída.

Por exemplo, isto é válido:

```c
printf("Olá, mundo!\n");
```

Mas inserir uma quebra de linha física dentro de uma string comum, antes de fechar as aspas, causa um erro de compilação:

```c
printf("Olá, mundo!
");
```

## 5. Instruções, declarações e blocos

Uma declaração introduz elementos como variáveis. Uma instrução representa uma ação realizada pelo programa.

```c
int idade = 18;        // Declara e inicializa uma variável
idade = idade + 1;     // Atribui um novo valor
printf("%d\n", idade); // Exibe o valor
```

Um bloco reúne instruções entre chaves:

```c
if (idade >= 18) { // início do bloco
    printf("Maior de idade\n");
    printf("Pode continuar\n");
} // fim do bloco
```

As chaves também delimitam o escopo de variáveis locais:

```c
{
    int numero = 10; // numero só existe aqui
    printf("%d\n", numero);
}

// numero não pode ser utilizado aqui.
```

A variável `numero` só pode ser acessada dentro do bloco em que foi declarada. Isso se aplica para variáveis criadas dentro de estruturas como `if`, `for`, `while`, `do while` e etc.

### Cuidado com o ponto e vírgula

Observe este exemplo:

```c
if (idade >= 18); {
    printf("Maior de idade\n");
}
```

O `;` depois do `if` forma uma instrução vazia. Assim, o bloco seguinte é executado independentemente da condição.

O correto é:

```c
if (idade >= 18) {
    printf("Maior de idade\n");
}
```

O mesmo cuidado vale para repetições:

```c
while (i > 0); {
    printf("%d\n", i);
}
```

Nesse caso, o `while` possui um corpo vazio. Se `i` for maior que zero e não mudar, o programa ficará preso em um laço infinito, sem executar o `printf()`.

Já o ponto e vírgula depois da chave final, como em `while (i > 0) { ... };`, é desnecessário, mas não provoca esse mesmo problema.

## 6. Variáveis e expressões

### 6.1. Declaração, inicialização e atribuição

```c
int idade;          // Declaração
int quantidade = 5; // Declaração com inicialização

idade = 18;         // Atribuição posterior
```

Também podemos declarar mais de uma variável do mesmo tipo:

```c
int x = 10, y = 20;
```

Declarar variáveis separadamente pode facilitar a leitura quando elas possuem finalidades diferentes.

### 6.2. Operadores e expressões

Uma expressão combina valores, variáveis e operadores para produzir um resultado.

```c
int resultado = (10 + 5) * 2;
```

O resultado é `30`. Os parênteses indicam que a soma deve acontecer antes da multiplicação.

A precedência dos operadores também pode ser observada aqui:

```c
int resultado = a + b * c;
int resultado = a + (b * c);
```

As duas expressões possuem o mesmo significado, pois a multiplicação tem precedência sobre a adição.

Existem também diferentes formas de incrementar uma variável:

```c
contador = contador + 1;
contador += 1;
contador++;
```

Nas três formas, `contador` aumenta em uma unidade.

## 7. Condições e repetições

### 7.1. Condicional `if` e `else`

```c
if (nota >= 7) {
    printf("Aprovado\n");
} else {
    printf("Reprovado\n");
}
```

A condição fica entre parênteses, e os blocos são delimitados por chaves. O `else` é opcional e representa a alternativa executada quando a condição é falsa.

### 7.2. Repetição com `for`

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

Os três elementos dentro dos parênteses são separados por ponto e vírgula:

- **Inicialização:** `int i = 0`
- **Condição:** `i < 5`
- **Atualização:** `i++`

Nesse caso, os pontos e vírgulas separam os elementos do cabeçalho do `for`; não encerram o laço inteiro.

### 7.3. Repetição com `while`

```c
int i = 0;

while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

O laço continua enquanto a condição for verdadeira. Observe que não colocamos ponto e vírgula depois da condição quando o corpo é um bloco entre chaves.

## 8. Comentários

Comentários ajudam a explicar o código e não são executados como instruções.

**Uma linha:**

```c
// Calcula a média das notas.
```

**Várias linhas:**

```c
/*
 * Este comentário ocupa
 * várias linhas.
 */
```

Comentários são úteis para explicar decisões ou detalhes que não são óbvios. Evite, porém, explicar operações simples quando o próprio código já deixa sua intenção clara.
