///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file classWeight.cpp
/// @version 1.0
///
/// @author Xiaokang Chen <xiaokang@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include "classWeight.h"


/////////////// Public Attributes ///////////////
const float classWeight::UNKNOWN_WEIGHT   = -1       ;
const float classWeight::KILOS_IN_A_POUND = 0.453592 ;
const float classWeight::SLUGS_IN_A_POUND = 0.031081 ;

const string classWeight::POUND_LABEL = "Pound" ;
const string classWeight::KILO_LABEL  = "Kilo"  ;
const string classWeight::SLUG_LABEL  = "Slug"  ;
/////////////// Public Attributes ///////////////


//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Constructors ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
classWeight::classWeight() = default;

classWeight::classWeight( float newWeight ) {

    setWeight( newWeight );
    assert( validate() );

}

classWeight::classWeight( classWeight::UnitOfWeight newUnitOfWeight ) noexcept {

    unitOfWeight = newUnitOfWeight;

}

classWeight::classWeight( float newWeight, classWeight::UnitOfWeight newUnitOfWeight ) : classWeight( newUnitOfWeight ) {

    setWeight( newWeight, newUnitOfWeight );
    assert( validate() );

}

classWeight::classWeight( float newWeight, float newMaxWeight ) {

    setWeight( newWeight );
    setMaxWeight( newMaxWeight );
    assert( validate() );

}

classWeight::classWeight( classWeight::UnitOfWeight newUnitOfWeight, float newMaxWeight ) : classWeight( newUnitOfWeight ) {

    setMaxWeight( newMaxWeight );
    assert( validate() );

}

classWeight::classWeight( float newWeight, classWeight::UnitOfWeight newUnitOfWeight, float newMaxWeight ) : classWeight( newUnitOfWeight, newMaxWeight ) {

    setWeight( newWeight );
    assert( validate() );

}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Constructors ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Getters ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
bool classWeight::isWeightKnown() const noexcept {

    return bWeightIsKnown;

}

bool classWeight::hasMaxWeight() const noexcept {

    return bWeightIsKnown;

}

float classWeight::getWeight() const noexcept {

    if ( bWeightIsKnown ) {

        return weight;

    } else {

        return UNKNOWN_WEIGHT;

    }

}

float classWeight::getWeight( classWeight::UnitOfWeight weightUnits ) const noexcept {

    return convertWeight( weight, unitOfWeight, weightUnits );

}

float classWeight::getMaxWeight() const noexcept {

    if ( bWeightHasMax ) {

        return maxWeight;

    } else {

        return UNKNOWN_WEIGHT;

    }

}

classWeight::UnitOfWeight classWeight::getWeightUnit() const noexcept {

    return unitOfWeight;

}
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Getters ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Setters ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void classWeight::setWeight( float newWeight ) {

    if ( !isWeightValid( newWeight ) ) {

        throw out_of_range( "newWight is <= 0 || > maxWeight" );

    }

    weight         = newWeight ;
    bWeightIsKnown = true      ;

    assert( validate() );

}

void classWeight::setWeight( float newWeight, classWeight::UnitOfWeight weightUnits ) {

    setWeight( convertWeight( newWeight, weightUnits, unitOfWeight ) );

}

//This is a private member function.
void classWeight::setMaxWeight( float newMaxWeight ) {

    if ( !bWeightHasMax ) {

        maxWeight     = newMaxWeight ;
        bWeightHasMax = true         ;

    } else {

        cout << "Your Animal's maxWeight is already defined." << endl;

    }

}
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Setters ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Conversion /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
float classWeight::fromKilogramToPound( float kilogram ) noexcept {

    return kilogram / KILOS_IN_A_POUND ;

}

float classWeight::fromPoundToKilogram( float pound ) noexcept {

    return pound * KILOS_IN_A_POUND ;

}

float classWeight::fromSlugToPound( float slug ) noexcept {

    return slug / SLUGS_IN_A_POUND ;

}

float classWeight::fromPoundToSlug( float pound ) noexcept {

    return pound * SLUGS_IN_A_POUND ;

}

