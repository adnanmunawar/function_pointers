#ifndef SHAREDLIB2_H
#define SHAREDLIB2_H

#include <stdio.h>

class TestClass{
public:
  TestClass();
  void set_double(double &a_a);
  void set_int(int &a_i);
  double get_double();
  double m_double;
  int m_int[10];

};

TestClass::TestClass(){
  printf("Creating Test Class\n");
  m_double = 50;
}

double TestClass::get_double(){
  return m_double;
}

void TestClass::set_double(double &a_a){
  m_double = a_a;
}

void TestClass::set_int(int &a_i){
  m_int[0] = a_i;
}

extern "C" TestClass* create(){
  return new TestClass;
}

#endif
