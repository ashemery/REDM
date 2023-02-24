#include <Windows.h>
#include <stdio.h>

int main()
{
    HKEY hKey;
    LONG lResult;

    // Open or create the key
    lResult = RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\CDF", &hKey);

    if (lResult != ERROR_SUCCESS) {
        printf("Error creating key: %d\n", lResult);
        return 1;
    }

    printf("Key created successfully!\n");

    // Close the key
    RegCloseKey(hKey);

    char subkey[] = "SOFTWARE\\CDF";
    char value[] = "FOR300";
    char data[] = "Reverse Engineering!";

    // Open the registry key
    LONG regOpenResult = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_SET_VALUE, &hKey);
    if (regOpenResult != ERROR_SUCCESS) {
        printf("Error opening registry key: %d\n", regOpenResult);
        return 1;
    }

    // Set the value in the registry
    LONG regSetValueResult = RegSetValueEx(hKey, value, 0, REG_SZ, (BYTE*)data, sizeof(data));
    if (regSetValueResult != ERROR_SUCCESS) {
        printf("Error setting registry value: %d\n", regSetValueResult);
        RegCloseKey(hKey);
        return 1;
    }

    // Close the registry key
    RegCloseKey(hKey);

    printf("Registry value set successfully!\n");

    return 0;
}
