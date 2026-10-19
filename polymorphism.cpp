//progam for polymorphism
#include <iostream>
#include <conio.h>
class Calculator
{
	public:
		void Add(int  a,int b)
		{
			std::cout<<"sum of two numbers:"<<a+b<<std::endl;
		}
		void Add(int a,float b,double c  )
		{
		std::cout<<"sum of three numbers:"<<a+b+c<<std::endl;	
		}
};
int main()
{
	Calculator cal;
	cal.Add(503,94);
	cal.Add(20,9.2,8.7);
	getch;
}
