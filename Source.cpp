#include <iostream>
using namespace std;

unsigned long long factorial(unsigned int n)
{
	unsigned long long ret = 1;
	for (unsigned int i = 1; i <= n; ++i)
		ret *= i;
	return ret;
}

class bignum
{
public:
	int length;
	int digit[302];

	void multiply(int fact){
		int len = length;
		int temp1[300] = {};
		int temp2[300] = {};
		int factor = fact % 10;
		temp1[len+1] = digit[len] * factor;

		while (len>=0)
		{
			if (len>0)
			{
				temp1[len] = digit[len - 1] * factor + temp1[len + 1] / 10;
				temp1[len + 1] = temp1[len + 1] % 10;
			}
			else
			{
				temp1[len] = temp1[len + 1] / 10;
				temp1[len + 1] = temp1[len + 1] % 10;
			}	
			len--;
		}
		factor = fact / 10;
		len = length;
		if (factor){			
			temp2[len + 1] = digit[len] * factor;

			while (len >-1)
			{
				if (len>0)
				{
					temp2[len] = digit[len - 1] * factor + temp2[len + 1] / 10;
					temp2[len + 1] = temp2[len + 1] % 10;
				}
				else
				{
					temp2[len] = temp2[len + 1] / 10;
					temp2[len + 1] = temp2[len + 1] % 10;
				}
				len--;
			}

			len = length;
			digit[len + 2] = temp1[len + 1];
			len--;
			while (len>-3)
			{
				if (len>-2)
				{
					digit[len + 2] = temp1[len + 1] + temp2[len + 2]+ digit[len+3]/10;
					digit[len + 3] = digit[len + 3] % 10;
				}
				else if (len>-3)
				{
					digit[len + 2] = temp2[len + 2] + digit[len + 3] / 10;
					digit[len + 3] = digit[len + 3] % 10;
				}
				len--;
			}
			length = length + 2;
		}
		else
		{
			len = length;
			while (len)
			{
				digit[len] = temp1[len + 1];
				len--;
			}
			digit[0] = 0;
			length = length + 1;
		}
	}



	void init(int s)
	{
		int tp = 203;
		while (tp)
		{
			digit[tp-1] = 0;
			tp--;
		}

		if (s==100)
		{
			digit[0] = 1;
			digit[1] = 0;
			digit[2] = 0;
			length = 2;
		}
		else
		{
			length = 1;
			digit[1] = s % 10;
			digit[0] = s / 10;
		}
	}

	void printdigit(){
		length = length - 8;
		int i2 = length;
		int ot;
		while (digit[length - i2]==0)
		{
			i2--;
		}
		while (i2)
		{		
			ot = digit[length - i2];
			cout<<ot;
			i2--;
		}	
	}
};

int main(){
	int a;
	int s= 0;
	cin >> a;
	bignum ans;

	while (a>0)
	{	
		cin >> s;
		if (s>17)
		{
			ans.init(s);
			int temp2 = s;
			while (temp2>1)
			{
				ans.multiply(temp2 - 1);
				temp2--;
			}
			ans.printdigit();			
		}
		else
		{
			cout << factorial(s);
		}
		cout << endl;
		a--;
	}
}
