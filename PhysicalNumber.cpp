#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#include <sstream>
#include <string.h>

bool checkType (Unit unit_a, Unit unit_b);
double double_base(double value, Unit temp_unit);
double unit_double(double value, Unit unit_temp);



PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& phyNum) {
    if(!checkType(this->unit_type, phyNum.unit_type)){
throw std::invalid_argument("you cant using operation '+' with differnt types.");    }
    else{
        double temp_num = (double_base(this->value_number, this->unit_type))+(double_base(phyNum.value_number, phyNum.unit_type));
        return PhysicalNumber(unit_double(temp_num, this->unit_type), this->unit_type);
    }
};

PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& phyNum) {
    if(!checkType(this->unit_type, phyNum.unit_type)){
  throw std::invalid_argument("you cant using operation '-' with differnt types.");
      }
    else{
        double temp_num = (double_base(this->value_number, this->unit_type))-(double_base(phyNum.value_number, phyNum.unit_type));
    
        return PhysicalNumber(unit_double(temp_num, this->unit_type), this->unit_type);
    }
};

PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber& phyNum) {
    if(!checkType(this->unit_type, phyNum.unit_type)){
        throw std::invalid_argument("you cant using operation '+=' with differnt types.");
    }
    else{
        double temp_num = double_base(this->value_number, this->unit_type)+( double_base(phyNum.value_number, phyNum.unit_type));
       
        this->value_number = unit_double(temp_num, this->unit_type);
    }
    return *this;
};

PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber& phyNum) {
    if(!checkType(this->unit_type, phyNum.unit_type)){
        throw std::invalid_argument("you cant using operation '-=' with differnt types.");
    }
    else{
        double temp_num = double_base(this->value_number, this->unit_type)-(double_base(phyNum.value_number, phyNum.unit_type));
        this->value_number = unit_double(temp_num, this->unit_type);
    }
    return *this;
};

const PhysicalNumber ariel::PhysicalNumber::operator+() {
    if(this->value_number < 0)
     return PhysicalNumber((-1)*this->value_number, this->unit_type);
    else
     return PhysicalNumber(this->value_number, this->unit_type);
};
const PhysicalNumber ariel::PhysicalNumber::operator-() {
    return PhysicalNumber(-1*(this->value_number), this->unit_type);
};



bool ariel::operator== (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
    }
    return (double_base(phy.value_number, phy.unit_type)) == (double_base(phy2.value_number, phy2.unit_type));
};



bool ariel::operator<= (const PhysicalNumber& phy, const PhysicalNumber& phy2){    
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
    }
    return (double_base(phy.value_number, phy.unit_type)) <= (double_base(phy2.value_number, phy2.unit_type));
};

bool ariel::operator>= (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
    }
    return (double_base(phy.value_number, phy.unit_type)) >= (double_base(phy2.value_number, phy2.unit_type));
};
bool ariel::operator< (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }
    return (double_base(phy.value_number, phy.unit_type)) < (double_base(phy2.value_number, phy2.unit_type));
};
bool ariel::operator> (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
    }

    return (double_base(phy.value_number, phy.unit_type)) > (double_base(phy2.value_number, phy2.unit_type));
};

bool ariel::operator!= (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '!=' with differnt types.");
    }
    return (double_base(phy.value_number, phy.unit_type)) != (double_base(phy2.value_number, phy2.unit_type));
};


PhysicalNumber& ariel::PhysicalNumber::operator++() {
    value_number++;
    return *this;
};
PhysicalNumber& ariel::PhysicalNumber::operator--() {
    value_number--;
    return *this;
};
PhysicalNumber ariel::PhysicalNumber::operator++(int num) {
    PhysicalNumber copy = *this;
    value_number++;
    return copy;
};
PhysicalNumber ariel::PhysicalNumber::operator--(int num) {
    PhysicalNumber copy = *this;
    value_number--;
    return copy;
};

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& c){

  return (os << c.value_number << "[" << unit_types[c.unit_type] << "]");
};







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


bool checkType (Unit unit_a, Unit unit_b){
    int this_type = ((int)unit_a - 1) / 3;
    int other_type = ((int)unit_b - 1) / 3;
    return this_type == other_type;
}
double unit_double(double value, Unit unit_temp){
    if(unit_temp == Unit::CM || unit_temp == Unit::SEC || unit_temp == Unit::G){
        return value;
    }
    else{
        double result = 0;
        switch(unit_temp){
            case Unit::MIN: result = value / 60;
                break;
            case Unit::HOUR: result = value / 3600;
                break;
            case Unit::KG: result = value / 1000;
                break;
            case Unit::TON: result = value / (1000 * 1000);
                break;
            case Unit::M: result = value / 100;
                break;
            case Unit::KM: result = value / (1000 * 100);  
                break;  
                default :
                cout<< "no change"<<endl;
        }
        return result;
    }
}

double double_base(double value, Unit temp_unit){
    if(temp_unit == Unit::CM || temp_unit == Unit::SEC || temp_unit == Unit::G){
        return value;
    }
    else{
        double result = 0;
        switch(temp_unit){
            case Unit::MIN: result = value * 60;
                break;
            case Unit::HOUR: result = value * 3600;
                break;
            case Unit::KG: result = value * 1000;
                break;
            case Unit::TON: result = value * 1000 * 1000;
                break;
            case Unit::M: result = value * 100;
                break;
            case Unit::KM: result = value * 1000 * 100;  
                break; 
                default :
                cout<< "no change"<<endl;
        }
        return result;
    }
}
