#include <stdio.h>
#include <stdlib.h>

/* Program to determine the parity of a number, and the number of 1 bit pairs.
   Input is number on command line.
   Parity is even if the number of 1 bits is even, else odd.
   1 bit pairs refer to 2 adjacent 1's. 
   For example, 111101101 is odd parity and 3 pairs.
*/

unsigned short pair(unsigned short num){
  unsigned short temp1;
  unsigned short temp2;
  unsigned short d = 0;
  unsigned short counter = num;
  unsigned short result = 0;
  while(counter > 0){
      if(counter == 0){
        break;
    }
    temp1 = (num & 1);
    if(d){
      num = (num >> 2);
    } else {
    num = (num >> 1);
    }
    d = 0;
    counter = num;
    temp2 = (counter & 1);
    if((temp1 & 1 )== 1 && (temp2 & 1)== 1){
      result++;
      d = 1;
    }

  }
  printf("%hu\n", result);
  return 0;
}
unsigned short parity(int num){
  unsigned short result =0;
   while(num >= 0){
     if((num & 1) == 1){
       result++;
     }
     num = (num >> 1);
     if(num == 0){
       break;
     }
   }
 
 if((result % 2) == 0){
   printf("Even-Parity\t");
 } else {
   printf("Odd-Parity\t");
 }
return 0;
}

int main(int argc, char**argv){
  int n = atoi(argv[1]);
  unsigned short num = (unsigned short) n;
  parity(num);
  pair(num);
return 0;
}

