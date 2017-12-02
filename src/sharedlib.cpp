#ifndef SHARED_H
#define SHARED_H
#include "stdio.h"
#include "string"

extern "C"{
int addfcn123(int a, int b){
  return a+b;
}

void print_str123(std::string str){
  printf("The passed string is %s", str.c_str());
}
}
#endif
