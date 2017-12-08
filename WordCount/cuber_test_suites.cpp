// cuber_test_suites.cpp  INCOMPLETE
// Glenn G. Chappell
// 2 Dec 2017
//
// For CS 311 Fall 2017
// Tests for class Cuber: test suites
// For Assignment 8, Exercise B
// Uses the "Catch" unit-testing framework
// Requires cuber_test_main.cpp, catch.hpp, cuber.h

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"
    // For the "Catch" unit-testing framework

// Additional includes for this test program


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE( "Cuber: positive numbers",
           "[positive]" ){
    Cuber cc;
    INFO( "5 cubed is 125");
    REQUIRE( cc(5) == 125);
    INFO( "10 cubed is 1000");
    REQUIRE(cc(10) == 1000);
    INFO( "1234 cubed is 1879080904");
    REQUIRE(cc(1234) == 1879080904);
}

TEST_CASE( "Cuber: negative numbers",
           "[negative]"              ) {
   Cuber cc;
   INFO( "-2 cubed is -8");
   REQUIRE( cc(-2) == -8);
   INFO( "-25 cubed is -15625");
   REQUIRE( cc(-25) == -15625);
   INFO( "-150^3 cubed is -3375000");
   REQUIRE( cc(-150) == -3375000);
}

TEST_CASE( "Cuber: floaters",
           "[floating]"              ) {
   Cuber cc;
   INFO( "1.234 cubed is 1.879080904");
   REQUIRE( cc(1.234) == 1.879080904);
   INFO( "3.0 cubed is 27.0");
   REQUIRE( cc(3.0) == 27.0);
   INFO( "3.14 cubed is 30.959144");
   REQUIRE( cc(0.0) == 0.0);
}

TEST_CASE( "Cuber: doubles",
           "[double]"              ) {
   Cuber cc;
   INFO( "1.01 cubed is 1.030301");
   REQUIRE( cc(1.01) == 1.030301);
   INFO( "double -1 cubed is -1");
   REQUIRE( cc(-1.0) == -1.0);
   INFO( "12.62 cubed is 2009.916728");
   REQUIRE( cc(12.62) == cc(12.62));
}
