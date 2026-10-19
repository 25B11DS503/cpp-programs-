#include<iostream>
#include<string>
using namespace std;
class Parent
{
 private:
 	void privatefunc()
 	{
 		cout<<"this is provate function:"<<endl;
	 }
	 public:
	 	void toaccessprivate()
	 	{
	 		privatefunc();
		 }
};
int main()
{
Parent p;
p.toaccessprivate();
}
