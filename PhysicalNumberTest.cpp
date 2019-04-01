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
    PhysicalNumber e(44,Unit::TON )
    PhysicalNumber f(2, Unit::SEC);
    PhysicalNumber g(500, Unit::CM);
    PhysicalNumber h(4, Unit::G);;
    PhysicalNumber j(71,Unit::KG )


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



      .setname("Time Test")
      .CHECK_OUTPUT(f, "2[sec]")
      .CHECK_OUTPUT(d, "30[min]")
      .CHECK_OUTPUT(d+f, "30.03[min]")
      .CHECK_OUTPUT(c+d, "2,5005[hour]")
      .CHECK_OUTPUT(c+c, "5.001[hour]")
      .CHECK_OUTPUT(d+d, "60.06[min]")
      .CHECK_OUTPUT(c-d, "4[hour]")
      .CHECK_OUTPUT(f-f, "0[sec]")
      .setname("Incompatible dimensions Operator ") 
      .CHECK_THROWS(j+f)
      .CHECK_THROWS(c+e)
      .CHECK_THROWS(g+f)
     .setname("Mass Test")
      .CHECK_OUTPUT(j+j, "142[kg]")
      .CHECK_OUTPUT(j-j, "0[kg]")
      .CHECK_OUTPUT(j, "71[kg]")
      .CHECK_OUTPUT(j+h, "71,4[kg]")
      .CHECK_OUTPUT(j, "71[kg]")
      .CHECK_OUTPUT(e-j, "44,071[ton]")
      .setname("Incompatible dimensions Operator ") 
      .CHECK_THROWS(h+g)
      .CHECK_THROWS(j-f)
      .CHECK_THROWS(e+b+f)
      .setname("Distance Test")
    .CHECK_OUTPUT(a-a, "0[km]")
    .CHECK_OUTPUT(a, "2[km]")
      .CHECK_OUTPUT(a+b, "2,3[km]")
      .CHECK_OUTPUT(a, "2[km]")
      .CHECK_OUTPUT(b-a, "1,7[m]")
      .CHECK_OUTPUT(g, "500[cm]")
      .setname("Incompatible Distance Operator ") 
      .CHECK_THROWS(a-j)
      .CHECK_THROWS(h+g)
      .CHECK_THROWS(a+b+c)
      .setname("Other Tests :")
 
      .CHECK_OK(istringstream("1000[km]") >> a)
      .CHECK_OK(istringstream("33[m]") >> b)
      .CHECK_OK(istringstream("0[ton]") >> c)
       
     .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "2000[kg]")
       .CHECK_OUTPUT((b += PhysicalNumber(1, Unit::KM)), "1033[m]")
       .CHECK_OUTPUT((c += PhysicalNumber(6, Unit::TON)), "6[ton]")
















      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
