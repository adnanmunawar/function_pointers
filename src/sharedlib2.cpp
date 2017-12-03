#ifndef SHAREDLIB2_H
#define SHAREDLIB2_H

#include <stdio.h>
#include <string>

class TestClass{
public:
  TestClass(double a_a);
  void set_double(double &a_a);
  void set_double(double&a_a, std::string str);
  void set_int(int &a_i);
  double get_double();
  double m_double;
  int m_int[10];

};

TestClass::TestClass(double a_a){
  printf("Creating Test Class\n");
  m_double = a_a;
}

double TestClass::get_double(){
  return m_double;
}

void TestClass::set_double(double &a_a){
  m_double = a_a;
}

void TestClass::set_double(double &a_a, std::string str){
  m_double = a_a;
  printf("And the passed string is %s\n", str.c_str());
}

void TestClass::set_int(int &a_i){
  m_int[0] = a_i;
}

extern "C"{
TestClass* create(double a_a){
  return new TestClass(a_a);
}

void destroy(TestClass* obj){
    printf("Destroying Object \n");
    delete obj;
}
}

#endif
