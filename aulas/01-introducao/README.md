# ntrodução à linguagem C

Neste módulo, vamos conhecer a estrutura básica de um programa em C, escrever nosso primeiro código e aprender como compilá-lo e executá-lo.

## 1. Primeiro programa

O exemplo [hello.c](hello.c) contém um programa simples que exibe uma mensagem na tela.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");

    return 0;
}
```

### Estrutura

#### `#include <stdio.h>`

O comando `#include` é utilizado para incluir o conteúdo de um arquivo que contém determinadas funções que serão utilizadas no nosso programa.

No caso do `<stdio.h>`, contém as funções de entrada e saída de dados básicas, como o `printf`.

#### `int main(void)`

Define a função principal do programa. Quando executamos um programa C, normalmente é por ela que a execução começa.

- `int` indica que a função é do tipo inteiro.
- `main` é o nome da função.
- `void`, indica que ela não recebe argumentos (opcional).

#### `printf("Hello, World!\n");`

`printf()` é a função utilizada para exibir informações no terminal. O Texto que queremos exibir fica entre aspas duplas (" ").

O `\n` representa uma quebra de linha, criando uma nova linha no final da impressão.

#### `return 0;`

Encerra a função `main()` e indica término bem-sucedido do programa ao ambiente que o executou.

O valor do return pode ser utilizado pelo sistema ou por outro programa para verificar o resultado da execução. Em geral, zero indica sucesso, enquanto valores diferentes são utilizados para indicar falha.

O uso de `return 0` é opcional desde o padrão C99. Mesmo sendo opcional, é recomendado colocar o return 0; de forma explícita para manter a clareza e a compatibilidade com compiladores ou estilos de código mais antigos.

## 2. Execução

Para executar o programa, precisamos utilizar um ambiente capaz de compilar e executar código C.

Se você utiliza o Visual Studio Code (VS Code), o procedimento depende das extensões e das ferramentas instaladas na sua máquina. Caso seu ambiente já esteja configurado, você pode utilizar o botão de execução no canto superior direito.

Após executar o programa, o resultado esperado é:

```bash
Hello, World!
```

A mensagem pode aparecer no terminal integrado do VS Code ou em outro terminal aberto pela ferramenta de execução.

> Para executar corretamente o código no Visual Studio, é preciso ter instalado o compilador C e uma extensão para C/C++. o Compilador padrão do windows é o MinGW-w64.

## 3. Exercícios

- Modifique a mensagem para exibir seu nome.
- Faça o programa exibir duas mensagens em linhas diferentes.
- Remova o return 0;, execute o programa novamente e observe que ele continua funcionando normalmente.
