#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//classで色々するのは今回はちょっと遠慮しておきます

struct problem{
        string question;
        string answer;
        bool issucceeded;
};
vector<problem> problems;

void save(string file_path){
        ofstream ofs(file_path);
        for(auto p:problems){
                ofs<<p.issucceeded<<endl;
        }
}

int main(){
	cout<<"開きたいファイル名を入力してください。"<<endl;
	string file_name;
        cin>>file_name;

        string file_path_without_extension="questions/"+file_name;
        string data_file_path=file_path_without_extension+".csv";
        ifstream data_st(data_file_path);
        if(!data_st){
		cerr<<"ぬるぽ"<<"("<<data_file_path<<"なんてファイルないです)"<<endl;
		return -1;
        }
        string save_file_path=file_path_without_extension+".txt";
        ifstream save_st(save_file_path);
        while(true){
                problem p;
                data_st >> p.question;
                if(data_st.eof()){
                        break;
                }
                data_st >> p.answer;
                if(save_st){
                        save_st >> p.issucceeded;
                }else{
                        p.issucceeded=false;
                }
                problems.push_back(p);
        }

        for(auto p:problems){
                cout<<p.question<<" "<<p.answer<<" "<<p.issucceeded<<endl;
        }

        save(save_file_path);
}
