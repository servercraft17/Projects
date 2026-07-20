#ifndef PROJECTS_FUNC_HPP
#define PROJECTS_FUNC_HPP

#include <stdio.h>
#include <string>

std::string PRJ_GetFSRoot();

std::string PRJ_GetDataPath();

std::string PRJ_GetDocumentsPath();

std::string PRJ_ToUNIXPath(std::string path);

// NOTE: this function will return true even if the directory already exists, it only returns false when it failes to create the directory.
bool PRJ_CreateDirectory(std::string path);

bool PRJ_DoesFileExist(std::string path);

#endif/* PROJECTS_FUNC_HPP */
