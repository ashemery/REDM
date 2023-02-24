//Caesar Cipher
#include <stdio.h>
#include <string.h>

void encrypt(char* input, char* output, int key)
{
   int i;
   for (i = 0; i < strlen(input); i++) {
       if (input[i] >= 'a' && input[i] <= 'z') {
           output[i] = 'a' + ((input[i] - 'a' + key) % 26);
       }
       else if (input[i] >= 'A' && input[i] <= 'Z') {
           output[i] = 'A' + ((input[i] - 'A' + key) % 26);
       }
       else {
           output[i] = input[i];
       }
   }
   output[i] = '\0';
}

int main()
{
   char input[] = "CDF Rocks!";
   int len = strlen(input);
   //char output[strlen(input) + 1];
   char output[11];
   int key = 3;

   encrypt(input, output, key);

   printf("Input: %s\n", input);
   printf("Output: %s\n", output);

   return 0;
}