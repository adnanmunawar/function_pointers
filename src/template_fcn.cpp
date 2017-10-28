#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <stdio.h>
#include <string.h>


class B{
public:
  B(){}
  ~B(){}

  template<typename U>
  using FCN = boost::function<void (U)>;

  FCN<std::string> my_func;
  template<typename Q>
  void assign_fcn(boost::function<void (Q)> func){
    bool flag = std::is_same<Q, bool>::value;
    printf("Types are same? : %d \n", flag);
    my_func = func;
    my_func("Hey");
  }

  void run(){
  //  my_func("YO");
  }
};


class A{
public:
  A(){}
  ~A(){}
void print_fcn(std::string str){
  printf("Passed String is %s \n", str.c_str());
}
void pass(){
  objB.assign_fcn<std::string>(boost::bind(&A::print_fcn, this, _1));
}
B objB;
};


int main(){
  A objA;

  objA.pass();

  return 0;
}
