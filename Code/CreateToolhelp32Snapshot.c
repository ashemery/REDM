#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

int main() {
   HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
   if (hSnapshot == INVALID_HANDLE_VALUE) {
       printf("Error: could not create snapshot\n");
       return 1;
   }

   PROCESSENTRY32 pe32;
   pe32.dwSize = sizeof(PROCESSENTRY32);

   if (!Process32First(hSnapshot, &pe32)) {
       printf("Error: could not retrieve first process\n");
       CloseHandle(hSnapshot);
       return 1;
   }

   printf("Running processes:\n");

   do {
       printf("  %s\n", pe32.szExeFile);
   } while (Process32Next(hSnapshot, &pe32));

   CloseHandle(hSnapshot);
   return 0;
}