#include<iostream>
using namespace std;
template<typename T>
T add(T a,T b )
{
	return a+b;
}
template<typename T>
T add(T a,T b,T c)
{
	return a+b+c;
}
int main()
{
	cout<<add<int>(1,2,3)<<endl;
	cout<<add<float>(2.5f,3.2f)<<endl;
	cout<<add<string>("keerthi","navya")<<endl;
}
