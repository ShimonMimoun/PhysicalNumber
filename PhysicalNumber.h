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
double value_number;
Unit unit_type;

//---------------------------------
//Helping Functions
//---------------------------------

bool checkType (const PhysicalNumber& phy1 ,const PhysicalNumber& phy2) const;
double convertor (const PhysicalNumber& phy) const;


public:
//---------------------------------
//constractors
//---------------------------------


PhysicalNumber(double,Unit);
~PhysicalNumber();
PhysicalNumber() = default;


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

const bool operator==(const PhysicalNumber& phy);
const bool operator<(const PhysicalNumber& phy);
const bool operator>(const PhysicalNumber& phy);
const bool operator<=(const PhysicalNumber& phy);
const bool operator>=(const PhysicalNumber& phy);
const bool operator!=(const PhysicalNumber& phy);

//---------------------------------
// increment & decrement prefix and postfix operations
//---------------------------------


PhysicalNumber& operator++();
PhysicalNumber& operator--();
PhysicalNumber& operator++ (int);
PhysicalNumber& operator-- (int);



//---------------------------------
// I/O friends operations
//---------------------------------

friend ostream& operator<<(ostream& os, const PhysicalNumber& c);
friend istream& operator>>(istream& is, PhysicalNumber& c);


};

ostream& operator<<(ostream& os, const PhysicalNumber& c);
istream& operator>>(istream& is, PhysicalNumber& c);

}