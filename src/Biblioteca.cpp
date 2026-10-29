#include "Biblioteca.hpp"
#include <algorithm>

bool Biblioteca::cadastrarMusica(int id, const std::string& titulo, const std::string& artista, const std::string& genero, int duracao) {
    if (catalogo.find(id) != catalogo.end()) {
        return false;
    }
    Musica nova(id, titulo, artista, genero, duracao);
    catalogo[id] = nova;
    generosUnicos.insert(genero);
    return true;
}

std::vector<Musica> Biblioteca::listarTodasMusicas() const {
    std::vector<Musica> lista;
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        lista.push_back(it->second);
    }
    std::sort(lista.begin(), lista.end());
    return lista;
}

bool Biblioteca::buscarMusicaPorTitulo(const std::string& titulo, Musica& resultado) const {
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (it->second.getTitulo() == titulo) {
            resultado = it->second;
            return true;
        }
    }
    return false;
}

bool Biblioteca::criarPlaylist(const std::string& nome) {
    if (playlists.find(nome) != playlists.end()) {
        return false;
    }
    playlists[nome] = Playlist(nome);
    return true;
}

bool Biblioteca::adicionarMusicaNaPlaylist(const std::string& nomePlaylist, int idMusica) {
    auto itP = playlists.find(nomePlaylist);
    auto itM = catalogo.find(idMusica);

    if (itP != playlists.end() && itM != catalogo.end()) {
        itP->second.adicionarMusica(itM->second);
        return true;
    }
    return false;
}

bool Biblioteca::obterPlaylist(const std::string& nomePlaylist, Playlist& p) const {
    auto it = playlists.find(nomePlaylist);
    if (it != playlists.end()) {
        p = it->second;
        return true;
    }
    return false;
}
