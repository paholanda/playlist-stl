#include "Interface.hpp"
#include <iostream>

void Interface::limparBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void Interface::executar() {
    int opcao = 0;
    while (opcao != 7) {
        std::cout << "\n=== GERENCIADOR DE MUSICAS ===\n"
                  << "1. Cadastrar Musica\n"
                  << "2. Listar Todas as Musicas (Ordenadas por Titulo)\n"
                  << "3. Buscar Musica por Titulo\n"
                  << "4. Criar Playlist\n"
                  << "5. Adicionar Musica a Playlist\n"
                  << "6. Exibir Playlist\n"
                  << "7. Sair\n"
                  << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "Entrada invalida! Digite um numero.\n";
            limparBuffer();
            continue;
        }

        if (opcao == 1) {
            int id, duracao;
            std::string titulo, artista, genero;
            std::cout << "ID: "; std::cin >> id;
            limparBuffer();
            std::cout << "Titulo: "; std::getline(std::cin, titulo);
            std::cout << "Artista: "; std::getline(std::cin, artista);
            std::cout << "Genero: "; std::getline(std::cin, genero);
            std::cout << "Duracao (segundos): "; std::cin >> duracao;

            if (biblio.cadastrarMusica(id, titulo, artista, genero, duracao)) {
                std::cout << "Musica cadastrada com sucesso!\n";
            } else {
                std::cout << "Erro: ID ja existente!\n";
            }
        } else if (opcao == 2) {
            auto lista = biblio.listarTodasMusicas();
            if (lista.empty()) {
                std::cout << "Nenhuma musica cadastrada.\n";
            } else {
                std::cout << "\n--- CATALOGO --- \n";
                for (const auto& m : lista) {
                    std::cout << "[" << m.getId() << "] " << m.getTitulo() 
                              << " - " << m.getArtista() << " (" << m.getGenero() << ") " 
                              << m.getDuracao() << "s\n";
                }
            }
        } else if (opcao == 3) {
            std::string titulo;
            limparBuffer();
            std::cout << "Digite o titulo exato: ";
            std::getline(std::cin, titulo);
            Musica m;
            if (biblio.buscarMusicaPorTitulo(titulo, m)) {
                std::cout << "Encontrada: [" << m.getId() << "] " << m.getTitulo() << " - " << m.getArtista() << "\n";
            } else {
                std::cout << "Musica nao encontrada.\n";
            }
        } else if (opcao == 4) {
            std::string nome;
            limparBuffer();
            std::cout << "Nome da Playlist: ";
            std::getline(std::cin, nome);
            if (biblio.criarPlaylist(nome)) {
                std::cout << "Playlist criada!\n";
            } else {
                std::cout << "Erro: Playlist ja existe!\n";
            }
        } else if (opcao == 5) {
            std::string nome;
            int id;
            limparBuffer();
            std::cout << "Nome da Playlist: "; std::getline(std::cin, nome);
            std::cout << "ID da Musica: "; std::cin >> id;
            if (biblio.adicionarMusicaNaPlaylist(nome, id)) {
                std::cout << "Musica adicionada com sucesso!\n";
            } else {
                std::cout << "Erro: Playlist ou Musica nao encontrada!\n";
            }
        } else if (opcao == 6) {
            std::string nome;
            limparBuffer();
            std::cout << "Nome da Playlist: "; std::getline(std::cin, nome);
            Playlist p;
            if (biblio.obterPlaylist(nome, p)) {
                std::cout << "\n--- PLAYLIST: " << p.getNome() << " ---\n";
                for (const auto& m : p.getFaixas()) {
                    std::cout << "- " << m.getTitulo() << " (" << m.getArtista() << ")\n";
                }
            } else {
                std::cout << "Playlist nao encontrada.\n";
            }
        }
    }
}
