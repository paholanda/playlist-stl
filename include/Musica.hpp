#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include <list>
#include "Musica.hpp"

class Playlist {
private:
    std::string nome;
    std::list<Musica> faixas; // Uso da STL: std::list

public:
    Playlist();
    explicit Playlist(std::string nome);

    std::string getNome() const;
    void adicionarMusica(const Musica& m);
    const std::list<Musica>& getFaixas() const;
};

#endif
