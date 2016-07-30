#include<iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

#define LIST

#define MAP 1

int main(int argc, char *argv[])
{	

	#ifdef VECTOR
		
	cout << "Welcome to my stl test "<<endl;

	int Array[] = {1,5,8,9,4,89};
	vector <int>  intVector1;

	vector <int> intVector2(Array,Array+5);

	cout<<"V2的容量是"<<intVector2.capacity()<<endl;

	cout<<"V2的数据:"<<endl;

	for (decltype(intVector2.size()) i = 0; i < intVector2.size();i++)
	{
		cout<<"  "<<intVector2[i];
	}
	
	cout<<endl;

	intVector1.swap(intVector2);
	
    for (decltype(intVector1.size()) i = 0; i < intVector1.size();i++)
	{
		cout<<"  "<<intVector1[i];
	}

    cout<<endl;

	cout<<"after resize"<<endl;

	intVector1.resize(2);

	for (decltype(intVector1.size()) i = 0; i < intVector1.size();i++)
	{
		  cout<<"  "<<intVector1[i];
	}

	cout<<endl;

	intVector1.resize(5);

	intVector1.pop_back();

	cout<<"the size of V1 is " <<intVector1.size()<<endl;

	intVector1.push_back(3);

	intVector1.erase(intVector1.begin());
	
	for (decltype(intVector1.size()) i = 0; i < intVector1.size();i++)
	{
		  cout<<"  "<<intVector1[i];
	}

	cout<<endl;

	int a = intVector1.back();

	cout<<"number is "<<a<<endl;

	cout<<"at "<<endl;

	cout<<intVector1.at(1)<<endl;
	cout<<intVector1.at(0)<<endl;

	#endif


	#ifdef LIST

	list <int> Listint1(5,8);


	Listint1.pop_back();
	Listint1.pop_front();

	cout<<"the size of list1 is " << Listint1.size()<<endl;

	Listint1.push_back(3);
	Listint1.push_front(9);

	for(auto it=Listint1.begin(); it != Listint1.end();it++)
	{
		cout<<" "<<*it;
	}

	cout<<endl;


	cout<<"change the third value"<<endl;

	list <int>::iterator iter = Listint1.begin();
	for (int i = 0; i < 2; i++)
	{
		iter++;
	}

	*iter = 98;

	Listint1.insert(Listint1.end(),56);

	Listint1.sort();
	
	for(auto it=Listint1.begin(); it != Listint1.end();it++)
	{
		cout<<" "<<*it;
	}

	cout<<endl;

	#endif
	
	#ifdef MAP

	string Name("agent");

	pair<int,string> pair1(123,Name);

	pair<int,string> pair2(234,"gg");

	map <int,string> map1;

	map1.insert(pair1);
	map1.insert(pair2);
	
	auto Mapit =map1.find(123);

	string TempName = Mapit->second;

	int tempData = 0;
	
	tempData = Mapit->first;

	cout <<"Name is "<<TempName <<endl;
	cout <<"temp is "<<tempData <<endl;
	
	#endif
	
	return 1;

}
