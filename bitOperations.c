#include <stdio.h>
#include <string.h>


/* Program to perform basic bit operations. Takes a file containing the number to be manipulated, and a series of commands.
   Usable commands are get x n (returns nth bit of number x), set x n v (sets nth bit of x to v,
   and comp x n (sets the value of nth bit of x to its complement).
   The output is the result of the operations. See the readme and test1.txt for example input files and expeced outputs.   
*/
unsigned short get(unsigned short num, unsigned short index, int zero){
  unsigned short mask = (num >> index) & 1;
  //printf("%hu\n", mask);
  return mask;
}

unsigned short set(int num, int index, int replacement){
  unsigned short mask = (1 << index);
  unsigned short temp = (num & ~mask);
  unsigned short temp2 = ((replacement << index) & mask);
  unsigned short temp3 = temp | temp2;
  //printf("%d\n", temp3);
  return temp3;
}

unsigned short comp(unsigned short num, unsigned index, int zero){
  unsigned short a = (1 << index) ^ num;
  //printf("%hu\n", a);
  return a;
}

int main(int argc, char**argv){
  FILE *f = fopen(argv[1], "r");
  if(f == NULL){
    return 0;
  }
  unsigned short num;
  fscanf(f, "%hu\n", &num);
  char op[256];
  unsigned short operand1, operand2;
  while(fscanf(f, "%s\t%hu\t%hu\n", op, &operand1, &operand2) != EOF){
    if(op[0] == 'g'){
      printf("%hu\n", get(num, operand1, operand2));
    } else
    if(op[0] == 's'){
      num = set(num, operand1, operand2);
      printf("%hu\n", num);
    } else
    if(op[0] == 'c'){
      num = comp(num, operand1, operand2);
      printf("%hu\n", num);
    }
  }
  return 0;
}

