/**
 * @file Classe Carta - implementação.
 */

#include "Carta.h"
#include <iostream>

Carta::Carta(const Carta& other){
    this->id = other.id;
    this->nome = other.nome;
}

unsigned int Carta::getId() const {
    return id;
}

void Carta::setId(unsigned int id) {
    this->id = id;
}

std::string Carta::getNome() const {
    return nome;
}

void Carta::setNome(std::string nome) {
    this->nome = nome;
}

std::ostream& operator<<(std::ostream& o, const Carta& carta){
    o << "Nome: " << carta.getNome() << std::endl
      << "Id: " << carta.getId();

    return o;
}