#include <iostream>
#include <stdio.h>
class B;

template <typename U, typename V>
class Conversion{
public:
  Conversion(){}
  ~Conversion(){}
  void (U::*my_func)(V);
};

class A{
public:
   A(){

   }
   ~A(){
   }

   template <typename T, typename P>
   void init(void (T::*b_func)(P), T &obj){
     printf("Pointer function in A called \n");
     Conversion<T,P> con;
     con.my_func = b_func;
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
  }

  void pass_ptrTo_A(){
  }

  void run(){
    init(&B::B_func, *this);
  }
private:
  int b_val = 2;
};




int main(int argc, char** argv){
  B objB;
  objB.run();
  return 0;
}
