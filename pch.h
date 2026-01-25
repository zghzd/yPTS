#pragma once
#include <map>
#include <filesystem>
#include <string>

#define NOMINMAX
#include "b_ypts.h"
#include "takemeback.h"
#include "ipath,chk.h"
#include "plug.h"

namespace ypts {
    int run_main(std::vector<std::string> argu);
}