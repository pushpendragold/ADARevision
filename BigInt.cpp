#include "BigInt.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

BigInt::BigInt(string d) : sign(d[0] == '-' ? -1 : 1)
{
	digits.resize(d.size() - (d[0] == '-'));

	for(int i = d.size() - 1, j = 0 ; i >= (d[0] == '-'); i--, j++) 
		digits[j] = d[i] - '0';
}

BigInt::BigInt(const BigInt &Num)
{
	sign = Num.sign;
	digits.resize(Num.digits.size());

	for(int i=0;i < Num.digits.size(); i++) 
		digits[i] = Num.digits[i];
}

BigInt BigInt::operator + (const BigInt &Num) const
{
	BigInt result("");
	result.digits.resize(Num.digits.size() + digits.size());
	
	//If both operands are of same sign
	if(Num.sign == sign)
	{
		//Addition will take place
		int len = Num.digits.size() > digits.size() ? Num.digits.size() : digits.size();
		int i, carry = 0;
		for(i = 0; i < len || carry; i++) 
		{
			int n_num = 0;
			if(Num.digits.size() - 1 >= i) 
				n_num += Num.digits[i];

			if(digits.size() - 1 >= i)
				n_num += digits[i];

			n_num += carry;

			result.digits[i] = n_num % 10;
			carry = n_num / 10;
		}

		result.sign = sign;
		result.digits.resize(i);
	}
	else
	{
		//Sign of numbers are different substraction will take place
		if(Num.digits.size() > digits.size())
		{
			int i, borrow = 0;
			for(i = 0; i < Num.digits.size(); i++) 
			{
				int n_num = Num.digits[i];

				if(borrow)
				{
					if(n_num > 0) 
					{	
						n_num--;
						borrow = 0;
					}
					else
					{
						n_num = 9;
						borrow = 1;
					}
				}

				if(digits.size() - 1 >= i)
				{
					//substract
					if(n_num >= digits[i]) n_num -= digits[i];
					else 
					{
						n_num += 10;
						borrow = 1;
						n_num -= digits[i];
					}
				}

				if(n_num > 10)
				{
					//should not happen
					assert(false);
				}

				result.digits[i] = n_num;
			}

			result.sign = Num.sign;
			result.digits[i - 1] == 0 ? result.digits.resize(i - 1) : result.digits.resize(i);

		}
		else if(Num.digits.size() < digits.size())
		{
			int i, borrow = 0;
			for(i = 0; i < digits.size(); i++) 
			{
				int n_num = digits[i];

				if(borrow)
				{
					if(n_num > 0) 
					{	
						n_num--;
						borrow = 0;
					}
					else
					{
						n_num = 9;
						borrow = 1;
					}
				}

				if(Num.digits.size() - 1 >= i)
				{
					//substract
					if(n_num >= Num.digits[i]) n_num -= Num.digits[i];
					else 
					{
						n_num += 10;
						borrow = 1;
						n_num -= Num.digits[i];
					}
				}

				if(n_num > 10)
				{
					//should not happen
					assert(false);
				}

				result.digits[i] = n_num;
			}

			result.sign = sign;
			result.digits[i - 1] == 0 ? result.digits.resize(i - 1) : result.digits.resize(i);
		}
		else //Both are equal in length
		{
			int i;

			for(i = 0; i < digits.size(); i++)
				if(digits[i] != Num.digits[i])
					break;

			if(i == digits.size())
			{
				result.digits[0] = 0;
				result.digits.resize(1);
				result.sign = 1;
			}
			else if(digits[i] > Num.digits[i])
			{
				//this is bigger
				int i, borrow = 0;
				for(i = 0; i < digits.size(); i++) 
				{
					int n_num = digits[i];

					if(borrow)
					{
						if(n_num > 0) 
						{	
							n_num--;
							borrow = 0;
						}
						else
						{
							n_num = 9;
							borrow = 1;
						}
					}

					if(Num.digits.size() - 1 >= i)
					{
						//substract
						if(n_num >= Num.digits[i]) n_num -= Num.digits[i];
						else 
						{
							n_num += 10;
							borrow = 1;
							n_num -= Num.digits[i];
						}
					}

					if(n_num > 10)
					{
						//should not happen
						assert(false);
					}

					result.digits[i] = n_num;
				}

				result.sign = sign;
				result.digits[i - 1] == 0 ? result.digits.resize(i - 1) : result.digits.resize(i);
			}
			else
			{
				//Num is bigger
				int i, borrow = 0;
				for(i = 0; i < Num.digits.size(); i++) 
				{
					int n_num = Num.digits[i];

					if(borrow)
					{
						if(n_num > 0) 
						{	
							n_num--;
							borrow = 0;
						}
						else
						{
							n_num = 9;
							borrow = 1;
						}
					}

					if(digits.size() - 1 >= i)
					{
						//substract
						if(n_num >= digits[i]) n_num -= digits[i];
						else 
						{
							n_num += 10;
							borrow = 1;
							n_num -= digits[i];
						}
					}

					if(n_num > 10)
					{
						//should not happen
						assert(false);
					}

					result.digits[i] = n_num;
				}

				result.sign = Num.sign;
				result.digits[i - 1] == 0 ? result.digits.resize(i - 1) : result.digits.resize(i);
			}
		}
	}
	return result;
}
BigInt BigInt::operator * (const BigInt &Num) const
{
	BigInt result("");
	result.digits.resize(Num.digits.size() + digits.size());

	result.sign = Num.sign * sign;

	int i,j;
	for(i=0 ; i < digits.size(); i++ ) 
	{
		if(digits[i]) //if multiplier is non zero
		{
			int carry = 0;
			for(j = 0 ;j < Num.digits.size() || carry; j++) 
			{
				int n_digit = result.digits[i + j] + digits[i] * Num.digits[j] + carry;
				result.digits[i + j] = n_digit % 10;
				carry = n_digit / 10;
			}
		}
	}

	//Check if any of the numbers is zero then result should be zero
	if(Num.digits.size() == 1 && Num.digits[0] == 0 || digits.size() == 1 && digits[0] == 0)
	{
		result.digits.resize(1);
		result.digits[0] = 0;
		result.sign = 1;
	}
	else
	{
		result.digits.resize(i + j - 1);
	}
	return result;
}

