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
int getUnitSize(string str);
int unitCorrect(string str);
int value_numberCorrect(string str);
double getvalue_number(string str);
Unit getUnit(int unit);

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




int getUnitSize(string str){
    int unit_size = 1;
    int size = str.length();
    
    if(str.at(size - 1)  != ']'){
        throw std::out_of_range{"Input not correct!!!"};
        return 0;
    }
    
    while(str.at(size - unit_size - 1) >= 'a' && str.at(size - unit_size - 1) <= 'z'){
        unit_size++;
    }
    
    if(str.at(size - unit_size - 1) != '['){
        return 0;
    }

    return unit_size - 1;
}

int unitCorrect(string str){
    int unitSize = getUnitSize(str);//get unit length of input
    int unit = 0; //type of unit

    if(unitSize == 0 || unitSize > 4){//if unitSize = 0 or more than 4 so input is not correct
        return 0;
    }
    else{
        string tempUnit = str.substr(str.length() - unitSize - 1, unitSize);
        if(!tempUnit.compare("cm")){ unit = (int)Unit::CM; }
        if(!tempUnit.compare("m")){ unit = (int)Unit::M; }
        if(!tempUnit.compare("km")){ unit = (int)Unit::KM; }
        if(!tempUnit.compare("sec")){ unit = (int)Unit::SEC; }
        if(!tempUnit.compare("min")){ unit = (int)Unit::MIN; }
        if(!tempUnit.compare("hour")){ unit = (int)Unit::HOUR; }
        if(!tempUnit.compare("g")){ unit = (int)Unit::G; }
        if(!tempUnit.compare("kg")){ unit = (int)Unit::KG; }
        if(!tempUnit.compare("ton")){ unit = (int)Unit::TON; }
    }
    return unit;//return 0 if tempUnit string not equals to some Unit type
}



int value_numberCorrect(string str){
    int unitSize = getUnitSize(str);//find unit length
    int size = str.length() - unitSize - 2;//unit length + []
    string value_number = str.substr(0, size);//cut string from 0 to '['
    int dotCount = 0;//count of dots
    for(int i = 0; i < size; i++){
        if(value_number.at(i) < '0' || value_number.at(i) > '9'){
            if(value_number.at(i) == '.'){//if char is '.' so dotCount ++
                dotCount++;
            }
            else{//if char is not number or dot so value_number input is wrong
                return 0;
            }
        }
        if(dotCount > 1){ // more than 1 dot so value_number input is wrong
            return 0;
        }
    }
    return 1;
}
istream& ariel::operator>> (istream& input, PhysicalNumber& other){
    int value_number;
    string unit;
    Unit unit_type;

    ostringstream os;       
    input >> os.rdbuf();    
    string str = os.str();  
   


    int unitSize = unitCorrect(str);
    int amountSize = value_numberCorrect(str);


    ios::pos_type startPosition = input.tellg();

    if (!unitSize || !amountSize) { 
  
        auto errorState = input.rdstate(); 
        input.clear(); 
        input.seekg(startPosition);
        input.clear(errorState); 

    } else {
        other.value_number = getvalue_number(str);
        other.unit_type = getUnit(unitSize);
    }

    return input;
} ;


Unit getUnit(int unit){
    Unit temp;
    switch (unit)
    {
        case 1: temp = Unit::CM;
            break;
        case 2: temp = Unit::M;
            break;
        case 3: temp = Unit::KM;
            break;
        case 4: temp = Unit::SEC;
            break;
        case 5: temp = Unit::MIN;
            break;
        case 6: temp = Unit::HOUR;
            break;
        case 7: temp = Unit::G;
            break;
        case 8: temp = Unit::KG;
            break;    
        case 9: temp = Unit::TON;
            break;
    }
    return temp;
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
double getvalue_number(string str){
    int unitSize = getUnitSize(str); //find unit length
    int size = str.length() - unitSize - 2;//unit length + []
    string value_number = str.substr(0, size);//cut string from 0 to '['
    double value = stod(value_number);//parsing
    return value;
}
