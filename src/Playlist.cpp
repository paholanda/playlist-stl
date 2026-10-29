#include "Playlist.hpp"

Playlist::Playlist() : nome("") {}

Playlist::Playlist(std::string nome) : nome(nome) {}

std::string Playlist::getNome() const { return nome; }

void Playlist::adicionarMusica(const Musica& m) {
    faixas.push_back(m);
}

const std::list<Musica>& Playlist::getFaixas() const {
    return faixas;
}
