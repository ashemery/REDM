#include <stdio.h>
int main() {
       FILE* fp;

       fp = fopen("example.txt", "w");

       if (fp == NULL) {
           printf("Error creating file.");
           return 1;
       }

       fprintf(fp, "This is an example file.");

       fclose(fp);

       return 0;
}