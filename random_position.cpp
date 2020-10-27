#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<string> p1vector;
	vector<string> p2vector;
	vector<string> pattern;
	p1vector.clear();
	p2vector.clear();
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			p1vector.push_back(to_string(i)+" "+to_string(j));
		}
	}
	for(int i=0;i<6;i++){
		for(int j=3;j<6;j++){
			p2vector.push_back(to_string(i)+" "+to_string(j));
		}
	}
	random_shuffle(p1vector.begin(),p1vector.end());
	random_shuffle(p2vector.begin(),p2vector.end());
	for(int i=0;i<9;i++){
		pattern.push_back(p1vector[i]) ;
	}
	for(int i=0;i<9;i++){
		pattern.push_back(p2vector[i]) ;
	}
	for(int i=0;i<pattern.size();i++){
		cout << pattern[i] << " ";
	}
	return 0;
}