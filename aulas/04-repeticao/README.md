# MÓDULO 04: Estruturas de Repetição

As estruturas de repetição permitem executar um bloco de código várias vezes, evitando a necessidade de escrever as mesmas instruções repetidamente.

Em C, como na maioria das outras linguagens de programação, existem pelo menos 2 ou 3 instruções de repetição diferentes.

## 1. Laço for

O `for` utilizado principalmente quando existe uma contagem ou sequência de repetições bem definida. É a opção mais prática quando se sabe o valor inicial, valor final e intervalo de contagem.

### Sintaxe

```c
for (inicialização; condição; atualização) {
    // Código a ser repetido
}
```

A estrutura possui três partes, separadas por ponto e vírgula:

- **Inicialização:** executada uma única vez, antes da primeira verificação da condição. Declarando e inicializando uma variável de controle.
- **Condição:** verificada antes de cada repetição. Se for verdadeira, o bloco será executado; se for falsa, o laço termina.
- **Atualização:** executada ao final de cada repetição, geralmente para incrementar ou decrementar a variável de controle.

### Exemplo

```c
for (int i = 0; i < 5; i++) {
    printf("Olá!\n");
}
```

**Saída:**

```text
Olá!
Olá!
Olá!
Olá!
Olá!
```

Nesse exemplo:

1. `int i = 0` cria a variável `i` e começa sua contagem em zero.
2. `i < 5` permite a repetição enquanto `i` for menor que 5.
3. `i++` incrementa `i` em uma unidade ao final de cada repetição.

Como a variável começa em 0 e o laço termina quando a condição deixa de ser verdadeira, o bloco é executado cinco vezes: para os valores de i iguais a 0, 1, 2, 3 e 4.

### Outras formas de atualização

Embora `i++` seja bastante comum, existem outras formas de atualizar uma variável.

```c
for (int i = 0; i < 5; i += 1) {
    printf("%d\n", i);
}
```

Nesse exemplo, `i += 1` incrementa a variável em uma unidade. Essa expressão equivale a:

```c
i = i + 1;
```

Portanto, para esse uso, `i++`, `i += 1` e `i = i + 1` produzem o mesmo efeito sobre a variável.

Também podemos alterar a variável em quantidades diferentes:

```c
for (int i = 0; i <= 10; i += 2) {
    printf("%d\n", i);
}
```

**Saída:**

```text
0
2
4
6
8
10
```

Nesse caso, adicionando duas unidades a cada repetição.

A atualização não precisa necessariamente incrementar uma variável: podemos decrementá-la ou atualizar outros valores, dependendo do problema.

### Escopo da variável de controle

Quando declaramos a variável no cabeçalho do `for`, como em `int i = 0`, ela fica limitada ao escopo do laço.

```c
for (int i = 0; i < 3; i++) {
    printf("%d\n", i);
}

// A variável i não pode ser utilizada aqui.
```

Se precisarmos utilizar a variável depois do laço, podemos declará-la antes:

```c
int i;

for (i = 0; i < 3; i++) {
    printf("%d\n", i);
}

printf("Valor final: %d\n", i);
```

**Saída:**

```text
0
1
2
Valor final: 3
```

O escopo determina onde uma variável pode ser acessada. Em C, uma variável declarada dentro de um bloco normalmente só pode ser utilizada dentro desse bloco, a partir de sua declaração.

## 2. Laço while

O `while` executa um bloco de código enquanto uma condição for verdadeira. É bastante útil quando a repetição depende de uma condição que pode mudar durante a execução.

### Sintaxe

```c
while (condição) {
    // Código a ser repetido
}
```

Antes de cada repetição, o programa verifica a condição. Se ela for verdadeira, executa o bloco; caso contrário, encerra o laço.

### Exemplo

```c
int i = 0;

while (i < 5) {
    printf("Valor de i: %d\n", i);
    i++;
}
```

**Saída:**

```text
Valor de i: 0
Valor de i: 1
Valor de i: 2
Valor de i: 3
Valor de i: 4
```

Nesse exemplo, a variável `i` é inicializada antes do laço. Enquanto `i` for menor que 5, seu valor será exibido e, em seguida, incrementado.

Diferente do exemplo com `for`, a inicialização e a atualização são feitas de forma separada, enquanto o `for` reúne tudo em uma estrutura só.

### Laços infinitos

Quando a condição depende de uma variável que deveria mudar durante a repetição, é importante garantir que essa atualização aconteça.

```c
int i = 0;

while (i < 5) {
    printf("%d\n", i);
    // Esquecemos de atualizar i!
}
```

Nesse exemplo, `i` permanece igual a zero. Como a condição `i < 5` continua verdadeira, o laço não termina normalmente.

Esse comportamento é chamado de **laço infinito**. Ele pode ser intencional em alguns programas, mas, quando acontece por engano, pode impedir que o programa continue seu fluxo esperado.

Nem todo `while` precisa de um incremento. A condição pode depender de uma entrada do usuário ou de outro estado do programa. O importante é garantir que exista uma forma adequada de encerrar a repetição, quando necessário.

