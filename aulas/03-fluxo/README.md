# MÓDULO 03: Estruturas de controle de fluxo

As estruturas de controle de fluxo permitem definir quais partes do código serão executadas, dependendo de determinadas condições. Com elas, podemos criar programas que tomam decisões, escolhem entre diferentes caminhos e executam instruções de acordo com os valores recebidos.

## 1. if-else

A estrutura `if-else` permite executar diferentes blocos de código dependendo de uma condição.

- `if`: executa um bloco caso a condição seja verdadeira.
- `else`: executa outro bloco caso a condição do `if` seja falsa.

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

Nesse exemplo, como a condição idade >= 18 é verdadeira, o primeiro bloco é executado.

Se alterarmos a idade para 16, a condição será falsa e o programa executará o bloco do `else`, exibindo "Menor de idade".

O `else` é opcional. Quando queremos executar uma ação apenas se determinada condição for verdadeira, podemos utilizar somente o `if`.

```c
int temperatura = 35;

if (temperatura > 30) {
    printf("Temperatura elevada\n");
}
```

**Saída:**

```text
Temperatura elevada
```

Se a temperatura fosse 25, a mensagem não seria exibida, mas o programa continuaria executando normalmente.

### Operadores relacionais

As condições geralmente utilizam operadores relacionais, estudados anteriormente em [operadores](../02-tipos/README.md#74-operadores-relacionais), para comparar valores.

| Operador | Significado      | Exemplo     |
| -------- | ---------------- | ----------- |
| ==       | Igual a          | idade == 18 |
| !=       | Diferente de     | idade != 18 |
| >        | Maior que        | idade > 18  |
| <        | Menor que        | idade < 18  |
| >=       | Maior ou igual a | idade >= 18 |
| <=       | Menor ou igual a | idade <= 18 |

**Atenção:** `=` é o operador de atribuição, enquanto `==` é o operador de igualdade. O primeiro atribui um valor; o segundo compara dois valores. em uma estrura de if-else, o correto é utilizar `==`.

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

**Saída:**

```text
Aprovado
```

O programa verifica as condições na ordem em que aparecem, de cima para baixo. Como nota vale 7, a primeira condição é verdadeira e o programa exibe "Aprovado". As condições seguintes não são verificadas.

É possível utilizar vários `else if` para representar diferentes possibilidades.

### A importância da ordem das condições

A ordem pode alterar o resultado do programa, pois, quando uma condição é verdadeira, o restante da sequência é ignorado.

Por exemplo:

```c
int nota = 8;

if (nota >= 4) {
    printf("Recuperação ou aprovação\n");
} else if (nota >= 7) {
    printf("Aprovado\n");
}
```

Nesse caso, a primeira condição já é verdadeira para uma nota 8. Portanto, o `else if` nunca será executado.

Para classificar as notas do exemplo anterior corretamente, a condição `nota >= 7` deve ser verificada primeiro.

## 3. Condicionais aninhadas

Uma condicional aninhada ocorre quando uma estrutura condicional é colocada dentro de outra. Isso permite verificar uma condição adicional somente quando a condição externa for verdadeira.

### Exemplo

```c
int idade_aluno = 20;
int matriculado = 1;

if (idade_aluno >= 18) {
    printf("Maior de idade\n");

    if (matriculado == 1) {
        printf("Aluno matriculado\n");
    }
}
```

**Saída:**

```text
Maior de idade
Aluno matriculado
```

Nesse exemplo, o segundo if está dentro do primeiro. Portanto, a condição matriculado == 1 só é verificada se idade_aluno >= 18 for verdadeira.

Se a idade fosse 16, nenhum dos dois textos seria exibido.

### Condicionais aninhadas e condições compostas

Em algumas situações, podemos utilizar um operador lógico para combinar condições em vez de aninhar estruturas.

Por exemplo, o segundo `if` do exemplo anterior poderia ser substituído por:

```c
if (idade_aluno >= 18 && matriculado == 1) {
    printf("Aluno matriculado\n");
}
```

Essa alternativa verifica as duas condições juntas. Entretanto, ela não é totalmente equivalente ao exemplo completo anterior, pois deixa de exibir "Maior de idade" quando a pessoa é maior de idade, mas não está matriculada.

A escolha depende do comportamento desejado e da clareza do código.

### Operador `&&` — E lógico

```c
int idade = 20;
int possui_ingresso = 1;

if (idade >= 18 && possui_ingresso == 1) {
    printf("Entrada permitida\n");
}
```

**Saída:**

```text
Entrada permitida
```

As duas condições precisam ser verdadeiras: a pessoa deve ter pelo menos 18 anos e possuir ingresso.

### Operador `||` — OU lógico

```c
int temperatura = 35;

if (temperatura < 10 || temperatura > 30) {
    printf("Temperatura fora da faixa\n");
}
```

**Saída:**

```text
Temperatura fora da faixa
```

Basta uma das condições ser verdadeira para que o bloco seja executado.

### Operador `!` — NÃO lógico

```c
int possui_ingresso = 0;

if (!possui_ingresso) {
    printf("Ingresso não encontrado\n");
}
```

**Saída:**

```text
Ingresso não encontrado
```

O operador `!` inverte o valor lógico da expressão. Como `possui_ingresso` vale zero, `!possui_ingresso` resulta em verdadeiro.

Em C, zero representa falso e qualquer valor diferente de zero representa verdadeiro em uma condição. Por isso, variáveis inteiras também podem ser utilizadas diretamente em expressões condicionais.

## 5. Operador ternário

O operador ternário é uma forma compacta de escolher entre duas expressões com base em uma condição. Ele pode ser utilizado em situações simples nas quais um `if-else` ocuparia mais linhas.

### Sintaxe

```c
condicao ? valor_se_verdadeiro : valor_se_falso;
```

A condição é avaliada primeiro. Se for verdadeira, a expressão retorna o valor antes dos dois-pontos (`:`). Caso contrário, retorna o valor depois deles.

### Exemplo

```c
int idade = 18;

printf(idade >= 18 ? "Maior de idade" : "Menor de idade");
```

**Saída:**

```text
Maior de idade
```

Nesse caso, o operador ternário verifica se a idade é maior ou igual a 18 e escolhe a mensagem correspondente.

Também podemos atribuir o resultado de um operador ternário a uma variável:

```c
int nota = 90;

char resultado = nota >= 70 ? 'A' : 'R';

printf("%c\n", resultado);
```

**Saída:**

```text
A
```

Nesse exemplo, o resultado da condição é utilizado para escolher qual caractere será atribuído à variável `resultado`.

### Múltiplas condições com o operador ternário

Também é possível encadear operadores ternários para representar mais de duas possibilidades.

```c
int nota = 5;

printf("%s\n",
    nota >= 7 ? "Aprovado" :
    nota >= 4 ? "Recuperação" :
                "Reprovado"
);
```

**Saída:**

```text
Recuperação
```

Esse exemplo segue a mesma lógica da estrutura:

```c
if (nota >= 7) {
    // Aprovado
} else if (nota >= 4) {
    // Recuperação
} else {
    // Reprovado
}
```

Embora seja possível encadear vários operadores ternários, muitas condições podem tornar a expressão difícil de ler. Nesses casos, prefira utilizar `if-else`.

---

## 6. switch-case

A estrutura `switch-case` permite escolher entre diferentes blocos de código com base no valor de uma expressão. É especialmente útil quando queremos comparar uma mesma expressão com vários valores constantes específicos.

### Exemplo

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

**Saída:**

```text
Sexta-feira
```

Como dia vale 5, o programa executa o bloco associado a `case 5`.

### Elementos do switch-case

- `switch (dia)`: indica qual expressão será avaliada.
- `case <valor>:` define um caso que pode corresponder ao valor avaliado.
- `break`: encerra o switch, impedindo que a execução continue pelos próximos casos.
- `default`: define o caso de fallback, executado quando nenhum case corresponde ao valor.

Por exemplo, se a variável dia receber o valor 8, nenhum dos casos de 1 a 7 corresponderá. Nesse caso, o programa executará o default e exibirá "Valor inválido".

**Atenção:** sem um `break`, a execução pode continuar pelos próximos casos, mesmo que seus valores não correspondam à expressão. Esse comportamento é chamado de _fall-through_ e pode ser utilizado intencionalmente, mas deve ser evitado quando não for desejado.

O `switch-case` é adequado para comparar uma expressão com valores constantes específicos já conhecidos. Para condições que envolvem intervalos ou comparações como `nota >= 7`, normalmente utilizamos `if-else`.

## 💡 Recomendações de estudo

- Leia o arquivo [condicoes.c](../03-fluxo/condicoes.c) e execute o programa para observar o comportamento de cada estrutura.
- Altere os valores de `idade`, `nota` e `dia` para testar diferentes resultados.
- Experimente utilizar `if` sem `else`, criar condicionais aninhadas e combinar condições com `&&`, `||` e `!`.
- Teste diferentes ordens de condições para entender como elas afetam o resultado.
- Experimente valores que acionem o `else`, o último caso do operador ternário e o `default` do `switch`.
- Compare o uso de `if-else` e `switch-case` para entender em quais situações cada estrutura é mais adequada.
- Procure prever a saída antes de executar o programa. Isso ajuda a desenvolver o raciocínio lógico e a compreender a ordem de execução.
- Desenvolva suas próprias condições e fluxos para testar diferentes possibilidades.
