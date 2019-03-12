#include <fstream>
#include <iostream>
#include "../include/LenEnc.h"

int main(){
  LenEnc rlen;
  
  std::string filename = "h";
  rlen.encoding(filename);
  rlen.decoding("h.rlen");
  
  
}
