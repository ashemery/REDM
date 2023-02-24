#include <windows.h>
#include <stdio.h>

int main()
{
   HMODULE hModule = LoadLibraryA("user32.dll");
   if (hModule != NULL) {
       printf("user32.dll loaded successfully\n");
       // Do something with the loaded module here...
       FreeLibrary(hModule);
   }
   else {
       printf("Failed to load user32.dll\n");
   }
   return 0;
}