#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#define _KM 10000;


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
                else return 0.0166666667;
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
                else return 1000;
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
//+, -, +=, -=, = ,-(onary), +(onary) Operations 
//---------------------------------


const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phyNum) const{
        if(!checkType(*this,phyNum)){
        throw std::invalid_argument("you cant using operation '+' with differnt types.");
        }else{
            double ans = PhysicalNumber::convertor(phyNum);
            return PhysicalNumber(value_number+(ans*phyNum.value_number),unit_type);
        }
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

