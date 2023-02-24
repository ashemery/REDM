#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
int main()
{
   LPCSTR filePath = "C:\\Windows\\System32\\notepad.exe";
   LPCSTR operation = NULL;
   LPCSTR parameters = NULL;
   LPCSTR directory = NULL;
   int showCmd = SW_SHOWNORMAL;
   HINSTANCE hInstance = ShellExecuteA(NULL, operation, filePath, parameters, directory, showCmd);
   if ((int)hInstance > 32) {
       printf("File opened successfully in the default editor\n");
   }
   else {
       printf("Failed to open file\n");
   }
   return 0;
}