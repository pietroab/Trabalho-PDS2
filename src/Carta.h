/**
 * @file Classe Carta - interface.
 */

#ifndef CARTA_H
#define CARTA_H

#include <string>

/**
 * @brief Classe que representa uma carta.
 * 
 * @param id Identificação da carta no baralho.
 * @param nome Nome da carta.
 */
class Carta {
public:
    /**
     * @brief Construtor padrão.
     */
    inline Carta(): id(0), nome(""){};
    /**
     * @brief Construtor por cópia.
     */
    Carta(const Carta& other);
    /**
     * @brief Construtor.
     */
    inline Carta(unsigned int id, std::string nome): id(id), nome(nome){};
    /**
     * @brief Destrutor.
     */
    inline virtual ~Carta(){};
    /**
     * @brief Get para id.
     * @return Id
     */
    unsigned int getId() const;
    /**
     * @brief Set para id.
     * @param id Id da carta.
     */
    void setId(unsigned int id);
    /**
     * @brief Get para nome.
     * @return 
     */
    std::string getNome() const;
    /**
     * @brief Set para nome.
     * @param nome Nome da carta.
     */
    void setNome(std::string nome);
    /**
     * @brief Sobrecarga do operador << 
     * para stream (escrita na saída padrão ou arquivo).
     * @param ostream Stream de saída.
     * @param carta Carta a ser enviada para o stream.
     * @return Stream modificado com o conteúdo da carta.
     */
    friend std::ostream& operator<<(std::ostream& o, const Carta& carta);
private:
    unsigned int id;
    std::string nome;
};

#endif /* CARTA_H */

