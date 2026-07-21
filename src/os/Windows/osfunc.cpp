#include "../osfunc.hpp"

#include <shlobj.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif


std::string PRJGetFSRoot() {
    return "C:\\";
}

std::string PRJGetDataPath() {
    const char APPNAME[] = "\\Projects";
    char path[MAX_PATH];
    size_t new_path_len;
    BOOL result = FALSE;

    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA | CSIDL_FLAG_CREATE, NULL, 0, path))) {
        printf("ERROR! Failed to locate datapath!\n");
        return "";
    }
     
    new_path_len = strlen(path) + strlen(APPNAME);

    if ((new_path_len+1) > MAX_PATH) {
        printf("ERROR! Path too long!\n");
        return "";
    }
    
    strcat(path, APPNAME);
    
    result = CreateDirectoryA(path, NULL);
    if (result == FALSE && GetLastError() != ERROR_ALREADY_EXISTS) {
        printf("ERROR! Couldn't create datapath!\n");
        return "";
    }

    strcat(path, "\\");
    return path;
}

std::string PRJGetDocumentsPath() {
    char path[MAX_PATH];
    BOOL result = FALSE;
    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path))) {
        printf("ERROR! Failed to locate documents path!\n");
        return "";
    }
    strcat(path, "\\");
    return path;
}

void PRJOpenDirectoryInFileBrowser(std::string path) {
    if (!PRJDoesFileExist(path)) {
        printf("ERROR! Failed to open directory in file browser, given directory does not exist.\n");
        return;
    }

    if (path.length() > MAX_PATH) {
        printf("ERROR! Failed to open directory in file browser, given path is to long.\n");
        return;
    }

    char newpath[MAX_PATH+10] = "\"C:\\\" \"";
    strcat(newpath, path.c_str());
    strcat(newpath, "\"");

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    
    CreateProcessA("C:\\Windows\\explorer.exe",
        newpath,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    return;
}

bool PRJCreateDirectory(std::string path) {
    BOOL result = FALSE;
    result = CreateDirectoryA(path.c_str(), NULL);
    if (result == FALSE && GetLastError() != ERROR_ALREADY_EXISTS)
        return false;
    return true;
}

bool PRJCreateEmptyFile(std::string name, std::string path) {
    if (!PRJDoesFileExist(path) || name.empty()) return false;
    if (path[path.length()-1] != '\\') path += '\\';
    std::ofstream file(path+name);
    file.close();
    return true;
}

bool PRJDoesFileExist(std::string path) {
    if (access(path.c_str(), F_OK) == 0) return true;
    return false;
}