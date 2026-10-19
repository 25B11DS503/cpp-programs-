#include<iostream>
class Parent
{
	public:void publicfunc()
	{
	std::cout<<"this is public function"<<std::endl;
	}
	private:void privatefunc()
	{
	std::cout<<"this is private function"<<std::endl;
	}
	public:
	void ToAccessprivate()
	{
		privatefunc();
	}
	protected:void protectedfunc()
	{
	std::cout<<"this is protected function"<<std::endl;
	}
};
class child:public Parent
{   
    public:
	void ToAccessprotected()
	{
		protectedfunc();
	}
};
int main()
{
	child*c=new child;
	c->publicfunc();
	c->ToAccessprivate();
	c->ToAccessprotected();
}
