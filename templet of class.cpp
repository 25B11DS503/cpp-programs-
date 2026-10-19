#include<iostream>
using namespace std;
template < class T>
	class calculator
	{
		T a,b;
		public:
			calculator(T x,T y)
			{
			a=x;
			b=y;	
			}
			T add()
			{
				return a+b;
			}
    };
	int main()
	{
		calculator<int> c1(12,20);
        calculator<float>c2(12.1,20.1);
	    cout<<"addition of integers:"<<c1.add()<<endl;
 cout<<"addition of float values:"<<c2.add()<<endl;	
}

