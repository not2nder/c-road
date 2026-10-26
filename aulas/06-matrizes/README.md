# Módulo 06: Matrizes

Matrizes são estruturas que permitem armazenar vários elementos do mesmo tipo, organizados em linhas e colunas. São úteis quando precisamos representar dados com uma organização bidimensional, como tabelas, notas de alunos, tabuleiros e resultados de cálculos.

Em C, uma matriz bidimensional pode ser entendida como um array cujos elementos são outros arrays. Isso permite organizar os dados em duas dimensões e acessar cada elemento utilizando dois índices.

## 1. Declaração e inicialização

Assim como os vetores, as matrizes precisam ter um tipo definido. A diferença é que, enquanto um vetor possui uma dimensão, uma matriz bidimensional possui duas: linhas e colunas.

A sintaxe básica é:

```c
tipo nome[linhas][colunas];
```

Por exemplo:

```c
int matriz[2][3];
```

Isso declara uma matriz de tamanho 2 por 3, que armazena dados do tipo inteiro.

Uma matriz pode ser entendida como um vetor cujos elementos são outros vetores. Assim, `matriz[2][3]` representa dois arrays, cada um contendo três elementos do tipo `int`.

<div align=center>
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20221202105055/GIffor2D3D11.gif">
</div>

### 1.1. Declarando dimensões com `#define`

Neste módulo, as dimensões fixas das matrizes são representadas por constantes simbólicas, declaradas com a diretiva `#define`:

```c
#define LINHAS 2
#define COLUNAS 3

int matriz[LINHAS][COLUNAS];
```

Essa abordagem é útil por alguns motivos:

- **Legibilidade:** `LINHAS` e `COLUNAS` expressam a intenção do código melhor do que números isolados.
- **Manutenção:** se a quantidade de linhas ou colunas mudar, podemos atualizar a definição e reutilizar os nomes no restante do programa.
- **Consistência:** os limites dos laços de repetição podem utilizar as mesmas definições usadas na declaração da matriz.
- **Compatibilidade:** as dimensões são substituídas pelo pré-processador antes da compilação, permitindo utilizá-las em declarações de arrays de tamanho fixo.

Por exemplo, ao escrever:

```c
for (int i = 0; i < LINHAS; i++) {
    // ...
}
```

o limite do laço acompanha a dimensão definida para a matriz. Isso diminui o risco de esquecer de atualizar um número em algum ponto do código.

Lembrando que `#define` não cria uma variável. O pré-processador substitui ocorrências do nome definido pelo valor correspondente antes da compilação. Por convenção, constantes simbólicas desse tipo costumam ser escritas em letras maiúsculas.

### 1.2. Inicializando uma matriz

Os valores podem ser fornecidos durante a declaração, organizados em conjuntos que representam as linhas:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

A matriz contém duas linhas, e cada linha contém três elementos.

Também podemos escrever a inicialização de forma compacta:

```c
int matriz[2][3] = {1, 2, 3, 4, 5, 6};
```

Nesse caso, os valores são distribuídos sequencialmente pelas linhas. A primeira linha recebe `1`, `2` e `3`; a segunda recebe `4`, `5` e `6`.

Se fornecermos menos valores do que a quantidade total de elementos, os elementos restantes serão inicializados com zero:

```c
int matriz[2][3] = {
    {1, 2},
    {3}
};
```

A matriz será:

```text
1 2 0
3 0 0
```

Essa regra também vale para uma inicialização parcial sem as chaves internas:

```c
int matriz[2][3] = {1, 2, 3};
```

Nesse caso, os três primeiros elementos recebem os valores informados e os demais são inicializados com zero.

Por outro lado, se uma matriz local for declarada sem inicialização:

```c
int matriz[2][2];
```

seus elementos terão valores indeterminados. Não devemos presumir que estarão zerados. Antes de utilizar esses valores, precisamos atribuir valores válidos às posições.

Uma alternativa para inicializar todos os elementos com zero é:

```c
int matriz[2][3] = {0};
```

### 1.3. Quantidade de elementos

Para descobrir a quantidade total de elementos de uma matriz retangular, multiplicamos o número de linhas pelo número de colunas:

$$
\text{elementos} = \text{linhas} \times \text{colunas}
$$

Em uma matriz de duas linhas e três colunas:

$$
2 \times 3 = 6 \text{ elementos}
$$

