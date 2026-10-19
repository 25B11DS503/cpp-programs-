#include<iostream>
using namespace std;
class person//abstract class
{
	public:
		virtual void showduty()=0;//abstract method
};
class student:public person
{
	 public :void showduty()
	{
		cout<<"attending class work"<<endl;
	}
};
int main()
{
	student s;
	person p;
	p.showduty();
	s.showduty();
}
	
