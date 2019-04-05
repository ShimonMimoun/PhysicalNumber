#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#define _KM 10000;


PhysicalNumber::PhysicalNumber(int num , Unit type):value_number(num) ,unit_type(type){}

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

double PhysicalNumber::convertor (PhysicalNumber& phy) const{
    switch (unit_type)
    {
        case KM:
            if(phy.getType() == KM) return 1;  // KM = 1
          //  else if(phy.getType() == M) return _KM/; // M = 1
           // else return CM; // CM = 1
            break;
        case M:
         //   if(phy.getType() == KM) return _KM*1000;
            //else if(phy.getType() == M) return _M;
         //   else return CM/(M*100);
            break;
        case CM:
         //   if(phy.getType() == KM) return _KM*10000;
         //   else if(phy.getType() == M) return _M;
         //   else return CM/(M*100);
            break;                
    
        default:
            break;
    }


}



//---------------------------------
//+, -, +=, -=, = ,-(onary), +(onary) Operations 
//---------------------------------


const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phyNum) const{
        return PhysicalNumber(0,unit_type);
}

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& phyNum) const{
        return PhysicalNumber(0,unit_type);

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
        return PhysicalNumber(0,unit_type);
}
const PhysicalNumber PhysicalNumber::operator-() const {
        return PhysicalNumber(0,unit_type);

}

//---------------------------------
//<, >, <=, >=, Operations 
//---------------------------------

const bool operator<(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return false;};
const bool operator>(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return false;};
const bool operator<=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return false;};
const bool operator>=(const PhysicalNumber phy1 , const PhysicalNumber phy2) {return false;};

//---------------------------------
//-- , ++ Operations 
//---------------------------------

PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
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
    return is;
}

