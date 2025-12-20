#pragma once
#include "takemeback.h"
#include <iostream>
#define NOMINMAX
#include <windows.h>
#include "pch.h"

namespace ypts {
    namespace backtofilepath {
        bool SetCurrentDirToExecutableDir() {
            char buffer[MAX_PATH] = { 0 };
            DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);

            if (length == 0 || length == MAX_PATH) {
                return false;
            }

            std::string exePath(buffer);
            size_t lastSlash = exePath.find_last_of("\\/");

            if (lastSlash == std::string::npos) {
                return false;
            }

            std::string dirPath = exePath.substr(0, lastSlash);

            return SetCurrentDirectoryA(dirPath.c_str()) != 0;
        }

    }
}