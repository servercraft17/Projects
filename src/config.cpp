#include "config.hpp"

#include "os/osfunc.hpp"
#include <iostream>
#include <fstream>



void PRJConfig::LoadDefaultValues() {
    std::string documents = PRJGetDocumentsPath();
    if (documents.empty()) {
        documents = PRJGetFSRoot();
    }
    projects_dir = documents + "Projects\\";
}

void PRJConfig::SaveDefaultValues() { //! UNFINISHED
    std::string datapath = PRJGetDataPath();
    if (datapath.empty()) {
        printf("ERROR! Failed to load config values!\n");
        return;
    }
    if (!PRJDoesFileExist(datapath+"config.json")) {
        remove((datapath+"config.json").c_str());
        return;
    }

    std::ofstream configFile(datapath+"config.json");
}

void PRJConfig::LoadConfigValues() { //! UNFINISHED
    std::string datapath = PRJGetDataPath();
    if (datapath.empty()) {
        printf("ERROR! Failed to load config values!\n");
        return;
    }
    if (!PRJDoesFileExist(datapath+"config.json")) {
        SaveDefaultValues();
        return;
    }
}
    
