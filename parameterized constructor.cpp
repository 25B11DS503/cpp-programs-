#include<iostream>
#include<string>
class student
{
	public:
		int sid;
		std::string sname;
student(int sid,std::string sname)
{
	sid;
	sname;
}
void display()
{
	std::cout<<"sid is:"<<sid<<std::endl;
	std::cout<<"sname is:"<<sname<<std::endl;
}	
};
int main()
{
student*s1=new student(101,"ajay");
s1->display();
student*s2=new student(102,"vijay");
s2->display();
}


