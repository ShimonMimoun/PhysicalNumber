#include "PhysicalNumber.h"
#include "Unit.h"
#include <iostream>
using namespace std;
using namespace ariel;
#include <sstream>
#include <string.h>

Unit get_Unit(int unit);
bool checkType (Unit unit_a, Unit unit_b);
double getdata_number(string str);
double double_base(double data_number, Unit temp_unit);
double unit_double(double data_number, Unit unit_temp);
int size_uni(string str);
int verif_string_unit(string str);
int data_numberCorrect(string str);



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



bool ariel::operator== (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '==' with differnt types.");
    }

    double value_number1 = double_base(phy.value_number, phy.unit_type);
    double value_number2 = double_base(phy2.value_number, phy2.unit_type);
    return value_number1 == value_number2;
};


bool ariel::operator> (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
    }
        double value_number1 = double_base(phy.value_number, phy.unit_type);
    double value_number2 = double_base(phy2.value_number, phy2.unit_type);
    return value_number1 > value_number2;
};


bool ariel::operator< (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double value_number1 = double_base(phy.value_number, phy.unit_type);
    double value_number2 = double_base(phy2.value_number, phy2.unit_type);
    return value_number1 < value_number2;
};

bool ariel::operator>= (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
    }

    double value_number1 = double_base(phy.value_number, phy.unit_type);
    double value_number2 = double_base(phy2.value_number, phy2.unit_type);
    return value_number1 >= value_number2;
};


bool ariel::operator<= (const PhysicalNumber& phy, const PhysicalNumber& phy2){    
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
    }

    double value_number1 = double_base(phy.value_number, phy.unit_type);
    double value_number2 = double_base(phy2.value_number, phy2.unit_type);
    return value_number1 <= value_number2;
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


ostream& ariel::operator<< (ostream& os, const PhysicalNumber& p_temp) {
    string unit = "";
    switch(p_temp.unit_type) {  
        case Unit::G : unit = "g";
        break;
        case Unit::KG : unit = "kg";
        break;
        case Unit::TON : unit = "ton";
        break;           
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
       
         default :
                cout<< "no change"<<endl;
    }
    return (os << p_temp.value_number << '[' << unit << ']');
};





Unit get_Unit(int unit){
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


int verif_string_unit(string str){
    int unitSize = size_uni(str);
    int unit = 0;
    if(unitSize == 0 || unitSize > 4){
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
    return unit;
}



int data_numberCorrect(string str){
    int unitSize = size_uni(str);
    int size = str.length() - unitSize - 2;
    string value_number = str.substr(0, size);
    int dotCount = 0;
    for(int i = 0; i < size; i++){
        if(value_number.at(i) < '0' || value_number.at(i) > '9'){
            if(value_number.at(i) == '.'){
                dotCount++;
            }
            else{
                return 0;
            }
        }
        if(dotCount > 1){
            return 0;
        }
    }
    return 1;
}



double getdata_number(string str){
    int unitSize = size_uni(str); 
    int size = str.length() - unitSize - 2;
    string data = str.substr(0, size);
    double data_number = stod(data);
    return data_number;
}


istream& ariel::operator>> (istream& input, PhysicalNumber& other){
    int data_number;
    string unit;
    Unit u;

   
    ostringstream os;       
    input >> os.rdbuf();    
    string str = os.str();  
    int unitSize = verif_string_unit(str); 
int data_numberSize = data_numberCorrect(str); 

  
    ios::pos_type startPosition = input.tellg();

    if (!unitSize || !data_numberSize) { 
      
        auto errorState = input.rdstate();
        input.clear(); 
        input.seekg(startPosition); 
        input.clear(errorState);

    } else {
        other.value_number = getdata_number(str);
        other.unit_type = get_Unit(unitSize);
    }

    return input;
};

bool checkType (Unit unit_a, Unit unit_b){
    int this_type = ((int)unit_a - 1) / 3;
    int other_type = ((int)unit_b - 1) / 3;
    return this_type == other_type;
}

double double_base(double value_number, Unit temp_unit){
    if(temp_unit == Unit::CM || temp_unit == Unit::SEC || temp_unit == Unit::G){
        return value_number;
    }
    else{
        double result = 0;
        switch(temp_unit){
            case Unit::MIN: result = value_number * 60;
                break;
            case Unit::HOUR: result = value_number * 3600;
                break;
            case Unit::KG: result = value_number * 1000;
                break;
            case Unit::TON: result = value_number * 1000 * 1000;
                break;
            case Unit::M: result = value_number * 100;
                break;
            case Unit::KM: result = value_number * 1000 * 100;  
                break; 
                default :
                cout<< "no change"<<endl;
        }
        return result;
    }
}

double unit_double(double value_number, Unit unit_temp){
    if(unit_temp == Unit::CM || unit_temp == Unit::SEC || unit_temp == Unit::G){
        return value_number;
    }
    else{
        double result = 0;
        switch(unit_temp){
            case Unit::MIN: result = value_number / 60;
                break;
            case Unit::HOUR: result = value_number / 3600;
                break;
            case Unit::KG: result = value_number / 1000;
                break;
            case Unit::TON: result = value_number / (1000 * 1000);
                break;
            case Unit::M: result = value_number / 100;
                break;
            case Unit::KM: result = value_number / (1000 * 100);  
                break;  
                default :
                cout<< "no change"<<endl;
        }
        return result;
    }
}


int size_uni(string str){
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
