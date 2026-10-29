# Plano de Implementação

## Etapa 1: Estrutura da Classe Musica
- Criar `include/Musica.hpp` e `src/Musica.cpp`.
- Atributos: `id`, `titulo`, `artista`, `genero`, `duracao`.
- Implementar `operator<` (para uso em `std::set` ou ordenação) e `operator==` (para busca/`std::find`).

## Etapa 2: Estrutura da Classe Playlist
- Criar `include/Playlist.hpp` e `src/Playlist.cpp`.
- Atributos: `nome` e container `std::list<Musica>`.
- Métodos para adicionar música, remover e listar.

## Etapa 3: Lógica Central na Classe Biblioteca
- Criar `include/Biblioteca.hpp` e `src/Biblioteca.cpp`.
- Atributos: `std::map<int, Musica>` (chave: ID) e `std::set<string>` para gêneros/estilos únicos.
- Métodos para gerenciar cadastro, buscas e associação a playlists.

## Etapa 4: Interface de Usuário e Menu
- Criar `include/Interface.hpp`, `src/Interface.cpp` e `src/main.cpp`.
- Leitura do teclado, tratamento de erros de digitação e navegação do menu.
