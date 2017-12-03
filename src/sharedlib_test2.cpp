#include <dlfcn.h>
#include <stdio.h>
#include "sharedlib2.cpp"


typedef TestClass* (*factory_create)(double);
typedef void (*factory_destroy)(TestClass*);

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
  TestClass* obj;
  // factory_func factory;
  factory_create create = (factory_create) dlsym(libhandle, "create");
  factory_destroy destroy = (factory_destroy) dlsym(libhandle, "destroy");
  if (!create || !destroy){
    printf("Error %s\n", dlerror());
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

  destroy(obj);
  dlclose(libhandle);
}
