#include<iostream>
#include<string>
class student
{
	private:
		std::string name; int Rollnumber;
		public:  
			void setData(std::string n,int r)
			{
				name=n;
				Rollnumber=r;
			}
			void getData()
			{
				std::cout<<"Rollnumber:"<<Rollnumber<<"name:"<<name<<std::endl;
			}
};
int main()
{
	student list[3];
	list[0].setData("keerthi",503);
	list[1].setData("navya",040);
	list[2].setData("asritha",136);

for (int i=0;i<3;i++)
	{
		list[i].getData();
	
	}
}
	