bool BigInt::operator == (const BigInt &R)
{ 
	if( digits.size() != R.digits.size() || sign != R.sign )
		return false;
	
	for(int i = 0; i < digits.size(); i++)
		if(digits[i] != R.digits[i])
			return false;

	return true;
}

bool BigInt::operator < (const BigInt &R)
{
	if(digits.size() < R.digits.size()) return true;
	if(digits.size() > R.digits.size()) return false;
	
	for(int i = digits.size() - 1; i >= 0 ; i--)
		if(digits[i] < R.digits[i])
			return true;

	return false;

}

bool BigInt::operator != (const BigInt &R)
{
	return ! (operator==(R));
}

void BigInt::operator ++()
{
	BigInt Num("1");
	if(sign == 1) // +ve
	{
		digits.resize(digits.size() + 1);

		//Addition will take place
		int len = digits.size();
		int i, carry = 0;
		for(i = 0; i < len - 1 || carry; i++) 
		{
			int n_num = 0;
			if(Num.digits.size() - 1 >= i) n_num += Num.digits[i];
			if(digits.size() - 1 >= i)     n_num += digits[i];

			n_num += carry;

			digits[i] = n_num % 10;
			carry = n_num / 10;
		}
		digits.resize(i);
	}
	else
	{
		assert(false);
	}
}

void BigInt::PrintNumber()
{
	sign == -1 ? printf("-") : printf("+") ;
	for(int i = digits.size() - 1; i >= 0; i--) printf("%d",digits[i]);
	cout<<endl;
}

