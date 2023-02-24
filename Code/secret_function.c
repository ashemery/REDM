// Case 3
#include <stdio.h>
void secret_function() {
   printf("Congratulations! You have found the secret function!\n");
}

int main() {
   int secret_value = 0;
   char buffer[16];

   printf("Enter a string:\n");
   scanf("%s", buffer);

   if (secret_value == 0x1337) {
       secret_function();
   }
   else {
       printf("Try again.\n");
   }

   return 0;
}