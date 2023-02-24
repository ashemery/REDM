#include <stdio.h>
#include <string.h>

void xor_string(char* string, size_t length, char key) {
   for (size_t i = 0; i < length; i++) {
       string[i] = string[i] ^ key;
   }
}

int main() {
   char original[] = "Hello FOR-300!";
   //char obfuscated[strlen(original) + 1];
   char obfuscated[20];
   char key = 'A';

   // Obfuscate the string
   strcpy(obfuscated, original);
   xor_string(obfuscated, strlen(original), key);

   printf("Original: %s\n", original);
   printf("Obfuscated: %s\n", obfuscated);

   // De-obfuscate the string
   xor_string(obfuscated, strlen(original), key);

   printf("De-obfuscated: %s\n", obfuscated);

   return 0;
}