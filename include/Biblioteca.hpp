#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <map>
#include <set>
#include <vector>
#include <string>
#include "Musica.hpp"
#include "Playlist.hpp"

class Biblioteca {
private:
    std::map<int, Musica> catalogo;
    std::set<std::string> generosUnicos; 
    std::map<std::string, Playlist> playlists;

public:
    bool cadastrarMusica(int id, const std::string& titulo, const std::string& artista, const std::string& genero, int duracao);
    std::vector<Musica> listarTodasMusicas() const;
    bool buscarMusicaPorTitulo(const std::string& titulo, Musica& resultado) const;
    
    bool criarPlaylist(const std::string& nome);
    bool adicionarMusicaNaPlaylist(const std::string& nomePlaylist, int idMusica);
    bool obterPlaylist(const std::string& nomePlaylist, Playlist& p) const;
};

#endif
