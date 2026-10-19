#include<iostream>
using namespace std;
class bankaccount
{
	private:
		double balance;
	public:
	   bankaccout(double balance )
	   {
	   	this->balance=balance;
	   }
	   bankaccount operator++(int)
	   {
	   	bankaccount temp=*this;
	   	balance=balance+100.00;
	   	return temp;
	   }
	   void display()
	   {
	   	cout<<"rs:"<<this->balance<<endl;
	    }
};
int main()
{
bankaccount mybalance();
mybalance.display();
mybalance+;
mybalance.display();
}
	
