#pragma once

#include <iostream>
#include "Unit.h"

namespace ariel{

class PhysicalNumber {

public:
int value_number;

//---------------------------------
//constractors
//---------------------------------


PhysicalNumber(int numb,int type);


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

friend const bool operator==(const PhysicalNumber phy1 , const PhysicalNumber phy2);
friend const bool operator<(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 < phy2;};
friend const bool operator>(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 > phy2;};
friend const bool operator<=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 <= phy2;};
friend const bool operator>=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return phy1 >= phy2;};
friend const bool operator!=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return !(phy1==phy2);};

//---------------------------------
// increment & decrement operations
//---------------------------------


PhysicalNumber& operator++();
PhysicalNumber& operator--();

//---------------------------------
// I/O friends operations
//---------------------------------

friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
friend istream& operator>> (istream& is, PhysicalNumber& c);


};

//---------------------------------
// implementation of friends operators
//---------------------------------

ostream& operator<< (ostream& os, const PhysicalNumber& c){
    return os;
}

istream& operator>> (istream& is, PhysicalNumber& c) {

    return is;
}





}