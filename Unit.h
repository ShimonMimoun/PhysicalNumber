/*
*  @author Omer Paz and Shimon Mimoun 
*
*/
#pragma once
#include <iostream>
using namespace std;

namespace ariel{

enum Unit {
    

    CM=1 , M , KM , SEC , MIN, HOUR, G ,KG ,TON ,count
};

const long unit_values[9] = {1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000};
const string unit_types[9] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};


};