/*
*  @author Omer Paz and Shimon Mimoun 
*
*/

#pragma once

#include <iostream>
#include "Unit.h"

namespace ariel{

class PhysicalNumber {
private:
long double value_number;
Unit unit_type;

//---------------------------------
//Helping Functions
//---------------------------------


public:
//---------------------------------
//constractors
//---------------------------------
Unit getUserType() {
    return unit_type;
}


PhysicalNumber(long double value_number,Unit unit_type){
    {
            this->value_number = value_number;
            this->unit_type = unit_type;
        }
}
~PhysicalNumber(){}


//---------------------------------
// +,- +=  Math opreation , ect..
//---------------------------------

 PhysicalNumber operator+(const PhysicalNumber& phyNum) ;
 PhysicalNumber operator-(const PhysicalNumber& phyNum) ;


PhysicalNumber& operator+=(const PhysicalNumber& phyNum);
PhysicalNumber& operator-=(const PhysicalNumber& phyNum);
// PhysicalNumber& operator=(const PhysicalNumber& phyNum);

//---------------------------------
// onary preations
//---------------------------------


const PhysicalNumber operator+()  ;
const PhysicalNumber operator-()  ;

//---------------------------------
// < , > <= , >=  friends globals opreations
//---------------------------------

friend bool operator==(const PhysicalNumber& phy,const PhysicalNumber& phy1);
friend bool operator<(const PhysicalNumber& phy,const PhysicalNumber& phy1);
friend bool operator>(const PhysicalNumber& phy,const PhysicalNumber& phy1);
friend bool operator<=(const PhysicalNumber& phy,const PhysicalNumber& phy1);
friend bool operator>=(const PhysicalNumber& phy,const PhysicalNumber& phy1);
friend bool operator!=(const PhysicalNumber& phy,const PhysicalNumber& phy1);

//---------------------------------
// increment & decrement prefix and postfix operations
//---------------------------------


PhysicalNumber& operator++();
PhysicalNumber& operator--();
PhysicalNumber operator++ (int);
PhysicalNumber operator-- (int);



//---------------------------------
// I/O friends operations
//---------------------------------

friend ostream& operator<<(ostream& os, const PhysicalNumber& c);
friend istream& operator>>(istream& is, PhysicalNumber& c);


};
bool operator==(const PhysicalNumber& phy,const PhysicalNumber& phy1);
bool operator<(const PhysicalNumber& phy,const PhysicalNumber& phy1);
bool operator>(const PhysicalNumber& phy,const PhysicalNumber& phy1);
bool operator<=(const PhysicalNumber& phy,const PhysicalNumber& phy1);
bool operator>=(const PhysicalNumber& phy,const PhysicalNumber& phy1);
bool operator!=(const PhysicalNumber& phy,const PhysicalNumber& phy1);

ostream& operator<<(ostream& os, const PhysicalNumber& c);
istream& operator>>(istream& is, PhysicalNumber& c);

}