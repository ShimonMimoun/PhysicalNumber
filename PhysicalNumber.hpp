#include <iostream>

namespace ariel{

class PhysicalNumber {

public:
int value_number;
enum unit; 

PhysicalNumber(int numb,int type);
const operator+(const PhysicalNumber& phyNum) const;




};

}