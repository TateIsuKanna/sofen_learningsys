#include <regex>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <stdio.h>

#include <dirent.h>

#include "quiz.hpp"

using namespace std;

//本当はC++17のfilesystem使いたい!!!!!
void ls(){
	dirent** namelist;
	int dir_n = scandir("questions/", &namelist, nullptr, [](const struct dirent **a, const struct dirent **b){return -alphasort(a,b);});
	if(dir_n<0){
		throw runtime_error("ディレクトリを読めません");
	}
	while(dir_n--){
		string dir_name_str=string(namelist[dir_n]->d_name);
		if(regex_match(dir_name_str,regex(R"(.+\.csv)"))){
			cout<<regex_replace(dir_name_str,regex(R"(questions/|\.\S*)"),"")<<" ";
		}
		free(namelist[dir_n]);
	}
	free(namelist);
	cout<<endl;
}

int main(){
	try{
		ls();
		cout<<"ファイル名を入力"<<endl;
		string file_name;
		cin>>file_name;

		quiz q(file_name);
		q.question();
	}catch(runtime_error& e){
		cerr<<e.what()<<endl;
	}
}
