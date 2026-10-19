#include<iostream>
using namespace std;
class student
{
	public:
		void showstudent()
		{
			cout<<"student details:"<<endl;
		}
};
class marks:public student
{
	public:
		void showmarks()
		{
			cout<<"marks:85"<<endl;
		}
};
int main()
{
	marks m1;
	m1.showstudent();
	m1.showmarks();
	return 0;
}