float classWeight::convertWeight( float fromWeight, classWeight::UnitOfWeight fromUnit, classWeight::UnitOfWeight toUnit ) noexcept {

    float weightToConvert ;

    switch( fromUnit ) {

        case POUND : weightToConvert = fromWeight ;
        break;

        case KILO  : weightToConvert = fromKilogramToPound( fromWeight ) ;
        break;

        case SLUG  : weightToConvert = fromSlugToPound( fromWeight ) ;
        break;

        default    : cout << "Please enter a proper unit to convert form." << endl ;
        assert( false ) ;

    }

    float convertedWeight;

    switch( toUnit ) {

        case POUND : convertedWeight = weightToConvert ;
        break;

        case KILO  : convertedWeight = fromPoundToKilogram( weightToConvert ) ;
        break;

        case SLUG  : convertedWeight = fromSlugToPound( weightToConvert ) ;
        break;

        default    : cout << "Please enter a proper unit to convert to." << endl ;
        assert( false );

    }

    return convertedWeight ;

}
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Conversion /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Validation & Print //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
bool classWeight::isWeightValid( float checkWeight ) const noexcept {

    if ( checkWeight <= 0 ) {

        cout << "Your Animal Weight [" << checkWeight << "] can't be <= 0" << endl;
        return false;

    }

    if ( bWeightHasMax ) {

        if ( checkWeight > maxWeight ) {

            cout << "Your Animal Weight [" << checkWeight << "] is greater than it's maxWeight [" << maxWeight << "], Please change it." << endl;
            return false;

        }

    }

    return true;

}

bool classWeight::validate() const noexcept {

    if ( bWeightHasMax ) {

        if ( maxWeight <= 0 ) {

            cout << "Your Animal maxWeight is <= 0, Please change it." << endl;
            return false;

        }

    }

    if ( bWeightIsKnown ) {

        if ( !isWeightValid( weight ) ) {

            return false;

        }

    }

    return true;

}
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void classWeight::print() const noexcept {

    assert( validate() ) ;

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;

    FORMAT_LINE( "classWeight", "this"           )  << this            << endl ;
    FORMAT_LINE( "classWeight", "bWeightIsKnown" )  << bWeightIsKnown  << endl ;
    FORMAT_LINE( "classWeight", "weight"         )  << weight          << endl ;
    FORMAT_LINE( "classWeight", "unitOfWeight"   )  << unitOfWeight    << endl ;
    FORMAT_LINE( "classWeight", "bWeightHasMax"  )  << bWeightHasMax   << endl ;
    FORMAT_LINE( "classWeight", "maxWeight"      )  << maxWeight       << endl ;

}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Validation & Print //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Operators ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
bool classWeight::operator==( const classWeight &rhs_WeightInput ) const {

    float lhs_weight = ( bWeightIsKnown                 ) ?                 getWeight( classWeight::POUND ) : 0 ;
    float rhs_weight = ( rhs_WeightInput.bWeightIsKnown ) ? rhs_WeightInput.getWeight( classWeight::POUND ) : 0 ;

    return lhs_weight == rhs_weight;

}

bool classWeight::operator<( const classWeight &rhs_WeightInput ) const {

    float lhs_weight = ( bWeightIsKnown                 ) ?                 getWeight( classWeight::POUND ) : 0 ;
    float rhs_weight = ( rhs_WeightInput.bWeightIsKnown ) ? rhs_WeightInput.getWeight( classWeight::POUND ) : 0 ;

    return lhs_weight < rhs_weight;

}

classWeight &classWeight::operator+=(float rhs_addToWeight) {

}

std::ostream& operator<<( ostream &lhs_stream, const classWeight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case classWeight::POUND : return lhs_stream << classWeight::POUND_LABEL ;
        case classWeight::KILO  : return lhs_stream << classWeight::KILO_LABEL  ;
        case classWeight::SLUG  : return lhs_stream << classWeight::SLUG_LABEL  ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Operators ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////