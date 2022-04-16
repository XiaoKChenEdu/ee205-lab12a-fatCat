///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file classWeight.h
/// @version 1.0
///
/// @author Xiaokang Chen <xiaokang@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <cassert>

using namespace std;


class classWeight {

    public:
        enum UnitOfWeight { POUND, KILO, SLUG };

    public:
        static const float UNKNOWN_WEIGHT   ;
        static const float KILOS_IN_A_POUND ;
        static const float SLUGS_IN_A_POUND ;

        static const string POUND_LABEL ;
        static const string KILO_LABEL  ;
        static const string SLUG_LABEL  ;

    public:
        //////////// Constructors ////////////
        classWeight();

        classWeight( float newWeight               )          ;
        classWeight( UnitOfWeight newUnitOfWeight  ) noexcept ;
        classWeight( float        newWeight,
                     UnitOfWeight newUnitOfWeight  )          ;
        classWeight( float newWeight,
                     float newMaxWeight            )          ;
        classWeight( UnitOfWeight newUnitOfWeight,
                     float        newMaxWeight     )          ;
        classWeight( float        newWeight,
                     UnitOfWeight newUnitOfWeight,
                     float        newMaxWeight     )          ;
        //////////// Constructors ////////////

    public:
        //////////// Getters ////////////
        bool isWeightKnow() const noexcept;
        bool hasMaxWeight() const noexcept;

        float getWeight() const noexcept;
        float getWeight( UnitOfWeight weightUnits ) const noexcept;
        float getMaxWeight() noexcept;
        UnitOfWeight getWeightUnit() const noexcept;
        //////////// Getters ////////////

        //////////// Setters ////////////
        void setWeight( float newWeight          );
        void setWeight( float newWeight,
                        UnitOfWeight weightUnits );
        //////////// Setters ////////////

    private:
        //////////// Setters ////////////
        void setMaxWeight( float newMaxWeight );
        //////////// Setters ////////////
};