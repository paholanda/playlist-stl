#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Biblioteca.hpp"

class Interface {
private:
    Biblioteca biblio;
    void limparBuffer();

public:
    void executar();
};

#endif
