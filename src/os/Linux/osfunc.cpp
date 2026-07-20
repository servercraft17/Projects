#include "../osfunc.hpp"

#include <unistd.h>

bool PRJ_DoesFileExist(std::string path) {
    if (access(PRJ_ToUNIXPath(path).c_str(), F_OK) == 0) return true;
    return false;
}