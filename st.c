// Returns true if s1 is substring of s2 
int isSubstring(char* s1, char* s2) 
{ 
    int M = strlen(s1); 
    int N = strlen(s2); 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return i; 
    } 
    return -1; 
} 
/* Driver program to test above function */
int main() 
{ 
    char *s1 = "for"; 
    char *s2 = "geeksforgeeks"; 
    int res = isSubstring(s1, s2); 
    if (res == -1) 
        printf("Not present \n"); 
    else
        printf("Present at index %d\n",res); 
    return 0; 
}

---------------**********************************************-----------------

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
   
/* Swaps strings by swapping data -- only used for arrays, for pointers deref and use double pointers to make changes to underlying ptr outside the function and swap*/
void swap2(char *str1, char *str2)   // char str1[10] = "hello"; char str2[10] = "hi"; swap2(str1, str2);  printf("str1 is %s, str2 is %s", str1, str2); 
{ 
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char)); 
  strcpy(temp, str1); 
  strcpy(str1, str2); 
  strcpy(str2, temp); 
  free(temp); 
}   

void anagram()
{
  char *s1 = (char *)malloc(10*sizeof(char));
  char *s2 = (char *)malloc(10*sizeof(char));

  strcpy(s1,"creative");
  strcpy(s2,"reactive");

  int c1[26] = {0},c2[26] = {0}; int i=0,flag=0; //init of index is very important
  int len=strlen(s1);

  while(len)
  {
      if(*(s1+i) != '\0')
        c1[*(s1+i) - 'a']++;
        
      if(*(s2+i) != '\0')
        c2[*(s2+i) - 'a']++;
    i++;
    len--;
  }

  i=0;
  while(c1[i] == c2[i])
  {
      i++;
      flag =1;
  }

  if(flag == 1)
  {
    printf("\nANAGRAM!");
  }
  else
  {
      printf("\nNOT ANAGRAM!");
  }
  free(s1);
  free(s2);
}

void palindrome()
{
  char s1[] = "MOMOM";
  int flag =0;

  int siz = strlen(s1);

  for(int i = 0; i< (siz);i++)
  {
    if(s1[i] != s1[siz-i-1])
    {
      flag=1;
      break;
    }
  }
  if(flag ==0)
    printf("\n PALINDROME \n");
  else
    printf("\n NOT PALINDROME \n");
}

void reverse(char *s)
{
  // for(int i = 0;i < strlen(s);i++) //print the OG and reversed string
  // {
  //   printf("%c",*(s+i));
  // }
  char *temp = (char*)malloc((strlen(s) + 1) * sizeof(char));

  for(int i =0;i<strlen(s);i++)
  {
    *(temp+i) = *(s+(strlen(s)-i-1));
    //printf("%c",*(temp+i));
  }
  strcpy(s,temp);
  free(temp);
}

void revwords(char *s2)  
{
  // char *s1 = (char*)malloc(8 * sizeof(char));
  // strcpy(s1,"CLASS");
  // char *s2 = (char*)malloc(25 * sizeof(char));
  // strcpy(s2,"My name is Isha");
  //reverse(s1);
  //revwords(s2);
  
  char *temps = (char *)calloc(10 , sizeof(char)); //words
  char *temp2 = (char *)malloc((strlen(s2)+1) * sizeof(char)); //concat
  reverse(s2);
  int j =0;
  for(int i = 0;i<=strlen(s2);i++)
  {
    if(*(s2+i) == ' ' || *(s2+i) == '\0') //detect every word
    {
      reverse(temps);

      strcat(temp2,temps);
      strcat( temp2 , " ");

      int k =0;
      while(*(temps+k)) //emptying a string completely else it keeps out traces
      {
        *(temps+k) = 0;
        k++;
      }
      j=0;
    }
    else
    {
      *(temps+j) = *(s2+i);
      j++;
    }
  }

  strcpy(s2,temp2);
  printf("\nReversed words: ");
  for(int i = 0;i < strlen(s2);i++)
  {
    printf("%c",*(s2+i));
  }

  printf("\n\n");
  free(temps);
  free(temp2);
}

void substring()
{
  char *string = (char *)malloc(20 * sizeof(char));
  strcpy(string,"Hello Isha");
  int position = 4; int length = 2;
  char *pointer;
  int c;
 
  pointer = malloc((length+1)*sizeof(char));
   
  if (pointer == NULL)
  {
    printf("Unable to allocate memory.\n");
    exit(1);
  }
 
  for (c = 0 ; c < length ; c++)
  {
    *(pointer+c) = *(string+position-1);      
    string++;  
  }
 
  *(pointer+c) = '\0';

  printf("Required substring is \"%s\"\n", pointer);
 
}

/*multiple substrings at all positions*/

char *func(char *string, int position, int length)
{
  int c; char *pointer;
  pointer = malloc((length+1) * sizeof(char));
    
  if (pointer == NULL)
  {
    printf("Unable to allocate memory.\n");
    exit(1);
  }
       
  for (c = 0 ; c < length ; c++)
  {
    *(pointer+c) = *(string+position-1);      
    string++;  
  }
       
  *(pointer+c) = '\0';

  return pointer;
}
void subs()
{
  char string[10];

  strcpy(string,"code");

  int i=0;

   char *pointer;
   int position = 1, length = 1, temp, string_length = strlen(string);
  
 
   temp = string_length;
   int c;
 
   printf("Substring of \"%s\" are : \n", string);
 
   while (position <= string_length)
   {
      while (length <= temp)
      {
 
        pointer = func(string,position,length);
        printf("%s\n", pointer);
        free(pointer);
        length++;
      }
      temp--;
      position++;
      length = 1;
   }
}
