#include <stdio.h>
#include <string>
#include <dlfcn.h>

int (*addfcn)(int, int);
void(*print_str)(std::string);
const char *error;

int main(){
  printf("Starting Shared Lib Code\n");

void* handle = dlopen("./libshare_test.dylib", RTLD_LOCAL|RTLD_LAZY);
if(handle == NULL){
  printf("Error: Failed to load shared lib %s\n", dlerror());
  dlclose(handle);
  handle = NULL;
}
else{
printf("Found Library \n");
dlerror();
*(void**)(&addfcn) = dlsym(handle, "addfcn123");
*(void**)(&print_str) = dlsym(handle, "print_str123");
if((!addfcn)||(!print_str)){
  printf("Error: Failed to load function %s\n", dlerror());
}

int val = addfcn(3,4);
printf("Added val is %d\n", val);
print_str("This is what I am printing\n");
dlclose(handle);
}
}
