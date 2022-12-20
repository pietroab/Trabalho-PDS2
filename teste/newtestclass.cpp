/**
 * @file Unit Testing.
 */

#include "newtestclass.h"
#include "../Carta.h"
#include "../Carro.h"
#include "../TipoCarta.h"
#include "../Baralho.h"
#include <limits>
#include <math.h> 

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testCarta() {
    Carta x;
    Carta y(123, "Carta y");
    Carta z(y);
    CPPUNIT_ASSERT(x.getId() == 0 && x.getNome()=="");
    CPPUNIT_ASSERT(y.getId() == 123 && y.getNome()=="Carta y");
    CPPUNIT_ASSERT(z.getId() == y.getId() && z.getNome()==y.getNome());
}

void newtestclass::testCarro() {
    Carro c(1, "Audi", 220, 3000, 280, 3.8, 2340);
    std::stringstream ss;
    std::string test = "";
    test += std::string("Nome: Audi\nId: 1\n")
            + std::string("Potência: 220cv\n")
            + std::string("Cilindradas: 3000cc\n")
            + std::string("Velocidade: 280Km/h\n")
            + std::string("Aceleracao: 3.8s\n")
            + std::string("Peso: 2340Kg");
    ss << c;
    CPPUNIT_ASSERT(ss.str() == test);
    Carro c2(1, "Audi", -220, -3000, 280, -3.8, 2340);
    CPPUNIT_ASSERT(isnan(c2.getPotencia()));
    CPPUNIT_ASSERT(isnan(c2.getCilindradas()));
    CPPUNIT_ASSERT(isnan(c2.getAceleracao()));
}

void newtestclass::testBaralho() {
    Baralho b("baralho.txt", TipoCarta::CARRO);
    std::cout << b.size();
    CPPUNIT_ASSERT(b.size() == 7);
    CPPUNIT_ASSERT(((Carro*)b.consultaCarta(3))->getNome() == "carro3");
    CPPUNIT_ASSERT(b.validId(3));
    b.retiraCarta(3);
    CPPUNIT_ASSERT(b.validId(3) == false);
    CPPUNIT_ASSERT(b.size() == 6);
    Carro c(8, "Audi", 220, 3000, 280, 3.8, 2340);
    b.addCarta(&c);
    CPPUNIT_ASSERT(b.size() == 7);
    CPPUNIT_ASSERT(((Carro*)b.consultaCarta(8))->getNome() == "Audi");
    b.addCarta(&c);
    CPPUNIT_ASSERT(b.size() == 7);
}