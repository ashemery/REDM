#include <windows.h>
#include <stdio.h>

int main() {
   HANDLE hFile;
   DWORD dwBytesWritten;
   char data[] = "Hello, World!";

   // Create a new file with write access
   hFile = CreateFile(L"example.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

   if (hFile == INVALID_HANDLE_VALUE) {
       printf("Failed to create file\n");
       return 1;
   }

   // Write the data to the file
   if (!WriteFile(hFile, data, sizeof(data), &dwBytesWritten, NULL)) {
       printf("Failed to write to file\n");
       CloseHandle(hFile);
       return 1;
   }

   // Close the file handle
   CloseHandle(hFile);

   return 0;
}