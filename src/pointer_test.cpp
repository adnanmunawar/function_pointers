#include <iostream>
#include <stdio.h>
#include <functional>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class B;

template <typename U, typename V>
class Conversion{
public:
  Conversion(){}
  ~Conversion(){}
  void (U::*my_func)(V);
  boost::function<void (V)> my_func2;
  void trythis(const boost::function<void (V)> cal_fcn){
    printf("2nd Pointer function in A called\n");
    my_func2 = cal_fcn;
    my_func2(505);

  }

};

class A{
public:
   A(){

   }
   ~A(){
   }
   void (B::*fcn2)(int);
   template <typename T, typename P>
   void init(void (T::*b_func)(P), T *obj){
     printf("Pointer function in A called \n");
    Conversion<T,P> con;
    con.my_func = b_func;
    fcn2 = b_func;
    (obj->*fcn2)(15);
    (obj->*(con.my_func))(2);

    con.trythis(boost::bind(b_func, obj, _1));
   }
   void run(){
   }
};

class B: public A{
public:
  B(){

  }
  ~B(){

  }
  void B_func(int val){
    printf("This is function in B %d \n", val);
    this->b_val = 4;
    printf("The new b_val is %d \n", b_val);
  }

  void pass_ptrTo_A(){
  }

  void run(){
    init(&B::B_func, this);
  }
private:
  int b_val = 2;
};




int main(int argc, char** argv){
  B objB;
  objB.run();
  return 0;
}
