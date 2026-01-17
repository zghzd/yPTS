#include <map>
#include <filesystem>
#include "pch.h"

int run_a_index(std::map<std::string, std::string>index) {
    ypts::logger::D("存储索引:" + ypts::paths::temp() + "inpath_index.txt");
    for (const auto& entry : index) {
        std::string temp_ypts_run_index_file = entry.first + ">" + entry.second + "\n";
        std::string temp_ypts_run_index_path = ypts::paths::temp() + "inpath_index.txt";
        ypts::fio::file_write_c(temp_ypts_run_index_path, temp_ypts_run_index_file);
    }
    ypts::logger::D("存储索引完成");
    ypts::logger::D("存储文件扩展名:" + ypts::paths::temp() + "index_ext.txt");
    std::vector<std::string> i_v_a;
    for (const auto& i : index) {
        auto s_a = ypts::fio::getFileExtension(i.second);
        ypts::data_process::addIfNotExists_invector(i_v_a, s_a);
    }
    for (const auto& i : i_v_a) {
        std::string temp_ypts_run_index_file = i +"\n";
        std::string temp_ypts_run_index_path = ypts::paths::temp() + "index_ext.txt";
        ypts::fio::file_write_c(temp_ypts_run_index_path, temp_ypts_run_index_file);
    }
    ypts::logger::D("存储文件扩展名完成");
    return 0;
}