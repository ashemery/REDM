#include <windows.h>
#include <stdio.h>

int main()
{
   DWORD processId = 1234; // Replace with the target process ID
   HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
   if (hProcess == NULL) {
       printf("Failed to open process with ID %d\n", processId);
       return 1;
   }
   LPVOID address = (LPVOID)0x400000; // Replace with the target memory address
   LPCSTR buffer = "Hello, World!";
   SIZE_T size = strlen(buffer) + 1;
   BOOL result = WriteProcessMemory(hProcess, address, buffer, size, NULL);
   if (result) {
       printf("Data written to process's memory at address %p\n", address);
   }
   else {
       printf("Failed to write data to process's memory\n");
   }
   CloseHandle(hProcess);
   return 0;
}