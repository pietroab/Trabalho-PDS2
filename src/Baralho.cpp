/**
 * @file Classe Baralho - baralho.
 */

#include "Baralho.h"
#include "Carta.h"
#include "Carro.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>

Baralho::Baralho(std::string arquivo, TipoCarta tipoCarta) {
    srand (time(NULL));
    this->valid = false;
    this->tipoCarta = tipoCarta;
    std::ifstream file(arquivo);
    if(file.is_open()){
        if (this->tipoCarta == TipoCarta::CARRO){
            unsigned int id = 0;
            std::string nome;
            float potencia;
            float cilindradas;
            unsigned int velocidade;
            float aceleracao;
            unsigned int peso;
            std::string line;
            std::getline (file, line);
            int count;
            while ( std::getline (file, line) ){
                std::stringstream ss(line);
                std::string value;
                count = 0;
                id++;
                while (!ss.eof()) {
                    try{
                        std::getline(ss, value, ',');
                        switch(count){
                            case 0:
                                nome = value;
                                break;
                            case 1:
                                potencia = std::stof(value);
                                break;
                            case 2:
                                cilindradas = std::stof(value);
                                break;
                            case 3:
                                velocidade = std::stoul(value);
                                break;
                            case 4:
                                aceleracao = std::stof(value);
                                break;
                            case 5:
                                peso = std::stoul(value);
                                break;
                        }
                        count++;
                    } catch (const std::exception& ex) {
                        count = 100;
                        break;
                    }
                }
                if (count != 6){
                    std::cerr << "Linha " << line 
                              << " é inválida e foi ignorada." << std::endl;
                } else {
                    this->cartas.push_back((Carta*) new Carro(id
                                                            , nome
                                                            , potencia
                                                            , cilindradas
                                                            , velocidade
                                                            , aceleracao
                                                            , peso));
                }
            }
        }
        file.close();
        this->valid = true;
    } else {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
    }
}

void Baralho::shuffle(){
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(this->cartas), std::end(this->cartas), rng);
}

Baralho::Baralho(TipoCarta tipoCarta){
    srand (time(NULL));
    this->tipoCarta = tipoCarta;
    this->valid=true;
}

bool Baralho::isValid(){
    return this->valid;
}

TipoCarta Baralho::getTipoCarta() const {
    return tipoCarta;
}

int Baralho::size() const{
    return this->cartas.size();
}

void Baralho::addCarta(Carta * carta){
    if (!this->validId(carta->getId()))
        this->cartas.push_back(carta);
}

Carta * Baralho::retiraCarta(){
    int idx = rand()%this->cartas.size();
    Carta * c = this->cartas[idx];
    this->cartas.erase(this->cartas.begin() + idx);
    return c;
}

/**
 * @brief Retira uma carta com o id caso válido.
 */
Carta * Baralho::retiraCarta(unsigned int id){
    int posicao = this->buscaCarta(id);
    if (posicao != -1){
        Carta * c = this->cartas[posicao];
        this->cartas.erase(this->cartas.begin() + posicao);
        return c;
    } else
        return NULL;
}

/**
 * @brief Consulta uma carta com o id caso válido.
 */
void * Baralho::consultaCarta(unsigned int id) const{
    int posicao = this->buscaCarta(id);
    if (posicao != -1){
        Carta * c = this->cartas[posicao];
        if (this->tipoCarta == TipoCarta::CARRO)
            return (void *) new Carro(*((Carro*) c));
    } else
        return (void* ) new Carta();
}

/**
 * Busca índice de uma carta no vetor pelo id.
 * @return Caso exista a carta retorna o índice, do contrário -1.
 */
int Baralho::buscaCarta(unsigned int id) const{
    int idx = 0;
    int posicao = -1;
    for (Carta * carta : this->cartas){
       if (carta->getId() == id){
           posicao = idx;
           break;
       }
       idx++;
    }
    return posicao;
}

std::ostream& operator<<(std::ostream& o, const Baralho& baralho){
    if (baralho.getTipoCarta() == TipoCarta::CARRO){
        for (Carta * carta : baralho.cartas)
            o << *((Carro*)carta) << std::endl 
              << "------------------------" << std::endl;
    }
    
    return o;
}