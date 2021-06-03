#include <iostream>

int main(){

	char k = 'a';
	for (int i = 0; i < 8; ++i)
	{
		if (k & 0x80){
			std::cout<<'1';
		}
		else
		{
			std::cout<<'0';
		}
		k<<=1;
	}
	return 0;	
}

