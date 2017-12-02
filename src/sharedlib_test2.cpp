#include <dlfcn.h>
#include <stdio.h>
#include "sharedlib2.cpp"

int main(){

  printf("Starting Main\n");

  void *libhandle = dlopen("./libshared_lib2.dylib", RTLD_NOW);
  if(libhandle == NULL){
    printf("Error: Failed to load shared lib %s\n", dlerror());
    dlclose(libhandle);
    libhandle = NULL;
    return -1;
  }
  else{
    printf("Found Lib \n");
  }
  dlerror();
  typedef TestClass* (*factory)(double);
  TestClass* obj;
  // factory_func factory;
  factory create = (factory) dlsym(libhandle, "create");
  if (!create){
    printf("Failed to find Factory Function\n");
    return -1;
  }
  else{
       obj = create(300);
     }

  printf("The value of m_double is %f \n", obj->m_double);
  double val = 25;
  obj->set_double(val);
  printf("The new value of m_double is %f \n", obj->m_double);
  val = val * 5;
  obj->set_double(val, "Overloaded Fcn");





  dlclose(libhandle);
}
