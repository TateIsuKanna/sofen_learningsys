#include"quiz.hpp"
#include"AA.hpp"
vector<int> quiz::make_rand_array(int min,int max){
	if(min>max) swap(min,max);
	vector<int> v;
	for(int i=min;i<=max;i++) v.push_back(i);
	random_device seed_gen;
	mt19937 engine(seed_gen());
	shuffle(v.begin(),v.end(),engine);
	return v;
}
quiz::quiz(string name){
	string file_path_without_extension="questions/"+name;
	string data_file_path=file_path_without_extension+".csv";
	ifstream data_st(data_file_path);
	if(!data_st){
		throw runtime_error("ぬるぽ("+data_file_path+"はないお。)");
	}
	save_file_path=file_path_without_extension+".txt";
	ifstream save_st(save_file_path);
	while(true){
		problem p;
		data_st >> p.question;
		if(data_st.eof()){
			break;
		}
		data_st >>p.answer;
		if(save_st){
			save_st >> p.issucceeded;
		}
		else{
			p.issucceeded=false;
		}
		problems.push_back(p);
	}
}
bool quiz::allsucceeded(){
	for(auto p:problems){
		if(!p.issucceeded) return false;
	}
	return true;
}
void quiz::reset_save(){
	for(auto& t:problems){
		t.issucceeded=false;
	}
}

void quiz::save(string file_path){
	ofstream ofs(file_path);
	for(auto p:problems){
		ofs<<p.issucceeded<<endl;
	}
}
void quiz::question(){
	const int q_number=10; //全出題数
	vector<int> rand=make_rand_array(0,problems.size()-1);
	int q=0;
	for(auto r:rand){
		if(problems[r].issucceeded) continue;
		cout<<"漢字："<<problems[r].question<<endl;
		string response;
		cout<<"読み：";
		cin>>response;
		string whole_answer=problems[r].make_whole_answer();
		if(response==problems[r].answer||response==whole_answer){
			cout<<"正解！"<<endl; problems[r].issucceeded=true;
		}else{
			cout<<"残念！正解は「"<<whole_answer<<"」"<<endl; problems[r].issucceeded=false;
		}
		if(++q>=q_number) break;
	}

	if(allsucceeded()){
		reset_save();
		AA::printAA();
	}

	save(save_file_path);
}
string quiz::problem::make_whole_answer(){
	cout<< ":"<<regex_replace(question,regex(R"([^あ-ん]+)"),answer)<<" ";
	return regex_replace(question,regex(R"([^あ-ん]+)"),answer);
}
