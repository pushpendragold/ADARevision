#include <cstdio>
#include <cstring>
#include <iostream>

#define DEBUG 1
using namespace std;


#define POSITIVE true
#define NEGATIVE false

class BigInt 
{
    private:
        bool sign;
        int length;
        char * digits;
    public:
        BigInt(char * input);
        
        void Print();
};

int main()
{
    BigInt a("123");

    a.Print();
    return 0;
}

BigInt::BigInt(char * input)
{
    int len = strlen(input);
    digits = new char[len+1];

    int i = 0;
    if(input[i] == '-') 
    {
        sign = NEGATIVE;
        ++i;
    }
    else
        sign = POSITIVE;

    for(int k = 0; i < len; ++i) 
        digits[k++] = input[i];
    
    if(sign == NEGATIVE ) 
        --len;
    length = len;
}
