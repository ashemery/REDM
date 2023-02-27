#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
    FreeConsole();
    while (TRUE)
    {
        MessageBoxW(0, L"CLOSE ME?", L"¯\\___(ツ)___/¯", 0);
    }
    
    return 0;
}