#include <stdio.h>
#include <string.h>

#define SIZE 9
#define SIZENUMBER 5

int main() {
    char buf[1000];   // Buffer to store text lines
    unsigned long len;
    int i, n, a, b;
    int sum = 0;
    int totalsum = 0;
    
    char * charptr;  // Pointer to the first character when a written number is found
    char substr[SIZENUMBER+1];
    const char * const numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    while(fgets(buf, sizeof(buf), stdin)) { // Read string lines until EOF. Each successful call to fgets() increments the count
      i = a = b = 0;
      len = strlen(buf)-1;
      
      /* Uncomment the below section in order to solve Part One*/
      /*
       for(i=0; i<=len; i++ ){ // Go through the string finding written numbers
        strncpy(substr, buf+i, SIZENUMBER);
        
        for(n=0; n<=SIZE; n++){ // Go through all possible written numbers
          charptr = strstr(substr, numbers[n]); // Find numbers as strings 
          if (charptr != NULL){
            *charptr = '0'+n; // Replace the first character with the matching number
            strncpy(buf+i, substr, SIZENUMBER);
          }
        }
      }
      */
      //printf("%s",buf);
      
      for(i=0; i<=len; i++ ){ //Get the first and last numbers in the string
        if (a == 0 && (buf[i] <= '9' && buf[i] > '0')){
          a = (int) buf[i] - '0';
        }
        
        if (b == 0 && (buf[len-i] <= '9'&& buf[len-i] > '0')){
          b = (int) buf[len-i] - '0';
        }
      }

      sum = (a*10) + b;
      totalsum += sum;
      //printf("%d\n",sum);
    }
    printf("%d",totalsum);
    return 0;
}
