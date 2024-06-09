// info@stce.rwth-aachen.de
#include <iostream>
#include <fstream>
#include <string>

int main(){
  std::ifstream in1("time.plt"), in2("../../../../../v2.4/apps/4th_order_convex_polynomial/time_measurements/time.plt");
  std::ofstream out("time_difference.plt");
  int i;
  std::string a, b;
  while(!in1.eof() && !in2.eof()){
    in1 >> i;
    in2 >> i;
    in1 >> a;
    in2 >> b;
    out << i << ' ' << 100.*(std::stod(a)-std::stod(b))/std::stod(b) << std::endl;
  }
  return 0;
}

