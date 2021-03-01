#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#define GetCurrentDir getcwd
#endif

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

/*This Function Returns the Current Working Directory*/
std::string get_current_dir() {

   char buff[FILENAME_MAX];     // Creates a String Buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}

/*This Function is used to Change the Directory*/
void change_dir()
{
    char ch_dir[FILENAME_MAX];
    std::cin >> ch_dir;     // Input Format: C:\Windows OR any other Directory
    chdir(ch_dir);
}

int main() {
    std::string line;
    std::string args = line.substr(3, line.find(" "));
    
    change_dir();   // Calls the Function to change the Directory
    std::cout << get_current_dir() << std::endl;    // get_current_dir() Function is Called
    
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
