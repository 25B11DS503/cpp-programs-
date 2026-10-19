#include<iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,3,4,5};
	int choice;
	cout<<"enter 1 for division test,2 for array test:";
	cin>>choice;
	try
	{
		if(choice==1)
		{
			int a=0,b=0;
			if(b==0) throw b;  //throws int
			cout<<a/b<<endl;
		}
		else if(choice == 2)
		{
			int index;
			cout<<"enter index:";
			cin>>index;
			if(index<0||index>=5)
			   throw string("array index out of bounds");//throws string
			   cout<<"value="<<arr[index]<<endl;
		}
		else
		{
			throw 3.14; //throws double
		}
	
	}
catch(int e)
{
	cout<<"caught an integer expection:divisor="<<e<<endl;
}
catch(string &e)
{
	cout<<"caught a string exception:"<<e<<endl;
}
catch(double e)
{
	cout<<"caught a double exception:"<<e<<endl;
}
catch(...)
{
	cout<<"caught an unknown exception"<<endl;
}
return 0;
}
