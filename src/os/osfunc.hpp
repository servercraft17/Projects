#ifndef PROJECTS_FUNC_HPP
#define PROJECTS_FUNC_HPP

#include <stdio.h>
#include <string>

std::string PRJGetFSRoot();

std::string PRJGetDataPath();

std::string PRJGetDocumentsPath();

std::string PRJToUNIXPath(std::string path);

void PRJOpenDirectoryInFileBrowser(std::string path);

// NOTE: this function will return true even if the directory already exists, it only returns false when it failes to create the directory.
// NOTE: this function will NOT recursively create directories, it only makes 1, if ".\a\b\c" is given and ".\a\b" doesn't exist, it WILL fail.
bool PRJCreateDirectory(std::string path);

bool PRJCreateEmptyFile(std::string name, std::string path);

bool PRJDoesFileExist(std::string path);

#endif/* PROJECTS_FUNC_HPP */
