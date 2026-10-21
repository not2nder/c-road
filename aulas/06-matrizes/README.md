# Módulo 06: Matrizes

Matrizes são estruturas que permitem armazenar vários elementos do mesmo tipo, organizados em linhas e colunas. Elas são úteis quando precisamos representar dados que possuem uma organização bidimensional, como tabelas, notas de alunos, tabuleiros e resultados de cálculos.

Em C, uma matriz pode ser entendida como um array cujos elementos também são arrays. Isso permite organizar os dados em mais de uma dimensão e acessar cada elemento utilizando índices.

## 1. Declaração e inicialização

Assim como os vetores, as matrizes precisam ter um tipo definido. A diferença é que, enquanto um vetor possui uma dimensão, uma matriz bidimensional possui duas: linhas e colunas.

A sintaxe básica é:

```c
tipo nome[linhas][colunas];
```

Nessa declaração:

- `int` define o tipo dos elementos armazenados.
- `matriz` é o nome da variável.
- `[2]` indica que a matriz possui duas linhas.
- `[3]` indica que cada linha possui três colunas.

A forma de declarar uma matriz é semelhante à forma de declarar um vetor, porque uma matriz é formada basicamente por vários vetores dentro de um vetor. Então, a declaração de uma matriz pode ser entendida como:

```c
//         ┌────> Número de arrays
int matriz[2][3];
//            └───> Número de elementos de cada array
```

Isso fica mais claro quando inicializamos os elementos da matriz diretamente:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

A matriz possui 2 vetores (linhas) e cada vetor possui 3 elementos (colunas).

Podemos representar essa matriz visualmente:

```text
             COLUNAS
           0   1   2
         ┌───┬───┬───┐
LINHA  0 │ 1 │ 2 │ 3 │
         ├───┼───┼───┤
LINHA  1 │ 4 │ 5 │ 6 │
         └───┴───┴───┘
```

Para descobrir a quantidade total de elementos de uma matriz retangular, podemos multiplicar a quantidade de linhas pela quantidade de colunas:

$$
\text{elementos} = \text{linhas} \times \text{colunas}
$$

No exemplo:

$$
2 \times 3 = 6 \text{ elementos}
$$

### Inicialização

Os valores podem ser fornecidos durante a declaração, organizados em conjuntos que representam as linhas:

```c
int matriz[2][2] = {
    {1, 2},
    {3, 4}
};
```

Também podemos escrever a inicialização de forma compacta:

```c
int matriz[2][2] = {1, 2, 3, 4};
```

Nesse caso, os valores são distribuídos sequencialmente pelas linhas, na ordem em que os elementos são armazenados.

Se fornecermos menos valores do que a quantidade total de elementos, os elementos restantes serão inicializados com zero:

```c
int matriz[2][3] = {
    {1, 2},
    {3}
};

// Resultado:
// 1 2 0
// 3 0 0
```

Por outro lado, se uma matriz local for declarada sem inicialização, seus elementos terão valores indeterminados:

```c
int matriz[2][2];
```

Nesse caso, devemos atribuir valores aos elementos antes de utilizá-los.

## 2. Acessando elementos

A forma de acessar os elementos de uma matriz é semelhante à como aprendemos com vetores de uma dimensão. Fazemos isso por meio de índices:

```c
nome[linha][coluna]
```

O primeiro índice seleciona a linha; o segundo seleciona a coluna.

Considere:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Podemos acessar elementos específicos:

```c
printf("%d\n", matriz[0][0]); // 1
printf("%d\n", matriz[0][2]); // 3
printf("%d\n", matriz[1][0]); // 4
printf("%d\n", matriz[1][2]); // 6
```

Na expressão `matriz[1][2]`, por exemplo:

1. O índice `1` seleciona a segunda linha.
2. O índice `2` seleciona a terceira coluna dessa linha.
3. O valor encontrado é `6`.

Assim como nos vetores, os índices das matrizes em C começam em zero.

Uma matriz com duas linhas e três colunas possui:

- Índices de linha de `0` a `1`.
- Índices de coluna de `0` a `2`.

> **Atenção:** acessar uma posição fora dos limites de qualquer dimensão causa comportamento indefinido. Em uma matriz declarada como `int matriz[2][3]`, por exemplo, `matriz[2][0]` e `matriz[0][3]` são acessos inválidos.

## 3. Modificando elementos

Para modificar um elemento, basta atribuir um novo valor à posição desejada:

```c
int matriz[2][2] = {
    {1, 2},
    {3, 4}
};

matriz[0][1] = 10;
```

Após a atribuição, a matriz passa a conter:

```text
1 10
3 4
```

Também podemos utilizar variáveis ou expressões nos índices:

```c
int linha = 1;
int coluna = 0;

matriz[linha][coluna] = 20;
```

Nesse exemplo, o valor `20` é armazenado na segunda linha e na primeira coluna.

Essa possibilidade é especialmente útil quando precisamos processar matrizes por meio de laços de repetição, pois os índices podem mudar a cada iteração.

## 4. Percorrendo matrizes

Percorrer uma matriz significa acessar seus elementos de maneira organizada, normalmente linha por linha.

