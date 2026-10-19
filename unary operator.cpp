#include<iostream>
using namespace std;
class bankaccount
{
	private:
		double balance;
	public:
		bankaccount(double balance)
		{
			this->balance=balance;
		}
	void operator + ()
	{
		balance=balance+100.00;
	}
	void display()
	{
		cout<<"rs:"<<this->balance<<endl;	
	}
};
int main()
{
bankaccount mybalance(600);
cout<<"currentbalance"<<endl;
mybalance.display();
+mybalance;
mybalance.display();
}