Isso representa a quantidade de posições disponíveis, não necessariamente a quantidade de valores diferentes armazenados.

## 2. Acessando e modificando elementos

A forma de acessar um elemento é semelhante à utilizada com vetores, mas precisamos informar dois índices:

```c
nome[linha][coluna]
```

O primeiro índice seleciona a linha; o segundo seleciona a coluna.

Considere a matriz:

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

A expressão `matriz[1][2]` aponta para a segunda linha (índice 1) e terceira coluna (índice 2), resultando no elemento 6.

Em C, os índices começam em zero. Portanto, para uma matriz com duas linhas e três colunas:

- Índices válidos das linhas: `0` e `1`.
- Índices válidos das colunas: `0`, `1` e `2`.

### 2.1. Modificando elementos

Para modificar um elemento, basta atribuir um novo valor à posição desejada:

```c
matriz[0][1] = 10;
```

Atribuímos `10` à primeira linha e à segunda coluna. A alteração afeta somente essa posição da matriz.

Os índices também podem ser representados por variáveis ou expressões:

```c
int linha = 1;
int coluna = 0;

matriz[linha][coluna] = 20;
```

Nesse caso, o valor `20` é armazenado na segunda linha e na primeira coluna.

Essa possibilidade é especialmente importante quando trabalhamos com laços de repetição, pois os índices podem mudar a cada iteração.

### 2.2. Limites dos índices

Os índices precisam respeitar as dimensões declaradas. Para uma matriz 2 por 3, expressões como `matriz[2][0]` e `matriz[0][3]` tentam acessar posições fora dos limites da matriz.

Esses acessos provocam **comportamento indefinido**. O programa pode apresentar resultados inesperados, corromper dados ou falhar. Não existe garantia de que o erro será detectado automaticamente.

Por isso, os limites dos laços devem corresponder às dimensões da matriz.

## 3. Percorrendo matrizes

Percorrer uma matriz significa acessar seus elementos de maneira organizada. Uma abordagem comum é percorrer cada linha e, dentro dela, percorrer cada coluna.

Como existem duas dimensões, utilizamos normalmente dois laços `for` aninhados:

- O laço externo controla as linhas.
- O laço interno controla as colunas da linha atual.

A estrutura geral é:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        // Acessa matriz[i][j]
    }
}
```

### 3.1. Entendendo a ordem das iterações

Considere uma matriz de duas linhas e três colunas. O laço externo começa com `i = 0`, enquanto o interno começa com `j = 0`.

A primeira posição acessada é `matriz[0][0]`. Ao terminar essa iteração do laço interno, `j` é incrementado e passa a valer `1`. Em seguida, o programa acessa `matriz[0][1]`.

O processo continua até `j = 2`, quando a última coluna da primeira linha é acessada.

Depois disso, o laço interno tenta avançar para `j = 3`. Como a condição `j < COLUNAS` deixa de ser verdadeira, ele termina.

Somente então o laço externo avança: `i` passa a valer `1`. O laço interno é iniciado novamente, e `j` começa outra vez em `0`.

A sequência completa de posições acessadas é:

| Iteração | `i` | `j` | Posição        |
| -------: | --: | --: | -------------- |
|        1 |   0 |   0 | `matriz[0][0]` |
|        2 |   0 |   1 | `matriz[0][1]` |
|        3 |   0 |   2 | `matriz[0][2]` |
|        4 |   1 |   0 | `matriz[1][0]` |
|        5 |   1 |   1 | `matriz[1][1]` |
|        6 |   1 |   2 | `matriz[1][2]` |

O detalhe mais importante é que o laço interno executa completamente para cada valor de `i`. A cada nova iteração do laço externo, o laço interno recomeça.

### 3.2. Por que utilizar `<` em vez de `<=`?

Considere:

```c
for (int i = 0; i < LINHAS; i++)
```

Se `LINHAS` vale `2`, os valores de `i` serão `0` e `1`. Quando `i` passa a valer `2`, a condição `i < 2` é falsa e o laço termina.

Se utilizássemos `i <= LINHAS`, o laço também executaria com `i = 2`, tentando acessar uma terceira linha inexistente.

Por isso, ao percorrer uma matriz indexada a partir de zero, o padrão mais comum é utilizar a condição `índice < dimensão`.

### 3.3. Exibindo a matriz

Para imprimir os elementos organizados em linhas e colunas, podemos utilizar `printf()` dentro do laço interno e imprimir uma quebra de linha após o término desse laço:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", matriz[i][j]);
    }

    printf("\n");
}
```

