# Sistema de Playlist e Biblioteca de Músicas

## Nome e ideia
O Gerenciador de Playlists é um sistema em C++ para organizar uma biblioteca de músicas e criar playlists personalizadas. Ele permite cadastrar músicas, listar faixas por artista/gênero e criar playlists com ordenação e busca avançadas.

## O que o sistema guarda
- **Música:** ID único (int), título (string), artista (string), gênero (string) e duração em segundos (int).
- **Playlist:** Nome da playlist (string) e uma coleção de faixas (`std::list`).
- **Biblioteca:** Coleção total de músicas (`std::map`) e playlists do usuário.

## O que dá para fazer
1. Cadastrar nova música (pede ID, título, artista, gênero e duração).
2. Listar todas as músicas cadastradas (ordenadas por título).
3. Buscar música por título exato.
4. Criar uma nova playlist com um nome.
5. Adicionar uma música cadastrada a uma playlist (pelo ID).
6. Listar todas as músicas de uma playlist específica.
7. Sair do programa.

## Regras
- Não podem existir duas músicas com o mesmo ID ou com o mesmo título.
- Não podem existir duas playlists com o mesmo nome.
- Os campos de texto (título, artista e gênero) não podem ser vazios.
- A duração da música e o ID devem ser valores numéricos inteiros maiores que zero.

## Quando algo dá errado
- Se o ID ou título buscado não existir, o sistema exibe uma mensagem de erro amigável sem fechar o programa.
- Se a entrada digitada for de tipo inválido (ex: texto no lugar de número), o menu limpa o buffer e pede uma nova opção.
- Se a lista ou playlist estiver vazia ao tentar exibir, o sistema avisa que não há itens cadastrados.

## Classes que eu imagino
- **Musica:** Representa uma faixa com seus atributos e operadores de comparação (`operator<` e `operator==`).
- **Playlist:** Agrupa músicas em uma coleção sequencial (`std::list`).
- **Biblioteca:** Gerencia o catálogo geral usando `std::map` (ID -> Música) e `std::set` (Gêneros).

## Exemplo de uso
```text
=== GERENCIADOR DE MUSICAS ===
1. Cadastrar Musica
2. Listar Todas as Musicas (Ordenadas por Titulo)
3. Buscar Musica por Titulo
4. Criar Playlist
5. Adicionar Musica a Playlist
6. Exibir Playlist
7. Sair
Escolha uma opcao: 1
ID: 101
Titulo: Time
Artista: Pink Floyd
Genero: Rock
Duracao (segundos): 413
Musica cadastrada com sucesso!

=== GERENCIADOR DE MUSICAS ===
1. Cadastrar Musica
2. Listar Todas as Musicas (Ordenadas por Titulo)
3. Buscar Musica por Titulo
4. Criar Playlist
5. Adicionar Musica a Playlist
6. Exibir Playlist
7. Sair
Escolha uma opcao: 4
Nome da Playlist: Favoritas
Playlist criada!

=== GERENCIADOR DE MUSICAS ===
1. Cadastrar Musica
2. Listar Todas as Musicas (Ordenadas por Titulo)
3. Buscar Musica por Titulo
4. Criar Playlist
5. Adicionar Musica a Playlist
6. Exibir Playlist
7. Sair
Escolha uma opcao: 5
Nome da Playlist: Favoritas
ID da Musica: 101
Musica adicionada com sucesso!

=== GERENCIADOR DE MUSICAS ===
1. Cadastrar Musica
2. Listar Todas as Musicas (Ordenadas por Titulo)
3. Buscar Musica por Titulo
4. Criar Playlist
5. Adicionar Musica a Playlist
6. Exibir Playlist
7. Sair
Escolha uma opcao: 6
Nome da Playlist: Favoritas

--- PLAYLIST: Favoritas ---
- Time (Pink Floyd)

=== GERENCIADOR DE MUSICAS ===
1. Cadastrar Musica
2. Listar Todas as Musicas (Ordenadas por Titulo)
3. Buscar Musica por Titulo
4. Criar Playlist
5. Adicionar Musica a Playlist
6. Exibir Playlist
7. Sair
Escolha uma opcao: 7
