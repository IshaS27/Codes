//SEL-1
#include <iostream>
class FizzBuzz
{
public:
 FizzBuzz(uint32_t fizz, uint32_t buzz) :
 fizz_(fizz), buzz_(buzz)
 {
 }
 void process(uint32_t value)
 {
 std::cout << value;
 if (isFizz(value))
 std::cout << " Fizz";
 if (isBuzz(value))
 std::cout << " Buzz";
 }
protected:
 const uint32_t fizz_;
 const uint32_t buzz_;
 virtual bool isFizz(uint32_t value)
 {
 return fizz_ == value;
 }
 virtual bool isBuzz(uint32_t value)
 {
 return buzz_ == value;
 }
};

class FizzBuzz1 : public FizzBuzz
{
public:
 FizzBuzz1(uint32_t fizz, uint32_t buzz) :
 FizzBuzz(fizz, buzz)
 {
     
 }
 protected:
 bool isFizz(uint32_t value)
 {
 return (value % fizz_) == 0;
 }
 virtual bool isBuzz(uint32_t value)
 {
 return (value % buzz_)== 0;
 }
};

class FizzBuzz2 : public FizzBuzz
{
public:
 FizzBuzz2(uint32_t fizz, uint32_t buzz, uint32_t target) :
 FizzBuzz(fizz, buzz)
 {
  target_ = target;  
 }
 
 protected:
 uint32_t countVar;
 uint32_t target_;
 
 void countFlip(int a, int b)
 {
    int n;
    n = a^b;
    int count = 0;
    while (n)
    {
        count += 1;
        n = n & n-1;
    }
    countVar = count;
 }
 
 bool isFizz(uint32_t value)
 {
 countFlip(value, target_);
 return fizz_ == countVar;
 }
 virtual bool isBuzz(uint32_t value)
 {
 countFlip(value, target_);
 return buzz_ == countVar;
 }
};



int main()
{
 std::cout << "Fizz Buzz!\n";
//  FizzBuzz fizzbuzz(2, 3);
//  FizzBuzz1 fizzbuzz(2, 3);
 FizzBuzz2 fizzbuzz(2, 3, 4);
 const uint32_t count = 32;
 for (uint32_t i = 1; i < count; i++)
 {
 fizzbuzz.process(i);
 std::cout << ", ";
 }
 fizzbuzz.process(count);
 std::cout << "Done\n";
}  


//esc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char *s,int size,int count)
{
    char *s1 = (char*)calloc((size+count),sizeof(char)); //allocate double just in case
    int j=0;
   
    for(int i=0;i<size+count+1;i++)
    {
        if(s[i] == '<' || s[i] == '>' || s[i] == 92) //using ASCII for '\'
        {
            s1[j] = 92;
            j++;
            s1[j] = s[i];
            j++;
        }
        else
        {
            s1[j] = s[i];
            j++;
        }
    }
   
    printf("%s",s1); //final string
    free(s1);
}

int main()
{
    char *str = (char*)calloc(25,sizeof(char));
    int count = 0;
    char c;
    printf("\nEnter a string:\n");
   
    gets(str);
   
    //strcpy(str,"<hello> world>"); //terminating character not accepted at the end

    for(int i =0;i<strlen(str)+1;i++) //for additional length
    {

        if(str[i] == '<' || str[i] == '>' || str[i] == 92) //using ASCII for '\'
        {
            count++;
        }
    }

  
    func(str,strlen(str),count);
    free(str);

    return 0;
}
