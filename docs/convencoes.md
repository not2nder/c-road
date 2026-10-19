# Convenções de escrita em C

Convenções de escrita são padrões que ajudam a manter o código organizado, legível e consistente.

A linguagem C permite diferentes estilos de escrita. O importante é escolher um padrão e utilizá-lo de maneira consistente ao longo do programa.

## 1. Nomeação de variáveis e funções

Em C, os nomes de variáveis e funções devem começar com uma letra ou _, seguidos de letras, números ou _.

Espaços e caracteres como `-` não são permitidos. Além disso, C diferencia letras maiúsculas de minúsculas: `idade`, `Idade` e `IDADE` são nomes diferentes.

**Prefira nomes claros e descritivos:**

```c
// Evite nomes pouco informativos
int x = 18;
float v = 7.5;

// Prefira nomes que indiquem a finalidade
int idade = 18;
float nota = 7.5;
```

Nomes curtos podem fazer sentido em contextos específicos, mas devem ser usados com cuidado.

### 1.1. Padrões de nomeação

Uma convenção comum em C é utilizar [`snake_case`](https://developer.mozilla.org/en-US/docs/Glossary/Snake_case) para variáveis e funções, ou seja, palavras minúsculas separadas por `_`.

```c
int idade_aluno;
float media_final;

int calcular_media(void);
void exibir_resultado(void);
```

Para constantes definidas com `#define`, é comum utilizar letras maiúsculas e `_`:

```c
#define MAX_TENTATIVAS 5
#define TAMANHO_BUFFER 100
```

Esses são padrões de escrita, não exigências da linguagem. O mais importante é manter a consistência.

## 2. Como escolher nomes adequados

O nome deve ajudar a entender a finalidade da variável sem exigir comentários desnecessários.

```c
// Pouco descritivo
int n = 10;

// Mais claro
int quantidade_alunos = 10;
```

Também evite nomes excessivamente longos quando uma opção mais simples comunica a mesma ideia.

```c
int idade;
int idade_do_aluno_matriculado_na_disciplina_de_lp1_turno_da_noite;
```

O segundo nome pode ser útil em um contexto específico, mas geralmente `idade` é suficiente quando o significado já está claro.

Prefira nomes que expliquem o papel da variável no programa, não apenas o tipo de dado que ela armazena.

## 3. O uso de `i`, `j` e `k`

As letras `i`, `j` e `k` são tradicionalmente utilizadas como variáveis de controle em laços, principalmente quando os índices são simples e o contexto é evidente.

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

Nesse exemplo, `i` funciona bem porque representa apenas o índice de um laço curto.

Em laços aninhados, é comum utilizar `i` e `j`:

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("i = %d, j = %d\n", i, j);
    }
}
```

A convenção mais comum é:

- `i`: primeiro índice ou contador;
- `j`: segundo índice, geralmente em um laço interno;
- `k`: terceiro índice, quando necessário.

Essas letras são convenções históricas, não regras da linguagem. Você pode utilizar outros nomes quando eles tornarem o código mais claro.

### 3.1. Quando usar nomes mais descritivos?

Em exemplos maiores, nomes como `linha`, `coluna` e `indice` podem comunicar melhor a finalidade da variável.

```c
for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
        printf("%d %d\n", linha, coluna);
    }
}
```

Isso é especialmente útil ao trabalhar com matrizes, em que cada variável representa uma posição diferente.

**Em resumo:** use `i`, `j` e `k` quando o contexto for simples e evidente. Prefira nomes descritivos quando eles ajudarem a compreender a lógica do programa.

## 4. Indentação e organização dos blocos

A indentação não determina os blocos em C, mas ajuda a visualizar sua estrutura.

```c
if (idade >= 18) {
    printf("Maior de idade\n");

    if (idade >= 65) {
        printf("Pessoa idosa\n");
    }
}
```

Cada nível de bloco recebe um nível adicional de indentação.

Neste projeto, utilizaremos **quatro espaços por nível de indentação**, evitando misturar espaços e tabulações no mesmo arquivo.

## 5. Espaços e organização das expressões

Espaços ao redor dos operadores tornam as expressões mais fáceis de ler.

```c
// Evite
int resultado=a+b*2;

// Prefira
int resultado = a + b * 2;
```

Também é comum separar os argumentos de funções com um espaço depois da vírgula:

```c
printf("%d, %d, %d\n", x, y, z);
```

Evite espaços desnecessários entre o nome de uma função e os parênteses da chamada:

```c
// Padrão adotado
printf("Olá!\n");

// Evite variar o estilo sem motivo
printf ("Olá!\n");
```

## 6. Posicionamento das chaves

Neste projeto, adotaremos o estilo em que a chave de abertura fica na mesma linha da estrutura:

```c
if (nota >= 7) {
    printf("Aprovado\n");
} else {
    printf("Reprovado\n");
}
```

O mesmo padrão será utilizado em funções e laços:

```c
int main() {
    for (int i = 0; i < 3; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Outros estilos também são válidos. A escolha é uma convenção; o importante é não alternar entre estilos sem necessidade.

## 7. Organização das declarações

Declare variáveis próximas do local em que serão utilizadas, quando isso ajudar a compreender o código.

```c
int main(void) {
    int idade = 18;
    float altura = 1.75;

    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);

    return 0;
}
```

Também prefira inicializar as variáveis com um valor adequado antes de utilizá-las, evitando depender de valores indeterminados.

Quando variáveis possuem finalidades diferentes, declará-las separadamente pode facilitar a leitura:

```c
int idade = 18;
int quantidade_alunos = 30;
```

Embora isto também seja válido:

```c
int idade = 18, quantidade_alunos = 30;
```

## 8. Comentários

Utilize comentários para explicar intenções, decisões ou detalhes que não sejam evidentes pela leitura do código.

```c
// Calcula a média das notas informadas.
float media = (nota1 + nota2 + nota3) / 3.0;
```

Evite comentários que apenas repetem a instrução:

```c
// Soma 1 a i
i++;
```

Em materiais didáticos, esse tipo de comentário ainda pode ser útil para explicar um conceito novo. Conforme você aprende, vale priorizar comentários que acrescentem informação.
