#include <regex>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <stdio.h>
using namespace std;
class quiz{
	vector<int> make_rand_array(int min,int max);
	struct problem{
		string question;
		string answer;
		bool issucceeded;
	};
	public:
		vector<problem>problems;
		quiz(string name);
		bool allsucceeded();
		void reset_save();

		void save(string file_path);
		void question();

};
