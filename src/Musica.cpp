#include "Musica.hpp"

Musica::Musica() : id(0), titulo(""), artista(""), genero(""), duracao(0) {}

Musica::Musica(int id, std::string titulo, std::string artista, std::string genero, int duracao)
    : id(id), titulo(titulo), artista(artista), genero(genero), duracao(duracao) {}

int Musica::getId() const { return id; }
std::string Musica::getTitulo() const { return titulo; }
std::string Musica::getArtista() const { return artista; }
std::string Musica::getGenero() const { return genero; }
int Musica::getDuracao() const { return duracao; }

bool Musica::operator<(const Musica& outra) const {
    return this->titulo < outra.titulo;
}

bool Musica::operator==(const Musica& outra) const {
    return this->id == outra.id || this->titulo == outra.titulo;
}
