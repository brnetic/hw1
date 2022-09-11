/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	
ULListStr dat;

for(int i = 0;i<13;i++){
	
	dat.push_back(to_string(i));
	dat.push_front(to_string(i));
}
for(unsigned int i = 0;i<dat.size();i++)
	{

		cout<<dat.get(i)<<endl;
	}

cout<<endl;
for(int i = 0;i<5;i++){
	dat.pop_back();
	dat.pop_front();
}
for(unsigned int i = 0;i<dat.size();i++)
	{
		cout<<dat.get(i)<<endl;
	}

cout << dat.front() << " " << dat.back() << endl;
return 0;
}
