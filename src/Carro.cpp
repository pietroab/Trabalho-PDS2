/**
 * @file Classe Carro - implementação.
 */

#include "Carro.h"
#include <iostream>
#include <limits>

Carro::Carro(unsigned int id, std::string nome, float potencia, float cilindradas
         , unsigned int velocidade, float aceleracao
         , unsigned int peso): Carta(id, nome){
    this->setPotencia(potencia);
    this->setCilindradas(cilindradas);
    this->setVelocidade(velocidade);
    this->setAceleracao(aceleracao);
    this->setPeso(peso);
}

/**
 * @brief Construtor por cópia.
 */
Carro::Carro(const Carro & carro ){
    this->setId(carro.getId());
    this->setNome(carro.getNome());
    this->potencia = carro.getPotencia();
    this->cilindradas = carro.getCilindradas();
    this->velocidade = carro.getVelocidade();
    this->aceleracao = carro.getAceleracao();
    this->peso = carro.getPeso();
}

float Carro::getAceleracao() const {
    return this->aceleracao;
}

void Carro::setAceleracao(float aceleracao) {
    if (aceleracao < 0)
        this->aceleracao = std::numeric_limits<float>::quiet_NaN();
    else
        this->aceleracao = aceleracao;
}

float Carro::getCilindradas() const {
    return this->cilindradas;
}

void Carro::setCilindradas(float cilindradas) {
    if (cilindradas < 0)
        this->cilindradas = std::numeric_limits<float>::quiet_NaN();
    else
        this->cilindradas = cilindradas;
}

unsigned int Carro::getPeso() const {
    return this->peso;
}

void Carro::setPeso(unsigned int peso) {
    this->peso = peso;
}

float Carro::getPotencia() const {
    return this->potencia;
}

void Carro::setPotencia(float potencia) {
    if (potencia < 0)
        this->potencia = std::numeric_limits<float>::quiet_NaN();
    else
        this->potencia = potencia;
}

unsigned int Carro::getVelocidade() const {
    return this->velocidade;
}

void Carro::setVelocidade(unsigned int velocidade) {
    this->velocidade = velocidade;
}

std::ostream& operator<<(std::ostream& o, const Carro& carro){
    o << *((Carta*)&carro) << std::endl
      << "Potência: " << carro.getPotencia() << "cv" << std::endl
      << "Cilindradas: " << carro.getCilindradas() << "cc" << std::endl
      << "Velocidade: " << carro.getVelocidade() << "Km/h" << std::endl
      << "Aceleracao: " << carro.getAceleracao() << "s" << std::endl
      << "Peso: " << carro.getPeso() << "Kg";
    
    return o;
}