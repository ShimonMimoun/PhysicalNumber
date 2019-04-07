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
    bool throwchecks;

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

.setname("----------------------------------------------------------")
      .setname("Verification of Masss ")
 
    .CHECK_OUTPUT(masse_01, "1[kg]") 
    .CHECK_OUTPUT((masse_01 += PhysicalNumber(1, Unit::KG)), "2[kg]") // kg=kg +kg
    .CHECK_OUTPUT((masse_01 += PhysicalNumber(5, Unit::G)), "2.005[kg]") //kg=kg +g
    .CHECK_OUTPUT((masse_01 += PhysicalNumber(10, Unit::TON)), "10002[kg]") //kg= kg +ton
    .CHECK_OUTPUT((masse_01 -= PhysicalNumber(10, Unit::TON)), "2.005[kg]") // Kg=kg-ton 
    .CHECK_OUTPUT((masse_01 -= PhysicalNumber(5, Unit::G)), "2[kg]") // Kg=kg-g 
    .CHECK_OUTPUT((masse_01 -= PhysicalNumber(1, Unit::KG)), "1[kg]") // Kg=kg-KG 
    .CHECK_OUTPUT((masse_01 = PhysicalNumber(2, Unit::KG)), "2[kg]") //  kg=  kg (other) 
    .CHECK_OUTPUT((masse_01 = PhysicalNumber(5, Unit::TON)), "5000[kg]") //  kg=  TON (other) 
    .CHECK_OUTPUT(-masse_01 , "-5000[kg]") // -lenght
    .CHECK_OUTPUT(+masse_01, "5000[kg]") // +lenght (no change )
    .CHECK_EQUAL((masse_01==PhysicalNumber(5, Unit::TON)),true) // 5000[kg]==5TON
    .CHECK_EQUAL((masse_01==PhysicalNumber(5, Unit::G)),false) // 5000[kg]==5g 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::TON))<(PhysicalNumber(5, Unit::G)),false) // 5Ton <5g
    .CHECK_EQUAL((masse_01<PhysicalNumber(50, Unit::TON)),true) //5000[kg]<50 ton 
    .CHECK_EQUAL((masse_01<PhysicalNumber(5, Unit::G)),false) //5000[kg]< 5 G
    .CHECK_EQUAL((masse_01>PhysicalNumber(11, Unit::TON)),false) // 5000[kg]> 11 ton 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::TON))>(PhysicalNumber(100, Unit::G)),true)//5 Ton>100g
    .CHECK_EQUAL((masse_01>PhysicalNumber(2, Unit::G)),true) // 5000[kg]>=2  g
    .CHECK_EQUAL((masse_01>=PhysicalNumber(50, Unit::KG)),true) // 5000[KG]>= 5 Ton 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::TON))>=(PhysicalNumber(100, Unit::G)),true)//5ton>=100g
    .CHECK_EQUAL((masse_01>=PhysicalNumber(4, Unit::TON)),true) // 5000[kg]>4 ton
    .CHECK_EQUAL((PhysicalNumber(10, Unit::G))<=(PhysicalNumber(10, Unit::G)),true ) // 10G <=10g
    .CHECK_EQUAL((masse_01<=PhysicalNumber(50, Unit::TON)),true) //5000[kg]<=50 ton
    .CHECK_EQUAL((masse_01<=PhysicalNumber(5, Unit::G)),false) //5000[KG]<= 5 g 
    .CHECK_EQUAL((masse_01!=PhysicalNumber(50, Unit::TON)),true) //5000[kg]!=50 ton 
    .CHECK_EQUAL((PhysicalNumber(5000, Unit::KG)!=PhysicalNumber(5, Unit::TON)) ,false) //5000 kg!= 5ton 
    .CHECK_OUTPUT(++masse_01 , "5001[kg]") // lenght++
    .CHECK_OUTPUT(++masse_01 , "5002[kg]") // verif lenght++
    .CHECK_OUTPUT(--masse_01 , "5001[kg]") // verif lenght--
    .CHECK_OUTPUT(masse_01+masse_01 , "10002[kg]") // lenght+lenght
    .CHECK_OUTPUT(masse_01+PhysicalNumber(50, Unit::KG) , "5051[kg]") // lenght+other
    .CHECK_OUTPUT(masse_01-masse_01 , "0[kg]") // lenght-lenght
    .CHECK_OUTPUT(masse_01-PhysicalNumber(50, Unit::KG) , "4951[kg]") // lenght-other
    .CHECK_OUTPUT(masse_01++, "5002[kg]") // lenght chack postfix ++
    .CHECK_OUTPUT(masse_01--, "5001[kg]") // lenght chack postfix --
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::KG)++, "51[kg]") //  chack postfix ++
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::G)-- ,"49[g]") // lenght chack postfix --


