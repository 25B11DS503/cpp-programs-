#include<iostream>
class Test
{
	public:
void m1()
{
	std::cout<<"this is m1 method"<<std::endl;
}
  inline static void m2()
{
	std::cout<<"this is m2 method"<<std::endl;
}	
};
int main()
{
	Test*t=new Test;
	t->m1();// m1 is non static method ,call it with object 
	Test::m2();// m2 is a static method,call it with class (by using scope resolution)	
}
