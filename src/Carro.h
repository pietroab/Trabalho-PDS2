/**
 * @file Classe Carro - interface.
 */

#ifndef CARRO_H
#define CARRO_H

#include "Carta.h"

/**
 * Classe Carro 
 * 
 * @param id Identificação da carta no baralho.
 * @param nome Nome da carta.
 * @param potencia Potência do carro em cavalos.
 * @param cilindradas Cilindradas do carro em cm3.
 * @param velocidade Velocidade máxima do carro em km/h
 * @param aceleracao Segundos leva para ir de 0Km/h até 100Km/h.
 * @param peso Peso do carro em Kg.
 */
class Carro: public Carta {
public:
    /**
     * @brief Construtor.
     */
    Carro(unsigned int id, std::string nome, float potencia, float cilindradas
         , unsigned int velocidade, float aceleracao
         , unsigned int peso);
    /**
     * @brief Construtor por cópia.
     */
    Carro(const Carro & carro );
    /**
     * @brief Destrutor.
     */
    inline virtual ~Carro(){};
    
    /**
     * @brief Get para aceleração.
     * @return Aceleração.
     */
    float getAceleracao() const;

    /**
     * @brief Set para aceleração.
     * @param aceleracao Aceleração.
     */
    void setAceleracao(float aceleracao);

    /**
     * @brief Get para cilindradas.
     * @return Cilindradas.
     */
    float getCilindradas() const;
    
    /**
     * @brief Set para Cilindradas.
     * @param cilindradas Cilindradas.
     */
    void setCilindradas(float cilindradas);

    /**
     * @brief Get para peso.
     * @return Peso.
     */
    unsigned int getPeso() const;
    
    /**
     * @brief Set para Peso.
     * @param peso Peso.
     */
    void setPeso(unsigned int peso);

    /**
     * @brief Get para potência.
     * @return Potência.
     */
    float getPotencia() const;

    /**
     * @brief Set para aceleração.
     * @param aceleracao Aceleração.
     */
    void setPotencia(float potencia);

    /**
     * @brief Get para aceleração.
     * @return Aceleração.
     */
    unsigned int getVelocidade() const;

    /**
     * @brief Set para velocidade.
     * @param velocidade Velocidade.
     */
    void setVelocidade(unsigned int velocidade);
    /**
     * @brief Sobrecarga do operador << 
     * para stream (escrita na saída padrão ou arquivo).
     * @param ostream Stream de saída.
     * @param carro Carro a ser enviado para o stream.
     * @return Stream modificado com o conteúdo do carro.
     */
    friend std::ostream& operator<<(std::ostream& o, const Carro& carro);
private:
    float potencia;
    float cilindradas;
    unsigned int velocidade;
    float aceleracao;
    unsigned int peso;
};

#endif /* CARRO_H */

