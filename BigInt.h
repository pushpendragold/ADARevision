#ifndef _H_BIGINT_H_
#define _H_BIGINT_H_

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class BigInt
{

private: 
		string digits;
		int sign;

public:

    BigInt(string d);
    BigInt(const BigInt &Num);
   
	BigInt operator + (const BigInt &Num) const;
    BigInt operator * (const BigInt &Num) const;
	
    void operator ++ ();

	bool operator == (const BigInt &R);
    bool operator != (const BigInt &R);
	bool operator <  (const BigInt &R);
    
	void PrintNumber();
};

#endif