.setname("----------------------------------------------------------")
      .setname("Verification of Hour ")
 
    .CHECK_OUTPUT(time_01, "1[min]") 
    .CHECK_OUTPUT(PhysicalNumber(1, Unit::HOUR)+PhysicalNumber(10, Unit::MIN), "1.16667[hour]") 
    .CHECK_OUTPUT((time_01 += PhysicalNumber(1, Unit::MIN)), "2[min]") // min=min +min
    .CHECK_OUTPUT((time_01 += PhysicalNumber(5, Unit::SEC)), "2.08333[min]") //min=min +sec
    .CHECK_OUTPUT((time_01 += PhysicalNumber(10, Unit::HOUR)), "602.083[min]") //min= min +hour
    .CHECK_OUTPUT((time_01 -= PhysicalNumber(10, Unit::HOUR)), "2.08333[min]") // min=min-hour 
    .CHECK_OUTPUT((time_01 -= PhysicalNumber(5, Unit::SEC)), "2[min]") // min=min-sec 
    .CHECK_OUTPUT((time_01 -= PhysicalNumber(1, Unit::MIN)), "1[min]") // min=min-min 
    .CHECK_OUTPUT((time_01 = PhysicalNumber(2, Unit::MIN)), "2[min]") //  min=  min (other) 
    .CHECK_OUTPUT((time_01 = PhysicalNumber(5, Unit::HOUR)), "300[min]") //  min=  HOUR (other) 
    .CHECK_OUTPUT(-time_01 , "-300[min]") // -lenght
    .CHECK_OUTPUT(+time_01, "300[min]") // +lenght (no change )
    .CHECK_EQUAL((time_01==PhysicalNumber(5, Unit::HOUR)),true) // 300[min]==hour
    .CHECK_EQUAL((time_01==PhysicalNumber(5, Unit::SEC)),false) // 300[min]==5sec 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::HOUR))<(PhysicalNumber(5, Unit::SEC)),false) // 5 HOUR <5 sec
    .CHECK_EQUAL((time_01<PhysicalNumber(50, Unit::HOUR)),true) //300[min]<50 hour 
    .CHECK_EQUAL((time_01<PhysicalNumber(5, Unit::SEC)),false) //300[min]< 5 SEC
    .CHECK_EQUAL((time_01>PhysicalNumber(11, Unit::HOUR)),false) // 300[min]> 11 hour 
    .CHECK_EQUAL((PhysicalNumber(5, Unit::HOUR))>(PhysicalNumber(100, Unit::SEC)),true)//5 hour>100sec
    .CHECK_EQUAL((time_01>PhysicalNumber(2, Unit::SEC)),true) // 300[min]>=2 sec
    .CHECK_EQUAL((time_01>=PhysicalNumber(50, Unit::MIN)),true) // 300[min]>= 50 MIN
    .CHECK_EQUAL((PhysicalNumber(5, Unit::HOUR))>=(PhysicalNumber(100, Unit::SEC)),true)//5 HOUR>=100 SEC
    .CHECK_EQUAL((time_01>=PhysicalNumber(4, Unit::HOUR)),true) // 300[min]>4 HOUR
    .CHECK_EQUAL((PhysicalNumber(10, Unit::SEC))<=(PhysicalNumber(10, Unit::SEC)),true ) // 10sec <=10sec
    .CHECK_EQUAL((time_01<=PhysicalNumber(50, Unit::HOUR)),true) //300[min]<=50 HOur
    .CHECK_EQUAL((time_01<=PhysicalNumber(5, Unit::SEC)),false) //300[min]<= 5 sec
    .CHECK_EQUAL((time_01!=PhysicalNumber(50, Unit::HOUR)),true) //300[min]!=50 HOUR
    .CHECK_EQUAL((PhysicalNumber(5000, Unit::HOUR)!=PhysicalNumber(300000, Unit::MIN)) ,false) //5000[HOUR]!= 300000 MIN
    .CHECK_EQUAL((PhysicalNumber(5000, Unit::HOUR)!=PhysicalNumber(5000, Unit::HOUR)) ,false) //5000[HOUR]!= 5000[HOUR] MIN

    .CHECK_OUTPUT(++time_01 , "301[min]") // lenght++
    .CHECK_OUTPUT(++time_01 , "302[min]") // verif lenght++
    .CHECK_OUTPUT(--time_01 , "301[min]") // verif lenght--
    .CHECK_OUTPUT(time_01+time_01 , "602[min]") // lenght+lenght
    .CHECK_OUTPUT(time_01+PhysicalNumber(50, Unit::MIN) , "351[min]") // lenght+other
    .CHECK_OUTPUT(time_01-time_01 , "0[min]") // lenght-lenght
    .CHECK_OUTPUT(time_01-PhysicalNumber(50, Unit::MIN) , "251[min]") // lenght-other
    .CHECK_OUTPUT(time_01++, "302[min]") // lenght chack postfix ++
    .CHECK_OUTPUT(time_01--, "301[min]") // lenght chack postfix --
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::HOUR)++, "51[hour]") //  chack postfix ++
    .CHECK_OUTPUT(PhysicalNumber(50, Unit::SEC)-- ,"49[sec]") // lenght chack postfix --



   .setname("----------------------------------------------------------")

  .setname("check conversions")       
  .CHECK_EQUAL(PhysicalNumber(1, Unit::KG)==PhysicalNumber(1000, Unit::G),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::TON)==PhysicalNumber(1000, Unit::KG),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::TON)==PhysicalNumber(1000000, Unit::G),true)
  .CHECK_EQUAL(PhysicalNumber(1000, Unit::KG)==PhysicalNumber(1000000, Unit::G),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::HOUR)==PhysicalNumber(60, Unit::MIN),true)  
  .CHECK_EQUAL(PhysicalNumber(3600, Unit::SEC)==PhysicalNumber(60, Unit::MIN),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::HOUR)==PhysicalNumber(3600, Unit::SEC),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::KM)==PhysicalNumber(1000, Unit::M),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::KM)==PhysicalNumber(100000, Unit::CM),true)
  .CHECK_EQUAL(PhysicalNumber(1000, Unit::M)==PhysicalNumber(100000, Unit::CM),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::MIN)==PhysicalNumber(60, Unit::SEC),true)
  .CHECK_EQUAL(PhysicalNumber(1, Unit::M)==PhysicalNumber(100, Unit::CM),true)





   .setname("----------------------------------------------------------")
      .setname("Verification of TROW  ")

  .setname("Check Input")


  .CHECK_OK(istringstream("2[min]") >>a)
  .CHECK_OUTPUT((a += PhysicalNumber(30, Unit::SEC)), "2.5[min]")
  .CHECK_OK(istringstream("2[min]") >>b)
  .CHECK_OUTPUT((b += PhysicalNumber(30, Unit::SEC)), "2.5[min]")
