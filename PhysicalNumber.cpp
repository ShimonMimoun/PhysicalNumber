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



PhysicalNumber::PhysicalNumber(double num , Unit type):value_number(num) ,unit_type(type){}

PhysicalNumber::~PhysicalNumber(){}


//---------------------------------
//Helping Functions 
//---------------------------------


bool PhysicalNumber::checkType (const PhysicalNumber& phy1,const PhysicalNumber& phy2) const{

    if((phy1.unit_type >= 0 && phy1.unit_type <=2) && (phy2.unit_type >=0 && phy2.unit_type <=2)) {return true;}
    else if ((phy1.unit_type >= 3 && phy1.unit_type <=5) && (phy2.unit_type >=3 && phy2.unit_type <=5)) {return true;}
    else if((phy1.unit_type >= 6 && phy1.unit_type <=8) && (phy2.unit_type >=6 && phy2.unit_type <=8)) {return true;}
    else {return false;}
}

double PhysicalNumber::convertor (const PhysicalNumber& phy) const{
        switch (unit_type) {
            case KM:
                if(phy.unit_type==KM) return 1;
                else if (phy.unit_type==M) return 0.001;
                else return 0.00001;
                break;
            case M:
                if(phy.unit_type==KM) return 1000;
                else if (phy.unit_type==M) return 1;
                else return 0.01;
                break;
            case CM:
                if(phy.unit_type==KM) return 1000*100;
                else if (phy.unit_type==M) return 100;
                else return 1;
                break;
            case HOUR:
                if(phy.unit_type==HOUR) return 1;
                else if (phy.unit_type==MIN) return 0.0166666667;
                else return 0.0002777778;
                break;
            case MIN:
                if(phy.unit_type==HOUR) return 60;
                else if (phy.unit_type==MIN) return 1;
                else return 0.01666666;
                break;
            case SEC:
                if(phy.unit_type==HOUR) return 60*60;
                else if (phy.unit_type==MIN) return 60;
                else return 1;
                break;
            case TON:
                if(phy.unit_type==TON) return 1;
                else if (phy.unit_type==KG) return 0.001;
                else return 0.00001;
                break;
            case KG:
                if(phy.unit_type==TON) return 1000;
                else if (phy.unit_type==KG) return 1;
                else return 0.001;
                break;
            case G:
                if(phy.unit_type==TON) return 1000*1000;
                else if (phy.unit_type==KG) return 1000;
                else return 1;
                break;
            default:
                break;
        }


}


//---------------------------------
//+, -, +=, -=, =, ,-(onary), +(onary) Operations 
//---------------------------------


const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phy) const{
        if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '+' with differnt types.");
        }else{
            double ans = convertor(phy);
            return PhysicalNumber(value_number+(ans*phy.value_number),unit_type);
        }
}

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& phy) const{
        if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '-' with differnt types.");
        }else{
            double ans = convertor(phy);
            return PhysicalNumber(value_number-(ans*phy.value_number),unit_type);
        }

}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '+=' with differnt types.");
        }
        value_number = value_number+convertor(phy)*phy.value_number;
        return *this;
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '-=' with differnt types.");
        }
        value_number = value_number-convertor(phy)*phy.value_number;
        return *this;
}
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& phy){
        if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '=' with differnt types.");
        }
        value_number = convertor(phy)*phy.value_number;
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

const bool PhysicalNumber::operator<(const PhysicalNumber& phy) {
     if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '<' with differnt types.");
     }else
    return value_number < convertor(phy)*phy.value_number;

}
const bool PhysicalNumber::operator>(const PhysicalNumber& phy) {
         if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
     }else
    return value_number > convertor(phy)*phy.value_number;
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& phy) {
         if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
     }else
    return value_number <= convertor(phy)*phy.value_number;

}
const bool PhysicalNumber::operator>=(const PhysicalNumber& phy) {
         if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
     }else
    return value_number >= convertor(phy)*phy.value_number;
    
}
const bool PhysicalNumber::operator==(const PhysicalNumber& phy){
             if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
     }else
    return value_number == convertor(phy)*phy.value_number;

}
const bool PhysicalNumber::operator!=(const PhysicalNumber& phy){
             if(!checkType(*this,phy)){
         throw std::invalid_argument("you cant using operation '!=' with differnt types.");
     }else
    return value_number != convertor(phy)*phy.value_number;
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
PhysicalNumber& PhysicalNumber::operator++ (int){
    ++(*this);
    return *this;
}
PhysicalNumber& PhysicalNumber::operator-- (int){
      --(*this);
    return *this;
}

//---------------------------------
//I/O Operations 
//---------------------------------

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& c){
            switch (c.unit_type) {
            case KM:
                os<<c.value_number<<"[km]";
                break;
            case M:
                os<<c.value_number<<"[m]";
                break;
            case CM:
                os<<c.value_number<<"[cm]";
                break;
            case HOUR:
                os<<c.value_number<<"[hour]";
                break;
            case MIN:
                os<<c.value_number<<"[min]";
                break;
            case SEC:
                os<<c.value_number<<"[sec]";
                break;
            case TON:
                os<<c.value_number<<"[ton]";
                break;
            case KG:
                os<<c.value_number<<"[kg]";
                break;
            default:
                os<<c.value_number<<"[g]";
                break;
        }
        return os;
}
istream& ariel::operator>>(istream& is, PhysicalNumber& c){

string enumType[9] = {"km" , "m" , "cm" , "hour" , "min", "sec", "ton" ,"kg", "g"};

        std::string input,s;
        is>>input;
        int check = -1;
        std::istringstream iss(input);
        getline( iss, s, '[' );
         c.value_number = std::stoi(s);
        getline( iss, s, ']' );

    Unit curr  = Unit::KM;
    for(size_t i = 0; i <= Unit::G; i++) {
    if(enumType[i] == s) {
        c.unit_type = (Unit)i;
        check = 1;
    }
 }
 if(check == -1){
    throw std::invalid_argument("you cant use that type");

 }
    return is;
}

