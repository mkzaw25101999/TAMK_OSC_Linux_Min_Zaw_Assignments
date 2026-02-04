#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

void user_type() {
	cout << "Enter a command line: ";
}

vector<string> read_line() {
	string line;
	getline(cin, line);
	
	if(line.empty()){
		return {};
	}
	
	vector<string> args;
	string word;
	for(char c : line + ' '){
		if(c == ' '){
			if(!word.empty()){
			args.push_back(word);
			word.clear();
		}
	}
	else{
		word += c;
	}
}
	return args;
}

int main() {
	while(true){
		user_type();
	
		vector<string> args = read_line();
		if(args.empty()){
			cout << "Program is stopped!" << endl;
			break;
		}

		pid_t pid = fork();

		if(pid < 0){
			continue;
		}
		if(pid == 0){
			vector<char*> argv;
			for(const string& arg : args){
				argv.push_back((char*)arg.c_str());
			}
			argv.push_back(NULL);
			
			execvp(argv[0], argv.data());
			exit(1);
		}
		else{
			int status;
			waitpid(pid, &status, 0);
		}
	}
		return 0;
}
