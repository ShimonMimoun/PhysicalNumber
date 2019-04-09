/*
*  @author Omer Paz and Shimon Mimoun 
*
*/
#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#include <sstream>
#include <string.h>



PhysicalNumber::PhysicalNumber(long double num , Unit type):value_number(num) ,unit_type(type){}

PhysicalNumber::~PhysicalNumber(){}


//---------------------------------
//Helping Functions 
//---------------------------------


bool ariel::checkType (const PhysicalNumber& phy1,const PhysicalNumber& phy2) {

    if((phy1.unit_type >= 0 && phy1.unit_type <=2) && (phy2.unit_type >=0 && phy2.unit_type <=2)) {return true;}
    else if ((phy1.unit_type >= 3 && phy1.unit_type <=5) && (phy2.unit_type >=3 && phy2.unit_type <=5)) {return true;}
    else if((phy1.unit_type >= 6 && phy1.unit_type <=8) && (phy2.unit_type >=6 && phy2.unit_type <=8)) {return true;}
    else {return false;}
}
//---------------------------------
//+, -, +=, -=, =, ,-(onary), +(onary) Operations 
//---------------------------------


const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phy) const{
        if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '+' with differnt types.");
        }else{
         //   double ans = ariel::convertor(unit_type,phy);
        long double ans = this->value_number + (phy.value_number * (double(unit_values[phy.unit_type]) / unit_values[this->unit_type]));
            return PhysicalNumber(ans,this->unit_type);
        }
}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& phy) const{
        if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '-' with differnt types.");
        }else{
        long double ans = this->value_number - (phy.value_number * (double(unit_values[phy.unit_type]) / unit_values[this->unit_type]));
            return PhysicalNumber(ans,this->unit_type);
        }
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '+=' with differnt types.");
        }
        value_number = this->value_number + (phy.value_number * (double(unit_values[phy.unit_type]) / unit_values[this->unit_type]));
        return *this;
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '-=' with differnt types.");
        }
        value_number = this->value_number - (phy.value_number * (double(unit_values[phy.unit_type]) / unit_values[this->unit_type]));
        return *this;
}
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& phy){
        value_number = phy.value_number;
        unit_type = phy.unit_type;
        return *this;
}


const PhysicalNumber PhysicalNumber::operator+() const {
        return PhysicalNumber(value_number,unit_type);
}
const PhysicalNumber PhysicalNumber::operator-() const {
        return PhysicalNumber(-value_number,unit_type);

}

//---------------------------------
//<, >, <=, >=, == , != Operations 
//---------------------------------

bool ariel::operator<(const PhysicalNumber &phy,const PhysicalNumber& phy1) {
     if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '<' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    return phy.value_number < ans;
     }

}
bool ariel::operator>(const PhysicalNumber &phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    return phy.value_number > ans;
     }
}
bool ariel::operator<=(const PhysicalNumber &phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    return phy.value_number <= ans;
     }
}
bool ariel::operator>=(const PhysicalNumber& phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    return phy.value_number >= ans;
     }
}
bool ariel::operator==(const PhysicalNumber& phy,const PhysicalNumber& phy1){
             if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    return phy.value_number == ans;
     }

}
bool ariel::operator!=(const PhysicalNumber& phy,const PhysicalNumber& phy1){
            return !(phy == phy1);
     
}


//---------------------------------
//-- , ++  prefix and postfix Operations 
//---------------------------------

PhysicalNumber& PhysicalNumber::operator++(){
    value_number++;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    value_number--;
    return *this;
}
PhysicalNumber PhysicalNumber::operator++ (int){
    PhysicalNumber temp = *this;
    value_number++;
    return temp;
}
PhysicalNumber PhysicalNumber::operator-- (int){
    PhysicalNumber temp = *this;
    value_number++;
    return temp;
}

//---------------------------------
//I/O Operations 
//---------------------------------

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& c){

  return (os << c.value_number << "[" << unit_types[c.unit_type] << "]");
}

istream& ariel::operator>>(istream& is, PhysicalNumber& c){

        std::string input,s;
        is>>input;
        int check = -1;
        std::istringstream iss(input);
        getline( iss, s, '[' );
         c.value_number = std::stoi(s);
        getline( iss, s, ']' );

    Unit curr  = Unit::KM;
    for(size_t i = 0; i < Unit::count; i++) {
    if(unit_types[i] == s) {
        c.unit_type = (Unit)i;
        check = 1;
    }
 }
 if(check == -1){
    throw std::invalid_argument("you cant use that type");
 }
    return is;
}

