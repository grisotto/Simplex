#include <iostream>
#include <string>

using namespace std;
	int main(){
		
		string str = "x*1 + x*2 + x*3  <= 100;";
	size_t pos2 = 0;
	string token;
	string delimiter = "<=";
	
	while ((pos2 = str.find(delimiter)) != string::npos) {
	   token = str.substr(0, pos2);
	   cout <<"token: "<< token << endl;
	   str.erase(0, pos2 + delimiter.length());
	}
	cout <<"str2: "<< str << endl;
	cout <<"token: "<< token << endl;

	}

	   