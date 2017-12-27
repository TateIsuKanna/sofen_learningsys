#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct problem{
        string question;
        string answer;
        bool issucceeded;
};

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

        for(auto t:problems){
                cout<<t.question<<" "<<t.answer<<endl;
        }
}
