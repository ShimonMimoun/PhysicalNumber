#pragma once

#include <iostream>
#include "Unit.h"

namespace ariel{

class PhysicalNumber {

private:
int value_number;
Unit unit_type;

//---------------------------------
//Helping Functions
//---------------------------------

bool checkType (const PhysicalNumber& phy1 ,const PhysicalNumber& phy2) const;
double convertor (PhysicalNumber& phy) const;


public:
//---------------------------------
//constractors
//---------------------------------


PhysicalNumber(int,Unit);
~PhysicalNumber();
PhysicalNumber() = default;


Unit getType() {
    return unit_type;
}
double getValueNum() {
    return value_number;
}

//---------------------------------
// +,- +=  Math opreation , ect..
//---------------------------------

const PhysicalNumber operator+(const PhysicalNumber& phyNum) const;
const PhysicalNumber operator-(const PhysicalNumber& phyNum) const;


PhysicalNumber& operator+=(const PhysicalNumber& phyNum);
PhysicalNumber& operator-=(const PhysicalNumber& phyNum);
PhysicalNumber& operator=(const PhysicalNumber& phyNum);

//---------------------------------
// onary preations
//---------------------------------


const PhysicalNumber operator+() const ;
const PhysicalNumber operator-() const ;

//---------------------------------
// < , > <= , >=  friends globals opreations
//---------------------------------

friend const bool operator==(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1.unit_type == phy2.unit_type;};
friend const bool operator<(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 < phy2;};
friend const bool operator>(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 > phy2;};
friend const bool operator<=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 <= phy2;};
friend const bool operator>=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 >= phy2;};
friend const bool operator!=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return !(phy1.unit_type==phy2.unit_type);};

//---------------------------------
// increment & decrement operations
//---------------------------------


PhysicalNumber& operator++();
PhysicalNumber& operator--();

//---------------------------------
// I/O friends operations
//---------------------------------

friend ostream& operator<<(ostream& os, const PhysicalNumber& c);
friend istream& operator>>(istream& is, PhysicalNumber& c);


};

}