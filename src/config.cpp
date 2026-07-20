#include "config.hpp"

#include "os/osfunc.hpp"
#include <iostream>
#include <fstream>

void Config::LoadDefaultValues() {
    std::string documents = PRJ_GetDocumentsPath();
    if (documents.empty()) {
        documents = PRJ_GetFSRoot();
    }
    projects_dir = documents + "Projects\\";
}

void Config::SaveDefaultValues() { //! UNFINISHED
    std::string datapath = PRJ_GetDataPath();
    if (datapath.empty()) {
        printf("ERROR! Failed to load config values!");
        return;
    }
    if (!PRJ_DoesFileExist(datapath+"config.json")) {
        remove((datapath+"config.json").c_str());
        return;
    }

    std::ofstream configFile(datapath+"config.json");
}

void Config::LoadConfigValues() { //! UNFINISHED
    std::string datapath = PRJ_GetDataPath();
    if (datapath.empty()) {
        printf("ERROR! Failed to load config values!");
        return;
    }
    if (!PRJ_DoesFileExist(datapath+"config.json")) {
        SaveDefaultValues();
        return;
    }
}
    
