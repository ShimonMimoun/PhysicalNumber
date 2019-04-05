/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Shimon Mimoun and Omer Paz
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"


int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber length_01 (1 ,Unit::M);
    PhysicalNumber time_01 (1 ,Unit::MIN);
    PhysicalNumber masse_01 (1 ,Unit::KG);
    

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT


      .setname("----------------------------------------------------------")
      .setname("Test Private")
      .setname("----------------------------------------------------------")
      .setname("Verification of Lenght ")
      .CHECK_OUTPUT(length_01, "1[m]") 
    .CHECK_OUTPUT((length_01 += PhysicalNumber(1, Unit::M)), "2[m]") // m=m +m
    .CHECK_OUTPUT((length_01 += PhysicalNumber(5, Unit::CM)), "2.05[m]") //m=m + cm
    .CHECK_OUTPUT((length_01 += PhysicalNumber(10, Unit::KM)), "10002[m]") //m= m +km
    .CHECK_OUTPUT((length_01 -= PhysicalNumber(10, Unit::KM)), "2.05[m]") // m=m - km 
    .CHECK_OUTPUT((length_01 -= PhysicalNumber(5, Unit::CM)), "2[m]") // m=m-cm 
    .CHECK_OUTPUT((length_01 -= PhysicalNumber(1, Unit::M)), "1[m]") // m=m-m 
    .CHECK_OUTPUT((length_01 = PhysicalNumber(2, Unit::M)), "2[m]") //  m=  m other 
    .CHECK_OUTPUT((length_01 = PhysicalNumber(5, Unit::KM)), "5000[m]") //  m=  m other 
    .CHECK_OUTPUT(-length_01 , "-5000[m]") // -lenght
    .CHECK_OUTPUT(+length_01, "5000[m]") // +lenght (no change )
    .CHECK_EQUAL((length_01==PhysicalNumber(5, Unit::KM)),true) // 5000[m]==5km
    .CHECK_EQUAL((length_01==PhysicalNumber(5, Unit::M)),false) // 5000[m]==5m 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::KM))<(PhysicalNumber(5, Unit::M)),false) // 5KM <5M
    .CHECK_EQUAL((length_01<PhysicalNumber(50, Unit::KM)),true) //5000[m]<50 km 
    .CHECK_EQUAL((length_01<PhysicalNumber(5, Unit::CM)),false) //5000[m]< 5 Cm
    .CHECK_EQUAL((length_01>PhysicalNumber(11, Unit::KM)),false) // 5000[m]> 11 KM 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::KM))>(PhysicalNumber(100, Unit::M)),true)//5km>100M
    .CHECK_EQUAL((length_01>PhysicalNumber(2, Unit::CM)),true) // 5000[m]>=2  cm
    .CHECK_EQUAL((length_01>=PhysicalNumber(50, Unit::M)),true) // 5000[m]>= 11 KM 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::KM))>=(PhysicalNumber(100, Unit::M)),true)//5km>=100M
    .CHECK_EQUAL((length_01>=PhysicalNumber(4, Unit::KM)),true) // 5000[m]>4 km
    .CHECK_EQUAL((PhysicalNumber(10, Unit::CM))<=(PhysicalNumber(10, Unit::CM)),true ) // 10CM <=10M
    .CHECK_EQUAL((length_01<=PhysicalNumber(50, Unit::KM)),true) //5000[m]<=50 km 
    .CHECK_EQUAL((length_01<=PhysicalNumber(5, Unit::CM)),false) //5000[m]<= 5 Cm 
    .CHECK_EQUAL((length_01!=PhysicalNumber(50, Unit::KM)),true) //5000[m]!=50 km 
    .CHECK_EQUAL((PhysicalNumber(5000, Unit::M)!=PhysicalNumber(5, Unit::KM)) ,false) //5000 m!= 5 Km 
    .CHECK_OUTPUT(++length_01 , "5001[m]") // lenght++
    .CHECK_OUTPUT(++length_01 , "5002[m]") // verif lenght++
    .CHECK_OUTPUT(--length_01 , "5001[m]") // verif lenght--
    .CHECK_OUTPUT(length_01+length_01 , "10002[m]") // lenght+lenght
    .CHECK_OUTPUT(length_01+PhysicalNumber(50, Unit::M) , "5051[m]") // lenght+other
    .CHECK_OUTPUT(length_01-length_01 , "0[m]") // lenght-lenght
    .CHECK_OUTPUT(length_01-PhysicalNumber(50, Unit::M) , "4951[m]") // lenght-other
    .CHECK_OUTPUT(length_01++, "5002[m]") // lenght chack postfix ++
    .CHECK_OUTPUT(length_01--, "5001[m]") // lenght chack postfix --
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::KM)++, "51[km]") //  chack postfix ++
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::CM)-- ,"49[cm]") // lenght chack postfix --
    .CHECK_OUTPUT(time_01, "1[min]") 
    .CHECK_OUTPUT((time_01 += PhysicalNumber(1, Unit::MIN)), "2[min]") // min=min +min
    .CHECK_OUTPUT((time_01 += PhysicalNumber(60, Unit::SEC)), "3[min]") //min=min +sec

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}


