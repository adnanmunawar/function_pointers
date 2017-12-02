#include <stdio.h>


template<int a, int b>
struct add{
  static const int result = a+b;
};

template<int X> struct Factorial{
  static const int result = X*Factorial<X-1>::result;
};

template<> struct Factorial<0>{
  static const int result = 1;
};

template <int N, int D> struct Frak {
    static const long Num = N;
    static const long Den = D;
};

template <int N, typename F> struct ScalarMultiplication {
    typedef Frak<N*F::Num, N*F::Den> result;
};

int main(){
  int fact = Factorial<5>::result;
  printf("%d \n",fact);
  typedef Frak<2,5> my_frak;
  typedef ScalarMultiplication<3, my_frak> scaled_frak;
  printf("Num is %d, den is %d\n", scaled_frak::result::Num,
  scaled_frak::result::Den);
  return 0;
}
