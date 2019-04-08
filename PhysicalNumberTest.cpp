<<<<<<< HEAD
/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>

#include <sstream>

using std::cout, std::endl, std::istringstream;

#include "PhysicalNumber.h"

using ariel::PhysicalNumber, ariel::Unit;

#include "badkan.hpp"

int main()
{

  badkan::TestCase testcase;

  int grade = 0;

  int signal = setjmp(badkan::longjmp_buffer);

  if (signal == 0)
  {

    // BASIC TESTS - DO NOT CHANGE

    PhysicalNumber a(2, Unit::KM);

    PhysicalNumber b(300, Unit::M);

    PhysicalNumber c(2, Unit::HOUR);

    PhysicalNumber d(30, Unit::MIN);

    //DISTANCE
    PhysicalNumber km2(2, Unit::KM);

    PhysicalNumber mtr2000(2000, Unit::M);

    PhysicalNumber cm200000(200000, Unit::CM);

    PhysicalNumber km05(0.5, Unit::KM);

    //TIME
    PhysicalNumber hr2(2, Unit::HOUR);

    PhysicalNumber min120(120, Unit::MIN);

    PhysicalNumber sec7200(7200, Unit::SEC);

    PhysicalNumber min60(60, Unit::MIN);

    //MASS
    PhysicalNumber ton2(2, Unit::TON);

    PhysicalNumber kg2000(2000, Unit::KG);

    PhysicalNumber g2000000(2000000, Unit::G);

    PhysicalNumber ton1(1, Unit::TON);

    PhysicalNumber kg500(500, Unit::KG);

    PhysicalNumber g1000(1000, Unit::G);

    testcase

        .setname("Basic output")

        .CHECK_OUTPUT(a, "2[km]")

        .CHECK_OUTPUT(b, "300[m]")

        .setname("Compatible dimensions")

        .CHECK_OUTPUT(b + a, "2300[m]")

        .CHECK_OUTPUT((a += b), "2.3[km]")

        .CHECK_OUTPUT(a, "2.3[km]")

        .CHECK_OUTPUT(a + a, "4.6[km]")

        .CHECK_OUTPUT(b - b, "0[m]")

        .CHECK_OUTPUT(c, "2[hour]")

        .CHECK_OUTPUT(d, "30[min]")

        .CHECK_OUTPUT(d + c, "150[min]")

        .setname("Incompatible dimensions")

        .CHECK_THROWS(a + c)

        .CHECK_THROWS(a + d)

        .CHECK_THROWS(b + c)

        .CHECK_THROWS(b + d)

        .setname("Basic input")

        .CHECK_OK(istringstream("700[kg]") >> a)

        .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

        // YOUR TESTS - INSERT AS MANY AS YOU WANT

        ////// AUTHORS : OFEK BADER AND SNIR YEFET /////

        ///////////// DISTANCE UNITS ///////////////////

        // TEST DISTANCE UNITS CONSTRUCTOR and output (Ctor)

        .CHECK_OUTPUT(km2, "2[km]")

        .CHECK_OUTPUT(mtr2000, "2000[m]")

        .CHECK_OUTPUT(cm200000, "200000[cm]")

        .CHECK_OUTPUT(km05, "0.5[km]")

        // TEST DISTANCE UNITS COMPARISON (=)

        .CHECK_EQUAL(mtr2000, km2) // Should Return True (V)

        .CHECK_EQUAL(cm200000, km2) // Should Return True (V)

        .CHECK_EQUAL(cm200000, mtr2000) // Should Return True (V)

        // TEST DISTANCE UNITS COMPARISON (NOT) (!=)

        .CHECK_EQUAL((km05 != km05), false) //suppose to return true

        .CHECK_EQUAL((km05 != km2), true) //suppose to return true

        .CHECK_EQUAL((mtr2000 != km2), false) //suppose to return false (actual=false ,expected=true)

        .CHECK_THROWS(km05 != hr2)

        // TEST DISTANCE UNITS GREATER (>)

        .CHECK_EQUAL((km05 > km2), false) //suppose to return true

        .CHECK_EQUAL((km2 > km05), true) // supose to return true

        .CHECK_EQUAL((km05 > km05), false) //suppose to return true

        .CHECK_EQUAL((b > km05), false) //suppose to return true (b = 300 meter)

        .CHECK_THROWS(km05 > hr2)

        // TEST DISTANCE UNITS LESSER (<)

        .CHECK_EQUAL((km05 < km2), true) //suppose to return true

        .CHECK_EQUAL((km2 < km05), false) // supose to return true

        .CHECK_EQUAL((km05 < km05), false) //suppose to return true

        .CHECK_EQUAL((b < km05), true) //suppose to return true (b = 300 meter)

        .CHECK_THROWS(km05 < hr2)

        // TEST DISTANCE UNITS COMPARISON GREATER (>=)

        .CHECK_EQUAL((km05 >= km2), false)

        .CHECK_EQUAL((km2 >= km05), true)

        .CHECK_EQUAL((km05 >= km05), true) //suppose to return true

        .CHECK_EQUAL((b >= km05), false) //suppose to return false (b = 300 meter)

        .CHECK_THROWS(km05 >= hr2)

        // TEST DISTANCE UNITS COMPARISON LESSER (<=)

        .CHECK_EQUAL((km05 <= km2), true) //suppose to return true

        .CHECK_EQUAL((km2 <= km05), false) // supose to return false

        .CHECK_EQUAL((km05 <= km05), true) //suppose to return true

        .CHECK_EQUAL((b <= km05), true) //suppose to return true (b = 300 meter)

        .CHECK_THROWS(km05 <= hr2)

        // TEST DISTANCE UNITS ADDITION OP (+)

        .CHECK_EQUAL((km05 + PhysicalNumber(1.5, Unit::KM)), km2) // Should Return True (V)

        .CHECK_EQUAL((km05 + PhysicalNumber(1500, Unit::M)), km2) // Should Return True (V)

        .CHECK_EQUAL((cm200000 + PhysicalNumber(1.2, Unit::KM)), +PhysicalNumber(3.2, Unit::KM)) // Should Return True (V)

        .CHECK_EQUAL((km05 + PhysicalNumber(250, Unit::M)), PhysicalNumber(750, Unit::M)) //should return true

        .CHECK_THROWS(km05 + hr2)

        // TEST DISTANCE UNITS ADDTIONEQ OP (+=)

        .CHECK_OUTPUT((cm200000 += km2), "400000[cm]") //suppose to return true (cm200000 = 400000cm)

        .CHECK_OUTPUT((km05 += PhysicalNumber(500, Unit::M)), "1[km]") // (km05 = 1km)

        //.CHECK_OUTPUT((km05+=0),"0.5[km]") //suppose to return true (ALERT MIGHT CAUSE PROBLEM SINCE WE A DECIMAL POINT??)

        .CHECK_OUTPUT((km05 += PhysicalNumber(0.5, Unit::KM)), "1.5[km]") // (km05 = 1.5km)

        .CHECK_THROWS(km05 += hr2) // should throw exception DISTANCE != TIME.

        // TEST DISTANCE UNITS ADDITION UNARY OP (+..)

        // TEST DISTANCE UNITS SUBSCTRACTION OP (-)
        .CHECK_OUTPUT(PhysicalNumber(1.5, Unit::KM) - km05, "0[km]") //

        .CHECK_OUTPUT(cm200000 - PhysicalNumber(1.3, Unit::KM), "270000[cm]") // suppose to return true

        .CHECK_THROWS(km05 -= hr2)

        // TEST DISTANCE UNTIS SUBSCTRACTIONEQ OP (-=)

        .CHECK_OUTPUT((cm200000 -= km2), "200000[cm]") // suppose to return true

        .CHECK_OUTPUT((km05 -= PhysicalNumber(400, Unit::M)), "1.1[km]") //SUPPOSE TO RETURN TRUE

        // .CHECK_OUTPUT((km05-=0),"0.5[km]") //suppose to return true (ALERT MIGHT CAUSE PROBLEM SINCE WE A DECIMAL POINT??)

        .CHECK_THROWS(km05 -= hr2) // should throw an exception

        // TEST DISTANCE UNTIS SUBSCTRACTION UNARY OP (-..)

        // TEST DISTANCE UNTIS POSTFIX INCREMENT (..++)

        .CHECK_OUTPUT(km2++, "2[km]") // (km3 = 3km)
        .CHECK_OUTPUT(km2, "3[km]")   // (km2 = 3km)

        .CHECK_OUTPUT(cm200000++, "200000[cm]") // (cm200000 = 270000)
        .CHECK_OUTPUT(cm200000, "200001[cm]")   // (cm200000 = 270000)

        // TEST DISTANCE UNTIS PREFIX INCREMENT (++..)

        .CHECK_OUTPUT(++km2, "4[km]") //suppose to return true
        .CHECK_OUTPUT(km2, "4[km]")   //suppose to return true

        .CHECK_OUTPUT(++cm200000, "200002[cm]") //suppose to return true
        .CHECK_OUTPUT(cm200000, "200002[cm]")   //suppose to return true

        ///////////// TIME UNITS ///////////////////  D=30MIN

        // TEST TIME UNITS CONSTRUCTOR and output (Ctor)

        .CHECK_OUTPUT(hr2, "2[hour]")

        .CHECK_OUTPUT(min120, "120[min]")

        .CHECK_OUTPUT(sec7200, "7200[sec]")

        .CHECK_OUTPUT(min60, "60[min]")

        .CHECK_OUTPUT(PhysicalNumber(14.212, Unit::MIN), "14.212[min]")

        // TEST TIME UNITS COMPARISON (=)

        .CHECK_EQUAL(hr2, min120) // suppose to return true

        .CHECK_EQUAL(sec7200, min120) //suppose to return true

        .CHECK_EQUAL(sec7200, hr2) //suppose to return true

        //.CHECK_THROWS(min120=km05) // TODO suppose to throw exception

        // TEST TIME UNITS COMPARISON (NOT) (!=)

        .CHECK_EQUAL(sec7200 != min60, true) //suppose to return true

        .CHECK_EQUAL(sec7200 != min120, false) // suppose to return true

        .CHECK_EQUAL(min120 != hr2, false) //suppose to return true

        .CHECK_EQUAL(hr2 != sec7200, false) // suppose to return true

        .CHECK_THROWS(hr2 != a)

        // TEST TIME UNITS GREATER (>)

        .CHECK_EQUAL(PhysicalNumber(121, Unit::MIN) > hr2, true) // suppose to return true to all

        .CHECK_EQUAL(hr2 > hr2, false) //

        .CHECK_EQUAL(min60 > d, true) //

        .CHECK_EQUAL(min60 > hr2, false) //

        .CHECK_THROWS(d > a)

        // TEST TIME UNITS LESSER (<)

        .CHECK_EQUAL(c < hr2, false) //both equals 2 hours

        .CHECK_EQUAL(d < c, true) //suppose to return true d =30min , c = 2hr

        .CHECK_EQUAL(min60 < hr2, true) //suppose to return true

        .CHECK_EQUAL(sec7200 < hr2, false) //suppose to return true

        .CHECK_THROWS(a < d)

        // TEST TIME UNITS COMPARISON GREATER (>=)

        .CHECK_EQUAL(c >= hr2, true) //both equals

        .CHECK_EQUAL(min60 >= d, true) //d is 30min

        .CHECK_EQUAL(sec7200 >= hr2, true) //suppose to return true

        .CHECK_EQUAL(min120 >= min60, true)

        .CHECK_THROWS(hr2 >= km2)

        // TEST TIME UNITS COMPARISON LESSER (<=)

        .CHECK_EQUAL(c <= hr2, true) //both equals

        .CHECK_EQUAL(min60 <= d, false) //d is 30min

        .CHECK_EQUAL(sec7200 <= hr2, true) //suppose to return true

        .CHECK_EQUAL(min120 <= min60, false)

        .CHECK_THROWS(hr2 <= km2)

        // TEST TIME UNITS ADDITION OP (+)
        .CHECK_EQUAL(hr2 + hr2, PhysicalNumber(4, Unit::HOUR)) //suppose to return true
        .CHECK_EQUAL(hr2 + min60, PhysicalNumber(3, Unit::HOUR))
        .CHECK_EQUAL(hr2 + d, PhysicalNumber(2.5, Unit::HOUR))
        .CHECK_EQUAL(min120 + sec7200, PhysicalNumber(240, Unit::MIN))
        .CHECK_THROWS(hr2 + km05)
        .CHECK_THROWS(min120 + PhysicalNumber(3, Unit::KM))
        // TEST TIME UNITS ADDTIONEQ OP (+=)
        .CHECK_OUTPUT((hr2 += hr2), "4[hour]")
        .CHECK_OUTPUT((sec7200 += PhysicalNumber(120, Unit::MIN)), "14400[sec]") //NOTICE: not sure about the string syntax "[sec]""
        .CHECK_OUTPUT((min60 += PhysicalNumber(30, Unit::MIN)), "90[min]")       // (min60 = 90)
        .CHECK_OUTPUT((min120 += hr2), "360[min]")                               // (min120 = 360min)
        .CHECK_THROWS(min120 += km05)
        .CHECK_THROWS(hr2 += km05)
        // TEST TIME UNTIS ADDITION UNARY OP (+..)
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_THROWS()
        // TEST TIME UNTIS SUBSCTRACTION OP (-)
        .CHECK_OUTPUT((hr2 - PhysicalNumber(30, Unit::MIN)), "3.5[hour]")
        .CHECK_OUTPUT((hr2 - hr2), "0[hour]")
        .CHECK_OUTPUT((sec7200 - PhysicalNumber(60, Unit::MIN)), "10800[sec]")
        .CHECK_OUTPUT((min120 - PhysicalNumber(30, Unit::MIN)), "330[min]")
        .CHECK_THROWS(min120 - km05)
        .CHECK_THROWS(sec7200 - km05)
        // TEST TIME UNTIS SUBSCTRACTIONEQ OP (-=)
        .CHECK_OUTPUT((hr2 -= PhysicalNumber(30, Unit::MIN)), "3.5[hour]") // hr2 = 3.5hour
        .CHECK_OUTPUT((hr2 -= hr2), "0[hour]")
        .CHECK_OUTPUT((sec7200 -= PhysicalNumber(60, Unit::MIN)), "10800[sec]")
        .CHECK_EQUAL(sec7200, PhysicalNumber(10800, Unit::SEC))
        .CHECK_OUTPUT((min120 -= PhysicalNumber(30, Unit::MIN)), "330[min]")
        .CHECK_THROWS(min120 -= km05)
        .CHECK_THROWS(sec7200 -= km05)
        // TEST TIME UNTIS SUBSCTRACTION UNARY OP (-..)
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        // .CHECK_OUTPUT((),"[]")
        //  .CHECK_THROWS()
        // TEST TIME UNTIS POSTFIX INCREMENT (..++)
        .CHECK_OUTPUT((hr2++), "0[hour]")
        .CHECK_OUTPUT((hr2), "1[hour]")
        .CHECK_OUTPUT((sec7200++), "10800[sec]")
        .CHECK_OUTPUT((sec7200), "10801[sec]")
        .CHECK_OUTPUT((min60++), "90[min]")
        .CHECK_OUTPUT((min60), "91[min]")
        // .CHECK_OUTPUT(((hr2++)++),"4[hour]")      //PROBLEM
        // TEST TIME UNTIS PREFIX INCREMENT (++..)
        .CHECK_OUTPUT((++hr2), "2[hour]")
        .CHECK_OUTPUT((hr2), "2[hour]")
        .CHECK_OUTPUT(++(++sec7200), "10803[sec]")
        .CHECK_OUTPUT(sec7200, "10803[sec]")
        .CHECK_OUTPUT((++min60), "92[min]")
        .CHECK_OUTPUT((min60), "92[min]")
        //.CHECK_OUTPUT(++++++(hr2),"5[hour]")      //PROBLEM
        //.CHECK_OUTPUT(++++++++++(min60),"65[min]")

        ///////////// MASS UNITS ///////////////////

        //TON2 , TON1 , KG2000 , KG500 ,G2000000 , G1000
        // TEST MASS UNITS COMPARISON (=)
        .CHECK_EQUAL(ton2 == ton1, false)
        .CHECK_EQUAL(ton2 == kg2000, true)
        .CHECK_EQUAL(g2000000 == kg2000, true)
        .CHECK_EQUAL(g1000 == ton1, false)
        .CHECK_THROWS(ton1 == hr2)

        // TEST MASS UNITS COMPARISON (NOT) (!=)
        .CHECK_EQUAL(ton2 != ton1, true)
        .CHECK_EQUAL(ton2 != kg2000, false)
        .CHECK_EQUAL(g2000000 != kg2000, false)
        .CHECK_EQUAL(g1000 != ton1, true)
        .CHECK_THROWS(ton1 != hr2)
        // TEST MASS UNITS GREATER (>)
        .CHECK_EQUAL(kg500 > ton2, false)
        .CHECK_EQUAL(ton2 > ton2, false)
        .CHECK_EQUAL(ton1 > g1000, true)
        .CHECK_EQUAL(kg2000 > kg500, true)
        .CHECK_THROWS(g2000000 > d)
        // TEST MASS UNITS LESSER (<)
        .CHECK_EQUAL(kg500 < ton2, true)
        .CHECK_EQUAL(ton2 < ton2, false)
        .CHECK_EQUAL(ton1 < g1000, false)
        .CHECK_EQUAL(kg2000 < kg500, false)
        .CHECK_THROWS(kg2000 < d)
        // TEST MASS UNITS COMPARISON GREATER (>=)
        .CHECK_EQUAL(g1000 >= kg2000, false)
        .CHECK_EQUAL(ton1 >= ton1, true)
        .CHECK_EQUAL(kg500 >= g1000, true)
        .CHECK_EQUAL(ton2 >= g2000000, true)
        .CHECK_THROWS(ton2 >= hr2)
        // TEST MASS UNITS COMPARISON LESSER (<=)
        .CHECK_EQUAL(g1000 <= kg2000, true)
        .CHECK_EQUAL(ton1 <= ton1, true)
        .CHECK_EQUAL(kg500 <= g1000, false)
        .CHECK_EQUAL(ton2 <= g2000000, true)
        .CHECK_THROWS(ton2 <= hr2)
        // TEST MASS UNITS ADDITION OP (+)
        .CHECK_OUTPUT(ton1 + ton1, "2[ton]")
        .CHECK_OUTPUT(kg2000 + ton1, "3000[kg]")
        .CHECK_OUTPUT(ton2 + g1000, "2.001[ton]")
        .CHECK_OUTPUT(kg500 + ton1, "1500[kg]")
        .CHECK_THROWS(kg500 + d)
        // TEST MASS UNITS ADDTIONEQ OP (+=)
        .CHECK_OUTPUT((ton1 += ton1), "2[ton]")
        .CHECK_OUTPUT((kg2000 += ton1), "4000[kg]")
        .CHECK_OUTPUT((g1000 += PhysicalNumber(150, Unit::G)), "1150[g]")
        .CHECK_OUTPUT((kg500 += ton1), "2500[kg]")
        .CHECK_THROWS(kg500 += hr2)
        // TEST MASS UNTIS ADDITION UNARY OP (+..)
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_THROWS()

        //<name> = <actual value>
        //ton1 = 2ton , ton2=ton2 ,kg2000= 4000kg , kg500= 2500kg , g1000=2001000  ,g2000000
        // TEST MASS UNTIS SUBSCTRACTION OP (-)
        .CHECK_OUTPUT(ton1 - ton2, "0[ton]")
        .CHECK_OUTPUT(g2000000 - PhysicalNumber(1998850, Unit::G), "1150[g]")
        .CHECK_OUTPUT(kg2000 - ton2, "2000[kg]")
        .CHECK_OUTPUT(kg2000 - PhysicalNumber(1000, Unit::G), "3999[kg]")
        .CHECK_THROWS(ton2 - hr2)

        //<name> = <actual value>
        //ton1 = 2ton , ton2=ton 2 ,kg2000= 4000kg , kg500= 2500kg , g1000=2001000  ,g2000000 = 2000000
        // TEST MASS UNTIS SUBSCTRACTIONEQ OP (-=)
        .CHECK_OUTPUT((ton2 -= ton1), "0[ton]")
        .CHECK_OUTPUT((g2000000 -= PhysicalNumber(1998850, Unit::G)), "1150[g]")
        .CHECK_OUTPUT((kg2000 -= ton2), "4000[kg]")
        .CHECK_OUTPUT((kg2000 -= PhysicalNumber(1000, Unit::G)), "3999[kg]")
        .CHECK_THROWS(ton2 -= hr2)

        //<name> = <actual value>
        //ton2= 0 ton , ton1 = 2 ton, kg2000 = 3000 ,kg500 =2500 , g200000=2000000, g1000=1000
        // TEST MASS UNTIS SUBSCTRACTION UNARY OP (-..)
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_OUTPUT(,"[]")
        // .CHECK_THROWS()

        //<name>=<actual value>
        ////ton2= 0 ton , ton1 = 2 ton, kg2000 = 3000 ,kg500 =2500 , g200000=2000000, g1000=1000
        // TEST MASS UNTIS POSTFIX INCREMENT (..++)
        .CHECK_OUTPUT(kg2000++, "3999[kg]")
        .CHECK_OUTPUT(kg2000, "4000[kg]")
        .CHECK_OUTPUT(ton1++, "2[ton]")
        .CHECK_OUTPUT(ton1, "3[ton]")
        .CHECK_OUTPUT(g1000++, "1150[g]")
        .CHECK_OUTPUT(g1000, "1151[g]")
        //.CHECK_OUTPUT(kg500++++++++,"2500[kg]")
        //.CHECK_OUTPUT(ton2++++++++++,"0[ton]")

        //<name> = <actual value>
        //ton2 = 5 ton , ton1 =3 ton ,kg2000= 3001 kg ,kg500 = 2504 kg , g1000= 1001 g ,g2000000=2000000
        // TEST MASS UNTIS PREFIX INCREMENT (++..)
        .CHECK_OUTPUT(++kg2000, "4001[kg]")
        .CHECK_OUTPUT(kg2000, "4001[kg]")
        .CHECK_OUTPUT(++ton1, "4[ton]")
        .CHECK_OUTPUT(++g1000, "1152[g]")
        //.CHECK_OUTPUT(++++++++kg500,"2508[kg]")
        //.CHECK_OUTPUT(++++++++++ton2,"10[ton]")

        ////////////////////////////////////////

        .setname("...")

        .print(cout, /*show_grade=*/false);

    grade = testcase.grade();
  }
  else
  {

    testcase.print_signal(signal);

    grade = 0;
  }

  cout << "*** Grade: " << grade << " ***" << endl;

  return grade;
}
=======
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


>>>>>>> 13665117c7749e3466050eeb99a5bca316dbea17
