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
        return PhysicalNumber(unit_double(temp_num, this->unit_type), this->unit_type);
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
        return PhysicalNumber(unit_double(temp_num, this->unit_type), this->unit_type);
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
        this->value_number = unit_double(temp_num, this->unit_type);
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
        this->value_number = unit_double(temp_num, this->unit_type);;
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
    }  return (double_base(phy.value_number, phy.unit_type)) == (double_base(phy2.value_number, phy2.unit_type));
};


bool ariel::operator> (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>' with differnt types.");
    }  return (double_base(phy.value_number, phy.unit_type)) > (double_base(phy2.value_number, phy2.unit_type));
};


bool ariel::operator< (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }return (double_base(phy.value_number, phy.unit_type)) < (double_base(phy2.value_number, phy2.unit_type));
};

bool ariel::operator>= (const PhysicalNumber& phy, const PhysicalNumber& phy2){
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '>=' with differnt types.");
    } return (double_base(phy.value_number, phy.unit_type)) >= (double_base(phy2.value_number, phy2.unit_type));
};


bool ariel::operator<= (const PhysicalNumber& phy, const PhysicalNumber& phy2){    
    if(!checkType(phy.unit_type, phy2.unit_type)){
         throw std::invalid_argument("you cant using operation '<=' with differnt types.");
    }

    return (double_base(phy.value_number, phy.unit_type)) <= (double_base(phy2.value_number, phy2.unit_type));
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




//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//                          HELP FONCTION
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------













int verif_string_unit(string str){
    int result = 0;
    int size = size_uni(str);
  
    if(size == 0 || size > 4){
        return 0;
    }
    else
    {
        string str_unit = str.substr(str.length()-1-size, size);
          if(!str_unit.compare("g")) 
                                        result = (int)Unit::G; 
        if(!str_unit.compare("kg")) 
                                         result = (int)Unit::KG; 
        if(!str_unit.compare("ton"))
                                         result = (int)Unit::TON; 
        if(!str_unit.compare("cm")) 
                                         result = (int)Unit::CM; 
        if(!str_unit.compare("m")) 
                                         result = (int)Unit::M; 
        if(!str_unit.compare("km")) 
                                         result = (int)Unit::KM; 
        if(!str_unit.compare("sec"))
                                         result = (int)Unit::SEC; 
        if(!str_unit.compare("min")) 
                                          result = (int)Unit::MIN; 
        if(!str_unit.compare("hour")) 
                                         result = (int)Unit::HOUR; 
      
    }
    return result;
}



int data_numberCorrect(string str)
{
    int size = str.length()-size_uni(str)-2;
    string str_unit = str.substr(0, size);
    int conter = 0;
    for(int i = 0; i < size; i++)
    {
        if(str_unit.at(i) > '9'||str_unit.at(i) < '0' ){
            if(str_unit.at(i) == '.')
            {
                conter++;
            }
            else
            {
                return 0;
            }
        }
        if(conter > 1)
        {
            return 0;
        }
    }
    return 1;
}



double getdata_number(string str){
    return stod(str.substr(0, (str.length() - ( size_uni(str)) - 2)));
}


bool checkType (Unit unit_a, Unit unit_b){
    return (((int)unit_a - 1) / 3) == (((int)unit_b - 1) / 3);
}

double double_base(double value_number, Unit temp_unit){
    if(temp_unit == Unit::SEC || temp_unit == Unit::G|| temp_unit == Unit::CM ){
        return value_number;
    }
    else{
        double result_double = 0;
        switch(temp_unit){
            case Unit::M: result_double = value_number * 100; break;
            case Unit::KM: result_double = value_number * 1000 * 100; break; 
            case Unit::MIN: result_double = value_number * 60; break;
            case Unit::HOUR: result_double = value_number * 3600; break;
            case Unit::KG: result_double = value_number * 1000;  break;
            case Unit::TON: result_double = value_number * 1000 * 1000; break;
                default :
                cout<< "The value don't change "<<endl;
        }
        return result_double;
    }
}

double unit_double(double value_number, Unit unit_temp){
    if(unit_temp == Unit::SEC ||unit_temp == Unit::CM || unit_temp == Unit::G){
        return value_number;
    }
    else{
        double result_unit = 0;
        switch(unit_temp){
              case Unit::M: result_unit = value_number / 100;  break;
            case Unit::KM: result_unit = value_number / (1000 * 100); break;  
            case Unit::MIN: result_unit = value_number / 60; break;
            case Unit::HOUR: result_unit = value_number / 3600; break;
            case Unit::KG: result_unit = value_number / 1000;  break;
            case Unit::TON: result_unit = value_number / (1000 * 1000);  break;
          
                default :
                cout<< "The value don't change"<<endl;
        }
        return result_unit;
    }
}


int size_uni(string str){
    int unit_size = 1;
    if(str.at(str.length() - 1)  != ']'){
        throw std::out_of_range{"Error Imput"};
        return 0;
    }
    
    while((str.at(str.length() - unit_size - 1) >= 'a' )  &&  
                                                            (str.at(str.length() - unit_size - 1) <= 'z')){
        unit_size++;
    }
    
    if(str.at(str.length() - unit_size - 1) != '[')
            return 0;
    
    return unit_size - 1;
}

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