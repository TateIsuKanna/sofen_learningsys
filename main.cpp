#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

struct problem{
	string question;
	string answer;
	bool issucceeded;
};

vector<int> make_rand_array(int min,int max){
	if(min>max) swap(min,max);
	vector<int> v;
	for(int i=min;i<=max;i++) v.push_back(i);
	random_device get_rand_mt;
	shuffle(v.begin(),v.end(),get_rand_mt);
	return v;
}

int main(){
	cout<<"開きたいファイル名を入力してください。"<<endl;
	string file_name;
	cin>>file_name;

	string file_path="questions/"+file_name+".csv";
	ifstream ifs(file_path);
	if(!ifs){
		cerr<<"ぬるぽ"<<"("<<file_path<<"なんてファイルないです)"<<endl;
		return -1;
	}

	vector<problem> problems;
	while(!ifs.eof()){
		problem t;
		ifs >> t.question;
		ifs >> t.answer;
		t.issucceeded=false;//TODO:
		problems.push_back(t);
	}

	const int q_number=10; //出題数
	vector<int> rand=make_rand_array(0,problems.size()-1);
	for(int i=0;i<q_number;i++){
		cout<<"漢字："<<problems[rand[i]].question<<endl;
	}

	// for(auto t:problems){
	// 	cout<<t.question<<" "<<t.answer<<endl;
	// }
}
