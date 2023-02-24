#include <windows.h>
#include <urlmon.h>
#include <stdio.h>
#pragma comment(lib, "urlmon.lib")

int main()
{
   LPCSTR url = "https://download.sysinternals.com/files/SysinternalsSuite.zip";
   LPCSTR filePath = "C:\\Users\\IEUser\\Downloads\\SysinternalsSuite.zip";
   HRESULT hr = URLDownloadToFile(NULL, url, filePath, 0, NULL);
   if (SUCCEEDED(hr)) {
       printf("File downloaded successfully to %s\n", filePath);
   }
   else {
       printf("Failed to download file from %s\n", url);
   }
   return 0;
}