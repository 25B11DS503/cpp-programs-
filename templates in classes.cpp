#include<iostream>
using namespace std;
//class template
template<typename T>
class Pair {
	private:
		T first,second;
	public:
		Pair(T a,T b):first(a),second(b)
		{
		}
		void display()
		{
			cout<<"first:"<<first<<"second:"<<second<<endl;
		}
};
int main()
{
	Pair<int>p1(10,20);
	p1.display();    //pair of integers  
	Pair<string>p2("hello","c++");
	p2.display();    //pair of strings
}
