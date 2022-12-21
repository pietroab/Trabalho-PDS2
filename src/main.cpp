/**
 * @file Engine do jogo.
 */


#include <cstdlib>
#include <iostream>

#include "Carta.h"
#include "Carro.h"
#include "Baralho.h"
#include "TipoCarta.h"

#define DEBUG true /*!< Mostra as cartas da máquina. Mude o #define para false caso queira sair do modo DEBUG */

/**
 * Retorna o valor de um atributo de uma Carta Carro pelo número.
 * @param carro Referência para uma Carta Carro.
 * @param atributo Número do atributo.
 * @return Valor do atributo.
 */
float getValor(Carro * carro, int atributo);


/**
 * @brief Engine do jogo.
 * @param argc Quantidade de parâmetros passados por linha de comando. 
 * @param argv Parâmetros passados por linha de comando.
 * @return Status do processo.
 */
int main(int argc, char** argv) {
    /* Semente do gerador de números pseudo-aleatórios. */
    srand (time(NULL));
    
    /* Cria baralho */
    Baralho mesa("baralho2.txt", TipoCarta::CARRO);
    if (!mesa.isValid()){
        std::cerr << "Arquivo de baralho inválido!" << std::endl;
        return -1;
    }
    
    /* Embaralha */
    mesa.shuffle();
    
    /* Cada jogador recebe 1/3 das cartas do baralho. 
     * A é o jogador humano.
     * B é a máquina.
     */
    int numCartasA = mesa.size()/3;
    int numCartasB = mesa.size()/3;
    Baralho a(TipoCarta::CARRO);
    Baralho b(TipoCarta::CARRO);
    while (a.size() != numCartasA)
        a.addCarta(mesa.retiraCarta());
    while (b.size() != numCartasB)
        b.addCarta(mesa.retiraCarta());
    
    bool vezHumano = true;
    unsigned int id;
    int atributo;
    float valor;
    float maquinaValor;
    unsigned int maquinaId;
    Carro * lerCarta;
    int round = 1;
    if (DEBUG)
        std::cout << "VOCÊ ESTÁ JOGANDO EM MODO DEBUG!" << std::endl;
    while (a.size() != 0 && b.size() != 0){
        std::cout << "+++++++++++++\nRound " << round 
                  << "\n+++++++++++++" << std::endl;
        /* Mostra as cartas do humano.*/
        std::cout << "Suas cartas são:\n" << a << std::endl;
        if (DEBUG)
            std::cout << "As cartas da máquina são:\n" << b << std::endl;
        
        /* Escolhas do humano. */
        std::cout << "Escolha sua carta por id: ";
        std::cin >> id;
        if (a.validId(id)){
            if (vezHumano){
                std::cout << "Escolha o atributo (1 a 5)" << std::endl
                          << "1: Potência" << std::endl
                          << "2: Cilindradas" << std::endl
                          << "3: Velocidade" << std::endl
                          << "4: Aceleração" << std::endl
                          << "5: Peso" << std::endl;
                std::cin >> atributo;
            } else {
                atributo = rand() % 5 + 1;
            }
            if (atributo >= 1 && atributo <= 5){
                lerCarta = (Carro*)a.consultaCarta(id);
                valor = getValor(lerCarta, atributo);
                
                /* Escolhas da máquina após escolhas válidas pelo humano. */
                lerCarta = (Carro *) b.retiraCarta();
                maquinaValor = getValor(lerCarta, atributo);
                maquinaId = lerCarta->getId();
                b.addCarta((Carta*) lerCarta);
                if (DEBUG)
                    std::cout << "A máquina escolheu a carta de id " 
                              << maquinaId << std::endl;
                
                if ((atributo == 4 && valor < maquinaValor) 
                    || ((atributo != 4 && valor > maquinaValor))) {
                    a.addCarta((Carta*) b.retiraCarta(maquinaId));
                    std::cout << "Parabéns, você ganhou a carta\n" 
                              << *((Carro*) a.consultaCarta(maquinaId)) 
                              << std::endl;
                    vezHumano = true;
                } else if (valor != maquinaValor) {
                    b.addCarta((Carta*) a.retiraCarta(id));
                    std::cout << "Você perdeu a carta\n" 
                              << *((Carro*) b.consultaCarta(id)) 
                              << std::endl;
                    vezHumano = false;
                } else {
                    std::cout << "Empate." << std::endl;
                    vezHumano = !vezHumano;
                }
                round++;
            } else
                std::cout << "Atributo inválido!" << std::endl;
        } else
            std::cout << "Carta inválida!" << std::endl;
    }
    
    if (b.size() == 0)
        std::cout << "Você Ganhou!!!" << std::endl;
    else
        std::cout << "Você Perdeu." << std::endl;
    
    return 0;
}

float getValor(Carro * carro, int atributo){
    float valor = -1;
    switch(atributo){
        case 1:
            valor = carro->getPotencia();
            break;                   
        case 2:
            valor = carro->getCilindradas();
            break;                 
        case 3:
            valor = carro->getVelocidade();
            break;         
        case 4:
            valor = carro->getAceleracao();
            break;      
        case 5:
            valor = carro->getPeso();
            break;
    }
    return valor;
}