O `printf("%d ", ...)` imprime cada elemento seguido de um espaço. Já o `printf("\n")`, posicionado fora do laço interno, encerra a linha atual antes que a próxima comece.

Se a quebra de linha estivesse dentro do laço interno, cada elemento seria impresso em uma linha separada.

### 3.4. Preenchendo uma matriz com `scanf()`

A mesma estrutura pode ser utilizada para armazenar valores informados pelo usuário:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        printf("Linha %d, coluna %d: ", i, j);
        scanf("%d", &matriz[i][j]);
    }
}
```

O operador `&` fornece o endereço da posição que receberá o valor digitado. Isso permite que `scanf()` armazene o valor diretamente no elemento indicado.

## 4. Operações com matrizes

As operações com matrizes dependem da regra matemática utilizada. Algumas operam sobre elementos correspondentes; outras combinam linhas de uma matriz com colunas de outra.

É importante distinguir essas operações, pois nem todas exigem as mesmas dimensões.

### 4.1. Adição e subtração

Na adição e na subtração, operamos sobre os elementos que ocupam as mesmas posições nas duas matrizes.

Por exemplo, na expressão `A[0][0] + B[0][0]`, somamos o primeiro elemento de `A` ao primeiro elemento de `B`.

As matrizes precisam possuir as mesmas dimensões. Essa regra não exige que sejam quadradas: duas matrizes de duas linhas e três colunas também podem ser somadas ou subtraídas.

A estrutura dos laços é igual para ambas as operações. A diferença está no operador utilizado dentro deles.

### 4.2. Multiplicação por escalar

Um escalar é um único valor numérico. Multiplicar uma matriz por um escalar significa multiplicar cada elemento da matriz por esse mesmo valor.

Para uma matriz `A` e um escalar `k`, cada posição do resultado é calculada como:

$$
C[i][j] = A[i][j] \times k
$$

Essa operação não exige uma segunda matriz. As dimensões do resultado são iguais às da matriz original.

### 4.3. Multiplicação elemento a elemento

A multiplicação elemento a elemento multiplica os valores que ocupam posições correspondentes em duas matrizes:

$$
C[i][j] = A[i][j] \times B[i][j]
$$

Assim como na adição e na subtração, as duas matrizes precisam ter as mesmas dimensões.

**Atenção:** essa operação não é a multiplicação matricial convencional. Apesar de ambas utilizarem o símbolo de multiplicação, suas regras são diferentes.

### 4.4. Multiplicação matricial convencional

Na multiplicação matricial convencional, cada elemento do resultado é obtido multiplicando os elementos de uma linha da primeira matriz pelos elementos correspondentes de uma coluna da segunda matriz e somando os produtos.

Se `A` possui dimensão M por N e `B` possui dimensão N por R, o produto `C = A × B` terá dimensão M por R.

Portanto, **o número de colunas da primeira matriz deve ser igual ao número de linhas da segunda**.

Por exemplo, uma matriz de dimensão 2 POR 3 pode ser multiplicada por uma matriz de dimensão 3 por 2. O resultado terá dimensão 2 por 2.

Para calcular cada posição do resultado, utilizamos três laços:

- O primeiro (`i`) percorre as linhas da primeira matriz.
- O segundo (`j`) percorre as colunas da segunda matriz.
- O terceiro (`k`) percorre os elementos envolvidos na soma dos produtos.

A variável `k` percorre os elementos da linha de `A` e da coluna de `B` que serão multiplicados. Cada produto é acumulado na posição correspondente de `C`.

Como a operação acumula vários produtos em uma mesma posição, a matriz de resultado deve começar com valores zero. Caso contrário, o cálculo poderia somar os produtos a valores indeterminados.

### 4.5. Armazenando e exibindo resultados

É comum armazenar os resultados em uma terceira matriz, como `resultado`, e imprimi-los depois do cálculo. Isso permite utilizar os valores calculados em outras operações sem precisar repetir o processamento.

Ao imprimir inteiros, podemos utilizar o especificador `%02d`:

```c
printf("%02d ", resultado[i][j]);
```

Nesse formato, `2` indica uma largura mínima de dois caracteres, e `0` solicita o preenchimento com zeros à esquerda quando necessário.

Por exemplo, o valor `6` será exibido como `06`. Entretanto, a largura é mínima, não fixa: valores como `-8` ou `100` ocupam mais de duas posições. Esse recurso ajuda a alinhar visualmente os elementos em exemplos com números de tamanhos semelhantes, mas não altera os valores armazenados.

## 5. Diagonais e regiões de uma matriz

Em matrizes quadradas, podemos identificar posições com base na relação entre os índices das linhas e das colunas.

Uma matriz quadrada possui a mesma quantidade de linhas e colunas. Essa característica é importante para as regras das diagonais e de algumas regiões centrais.

<div align=center>
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQnuefjbHqBkAGrufLqrwKCyCVBPwo6X3bXmFe_p3ymhxJp5CGdOMqhv9U&s=10">
</div>

### 5.1. Diagonal principal

A diagonal principal reúne os elementos em que o índice da linha é igual ao índice da coluna:

$$
i = j
$$

Em uma matriz quadrada de ordem 3, suas posições são `[0][0]`, `[1][1]` e `[2][2]`.

Para imprimir somente os elementos dessa diagonal, podemos utilizar condições dentro dos laços de repetição:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        if (i == j) {
            printf("%d ", matriz[i][j]);
        } else {
            printf("  ");
        }
    }
    printf("\n");
}
```

