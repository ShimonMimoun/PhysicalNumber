#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;


PhysicalNumber::PhysicalNumber(int num , int type):value_number(num) ,unit_type(type){

}




const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phyNum) const{
        return PhysicalNumber(0,0);
}

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& phyNum) const{
        return PhysicalNumber(0,0);

}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& phyNum){
        return *this;
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& phyNum){
        return *this;
}
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& phyNum){
        return *this;
}


const PhysicalNumber PhysicalNumber::operator+() const {
    return PhysicalNumber(0,0);
}
const PhysicalNumber PhysicalNumber::operator-() const {
    return PhysicalNumber(0,0);

}
PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
}

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& c){
    return os;
}
istream& ariel::operator>>(istream& is, PhysicalNumber& c){
    return is;
}

