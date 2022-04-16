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
#include <stdexcept>

using namespace std;


class classWeight {

    public:
        enum UnitOfWeight { POUND, KILO, SLUG };

    public:
        //////////// Public Attributes ////////////
        static const float UNKNOWN_WEIGHT   ;
        static const float KILOS_IN_A_POUND ;
        static const float SLUGS_IN_A_POUND ;

        static const string POUND_LABEL ;
        static const string KILO_LABEL  ;
        static const string SLUG_LABEL  ;
        //////////// Public Attributes ////////////

    private:
        //////////// Private Attributes ////////////
        bool bWeightIsKnown = false ;
        bool bWeightHasMax  = false ;

        enum UnitOfWeight unitOfWeight = POUND;

        float weight    {} ;
        float maxWeight {} ;
        //////////// Private Attributes ////////////

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
        bool isWeightKnow() const noexcept ;
        bool hasMaxWeight() const noexcept ;

        float getWeight    ()                           const noexcept ;
        float getWeight    ( UnitOfWeight weightUnits ) const noexcept ;
        float getMaxWeight ()                                 noexcept ;

        UnitOfWeight getWeightUnit() const noexcept ;
        //////////// Getters ////////////

        //////////// Setters ////////////
        void setWeight( float newWeight          ) ;
        void setWeight( float newWeight,
                        UnitOfWeight weightUnits ) ;
        //////////// Setters ////////////

    private:
        //////////// Setters ////////////
        void setMaxWeight( float newMaxWeight ) ;
        //////////// Setters ////////////

    public:
        //////////// Conversion ////////////
        static float fromKilogramToPound ( float kilogram           ) noexcept ;
        static float fromPoundToKilogram ( float pound              ) noexcept ;
        static float fromSlugToPound     ( float slug               ) noexcept ;
        static float fromPoundToSlug     ( float pound              ) noexcept ;
        static float convertWeight       ( float        fromWeight,
                                           UnitOfWeight fromUnit,
                                           UnitOfWeight toUnit      ) noexcept ;
        //////////// Conversion ////////////

    public:
        //////////// Validation & Print ////////////
        bool isWeightValid ( float checkWeight ) const noexcept ;
        bool validate      ()                    const noexcept ;

        void print() const noexcept ;
        //////////// Validation & Print ////////////

    public:
        //////////// Operators ////////////
        bool operator== ( const classWeight& rhs_Weight ) const ;
        bool operator<  ( const classWeight& rhs_Weight ) const ;

        classWeight& operator+=( float rhs_addToWeight ) ;
        //////////// Operators ////////////

};