A condição i == j verifica se os índices da linha e da coluna são iguais. Quando isso acontece, o elemento é impresso; caso contrário, são impressos espaços para preservar o alinhamento.

Exemplo de saída:

```bash
1
  5
    9
```

A diagonal principal também pode ser percorrida diretamente com um único laço, utilizando matriz[i][i]. Os dois laços do exemplo acima foram mantidos para demonstrar como selecionar posições específicas durante o percurso de uma matriz.

### 5.2. Diagonal secundária

A diagonal secundária reúne os elementos que começam no canto superior direito e terminam no canto inferior esquerdo.

Para uma matriz quadrada de ordem N, a condição é:

$$
i + j = n - 1
$$

Se a matriz possui três colunas, por exemplo, a soma dos índices de cada elemento da diagonal secundária deve ser `2`.

Em uma matriz de ordem 3, a soma dos índices de cada elemento dessa diagonal deve ser 2:

- `[0][2]`: (0 + 2 = 2)
- `[1][1]`: (1 + 1 = 2)
- `[2][0]`: (2 + 0 = 2)

```c
for (int i = 0; i < ORDEM; i++) {
    for (int j = 0; j < ORDEM; j++) {
        if (i + j == ORDEM - 1) {
            printf("%d ", matriz[i][j]);
        } else {
            printf("  ");
        }
    }
    printf("\n");
}
```

Exemplo de saída:

```text
     3
   5
7
```

A expressão `ORDEM - 1` representa o último índice válido de uma dimensão. Para uma matriz de ordem 3, esse índice é 2.

Essa fórmula pressupõe uma matriz quadrada. Não deve ser aplicada automaticamente a matrizes retangulares sem definir primeiro o que se deseja considerar como diagonal secundária.

### 5.3. Linha e coluna centrais

Em uma matriz com uma quantidade ímpar de linhas, a expressão `LINHAS / 2` identifica o índice da linha central quando `LINHAS` é um inteiro positivo.

Por exemplo, se existem três linhas:

$$
3 / 2 = 1
$$

Em C, a divisão entre dois inteiros resulta em um inteiro, descartando a parte fracionária. Por isso, `3/2` resulta em 1, correspondente à segunda linha.

Podemos imprimir somente a linha central utilizando:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        if (i == LINHAS / 2) {
            printf("%d ", matriz[i][j]);
        } else {
            printf("  ");
        }
    }
    printf("\n");
}
```

Exemplo de Saída:

```text

4 5 6

