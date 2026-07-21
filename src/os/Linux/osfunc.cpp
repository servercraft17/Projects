#include "../osfunc.hpp"

#include <unistd.h>

bool PRJDoesFileExist(std::string path) {
    if (access(PRJToUNIXPath(path).c_str(), F_OK) == 0) return true;
    return false;
}