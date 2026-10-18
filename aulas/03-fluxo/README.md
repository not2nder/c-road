# MÓDULO 03: Estruturas de controle de fluxo

As estruturas de controle de fluxo permitem definir quais partes do código serão executadas, dependendo de determinadas condições. Com elas, podemos criar programas que tomam decisões, escolhem entre diferentes caminhos e executam instruções de acordo com os valores recebidos.

## 1. if-else

A estrutura `if-else` permite executar diferentes blocos de código dependendo de uma condição.

- `if`: executa um bloco caso a condição seja verdadeira.
- `else`: executa outro bloco caso a condição do if seja falsa.

### Exemplo

```c
int idade = 18;

if (idade >= 18) {
    printf("Maior de idade\n");
} else {
    printf("Menor de idade\n");
}
```

**Saída:**

```text
Maior de idade
```

Nesse exemplo, a condição `idade >= 18` verifica se a idade é maior ou igual a 18. Como a condição é verdadeira, o primeiro bloco é executado e o programa termina.

Se alterarmos a idade para 16, a condição será falsa e o programa executará o bloco do `else`, exibindo "Menor de idade".

### Operadores relacionais

As condições geralmente utilizam operadores relacionais, vistos anteriormente em [operadores.c](../02-tipos/operadores.c) para comparar valores.

| Operador | Significado      | Exemplo       |
| -------- | ---------------- | ------------- |
| ==       | Igual a          | `idade == 18` |
| !=       | Diferente de     | `idade != 18` |
| `>       | Maior que        | `idade > 18`  |
| `<       | Menor que        | `idade < 18`  |
| >=       | Maior ou igual a | `idade >= 18` |
| <=       | Menor ou igual a | `idade <= 18` |

## 2. Múltiplas condições

Quando existem mais de duas possibilidades, podemos combinar `if`, `else if` e `else` para verificar diferentes condições em sequência.

- `if`: verifica a primeira condição.
- `else if`: verifica outra condição caso as anteriores sejam falsas. Podemos utilizar vários `else if`.
- `else`: executa um bloco caso nenhuma das condições anteriores seja verdadeira.

### Exemplo

```c
int nota = 7;

if (nota >= 7) {
    printf("Aprovado\n");
} else if (nota >= 4) {
    printf("Recuperação\n");
} else {
    printf("Reprovado\n");
}
```

Saída:

```text
Aprovado
```

O programa verifica as condições na ordem em que aparecem. Como `nota` vale 7, a primeira condição é verdadeira e o programa exibe `Aprovado`. As condições seguintes não são verificadas.

É possível utilizar mais de um `else if` em um bloco de `if` para verificar mais de uma condição.

## 3. Operador ternário

O operador ternário é uma forma compacta de escolher entre dois valores com base em uma condição. Ele pode ser utilizado em situações simples nas quais um `if-else` ocuparia mais linhas.

### Sintaxe

```c
condicao ? valor_se_verdadeiro : valor_se_falso;
```

A condição é avaliada primeiro. Se for verdadeira, o resultado será o valor antes dos dois-pontos (`:`). Caso contrário, será o valor depois deles.

### Exemplo

```c
int idade = 18;

printf(idade >= 18 ? "Maior de idade" : "Menor de idade");
```

Saída:

```text
Maior de idade
```

Nesse caso, o operador ternário verifica se a idade é maior ou igual a 18 e escolhe a mensagem correspondente. O especificador `%s` é utilizado para exibir uma string.

Também é possível associar um valor de variável utilizando operador ternário:

```c
int nota = 90;

```

Também é possível encadear operadores ternários para representar mais de duas possibilidades:

```c
int nota = 5;

printf(nota >= 7 ? "Aprovado" : nota >= 4 ? "Recuperação" : "Reprovado");
```

Isso é o mesmo que:

```c
if (nota >= 7) {
    // aprovado
} else if (nota >= 4) {
    // recuperação
} else {
    // reprovado
}
```

Saída:

```text
Recuperação
```

Embora seja possível encadear vários operadores ternários, muitas condições podem tornar a expressão difícil de ler. Nesses casos, prefira utilizar `if-else`.

## 4. Switch cases

A estrutura `switch-case` permite escolher entre diferentes blocos de código com base no valor de uma expressão. É especialmente útil quando queremos comparar uma mesma variável com vários valores previamente definidos.

```c
int dia = 5;

switch (dia) {
    case 1:
        printf("Segunda-feira\n");
        break;

    case 2:
        printf("Terça-feira\n");
        break;

    case 3:
        printf("Quarta-feira\n");
        break;

    case 4:
        printf("Quinta-feira\n");
        break;

    case 5:
        printf("Sexta-feira\n");
        break;

    case 6:
        printf("Sábado\n");
        break;

    case 7:
        printf("Domingo\n");
        break;

    default:
        printf("Valor inválido\n");
        break;
}
```

Saída:

```text
Sexta-feira
```

Como `dia` vale 5, o programa executa o bloco associado a `case 5`.

### Elementos do `switch-case`

- `switch (dia)`: indica qual expressão será avaliada.
- `case valor:` define um caso que pode corresponder ao valor avaliado.
- `break`: encerra o `switch`, impedindo que a execução continue pelos próximos casos.
- `default`: define o caso de fallback, executado quando nenhum `case` corresponde ao valor. É opcional.

Por exemplo, se `dia` receber o valor 8, nenhum dos casos de 1 a 7 será correspondente. Nesse caso, o programa executará o `default` e exibirá `Valor inválido`.

**Atenção:** sem um `break`, a execução pode continuar pelos próximos casos, mesmo que seus valores não correspondam à expressão. Esse comportamento é chamado de _fall-through_ e pode ser utilizado intencionalmente, mas deve ser evitado quando não for desejado.

O `switch-case` é adequado para comparar uma expressão com valores constantes específicos. Para condições que envolvem intervalos ou comparações como `nota >= 7`, normalmente utilizamos if-else.

## 💡 Recomendações de estudo

- Leia o arquivo [condicionais.c](../03-fluxo/condicionais.c) e execute o programa para observar o comportamento de cada estrutura.
- Altere os valores de `idade`, `nota` e `dia` para testar diferentes resultados.
- Experimente condições verdadeiras e falsas, além de valores que acionem o `else`, o último caso do operador ternário e o `default` do `switch`.
- Compare o uso de `if-else` e `switch-case` para entender em quais situações cada estrutura é mais adequada.
- Procure prever a saída antes de executar o programa. Isso ajuda a desenvolver o raciocínio lógico e a compreender a ordem de execução.
- Desenvolva as próprias condições, comparações e fluxos para testar possibilidades.