```

O teste `i == LINHAS / 2` é feito para cada elemento, mas seu resultado permanece igual durante todas as colunas de uma mesma linha.

Para imprimir a coluna central, a lógica é semelhante, mas a condição utiliza j:

```c
if (j == COLUNAS / 2) {
    printf("%d ", matriz[i][j]);
}
```

Nesse caso, percorremos todas as linhas e selecionamos somente a coluna central.

O mesmo raciocínio pode ser aplicado às colunas. Entretanto, em uma dimensão par, não existe uma única linha ou coluna central: há duas posições centrais.

### 5.4. Cruz

Em uma matriz quadrada de ordem ímpar, podemos representar uma cruz reunindo a linha central e a coluna central.

A condição utilizada combina duas comparações com o operador lógico `||`, que significa **OU**:

```c
for (int i = 0; i < ORDEM; i++) {
    for (int j = 0; j < ORDEM; j++) {
        if (i == ORDEM / 2 || j == ORDEM / 2) {
            printf("%d ", matriz[i][j]);
        } else {
            printf("  ");
        }
    }

    printf("\n");
}
```

Um elemento será impresso quando estiver na linha central ou na coluna central. O elemento central satisfaz ambas as condições, mas é impresso apenas uma vez, pois existe uma única chamada a printf() dentro do bloco if.

Exemplo de saída:

```text
  2
4 5 6
  8
```

A cruz reúne cinco elementos: três da linha central e três da coluna central, descontando o elemento central que pertence às duas regiões.

## 6. Matrizes especiais e transposição

Além das matrizes utilizadas nos exemplos de operações, algumas estruturas possuem características específicas que facilitam determinados cálculos.

### 6.1. Matriz nula

Uma matriz nula é uma matriz cujos elementos são todos iguais a zero.

Em C, podemos inicializar uma matriz com zeros utilizando:

```c
int matriz[3][3] = {0};
```

Isso é útil quando precisamos iniciar acumuladores, preparar uma matriz para receber resultados ou garantir que todos os elementos tenham um valor inicial conhecido.

### 6.2. Matriz identidade

A matriz identidade é uma matriz quadrada em que todos os elementos da diagonal principal são iguais a `1`, enquanto os demais são iguais a `0`.

Uma maneira de construí-la é inicializar a matriz com zeros e atribuir `1` às posições em que os índices são iguais:

```c
for (int i = 0; i < ORDEM; i++) {
    matriz[i][i] = 1;
}
```

A expressão `matriz[i][i]` utiliza o mesmo índice para a linha e para a coluna, percorrendo a diagonal principal.

Na multiplicação matricial, a matriz identidade desempenha um papel semelhante ao número `1` na multiplicação de números: multiplicar uma matriz compatível pela identidade preserva seus valores.

### 6.3. Matriz transposta

A transposta de uma matriz é obtida trocando suas linhas por colunas.

Se a matriz original possui dimensão M por N, sua transposta possui dimensão N por M.

Cada elemento `original[i][j]` passa para a posição `transposta[j][i]`:

$$
T[j][i] = A[i][j]
$$

Por isso, ao construir a transposta, os índices são invertidos na atribuição. Também é necessário declarar a matriz de destino com as dimensões trocadas.

Consulte [criando_matrizes.c](/aulas/06-matrizes/criando_matrizes.c) para acompanhar a construção dessas matrizes.

## 7. Limites, dimensões e boas práticas

Ao trabalhar com matrizes, precisamos respeitar as dimensões declaradas e garantir que os índices permaneçam dentro dos limites válidos.

Para uma matriz de dimensão `2 × 3`, por exemplo, o índice da linha deve estar entre `0` e `1`, enquanto o índice da coluna deve estar entre `0` e `2`.

Ao percorrer uma matriz, utilize a dimensão correspondente em cada laço:

```c
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        // Acessa matriz[i][j]
    }
}
```

O uso de `LINHAS` no laço externo e `COLUNAS` no interno deixa explícito o papel de cada índice e reduz o risco de acessar posições inválidas.

Outras boas práticas importantes:

- **Utilize nomes significativos:** `LINHAS`, `COLUNAS`, `matriz_a` e `resultado` deixam mais clara a função de cada elemento do código.
- **Evite números repetidos desnecessariamente:** constantes simbólicas ajudam a manter as dimensões e os limites dos laços consistentes.
- **Inicialize antes de utilizar:** não leia elementos de uma matriz local antes de atribuir valores válidos a eles.
- **Verifique as dimensões das operações:** adição, subtração e multiplicação elemento a elemento exigem dimensões iguais; a multiplicação matricial convencional exige que as dimensões internas sejam compatíveis.
- **Mantenha os laços organizados:** identifique claramente qual variável percorre as linhas, qual percorre as colunas e, quando necessário, qual controla a acumulação de produtos.
