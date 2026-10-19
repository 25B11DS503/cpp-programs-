#include<iostream>
using namespace std;
class rectangle
{
	public:
		int length;
		int breadth;//member variables 
		rectangle(int length,int breadth)//to create rectangle object //local variables 
		{
		this->length=length;
		this->breadth=breadth;
		}
	void display()
	{
		cout<<"the area of rectangle is"<<length*breadth<<endl;	
	}
};
int main()
{
rectangle r(4,5);
r.display();	
}
