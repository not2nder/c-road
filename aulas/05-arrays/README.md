# MÓDULO 05: Arrays (Vetores)

Arrays são estruturas que permitem armazenar vários elementos do mesmo tipo em uma única variável. Eles são úteis quando precisamos trabalhar com conjuntos de dados, como notas de alunos, listas de números ou resultados de cálculos.

## 1. Declaração e inicialização

Diferentemente de uma variável simples, que armazena um único valor, um array permite armazenar vários elementos do mesmo tipo.

```c
int nota = 10;                  // Variável simples
int notas[4] = {10, 7, 9, 8};  // Array com 4 elementos
```

Na declaração `int notas[4]`:

- `int` define o tipo dos elementos.
- `notas` é o nome do array.
- `[4]` indica a quantidade de elementos.

Assim como qualquer variável simples, vetores também precisam de um tipo definido.

Também podemos declarar um array sem inicializar seus elementos:

```c
int numeros[5];
```

Nesse caso, como o array é uma variável local, seus elementos possuem valores indeterminados. Portanto, devemos atribuir valores antes de utilizá-los.

Quando fornecemos menos valores do que o tamanho declarado, os elementos restantes são inicializados com zero:

```c
int vetor[5] = {1, 2, 3};
// Resultado: {1, 2, 3, 0, 0}
```

Outra possibilidade é inicializar todos os elementos com zero:

```c
int lista[5] = {0};
```

Também podemos omitir o tamanho quando os valores iniciais permitem que o compilador determine a quantidade de elementos:

```c
int valores[] = {4, 8, 12, 16};
// O array possui 4 elementos.
```

## 2. Acessando elementos

Cada elemento de um array possui um índice, utilizado para acessar sua posição.

Em C, os índices começam em zero. Assim, um array com `n` elementos possui índices de `0` até `n - 1`.

Por exemplo:

```c
int notas[4] = {10, 7, 9, 8};

printf("%d\n", notas[0]); // 10
printf("%d\n", notas[1]); // 7
printf("%d\n", notas[2]); // 9
printf("%d\n", notas[3]); // 8
```

A sintaxe básica é `nome_do_array[índice]`.

> **Atenção:** acessar uma posição fora dos limites do array causa comportamento indefinido. Em um array de quatro elementos, por exemplo, `notas[4]` é inválido, pois o último índice é `3`.

## 3. Modificando elementos

Podemos modificar um elemento atribuindo um novo valor à posição desejada:

```c
int notas[4] = {10, 7, 9, 8};

notas[0] = 6;
// Resultado: {6, 7, 9, 8}
```

Também podemos utilizar `scanf()` para armazenar um valor informado pelo usuário diretamente em uma posição:

```c
printf("Informe sua nota: ");
scanf("%d", &notas[0]);
```

O operador `&` é utilizado para passar o endereço da posição em que o valor deverá ser armazenado.

## 4. Percorrendo arrays

Percorrer um array significa acessar seus elementos em sequência. Uma das formas mais comuns de fazer isso é utilizando um laço `for`.

```c
int notas[4] = {10, 7, 9, 8};

for (int i = 0; i < 4; i++) {
    printf("Elemento na posição %d: %d\n", i, notas[i]);
}
```

A variável `i` começa em zero e aumenta a cada repetição. Dessa forma, `notas[i]` acessa uma posição diferente a cada iteração.

O mesmo princípio permite preencher um array com valores fornecidos pelo usuário:

```c
int numeros[5];

for (int i = 0; i < 5; i++) {
    printf("Informe um número: ");
    scanf("%d", &numeros[i]);
}
```

Nesse exemplo, cada número informado é armazenado em uma posição diferente do array.

## 5. Quantidade de elementos

Diferentemente do Python, C não possui um método `len()` para obter diretamente a quantidade de elementos de um array.

Podemos calcular essa quantidade utilizando o operador `sizeof`, que retorna o tamanho em bytes de um objeto:

```c
int notas[] = {10, 7, 9, 8};

int quantidade = sizeof(notas) / sizeof(notas[0]);

printf("Quantidade de elementos: %d\n", quantidade);
```

A expressão funciona da seguinte maneira:

- `sizeof(notas)` retorna o tamanho total do array em bytes.
- `sizeof(notas[0])` retorna o tamanho de um elemento em bytes.
- A divisão desses valores resulta na quantidade de elementos.

Podemos utilizar essa quantidade para percorrer o array sem precisar informar manualmente o número de elementos:

```c
for (int i = 0; i < quantidade; i++) {
    printf("%d\n", notas[i]);
}
```

## 6. Bubble Sort

O Bubble Sort é um algoritmo de ordenação que percorre um array comparando elementos adjacentes. Quando dois elementos estão fora da ordem desejada, eles trocam de posição.

Esse processo é repetido até que os elementos estejam ordenados.

Considere o array:

```c
int vetor[4] = {3, 5, 2, 1};
```

Durante uma passagem, o algoritmo compara os elementos vizinhos:

1. Compara `3` e `5`. Como estão na ordem correta, não troca.
2. Compara `5` e `2`. Como `5` é maior, troca os elementos.
3. Compara `5` e `1`. Como `5` é maior, troca novamente.

Ao final dessa passagem, o maior elemento chega à última posição.

O algoritmo repete o processo, reduzindo a quantidade de elementos que precisam ser comparados a cada passagem.

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4 - i - 1; j++) {
        if (vetor[j] > vetor[j + 1]) {
            int temp = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = temp;
        }
    }
}
```

O laço externo (`i`) controla as passagens, enquanto o interno (`j`) percorre os elementos que ainda precisam ser comparados. A variável temporária `temp` permite trocar dois valores sem perder nenhum deles.

O resultado final é:

```text
1
2
3
5
```

O Bubble Sort é útil para compreender a lógica de ordenação, embora não seja a opção mais eficiente para arrays grandes.

## 7. Busca linear

A busca linear é um algoritmo que percorre um array elemento por elemento até encontrar um valor desejado, chamado de **chave de busca**, ou até chegar ao final sem encontrá-lo.

Considere:

```c
int lista[4] = {83, 11, 55, 84};
int chave = 11;
```

Podemos percorrer o array com `for`:

```c
int indice = -1;

for (int i = 0; i < 4; i++) {
    if (lista[i] == chave) {
        indice = i;
        break;
    }
}
```

A variável `indice` começa em `-1`, indicando que o elemento ainda não foi encontrado. Quando a chave é localizada, seu índice é armazenado.

O `break` encerra o laço assim que o elemento é encontrado, evitando comparações desnecessárias.

Também é possível implementar a busca utilizando `while`:

```c
int numeros[4] = {2, 5, 7, 3};
int chave = 7;
int i = 0;
int achado = 0;

while (i < 4 && !achado) {
    if (numeros[i] == chave) {
        achado = 1;
    } else {
        i++;
    }
}
```

Nesse caso, o laço continua enquanto ainda houver posições para verificar e o elemento não tiver sido encontrado.

As duas abordagens podem funcionar corretamente. A escolha depende do contexto e de qual estrutura torna a lógica mais clara.