## 3. do while

O `do while` funciona igual ao `while`, porém, ele verifica a condição de execução apenas **depois da execução do bloco**.

Por isso, o código dentro do `do while` é executado pelo menos uma vez.

### Sintaxe

```c
do {
    // Código a ser repetido
} while (condição);
```

Observe o ponto e vírgula (`;`) depois da condição. Ele faz parte da sintaxe do `do while`.

### Exemplo

```c
int i = 0;

do {
    printf("Valor de i: %d\n", i);
    i++;
} while (i < 5);
```

**Saída:**

```text
Valor de i: 0
Valor de i: 1
Valor de i: 2
Valor de i: 3
Valor de i: 4
```

Primeiro, o bloco é executado. Em seguida, o programa verifica se `i < 5`. Se a condição for verdadeira, o bloco será executado novamente.

### A principal diferença

```c
int i = 10;

while (i < 5) {
    printf("while\n");
}

do {
    printf("do while\n");
} while (i < 5);
```

**Saída:**

```text
do while
```

O `while` não exibe nada porque a condição já começa falsa. Já o `do while` exibe a mensagem uma vez antes de verificar a condição.

Essa característica é útil quando uma operação precisa acontecer pelo menos uma vez, como exibir um menu antes de solicitar uma opção ao usuário.

Como orientação geral:

- **`for`:** costuma ser conveniente quando existe uma contagem ou sequência de repetições.
- **`while`:** costuma ser conveniente quando a repetição depende de uma condição.
- **`do while`:** costuma ser conveniente quando o bloco precisa ser executado pelo menos uma vez.

Essas são convenções, não regras obrigatórias. É possível resolver muitos problemas com mais de uma dessas estruturas.

## 5. Convenções para nomes de variáveis em laços

Em exemplos e algoritmos, é comum utilizar letras como `i`, `j`, `k` e, em alguns casos, `l` como nomes de variáveis de controle.

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

Essa convenção é bastante antiga e aparece em diversas linguagens de programação. Em geral, `i` é utilizada para o primeiro contador, `j` para um segundo e `k` para um terceiro, especialmente quando há laços aninhados.

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
        printf("i = %d, j = %d\n", i, j);
    }
}
```

Nesse exemplo, `i` controla o laço externo e `j` controla o laço interno.

**Esses nomes são uma convenção, não uma exigência da linguagem C.** Poderíamos utilizar nomes como `linha`, `coluna`, `tentativa` ou `contador`, desde que fossem identificadores válidos.

Por exemplo, ao percorrer uma matriz, nomes descritivos podem tornar a intenção do código mais clara:

```c
for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 2; coluna++) {
        printf("Linha: %d, coluna: %d\n", linha, coluna);
    }
}
```

O código fica um pouco mais longo, mas a função de cada variável pode ser compreendida sem precisar deduzir o significado de `i` e `j`.

A escolha de nomes é parte das convenções de escrita e das boas práticas de programação. Em laços pequenos, `i` e `j` geralmente são suficientes; em códigos mais extensos ou com lógica mais complexa, nomes como `indice`, `linha`, `coluna` e `tentativa` podem melhorar a legibilidade.

## 6. break e continue

Além de controlar a repetição por meio de uma condição, C oferece duas instruções que alteram o fluxo de um laço.

### break: encerrar o laço

O `break` encerra imediatamente o laço mais interno em que está localizado.

```c
for (int i = 0; i < 10; i++) {
    if (i == 3) {
        break;
    }

    printf("%d\n", i);
}
```

**Saída:**

```text
0
1
2
```

Quando `i` chega a 3, o `break` encerra o laço antes que o número seja exibido.

### continue: pular para a próxima repetição

O `continue` interrompe a parte restante da repetição atual e passa para a próxima.

```c
for (int i = 0; i < 5; i++) {
    if (i == 2) {
        continue;
    }

    printf("%d\n", i);
}
```

**Saída:**

```text
0
1
3
4
```

Quando `i` é igual a 2, o `continue` pula o `printf()` daquela repetição.

O comportamento do `continue` depende da estrutura utilizada. Em um `for`, a atualização é executada antes da próxima verificação da condição. Em um `while`, o fluxo retorna à verificação da condição. Por isso, usar `continue` em um `while` sem atualizar uma variável necessária pode causar um laço infinito.

## 💡 Recomendações de estudo

- Execute [repeticao.c](../04-repeticao/repeticao.c).
- Altere o valor inicial, a condição e a atualização do `for` para entender como essas mudanças afetam a repetição.
- Experimente utilizar `i++`, `i += 1` e `i = i + 1` e compare os resultados.
- Modifique a condição do `while` e acompanhe os valores exibidos.
- Compare `while` e `do while` usando uma condição que já começa falsa.
- Utilize `break` para encerrar uma repetição antecipadamente e `continue` para pular uma execução.
- Experimente usar `i` e `j` em laços aninhados e, depois, substituir esses nomes por outros mais descritivos.
