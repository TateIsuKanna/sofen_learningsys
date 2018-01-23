#include <regex>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <stdio.h>
#include "quiz.hpp"
using namespace std;

//本当はC++17のfilesystem使いたい!!!!!
void ls(){
	FILE* pf=popen("ls -w 0 -C questions/*.csv","r");
	char* file_list;
	size_t size;
	getline(&file_list,&size,pf);
	pclose(pf);
	cout<<regex_replace(string(file_list),regex(R"(questions/|\.\S*)"),"")<<endl;
}


int main(){
	ls();
	cout<<"ファイル名を入力"<<endl;
	string file_name;
	cin>>file_name;
	
	quiz q(file_name);
	q.question();
}
