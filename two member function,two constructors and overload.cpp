#include<iostream>
using namespace std;
class Test
{
	//declaring a member function
  public:
  	void add(int a ,int b)
	  {
	  	cout<<"addition of two numbers:"<<endl;
	  }
	void add(float a,float b,int c)
	{
		cout<<"addition of three numbers:"<<endl;	
	}
	//declaring a constructor 
	Test()
	{
	cout<<"constructor with zero parameters :"<<endl;	
	}
	Test(int a,int b)
	{
		cout<<"constructor with two parameters:"<<endl;
	}
};
	int main()
{
	Test();
	Test t(5,4) ;
		t.add(2,3);
		t.add(2.4,4.5,6);
		//Test t(5,4);
}
