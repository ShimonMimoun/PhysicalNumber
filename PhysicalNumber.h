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

friend bool checkType (const PhysicalNumber& phy1 ,const PhysicalNumber& phy2);
friend double convertor (Unit unit_type,const PhysicalNumber& phy);


public:
//---------------------------------
//constractors
//---------------------------------
Unit getUserType() {
    return unit_type;
}


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
PhysicalNumber& operator++ (int);
PhysicalNumber& operator-- (int);



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
bool checkType (const PhysicalNumber& phy1 ,const PhysicalNumber& phy2);
double convertor (Unit unit_type,const PhysicalNumber& phy);

ostream& operator<<(ostream& os, const PhysicalNumber& c);
istream& operator>>(istream& is, PhysicalNumber& c);

}