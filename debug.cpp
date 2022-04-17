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

    bool checkOperatorTrue  = ( w1True  == w2True  );
    bool checkOperatorFalse = ( w1False == w2False ) ;

    //True Statement
    cout << " @bool checkOperatorTrue  = ( w1True  == w2True  ) ;" << endl;
    cout << "    " << checkOperatorTrue                            << endl;

    //False Statement
    cout << " @bool checkOperatorFalse = ( w1False == w2False ) ;" << endl;
    cout << "    " << checkOperatorFalse                           << endl;

}
/// Checking Equality Operator ///