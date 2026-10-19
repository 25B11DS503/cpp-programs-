#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
	int a,b;
	cout<<"enter two numbers:"<<endl;
	cin>>a>>b;
	try{
    if(b==0)
    {
    	throw runtime_error("division by zero is not allowed ");
    	cout<<"result="<<a/b<<endl;
	}
}
catch(runtime_error &e)
{
	cout<<"exception caught:"<<e.what()<<endl;
}
	cout<<" program continues after exception handling"<<endl;
	return 0;
}
