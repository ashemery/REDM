#include <windows.h>
#include <stdio.h>

int main()
{
   // Execute the "notepad" program
   int result = WinExec("notepad", SW_SHOW);
   if (result > 31) {
       printf("notepad started successfully\n");
   }
   else {
       printf("Failed to start notepad\n");
   }
   return 0;
}