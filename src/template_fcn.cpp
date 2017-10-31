#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <stdio.h>
#include <string.h>

template<typename D>
class A{
public:
  A(){}
  ~A(){}
  template <typename C>
  void bind_func(void (C::*fcn)(D), C* obj);
  boost::function<void (D)> my_func;
};

template<typename D>
template<typename C>
void A<D>::bind_func(void (C::*fcn)(D), C* obj){
  my_func = boost::bind(fcn, obj, _1);
}

class B: public A<int>, public A<std::string>{
public:
  B(){
    my_int = 1;
    my_str = "Hello World";
  }
  ~B(){}
  std::string my_str;
  int my_int;
  void run(){
    A<int>::my_func(my_int);
    printf("Pause\n");
    A<std::string>::my_func(my_str);
  }
};

class C: public B{
public:
  C(){}
  ~C(){}
  void int_func(int x){
    printf("Printing passed int %d\n", x);
  }
  void double_func(double x){
    printf("Printing passed int %f\n", x);
  }
  void str_func(std::string x){
    printf("Printing passed char %s\n", x.c_str());
  }
  void assign_int_func(){
  A<int>::bind_func(&C::int_func, this);
  }
  void assign_char_func(){
  A<std::string>::bind_func(&C::str_func, this);
  }

  void assign_fcns(){
    assign_int_func();
    assign_char_func();
  }
};


int main(){
  C cobj;
  cobj.assign_fcns();
  cobj.run();
  //cobj.assign_char_func();

  return 0;
}
