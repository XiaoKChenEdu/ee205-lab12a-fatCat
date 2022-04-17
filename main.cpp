///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Xiaokang Chen <xiaokang@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include "classWeight.h"
#include "debug.h"

#define DEBUG


int main() {

    cout << "----- Starting Program Fat Cat -----" << endl;
    NL

    classWeight defaultWeight;
    defaultWeight.print();

    //////////////////////// Debug Starts Here ////////////////////////
    #ifdef DEBUG
    {
        NL NL
        cout << "---- Debugging Starts Here ----" << endl;
        NL

        checkConstructor();
        NL NL
        checkEqualityOperator() ;
        NL NL
        checkLessThanOperator() ;
        NL NL
        checkAddToOperator   () ;

        NL
        cout << "----- Debugging Ends Here -----" << endl;
        NL NL

    }
    #endif
    ///////////////////////// Debug Ends Here /////////////////////////

    NL
    cout << "------ Ending Program Fat Cat ------" << endl;

    return 0;

}
