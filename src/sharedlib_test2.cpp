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
  typedef TestClass* (*factory)();
  TestClass* obj;
  // factory_func factory;
  void* maker = dlsym(libhandle, "create");
  if (!maker){
    printf("Failed to find Factory Function\n");
    return -1;
  }
  else{
       factory create = (factory)(maker);
       obj = create();
     }

  printf("The value of m_double is %f \n", obj->m_double);




  dlclose(libhandle);
}
