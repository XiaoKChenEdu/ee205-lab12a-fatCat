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


/////////////// Attributes ///////////////
const float UNKNOWN_WEIGHT   = -1       ;
const float KILOS_IN_A_POUND = 0.453592 ;
const float SLUGS_IN_A_POUND = 0.031081 ;

const string POUND_LABEL = "Pound" ;
const string KILO_LABEL  = "Kilo"  ;
const string SLUG_LABEL  = "Slug"  ;
/////////////// Attributes ///////////////



//////////////////////////////////// Constructors ////////////////////////////////////
classWeight::classWeight() {

}

classWeight::classWeight(float newWeight) {

}

classWeight::classWeight(classWeight::UnitOfWeight newUnitOfWeight) noexcept {

}

classWeight::classWeight(float newWeight, classWeight::UnitOfWeight newUnitOfWeight) {

}

classWeight::classWeight(float newWeight, float newMaxWeight) {

}

classWeight::classWeight(classWeight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}

classWeight::classWeight(float newWeight, classWeight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}
//////////////////////////////////// Constructors ////////////////////////////////////



//////////////////////////////////// Getters ////////////////////////////////////
bool classWeight::isWeightKnow() const noexcept {
    return false;
}

bool classWeight::hasMaxWeight() const noexcept {
    return false;
}

float classWeight::getWeight() const noexcept {
    return 0;
}

float classWeight::getWeight(classWeight::UnitOfWeight weightUnits) const noexcept {
    return 0;
}

float classWeight::getMaxWeight() noexcept {
    return 0;
}

classWeight::UnitOfWeight classWeight::getWeightUnit() const noexcept {
    return classWeight::POUND;
}
//////////////////////////////////// Getters ////////////////////////////////////



//////////////////////////////////// Setters ////////////////////////////////////
void classWeight::setWeight(float newWeight) {

}

void classWeight::setWeight(float newWeight, classWeight::UnitOfWeight weightUnits) {

}

//This is a private member function.
void classWeight::setMaxWeight(float newMaxWeight) {

}
//////////////////////////////////// Setters ////////////////////////////////////