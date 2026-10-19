#include<iostream>
using namespace std;
template<typename T>
T getmax(T a, T b)
{
	return(a>b)?a:b;
}
int main()
{
	cout<<getmax<int>(10,25)<<endl;
	cout<<getmax<float>(10.5,7.8)<<endl;
	cout<<getmax<double>(2.3,0)<<endl;
}
