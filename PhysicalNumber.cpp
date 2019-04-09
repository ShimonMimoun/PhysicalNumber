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

double ariel::convertor (Unit unit_type,const PhysicalNumber& phy) {
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
                else if (phy.unit_type==MIN) return 0.01666666666667;
                else return 0.0002777777777777;
                break;
            case MIN:
                if(phy.unit_type==HOUR) return 60;
                else if (phy.unit_type==MIN) return 1;
                else return 0.016666666666666667;
                break;
            case SEC:
                if(phy.unit_type==HOUR) return 60*60;
                else if (phy.unit_type==MIN) return 60;
                else return 1;
                break;
            case TON:
                if(phy.unit_type==TON) return 1;
                else if (phy.unit_type==KG) return 0.001;
                else return 0.000001;
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
        return 0;
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
            double ans = ariel::convertor(unit_type,phy);
            return PhysicalNumber(value_number-(ans*phy.value_number),unit_type);
        }

}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '+=' with differnt types.");
        }
        value_number = value_number+convertor(unit_type,phy)*phy.value_number;
        return *this;
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& phy){
            if(!checkType(*this,phy)){
        throw std::invalid_argument("you cant using operation '-=' with differnt types.");
        }
        value_number = value_number-convertor(unit_type,phy)*phy.value_number;
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
     double ans = ariel::convertor(phy.unit_type,phy1)*phy1.value_number;
    return phy.value_number < ans;
     }

}
bool ariel::operator>(const PhysicalNumber &phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
     }else{
          double ans = ariel::convertor(phy.unit_type,phy1)*phy1.value_number;
    return phy.value_number > ans;
     }
}
bool ariel::operator<=(const PhysicalNumber &phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
     }else{
     double ans = ariel::convertor(phy.unit_type,phy1)*phy1.value_number;
    return phy.value_number <= ans;
     }
}
bool ariel::operator>=(const PhysicalNumber& phy,const PhysicalNumber& phy1) {
         if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
     }else{
    double ans = ariel::convertor(phy.unit_type,phy1)*phy1.value_number;
    return phy.value_number >= ans;
     }
}
bool ariel::operator==(const PhysicalNumber& phy,const PhysicalNumber& phy1){
             if(!checkType(phy,phy1)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
     }else{
    long double ans = (phy1.value_number * (double(unit_values[phy1.unit_type]) / unit_values[phy.unit_type]));
    //double ans = ariel::convertor(phy.unit_type,phy1)*phy1.value_number;
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

string enumType[10] = {"km" , "m" , "cm" , "hour" , "min", "sec", "ton" ,"kg", "g"};

        std::string input,s;
        is>>input;
        int check = -1;
        std::istringstream iss(input);
        getline( iss, s, '[' );
         c.value_number = std::stoi(s);
        getline( iss, s, ']' );

    Unit curr  = Unit::KM;
    for(size_t i = 0; i < Unit::count; i++) {
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

