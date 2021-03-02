#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

char home_path[] = "/home/";

char command[100];
char hostname[1024];
char* username = getlogin();

void help() {
    std::cout << "This shell rewrite to a2p1k02" << std::endl;
}

/*This Function Prints the Current Working Directory*/
void get_cwd()  
{
    char s[100]; 

    std :: cout << getcwd(s, 100) << std :: endl; 
}

/*This Function Changes the Directory*/
void change_dir()
{
    char dir[100];
    std :: cout << "Enter the Dirctory: ";
    std :: cin >> dir;  // Input Format Example: C:\Windows
    chdir(dir); 
  
}


int main() {
    std::string line;
    std::string args = line.substr(3, line.find(" "));
    
    get_cwd();      // Calling Function to Print Current Working Directory 
    change_dir();   // Calling Function to Change the Directory 
    get_cwd();

    
    while(true) {
        gethostname(hostname, 1024);
        std::cout << username << "@" << hostname << " ~ $ ";
        std::cin >> line;
        if (line == "exit") {
            return 1;
            break;
        } else if(line == "help") {
            help();
        } else {
            std::system(line.c_str());
        }
    }

    return 0;
}
