#include <stdio.h>
#include "os/osfunc.hpp"

int main(int argc, char *argv[]) {
    printf("%s\n", PRJ_GetDataPath().c_str());
    printf("%s\n", PRJ_GetDocumentsPath().c_str());
    printf("%s\n", argv[0]);
    return 0;
}