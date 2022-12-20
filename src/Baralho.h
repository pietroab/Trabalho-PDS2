/**
 * @file Classe Baralho - interface.
 */

#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include "Carta.h"
#include "TipoCarta.h"
#include <time.h>

/**
 * @brief Classe que representa um baralha. Carrega cartas de um arquivo.
 * 
 * @param cartas Lista de cartas.
 * @param tipoCarta Tipo de carta do baralho.
 * #param valido Se o baralho é válido.
 */
class Baralho {
public:
    /**
     * @brief Construtor
     * @param arquivo Arquivo com o baralho.
     * @param tipoCarta Tipo de carta do baralho.
     */
    Baralho(std::string arquivo, TipoCarta tipoCarta);
    /**
     * @brief Construtor. Baralho de jogador, inicialmente vazio.
     */
    Baralho(TipoCarta tipoCarta);
    /**
     * @brief Adiciona carta ao baralho.
     * @param carta Carta.
     * @param tipoCarta Tipo da Carta.
     */
    void addCarta(Carta * carta);
    /**
     * @brief Retira uma carta aleatoriamente.
     */
    Carta * retiraCarta();
    /**
     * @brief Retira uma carta com o id caso válido.
     */
    Carta * retiraCarta(unsigned int id);
    /**
     * @brief Consulta uma carta com o id caso válido.
     */
    void * consultaCarta(unsigned int id) const;
    /**
     * @brief Verifica se o id da carta selecionada é válido.
     * @param id Id da carta.
     * @return Se válido.
     */
    inline bool validId(unsigned int id){return this->buscaCarta(id) != -1;}
    /**
     * @brief Destrutor
     */
    inline virtual ~Baralho(){};
    /**
     * @brief Baralho válido (arquivo com o baralho bem formatado).
     * @return Se válido.
     */
    bool isValid();
    /**
     * @brief Retorna tipo de carta do baralho.
     * @return Tipo de Carta
     */
    TipoCarta getTipoCarta() const;
    /**
     * @brief Sobrecarga do operador << 
     * para stream (escrita na saída padrão ou arquivo).
     * @param ostream Stream de saída.
     * @param baralho baralho a ser enviada para o stream.
     * @return Stream modificado com o conteúdo do baralho.
     */
    friend std::ostream& operator<<(std::ostream& o, const Baralho& baralho);
    /**
     * @brief Tamanho do baralho.
     * @return Tamanho.
     */
    int size() const;
    /**
     * @brief Embaralha as cartas.
     */
    void shuffle();
private:
    std::vector<Carta*> cartas;
    TipoCarta tipoCarta;
    bool valid;
    /**
     * Busca índice de uma carta no vetor pelo id.
     * @return Caso exista a carta retorna o índice, do contrário -1.
     */
    int buscaCarta(unsigned int id) const;
};

#endif /* BARALHO_H */

