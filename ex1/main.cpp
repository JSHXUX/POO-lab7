#include <iostream>
using namespace std;
float operator"" _Kelvin(unsigned long long int val)
{
	float res = (float)val - 273.15;
	return res;
}
float operator"" _Fahrenheit(unsigned long long int val)
{
	float res = (float)(val - 32)/1.8;
	return res;
}
int main() 
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	printf("a=%.2f\nb=%.2f", a, b);
	return 0;
}