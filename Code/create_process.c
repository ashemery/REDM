#include <windows.h>
#include <stdio.h>

int main() {
   PROCESS_INFORMATION pi;
   STARTUPINFO si;
   ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
   ZeroMemory(&si, sizeof(STARTUPINFO));
   si.cb = sizeof(STARTUPINFO);

   // Create a new process
   if (!CreateProcess(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
       printf("Failed to create process\n");
       return 1;
   }

   // Wait for the process to exit
   WaitForSingleObject(pi.hProcess, INFINITE);

   // Close the process and thread handles
   CloseHandle(pi.hProcess);
   CloseHandle(pi.hThread);

   return 0;
}