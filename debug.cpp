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


/// Checking Equality Operator ///
void checkEqualityOperator() {

    classWeight w1True( 0.453592, classWeight::KILO  ) ;
    classWeight w2True( 1.0,      classWeight::POUND ) ;

    classWeight w1False( 1.0, classWeight::SLUG ) ;
    classWeight w2False( 1.0, classWeight::KILO ) ;

    bool checkEqualityTrue  = ( w1True  == w2True  );
    bool checkEqualityFalse = ( w1False == w2False ) ;

    //True Statement
    cout << " @bool checkEqualityTrue  = ( w1True  == w2True  ) ;" << endl;
    cout << "    " << checkEqualityTrue                            << endl;

    //False Statement
    cout << " @bool checkEqualityFalse = ( w1False == w2False ) ;" << endl;
    cout << "    " << checkEqualityFalse                           << endl;

}
/// Checking Equality Operator ///



/// Checking LessThan Operator ///
void checkLessThanOperator() {

    classWeight w1More( 1.0,      classWeight::KILO  ) ;
    classWeight w2Less( 1.0,      classWeight::POUND ) ;


    bool checkLessThanTrue  = ( w2Less < w1More ) ;
    bool checkLessThanFalse = ( w1More < w2Less ) ;

    //True Statement
    cout << " @bool checkLessThanTrue  = ( w2Less < w1More ) ;" << endl ;
    cout << "    " << checkLessThanTrue                         << endl ;

    //False Statement
    cout << " @bool checkLessThanFalse = ( w1More < w2Less ) ;" << endl ;
    cout << "    " << checkLessThanFalse                        << endl ;

}
/// Checking LessThan Operator ///


/// Checking AddTo Operator ///
//Only works with the same unit.
void checkAddToOperator() {

    classWeight w1( 1.0, classWeight::POUND, 10.0 ) ;

    //Adding weight over it's maxWeight, FAILS
    try {

        w1 += 10.0 ;
        cout << " @w1 += 10.0 ;" << endl ;
        cout << "    SUCCEED"    << endl ;

    } catch ( exception const &Error ) {

        cout << " @w1 += 10.0 ;"       << endl ;
        cout << "    " << Error.what() << endl ;

    }

    //Adding weight under it's maxWeight, SUCCEED
    try {

        w1 += 9.0 ;
        cout << " @w1 += 9.0 ;"  << endl ;
        cout << "    SUCCEED"    << endl ;

    } catch ( exception const &Error ) {

        cout << " @w1 += 9.0 ;"        << endl ;
        cout << "    " << Error.what() << endl ;

    }

}
/// Checking AddTo Operator ///