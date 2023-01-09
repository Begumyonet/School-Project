/*
Name: Begum Yonet
Id: 1179159
Date:10.14.2022
Assignment name: CIS2520 Data Structures II Assignment 2 Q2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <math.h>
#include <ctype.h>
#include <limits.h>

int stack[INT_MAX];
int top =0;

void emptyStack(){
      top = 0;
}
void push(int value){

      stack[top] = value;
       top++; // moving on the next value
}    

int pop(){
      if (top ==0){
            printf("Not enough operands in expression\n");
            exit(EXIT_FAILURE);
      }
      return stack[--top]; // retun the value of the stack 
}

int add (int a,int b){ // adding up a and b
      return a+b;
}

int sub(int a,int b){  // substracting a and b
      return a-b;
}

int mul(int a,int b){  // multiplication a and b
      return a*b;
}

int divison(int a,int b){ // division of a and b
      return a/b;
}

int getSize(){
      return top;
}


int main (int argc,  char * argv[]) {
      if (argc>2){  // it is only two command lines arguments 
            printf("Too many command Line arguments");
            return 0;
      }
      for (int i=0;argv[1][i]!='\0';i++){
           if ((int)argv[1][i] >= 48 && (int)argv[1][i] <= 57){  // if they are numbers in ascii
                  push(argv[1][i]-'0'); // pushing integer to the stack
           }

           if (argv[1][i]== '+'){ // if it is plus sign
                  int a = pop();
                  int b = pop();
                  push(add(b,a)); // it will add b into the a and then push back to stack

           }else if(argv[1][i] == '-'){ // if it is minus sign

                  int a = pop();
                  int b = pop();
                  push(sub(b,a));  // it will substract a and b then push back stack

           }else if(argv[1][i]== '*'){ // if it is multiplication sign
                  int a = pop();
                  int b = pop();
                  push(mul(b,a)); // it will multiplicate  a and b then push back stack

           }else if(argv[1][i] == '/'){ // if it is division sign
                  int a = pop();
                  int b = pop();
                  push(divison(b,a)); // it will divide a and b then push back stack
           }

      }
      printf("The answer to %s is %.2f\n",argv[1],(double)stack[top-1]);
}
