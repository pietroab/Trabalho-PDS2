/**
 * @file Unit Testing.
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);
    CPPUNIT_TEST(testCarta);
    CPPUNIT_TEST(testCarro);
    CPPUNIT_TEST(testBaralho);
    CPPUNIT_TEST_SUITE_END();
public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();
private:
    void testCarta();
    void testCarro();
    void testBaralho();
};

#endif /* NEWTESTCLASS_H */
