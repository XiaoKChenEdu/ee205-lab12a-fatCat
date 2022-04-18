///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file debug.cpp
/// @version 1.0
///
/// @author Xiaokang Chen <xiaokang@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include "debug.h"
#include "classWeight.h"


/// Checking Constructor ///
void checkConstructor() {

    ///Test for the first constructor ///
    classWeight testConstructor1;
    cout << " @classWeight testConstructor1;" << endl ;
        testConstructor1.debugPrint();
    ///Test for the first constructor ///

    ///Test for the second constructor ///
    classWeight testConstructor2( 10.0 ) ;
    cout << " @classWeight testConstructor2( 10.0 ) ;" << endl ;
        testConstructor2.debugPrint();
    ///Test for the second constructor ///

    ///Test for the third constructor ///
    classWeight testConstructor3( classWeight::KILO ) ;
    cout << " @classWeight testConstructor3( classWeight::KILO ) ;" << endl ;
        testConstructor3.debugPrint();
    ///Test for the third constructor ///

    ///Test for the four constructor ///
    classWeight testConstructor4( 10.0, classWeight::SLUG ) ;
    cout << " @classWeight testConstructor4( 10.0, classWeight::SLUG ) ;" << endl ;
        testConstructor4.debugPrint();
    ///Test for the four constructor ///

    ///Test for the fifth constructor ///
    classWeight testConstructor5( 10.0, 100.0 ) ;
    cout << " @classWeight testConstructor5( 10.0, 100.0 ) ;" << endl ;
        testConstructor5.debugPrint();
    ///Test for the fifth constructor ///

    ///Test for the sixth constructor ///
    classWeight testConstructor6( classWeight::KILO, 100.0 ) ;
    cout << " @classWeight testConstructor6( classWeight::KILO, 100.0 ) ;" << endl ;
        testConstructor6.debugPrint();
    ///Test for the sixth constructor ///

    ///Test for the seventh constructor ///
    classWeight testConstructor7( 10.0, classWeight::SLUG, 100.0 ) ;
    cout << " @classWeight testConstructor7( 10.0, classWeight::SLUG, 100.0 ) ;" << endl ;
        testConstructor7.debugPrint();
    ///Test for the seventh constructor ///

}
/// Checking Constructor ///



/// Checking Getters ///
void checkGetters() {

    classWeight unknownWeight ;
    classWeight knownWeight( 10.0, classWeight::KILO, 100.0 ) ;

    /// False and -1 ///
    cout << " @unknownWeight.isWeightKnown()"       << endl ;
    cout << "    " << unknownWeight.isWeightKnown() << endl ;

    cout << " @unknownWeight.hasMaxWeight()"        << endl ;
    cout << "    " << unknownWeight.hasMaxWeight()  << endl ;

    cout << " @unknownWeight.getWeight()"           << endl ;
    cout << "    " << unknownWeight.getWeight()     << endl ;

    cout << " @unknownWeight.unknownWeight.getWeight( classWeight::KILO )"   << endl ;
    cout << "    " << unknownWeight.getWeight( classWeight::KILO ) << endl ;

    cout << " @unknownWeight.getMaxWeight()"        << endl ;
    cout << "    " << unknownWeight.getMaxWeight()  << endl ;

    cout << " @unknownWeight.getWeightUnit()"       << endl ;
    cout << "    " << unknownWeight.getWeightUnit() << endl ;
    /// False and -1 ///

    /// True ///
    cout << " @knownWeight.isWeightKnown()"       << endl ;
    cout << "    " << knownWeight.isWeightKnown() << endl ;

    cout << " @knownWeight.hasMaxWeight()"        << endl ;
    cout << "    " << knownWeight.hasMaxWeight()  << endl ;

    cout << " @knownWeight.getWeight()"           << endl ;
    cout << "    " << knownWeight.getWeight()     << endl ;

    cout << " @knownWeight.unknownWeight.getWeight( classWeight::SLUG )"   << endl ;
    cout << "    " << knownWeight.getWeight( classWeight::SLUG ) << endl ;

    cout << " @knownWeight.getMaxWeight()"        << endl ;
    cout << "    " << knownWeight.getMaxWeight()  << endl ;

    cout << " @knownWeight.getWeightUnit()"       << endl ;
    cout << "    " << knownWeight.getWeightUnit() << endl ;
    /// True ///

}
/// Checking Getters ///



/// Checking Equality Operator ///
void checkEqualityOperator() {

    classWeight testWeight1True( 0.453592, classWeight::KILO  ) ;
    classWeight testWeight2True( 1.0,      classWeight::POUND ) ;

    classWeight testWeight1False( 1.0, classWeight::SLUG ) ;
    classWeight testWeight2False( 1.0, classWeight::KILO ) ;

    bool checkEqualityTrue  = ( testWeight1True  == testWeight2True  ) ;
    bool checkEqualityFalse = ( testWeight1False == testWeight2False ) ;

    //True Statement
    cout << " @bool checkEqualityTrue  = ( testWeight1True  == testWeight2True  ) ;" << endl ;
    cout << "    " << checkEqualityTrue                                              << endl ;

    //False Statement
    cout << " @bool checkEqualityFalse = ( testWeight1False == testWeight2False ) ;" << endl ;
    cout << "    " << checkEqualityFalse                                             << endl ;

}
/// Checking Equality Operator ///



/// Checking LessThan Operator ///
void checkLessThanOperator() {

    classWeight testWeight1More( 1.0,      classWeight::KILO  ) ;
    classWeight testWeight2Less( 1.0,      classWeight::POUND ) ;


    bool checkLessThanTrue  = ( testWeight2Less < testWeight1More ) ;
    bool checkLessThanFalse = ( testWeight1More < testWeight2Less ) ;

    //True Statement
    cout << " @bool checkLessThanTrue  = ( testWeight2Less < testWeight1More ) ;" << endl ;
    cout << "    " << checkLessThanTrue                                           << endl ;

    //False Statement
    cout << " @bool checkLessThanFalse = ( testWeight1More < testWeight2Less ) ;" << endl ;
    cout << "    " << checkLessThanFalse                                          << endl ;

}
/// Checking LessThan Operator ///


/// Checking AddTo Operator ///
//Only works with the same unit.
void checkAddToOperator() {

    classWeight testWeight( 1.0, classWeight::POUND, 10.0 ) ;

    //Adding weight over it's maxWeight, FAILS
    try {

        testWeight += 10.0 ;
        cout << " @testWeight += 10.0 ;" << endl ;
        cout << "    SUCCEED"            << endl ;

    } catch ( exception const &Error ) {

        cout << " @testWeight += 10.0 ;" << endl ;
        cout << "    " << Error.what()   << endl ;

    }

    //Adding weight under it's maxWeight, SUCCEED
    try {

        testWeight += 9.0 ;
        cout << " @testWeight += 9.0 ;" << endl ;
        cout << "    SUCCEED"           << endl ;

    } catch ( exception const &Error ) {

        cout << " @testWeight += 9.0 ;" << endl ;
        cout << "    " << Error.what()  << endl ;

    }

}
/// Checking AddTo Operator ///