.CHECK_OK(istringstream("30[kg]") >> c)
  .CHECK_OUTPUT((c+= PhysicalNumber(50, Unit::G)), "30.05[kg]")
 .CHECK_OK(istringstream("5[m]") >> length_01)
  .CHECK_OUTPUT((length_01 += PhysicalNumber(90, Unit::CM)), "5.9[m]")
  
  .CHECK_THROWS(istringstream("5[KM]") >> length_01)
  .CHECK_THROWS(istringstream("5") >> length_01)
  .CHECK_THROWS(istringstream("5 KM") >> length_01)
  .CHECK_THROWS(istringstream("2 cm ") >> length_01)
  .CHECK_THROWS(istringstream("afas") >> length_01)
  .CHECK_THROWS(istringstream("ton") >> length_01)
   .CHECK_THROWS(istringstream(" ") >> length_01)
  .CHECK_THROWS(istringstream("50 [k") >> length_01)
  .CHECK_THROWS(istringstream("2 ton] ") >> length_01)
  .CHECK_THROWS(istringstream("3[TON]") >> length_01)


        .setname("Check Throw ")


  .CHECK_THROWS(length_01+masse_01)
   .CHECK_THROWS(length_01-masse_01)
    .CHECK_THROWS(length_01+=masse_01)
      .CHECK_THROWS(length_01-=masse_01)
      .CHECK_THROWS(length_01=+masse_01)
      .CHECK_THROWS(length_01=-masse_01)
        .CHECK_THROWS(length_01=masse_01)
    .CHECK_THROWS(throwchecks= length_01==masse_01)
    .CHECK_THROWS(throwchecks= length_01<masse_01)
    .CHECK_THROWS(throwchecks= length_01>masse_01)
    .CHECK_THROWS(throwchecks= length_01<=masse_01)
   .CHECK_THROWS(throwchecks= length_01>=masse_01)
    .CHECK_THROWS(throwchecks= length_01!=masse_01)


    .CHECK_THROWS(time_01+masse_01)
   .CHECK_THROWS(time_01-masse_01)
    .CHECK_THROWS(time_01+=masse_01)
      .CHECK_THROWS(time_01-=masse_01)
        .CHECK_THROWS(time_01=+masse_01)
      .CHECK_THROWS(time_01=-masse_01)
    .CHECK_THROWS(time_01=masse_01)
        .CHECK_THROWS(throwchecks=time_01==masse_01)
    .CHECK_THROWS(throwchecks= time_01<masse_01)
    .CHECK_THROWS(throwchecks= time_01>masse_01)
    .CHECK_THROWS(throwchecks= time_01<=masse_01)
   .CHECK_THROWS(throwchecks= time_01>=masse_01)
    .CHECK_THROWS(throwchecks= time_01!=masse_01)


  .CHECK_THROWS(length_01+time_01)
  .CHECK_THROWS(length_01-time_01)
  .CHECK_THROWS(length_01+=time_01)
  .CHECK_THROWS(length_01-=time_01)
  .CHECK_THROWS(length_01=+time_01)
  .CHECK_THROWS(length_01=-time_01)
  .CHECK_THROWS(length_01=time_01)
  .CHECK_THROWS(throwchecks=time_01==length_01)
  .CHECK_THROWS(throwchecks= time_01<length_01)
  .CHECK_THROWS(throwchecks= time_01>length_01)
  .CHECK_THROWS(throwchecks= time_01<=length_01)
  .CHECK_THROWS(throwchecks= time_01>=length_01)
  .CHECK_THROWS(throwchecks= time_01!=length_01)


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}


