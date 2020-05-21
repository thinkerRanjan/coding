#include<iostream>
#include<stdio.h>
#include<string.h>
#include<functional>

using namespace std;

void urlify(string str, int l)
{
	for(int i=0;i<l;i++)
	{
		if(str[i] == ' ')
		{
			char a, b;
			str[i] = '%';
			a = str[i+1];
			b = str[i+2];
			str[i+1] = '2';
			str[i+2] = '0';

			l += 2; // update l as string gets longer by addition

			for(int j=i+3;j<l;j+=2)
			{
				char c, d;
				c = str[j];
				d = str[j+1];
				str[j]   = a; 
				str[j+1] = b;
				a = c; 
				b = d;
			}
		}
	}
	
	cout << "Final String = " << str << endl;
}

int main(int argc, char** argv){
	
	int l;
	string str;
	cout << "Enter the string: " << endl;
	getline(cin, str);
	cout << "Enter the true length of string: " << endl;
	cin >> l;

	urlify(str, l);

	return 0;
}