Como existem duas dimensões, uma abordagem comum é utilizar dois laços `for` aninhados:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matriz[i][j]);
    }

    printf("\n");
}
```

A saída será:

```text
1 2 3
4 5 6
```

O funcionamento dos laços é o seguinte:

- O laço externo, controlado por `i`, percorre as linhas.
- O laço interno, controlado por `j`, percorre as colunas da linha atual.
- `matriz[i][j]` acessa o elemento correspondente aos índices atuais.
- O `printf("\n")` executado após o laço interno inicia uma nova linha na saída.

Na primeira iteração do laço externo, `i` vale `0`. O laço interno percorre as colunas `0`, `1` e `2`, imprimindo os elementos da primeira linha.

Depois, `i` passa a valer `1`, e o mesmo processo acontece para a segunda linha.

### Preenchendo uma matriz com `scanf()`

Podemos utilizar a mesma estrutura para armazenar valores informados pelo usuário:

```c
int matriz[2][2];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        printf("Linha %d, coluna %d: ", i, j);
        scanf("%d", &matriz[i][j]);
    }
}
```

O operador `&` fornece o endereço da posição que receberá o valor digitado.

É possível utilizar a matriz preenchida em operações posteriores, como imprimir seus elementos, calcular somas ou comparar valores.

## 5. Operações com matrizes

Quando duas matrizes possuem a mesma quantidade de linhas e colunas, podemos realizar determinadas operações entre seus elementos correspondentes.

Considere as matrizes:

```c
int matriz_a[2][2] = {
    {8, 7},
    {4, 1}
};

int matriz_b[2][2] = {
    {5, 3},
    {2, 9}
};
```

Elas possuem a mesma dimensão: duas linhas e duas colunas.

Nas operações elemento a elemento, utilizamos os mesmos índices para acessar os valores das duas matrizes. Por exemplo, `matriz_a[0][0]` corresponde a `matriz_b[0][0]`.

### 5.1. Adição

Na adição, somamos os elementos que ocupam as mesmas posições:

$$
A+B=
\begin{bmatrix}
8+5 & 7+3\\
4+2 & 1+9
\end{bmatrix}
=
\begin{bmatrix}
13 & 10\\
6 & 10
\end{bmatrix}
$$

Podemos implementar essa operação utilizando dois laços:

```c
int resultado[2][2];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        resultado[i][j] = matriz_a[i][j] + matriz_b[i][j];
    }
}
```

A expressão `matriz_a[i][j] + matriz_b[i][j]` soma os elementos da mesma posição e armazena o resultado em `resultado[i][j]`.

### 5.2. Subtração

A subtração segue a mesma lógica, mas utiliza o operador `-`:

$$
A-B=
\begin{bmatrix}
8-5 & 7-3\\
4-2 & 1-9
\end{bmatrix}
=
\begin{bmatrix}
3 & 4\\
2 & -8
\end{bmatrix}
$$

O código é praticamente igual ao da adição:

```c
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        resultado[i][j] = matriz_a[i][j] - matriz_b[i][j];
    }
}
```

Observe que a estrutura dos laços não muda. A diferença está na operação aplicada aos elementos.

### 5.3. Multiplicação elemento a elemento

Também podemos multiplicar os elementos correspondentes das duas matrizes:

$$
\begin{bmatrix}
8 & 7\\
4 & 1
\end{bmatrix}
\times
\begin{bmatrix}
5 & 3\\
2 & 9
\end{bmatrix}
=
\begin{bmatrix}
40 & 21\\
8 & 9
\end{bmatrix}
$$

A implementação é:

```c
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        resultado[i][j] = matriz_a[i][j] * matriz_b[i][j];
    }
}
```

**Importante:** essa operação é chamada de multiplicação elemento a elemento. Ela não deve ser confundida com a multiplicação matricial convencional, que utiliza linhas de uma matriz e colunas da outra para calcular cada elemento do resultado.

### 5.4. Multiplicação por escalar

Um escalar é um único valor numérico. Multiplicar uma matriz por um escalar significa multiplicar cada elemento pelo mesmo valor.

Por exemplo, multiplicando a matriz `A` por `3`:

$$
3A=
\begin{bmatrix}
3\times8 & 3\times7\\
3\times4 & 3\times1
\end{bmatrix}
=
\begin{bmatrix}
24 & 21\\
12 & 3
\end{bmatrix}
$$

Em C:

```c
int k = 3;

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        resultado[i][j] = matriz_a[i][j] * k;
    }
}
```

Diferentemente das operações entre duas matrizes, a multiplicação por escalar utiliza apenas uma matriz e um valor numérico.

### 5.5. Armazenando e exibindo resultados

Os resultados podem ser armazenados em uma terceira matriz, como `resultado`, e exibidos depois do cálculo.

```c
int resultado[2][2];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        resultado[i][j] = matriz_a[i][j] + matriz_b[i][j];
    }
}

printf("Resultado:\n");

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        printf("%02d ", resultado[i][j]);
    }

    printf("\n");
}
```

A variável `resultado` mantém os valores calculados. Isso permite utilizá-los novamente, sem precisar repetir a operação.

O formato `%02d` utilizado em `printf()` reserva pelo menos duas posições para a representação inteira e acrescenta um zero à esquerda quando o número possui apenas um dígito. Por exemplo, `6` é exibido como `06`. Isso ajuda a alinhar visualmente os elementos.

## 6. Limites e dimensões

Ao trabalhar com matrizes, precisamos respeitar as dimensões declaradas.

Por exemplo:

```c
int matriz[2][3];
```

Essa matriz possui duas linhas e três colunas. Portanto, os índices válidos são:

- Linha: `0` ou `1`.
- Coluna: `0`, `1` ou `2`.

Para percorrê-la corretamente, os limites dos laços devem corresponder às dimensões:

```c
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        // Acessa matriz[i][j]
    }
}
```

Utilizar `i < 3` no laço externo, por exemplo, tentaria acessar uma terceira linha que não existe. Acessos fora dos limites de uma matriz causam comportamento indefinido.

Também é importante lembrar que as dimensões das matrizes envolvidas em uma operação precisam ser compatíveis com essa operação. Adição, subtração e multiplicação elemento a elemento exigem matrizes de mesmas dimensões. Já a multiplicação matricial convencional possui uma regra diferente: a quantidade de colunas da primeira matriz deve ser igual à quantidade de linhas da segunda.
