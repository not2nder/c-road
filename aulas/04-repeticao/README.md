# MÓDULO 04: Estruturas de Repetição

As estruturas de repetição permitem executar um bloco de código várias vezes.

## 1. Laço for

O `for` é utilizado principalmente quando conhecemos a quantidade de repetições desejada ou quando podemos definir uma variável de controle para acompanhar cada repetição.

### Sintaxe

```c
for (inicialização; condição; incremento) {
    // Código a ser repetido
}
```

A estrutura possui três partes:

- **Inicialização:** Chamada de variável de controle, controla e conta a quantidade de repetições do laço.
- **Condição:** verificada antes de cada repetição. Se for verdadeira, o bloco será executado; se for falsa, o laço termina.
- **Incremento:** executado ao final de cada repetição, geralmente para atualizar a variável de controle.

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

1. `int i = 0` cria a variável de controle e começa sua contagem em zero.
2. `i < 5` permite a repetição enquanto `i` for menor que 5.
3. `i++` incrementa `i` em uma unidade ao final de cada repetição.

Como a variável começa em 0 e o laço termina quando ela chega a 5, o bloco é executado cinco vezes: para os valores de `i` iguais a 0, 1, 2, 3 e 4.

Observe que a condição é verificada **antes** de cada execução. Quando `i` passa a valer 5, a condição `i < 5` torna-se falsa e o laço termina.

## 2. Laço `while`

O `while` executa um bloco de código enquanto uma condição for verdadeira. Diferentemente do `for`, a inicialização e a atualização da variável de controle normalmente ficam fora da estrutura ou dentro do próprio bloco.

### Sintaxe

```c
while (condição) {
    // Código a ser repetido
}
```

A cada repetição, o programa verifica a condição. Se ela for verdadeira, executa o bloco; caso contrário, encerra o laço.

### Exemplo

```c
int i = 0;

while (i < 5) {
    printf("Valor de i: %d\n", i);
    i++;
}
```

Nesse exemplo, também há uma variável de controle e uma operação de incremento, mas diferente do for, a variável é declarada fora do laço e o incremento é definido manualmente.

**Saída:**

```text
Valor de i: 0
Valor de i: 1
Valor de i: 2
Valor de i: 3
Valor de i: 4
```

A variável `i` é inicializada antes do laço. Enquanto `i` for menor que 5, seu valor será exibido e, em seguida, incrementado.

**Atenção:** é importante atualizar a variável de controle quando ela participa da condição de parada. Se `i++` fosse removido desse exemplo, `i` permaneceria igual a zero e a condição `i < 5` continuaria verdadeira indefinidamente, criando um laço infinito.

## 3. Diferenças entre `for` e `while`

As duas estruturas podem executar tarefas semelhantes. A principal diferença está na forma como o código é organizado e no contexto em que cada uma costuma ser utilizada.

| for                                                            | while                                                                                      |
| -------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| Reúne inicialização, condição e incremento na mesma estrutura. | Mantém a condição no cabeçalho; inicialização e atualização são organizadas separadamente. |
| É comum quando existe uma contagem ou sequência bem definida.  | É comum quando a repetição depende de uma condição que pode mudar durante a execução.      |
| A variável de controle pode ser declarada no cabeçalho.        | A variável de controle geralmente é declarada antes do laço, quando necessária.            |

Essas são convenções de uso, não regras obrigatórias. É possível utilizar qualquer uma das estruturas em diversas situações, desde que a lógica do programa seja adequada.

## 💡 Recomendações de estudo

- Execute [repeticao.c](../04-repeticao/repeticao.c).
- Altere o valor inicial, a condição e o incremento do `for` para entender como essas mudanças afetam a repetição.
- Modifique a condição do `while` e acompanhe os valores exibidos.
- Experimente começar a contagem em 1 em vez de 0.
