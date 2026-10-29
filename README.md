# Sistema de Playlist e Biblioteca de Músicas

Atividade da Unidade 2 - Linguagem de Programação I.

## Como Compilar:

Para compilar o projeto em C++11, execute no terminal na raiz do repositório:

```bash
g++ -std=c++11 -Wall -Wextra src/*.cpp -Iinclude -o sistema

```
## Onde uso a STL:

1. std::map<int, Musica> (em Biblioteca.hpp): Utilizado para guardar e indexar o catálogo de músicas de maneira eficiente através da chave única que é o ID da música.

2. std::set <std::string> (em Biblioteca.hpp): Armazena os géneros musicais únicos sem permitir duplicatas.

3. std::list<Musica> (em Playlist.hpp): Utilizado para gerenciar a sequência de faixas de uma playlist, permitindo inserções sequenciais.

4. std::sort (em Biblioteca.cpp): Utilizado para ordenar a lista do catálogo pelo título da música, fazendo uso direto do operador < sobrescrito na classe Musica.

## Onde uso a IA:

A Inteligência Artificial foi utilizada para auxiliar na estruturação e modularização do código em arquivos .hpp e .cpp, garantir o tratamento correto dos erros de leitura do buffer do cin e assegurar que as regras de C++11 fossem seguidas sem vazamento de memória.
