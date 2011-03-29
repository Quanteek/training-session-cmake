#define BOOST_TEST_MODULE ALGORITHM
#include <boost/test/included/unit_test.hpp>

#include "Algorithm.h"

BOOST_AUTO_TEST_SUITE(ALGORITHM)

BOOST_AUTO_TEST_CASE(max)
{
    double a = 10;
    double b = 5;
    BOOST_CHECK_EQUAL(Algorithm::max(a,b), a);
}

BOOST_AUTO_TEST_CASE(algo)
{
    Algorithm algo;
    BOOST_CHECK_CLOSE(algo(), 150, 10e-10);
}

BOOST_AUTO_TEST_SUITE_END();
