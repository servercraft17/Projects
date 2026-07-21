#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

namespace PRJConfig {
    inline std::string projects_dir;

    void LoadDefaultValues();
    void SaveDefaultValues();
    void LoadConfigValues();
}



#endif/* CONFIG_HPP */
