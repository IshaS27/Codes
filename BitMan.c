#include<stdio.h>	#include<stdlib.h>	#include<string.h>
#include<stdint.h>	#include<stdbool.h>	#include <unistd.h>

int computeXOR(int n) // printf("Compute the XOR of 1 to n: %d \n",computeXOR(7));
{ 
    if (n % 4 == 0) return n; 
    if (n % 4 == 1)  return 1; 
    if (n % 4 == 2) return n + 1; 
    else            return 0; 
} 

bool isPowerOfTwo(int x) // printf("Is it a power of two? %d \n", isPowerOfTwo(8));
{     return x && (!(x & (x - 1))); }

int lead(unsigned int x)  // printf("Number of leading 0s: %d \n",lead(10));
{
	int total_bits = sizeof(x) * 8;  //32 bits mostly, else just what is given
    int res = 0; 

    while ( !(x & (1 << (total_bits - 1))) ) 
    { 
        x = (x << 1); 
        res++; 
    }
	return res;
}

int trail(int32_t n) // printf("Number of trailing 0s: %d \n",trail(10));
{
    int count = 0; 
    while(n !=0)
    { 
    	if(n & 1)
    		break;
    	count++;

        n = n>>1;
    } 
    return count; 
}
int ones(int x) // printf("Number of 1s: %d \n",ones(001001));
{
	int count =0;
	while(x)
	{
		if(x & 1)
		{
			count++;
		}
		x = x >> 1;
	}
	return count;	
}

unsigned int alternate(int n) // printf("Alternate pattern? %u \n", alternate(12));
{
	unsigned int num = (n ^ (n >> 1));

	if(((num + 1) & num) == 0)
		return 1;
	else
		return 0;
} 
--------------------------****************************************-------------------------------
/*ENDIAN*/

#include <stdlib.h>	#include <stdint.h>

void whichendian() /*little endian*/
{
    short int word = 0x0101;
    char *b = (char *)&word;
    printf("num : %u\n", b[0]);
}
void convertendian()
{
	int32_t x = 0x12345678;
	x = ( x >> 24 ) | (( x << 8) & 0x00ff0000 )| ((x >> 8) & 0x0000ff00) | ( x << 24)  ; 
	printf("value = %x \n", x);  // x will be printed as 0x78563412
}

--------------------------****************************************-------------------------------
/*EXTRACT BITS*/

// void extr()
// {
// 	int r = (((1 << 2no.) - 1) & (temp >> (31pos - 1)));
// }

---------------------***********************-------------------

/*binary to decimal/dec to bin*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int convert(int n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        i++;
    }
    return dec;
}
int convertdec(int n) {
    int bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
    //    printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, rem, n / 2);
        n /= 2;
        bin += rem * i; /*binary format but not the 0b as such*/
        i *= 10;
    }
    return bin;
}
int main() {
    int n;
    printf("Enter a binary number: ");
    scanf("%d", &n);
    printf("%d in binary = %d in decimal\n\n", n, convert(n));

    int k;
    printf("Enter a decimal number: ");
    scanf("%d", &k);
    printf("%d in decimal = %d in binary \n", k, convertdec(k));

    return 0;
}
--------------------**********************************------------------
/*A to I*/

// Program to implement atoi() in C 
#include <stdio.h> 
  
// A simple atoi() function 
int myAtoi(char* str) 
{ 
    int res = 0; // Initialize result 
  
    // Iterate through all characters of input string and 
    // update result 
    for (int i = 0; str[i] != '\0'; ++i) 
        res = res * 10 + str[i] - '0'; 
  
    // return result. 
    return res; 
} 
  
// Driver program to test above function 
int main() 
{ 
    char str[] = "89789"; 
    int val = myAtoi(str); 
    printf("%d ", val); 
    return 0; 
} 