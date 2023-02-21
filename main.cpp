#include <curses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "checks.h"

fstream file;

using namespace std;

int main(int argc, char *argv[]){

    if(argc == 2){
        if(argc == 1){
            //Help Page
            cout << "MText Editor Help Page" << endl;
            cout << "1. mtext" << endl;
            cout << " Creates a new file\n";
            cout << "2. mtext <path>\n";
            cout << " Opens the selected path.\n";
            cout << "3. mtext --help\n";
            cout << " Opens this menu.";
            return 0;
        }
        else{
            if(!doesFileExist(argv[1])){
                cout << " is an invalid path, that does not exist. Try a different path or just launch MText without arguments.";
                return 1;
            }
            else if(!isFileAccessable(argv[1])){
                cout << "Access denial while opening " << argv[1];
                return 1;
            }
            else{
                //sucess
                file.open(argv[1], ios::in | ios::out | ios::app);
                cout << "Successfully opened the file.\n";
            }
        }
    }
    else if (argc > 2){
        cout << "Too many arguments. Refer to the help page by adding: \"--help\"";
        return 0;
    }
    else{
        //nothing here
    }



    //END
    return 0;
}
