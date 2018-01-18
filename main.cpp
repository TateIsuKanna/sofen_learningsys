#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

//classで色々するのは今回はちょっと遠慮しておきます

struct problem{
        string question;
        string answer;
        bool issucceeded;
};
vector<problem> problems;

void reset_save(){
        for(auto& t:problems){
                t.issucceeded=false;
        }
}

void save(string file_path){
        ofstream ofs(file_path);
        for(auto p:problems){
                ofs<<p.issucceeded<<endl;
        }
}

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

        const int q_number=10; //全出題数
        vector<int> rand=make_rand_array(0,problems.size()-1);
        for(int i=0,q=0;q<q_number&&i<(int)problems.size();i++){
                if(problems[rand[i]].issucceeded) continue;
                cout<<"漢字："<<problems[rand[i]].question<<endl;
                string response;
                cout<<"読み：";
                cin>>response;
                if(response==problems[rand[i]].answer){
                        cout<<"正解！"<<endl; problems[rand[i]].issucceeded=true;
                }else{
                        cout<<"残念！正解は「"<<problems[rand[i]].answer<<"」"<<endl; problems[rand[i]].issucceeded=false;
                }
                q++;
        }

        reset_save();

        for(auto t:problems){
                cout<<t.question<<" "<<t.answer<<" "<<t.issucceeded<<endl;
        }
        save(save_file_path);
}
