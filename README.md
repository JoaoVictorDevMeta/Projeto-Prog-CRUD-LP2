# VaporStudio

Sistema de cadastro e gerenciamento de jogos em C++ para a disciplina de Programação I / LP1.

## Sobre o projeto

O programa implementa um CRUD (Create, Read, Update e Delete) para jogos, com diferentes tipos de títulos:

- AAA
- Indie
- Mobile

Além disso, o sistema permite:

- cadastrar jogos
- listar jogos
- editar informações
- remover jogos
- vender cópias
- gerar relatórios
- salvar e carregar dados em arquivo

## Estrutura principal

- `main.cpp` — ponto de entrada do programa
- `vaporStudio.h` — lógica principal do sistema
- `jogo.h` — classe base `Jogo`
- `jogoAAA.h` — implementação de jogos AAA
- `jogoIndie.h` — implementação de jogos Indie
- `jogoMobile.h` — implementação de jogos Mobile
- `engine.h` — definição da engine
- `desenvolvedor.h` — definição do desenvolvedor
- `dados.txt` — arquivo de persistência

## Requisitos

- Compilador C++ (ex.: g++)
- Sistema operacional com terminal/console

## Como compilar

No diretório do projeto, execute:

```bash
g++ -std=c++17 main.cpp -o vaporstudio
```

## Como executar

```bash
./vaporstudio
```

Ou no Windows:

```bash
vaporstudio.exe
```

## Observação

Este projeto é acadêmico e foi desenvolvido para fins de estudo e prática de conceitos de orientação a objetos, herança e manipulação de arquivos em C++.