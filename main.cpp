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
        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(v.begin(),v.end(),engine);
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

        const int q_number=10; //全出題数
        vector<int> rand=make_rand_array(0,problems.size()-1);
        for(int i=0,q=0;q<min(q_number,(int)problems.size());i++){
                if(problems[rand[i]].issucceeded) continue;
                cout<<"漢字："<<problems[rand[i]].question<<endl;
                string response;
                cout<<"読み：";
                cin>>response;
                if(response==problems[rand[i]].answer){
                        cout<<"正解！"<<endl; problems[rand[i]].issucceeded=true;
                }else{
                        cout<<"残念！"<<endl; problems[rand[i]].issucceeded=false;
                }
                q++;
        }

        for(int i=0;i<min(q_number,(int)problems.size());i++){
                cout<<problems[rand[i]].question<<" "<<problems[rand[i]].answer<<" "<<problems[rand[i]].issucceeded<<endl;
        }

        // for(auto t:problems){
        //         cout<<t.question<<" "<<t.answer<<endl;
        // }
}
