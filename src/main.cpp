#include <stdio.h>
#include <string>
#include <optional>
#include "os/osfunc.hpp"
#include "config.hpp"

int PRJCreateNecessaryDirectories() {
    std::string datadir = PRJGetDataPath();
    if (datadir.empty()) return 9999;
    int failures = 0;

    std::string datadirs[] = {"Cache", "Templates", "Languages"};

    for (int i =0; i<(sizeof(datadirs)/sizeof(std::string)); i++) {
        failures++;
        if (PRJCreateDirectory(datadir+datadirs[i])) failures--;
    }

    return failures;
}

std::optional<std::string> PRJCreateProject(std::string name, std::optional<std::string> override_location = std::nullopt) {
    std::string location = PRJConfig::projects_dir;
    bool status = false;
    //$ Checks
    if (override_location) {
        location = *override_location;
        if (location[location.length()-1] != '\\') location += '\\';
    }

    if (name.empty()) {
        printf("ERROR! (PRJCreateProject) name cannot be empty!\n");
        return std::nullopt;
    }
    //$ Checks end

    if (!PRJDoesFileExist(location)) {
        status = PRJCreateDirectory(location);
        if (!status) {
            printf("ERROR! (PRJCreateProject) unable to create project parent directory. aborting.\n");
            return std::nullopt;
        }
        status = false;
    }

    status = PRJCreateDirectory(location+name);
    if (!status) {
        printf("ERROR! (PRJCreateProject) unable to create project directory\n");
        return std::nullopt;
    }



    PRJOpenDirectoryInFileBrowser(location+name);
    return location+name;
}

int main(int argc, char *argv[]) {
    
    printf("%d\n", PRJCreateNecessaryDirectories());
    PRJConfig::LoadDefaultValues();
    auto projdir = PRJCreateProject("test project");
    if (projdir) {
        printf("%s\n", (*projdir).c_str());
    } else printf("Failed to create project.\n");

    return 0;
}