#include <windows.h>
#include <stdio.h>

int main()
{
   // Allocate 1 MB of memory
   LPVOID lpvMem = VirtualAlloc(NULL, 1024 * 1024, MEM_COMMIT, PAGE_READWRITE);
   if (lpvMem == NULL)
   {
       printf("Error allocating memory\n");
       return 1;
   }

   // Write some data to the allocated memory
   char* pChar = (char*)lpvMem;
   for (int i = 0; i < 1024 * 1024; i++)
   {
       *pChar++ = 'A';
   }

   // Free the allocated memory
   VirtualFree(lpvMem, 0, MEM_RELEASE);

   return 0;
}