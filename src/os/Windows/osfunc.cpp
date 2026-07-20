#include "../osfunc.hpp"

#include <shlobj.h>
#include <string.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif


std::string PRJ_GetFSRoot() {
    return "C:\\";
}

std::string PRJ_GetDataPath() {
    const char APPNAME[] = "\\Projects";
    char path[MAX_PATH];
    size_t new_path_len;
    BOOL result = FALSE;

    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA | CSIDL_FLAG_CREATE, NULL, 0, path))) {
        printf("ERROR! Failed to locate datapath!");
        return "";
    }
     
    new_path_len = strlen(path) + strlen(APPNAME);

    if ((new_path_len+1) > MAX_PATH) {
        printf("ERROR! Path too long!");
        return "";
    }
    
    strcat(path, APPNAME);
    
    result = CreateDirectoryA(path, NULL);
    if (result == FALSE && GetLastError() != ERROR_ALREADY_EXISTS) {
        printf("ERROR! Couldn't create datapath!");
        return "";
    }

    strcat(path, "\\");
    return path;
}

std::string PRJ_GetDocumentsPath() {
    char path[MAX_PATH];
    BOOL result = FALSE;
    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path))) {
        printf("ERROR! Failed to locate documents path!");
        return "";
    }
    strcat(path, "\\");
    return path;
}

bool PRJ_CreateDirectory(std::string path) {
    BOOL result = FALSE;
    result = CreateDirectoryA(path.c_str(), NULL);
    if (result == FALSE && GetLastError() != ERROR_ALREADY_EXISTS)
        return false;
    return true;
}

bool PRJ_DoesFileExist(std::string path) {
    if (access(path.c_str(), F_OK) == 0) return true;
    return false;
}