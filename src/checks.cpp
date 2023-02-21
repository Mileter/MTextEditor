#include <sys/stat.h>
#include <string>
#include <fstream>
#include "checks.h"

inline bool doesFileExist(const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

inline bool isFileAccessable(const std::string& name) {
    ifstream file(name);
    string test = std::getline(file);
    if(test != ""){
        return false;
    }
    file.close();
    return true;
}
