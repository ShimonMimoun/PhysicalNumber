#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#include <sstream>
#include <string.h>

bool checkType (Unit unit_a, Unit unit_b){
    int this_type = ((int)unit_a - 1) / 3;
    int other_type = ((int)unit_b - 1) / 3;
    return this_type == other_type;
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


PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& other) {
    if(!checkType(this->unit_type, other.unit_type)){
throw std::invalid_argument("you cant using operation '+' with differnt types.");    }
    else{
        double temp_num = (double_base(this->value_number, this->unit_type))+(double_base(other.value_number, other.unit_type));
        temp_num = unit_double(temp_num, this->unit_type);
        return PhysicalNumber(temp_num, this->unit_type);
    }
};

PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& other) {
    if(!checkType(this->unit_type, other.unit_type)){
  throw std::invalid_argument("you cant using operation '-' with differnt types.");
      }
    else{
        double temp_num = double_base(this->value_number, this->unit_type);
        double othervalue_number = double_base(other.value_number, other.unit_type);
        temp_num -= othervalue_number;
        temp_num = unit_double(temp_num, this->unit_type);
        return PhysicalNumber(temp_num, this->unit_type);
    }
};

PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber& other) {
    if(!checkType(this->unit_type, other.unit_type)){
        throw std::invalid_argument("you cant using operation '+=' with differnt types.");
    }
    else{
        double temp_num = double_base(this->value_number, this->unit_type);
        double othervalue_number = double_base(other.value_number, other.unit_type);
        temp_num += othervalue_number;
        temp_num = unit_double(temp_num, this->unit_type);
        this->value_number = temp_num;
    }
    return *this;
};

PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber& other) {
    if(!checkType(this->unit_type, other.unit_type)){
        throw std::invalid_argument("you cant using operation '-=' with differnt types.");
    }
    else{
        double temp_num = double_base(this->value_number, this->unit_type);
        double othervalue_number = double_base(other.value_number, other.unit_type);
        temp_num -= othervalue_number;
        temp_num = unit_double(temp_num, this->unit_type);
        this->value_number = temp_num;
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



bool ariel::operator== (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!checkType(p1.unit_type, p2.unit_type)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 == value_number2;
};



bool ariel::operator<= (const PhysicalNumber& p1, const PhysicalNumber& p2){    
    if(!checkType(p1.unit_type, p2.unit_type)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 <= value_number2;
};

bool ariel::operator>= (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!checkType(p1.unit_type, p2.unit_type)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 >= value_number2;
};
bool ariel::operator< (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!checkType(p1.unit_type, p2.unit_type)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 < value_number2;
};
bool ariel::operator> (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!checkType(p1.unit_type, p2.unit_type)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 > value_number2;
};

bool ariel::operator!= (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!checkType(p1.unit_type, p2.unit_type)){
         throw std::invalid_argument("you cant using operation '!=' with differnt types.");
    }

    double value_number1 = double_base(p1.value_number, p1.unit_type);
    double value_number2 = double_base(p2.value_number, p2.unit_type);
    return value_number1 != value_number2;
};


PhysicalNumber& ariel::PhysicalNumber::operator++() {
    value_number++;
    return *this;
};
PhysicalNumber& ariel::PhysicalNumber::operator--() {
    value_number--;
    return *this;
};
PhysicalNumber ariel::PhysicalNumber::operator++(int dummy_flag_for_postfix_increment) {
    PhysicalNumber copy = *this;
    value_number++;
    return copy;
};
PhysicalNumber ariel::PhysicalNumber::operator--(int dummy_flag_for_postfix_increment) {
    PhysicalNumber copy = *this;
    value_number--;
    return copy;
};


ostream& ariel::operator<< (ostream& os, const PhysicalNumber& p_temp) {
    string unit = "";
    switch(p_temp.unit_type) {                //convert Unit to string
        case Unit::CM : unit = "cm";
        break;
        case Unit::M : unit = "m";
        break;
        case Unit::KM : unit = "km";
        break;
        case Unit::SEC : unit = "sec";
        break;
        case Unit::MIN : unit = "min";
        break;
        case Unit::HOUR : unit = "hour";
        break;
        case Unit::G : unit = "g";
        break;
        case Unit::KG : unit = "kg";
        break;
        case Unit::TON : unit = "ton";
        break;
    }
    return (os << p_temp.value_number << '[' << unit << ']');
};





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



double getvalue_number(string str){
    int unitSize = getUnitSize(str); //find unit length
    int size = str.length() - unitSize - 2;//unit length + []
    string value_number = str.substr(0, size);//cut string from 0 to '['
    double value = stod(value_number);//parsing
    return value;
}


istream& ariel::operator>> (istream& input, PhysicalNumber& other){
    int value_number;
    string unit;
    Unit u;

   
    ostringstream os;       
    input >> os.rdbuf();    
    string str = os.str();  
    int unitSize = unitCorrect(str); 
int value_numberSize = value_numberCorrect(str); 

  
    ios::pos_type startPosition = input.tellg();

    if (!unitSize || !value_numberSize) { 
      
        auto errorState = input.rdstate();
        input.clear(); 
        input.seekg(startPosition); 
        input.clear(errorState);

    } else {
        other.value_number = getvalue_number(str);
        other.unit_type = getUnit(unitSize);
    }

    return input;
};