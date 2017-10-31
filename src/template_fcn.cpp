#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <stdio.h>
#include <string.h>

template<typename D>
class A{
public:
  A(){}
  ~A(){}
  template <typename Cl>
  void bind_func(void (Cl::*fcn)(D), Cl* obj){
    my_func = boost::bind(fcn, obj, _1);
  }
  boost::function<void (D)> my_func;
};

class B: public A<int>, public A<char>{
public:
  B(){}
  ~B(){}
  void run(){
    
  }
};

class C: public B{
public:
  C(){}
  ~C(){}
  void int_func(int x){
    printf("Printing passed char %d", x);
  }
  void char_func(char x){
    printf("Printing passed char %c", x);
  }
  void assign_int_func(){
  A<int>::bind_func(&C::int_func, this);
  }
  void assign_char_func(){
  A<char>::bind_func(&C::char_func, this);
  }
};


int main(){
  C cobj;
  cobj.assign_int_func();
  //cobj.assign_char_func();

  return 0;
}
