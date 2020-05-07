/*Both threads call on this--benign data race*/

int is_prime(int v)
{
     int i;
     int bound = floor(sqrt ((double)v)) + 1;
    
     for (i = 2; i < bound; i++) {
         /* No need to check against known composites */ 
         if (!pflag[i]) 
             continue;
         if (v % i == 0) { 
             pflag[v] = 0;
            return 0;
        }
     }
     return (v > 1); 
 }
 
 -------------************************------------
 //Uart driver-- 
 flow control using circ buffer
 
 //virtual function-c++
 inheritable and overridable function or method for which dynamic dispatch is facilitated. 
 This concept is an important part of the polymorphism portion of object-oriented programming.

//CHECK INT OVERFLOW--

#include<stdio.h> 
#include<stdlib.h> 
int addOvf(int* result, int a, int b) 
{ 
     *result = a + b; 
     if(a > 0 && b > 0 && *result < 0) 
         return -1; 
     if(a < 0 && b < 0 && *result > 0) 
         return -1; 
     return 0; 
}  
int main() 
{ 
    int *res = (int *)malloc(sizeof(int)); 
    int x = 2147483640; //2^32
    int y = 10; 
    printf("%d", addOvf(res, x, y)); 
    printf("\n %d", *res); 
    return 0; 
}  
 
//RUN LENGTH ENCODING 
void printRLE(char* str) 
{ 
    int n = strlen(str); 
    for (int i = 0; i < n; i++) { 
  
        // Count occurrences of current character 
        int count = 1; 
        while (i < n - 1 && str[i] == str[i + 1]) { 
            count++; 
            i++; 
        } 
        // Print character and its count 
        printf("%c%d",str[i],count); 
    } 
} 
int main() 
{ 
    char *str = "xxxaabnnnnntt"; 
    printRLE(str); 
    return 0; 
}

//solving bottlenecks
send phy address to the kernel instead of copy to user and from (copying entire memory region) - map US and KS space (shared memory)

//middleware

//booting process
arm/embedded platform

//memory management OS

