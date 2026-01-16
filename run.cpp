#include <map>
#include <filesystem>
#include "pch.h"
namespace ypts {
	int run_main(std::vector<std::string> argu);//已去除ypts和run
}
namespace ypts {
	int run_main(std::vector<std::string> argu) {
		auto abledplug = ypts::plug::ForYPTS::list();
		if (argu.size() < 1) {
			ypts::logger::E("run:参数错误");
			return -1;
		}
		for (auto p : abledplug) {
			if (p == argu[0]) {
				ypts::plug::ForYPTS::load(p, argu);
				return 0;
				break;
			}
		}
        //索引 内部地址>真实地址
		std::map<std::string, std::string> ypts_run_index;//内部地址 -> 真实地址
        ypts::logger::I("为输入目录建立索引...");
		auto inpath_list_f = ypts::fio::file_read_lines(ypts::paths::data() + "inpaths.ypts");
		for (auto i : inpath_list_f) {
			auto a_f = ypts::data_process::getAllFiles(i);
            for (auto file : a_f) {
                std::filesystem::path filePath(file);
                std::filesystem::path inPath(i);
                std::string internal_path;
                try {
                    std::filesystem::path relative = std::filesystem::relative(filePath, inPath);
                    internal_path = "/" + relative.string();
                    for (size_t j = 0; j < internal_path.length(); ++j) {
                        if (internal_path[j] == '\\') {
                            internal_path[j] = '/';
                        }
                    }
                }
                catch (const std::exception& e) {
                    ypts::logger::W("无法计算相对路径: " + file + " 相对于 " + i);
                    ypts::logger::W(e.what());
                    return -1;
                }
                if (ypts_run_index.find(internal_path) != ypts_run_index.end()) {
                    std::string warning_msg = "无法区分文件<实际地址1:" + ypts_run_index[internal_path] + "><实际地址2:" + file + ">，最后的值为:<" + file + ">(已替换)";
                    ypts::logger::W(warning_msg);
                }
                ypts_run_index[internal_path] = file;
            }
        }
        ypts::logger::I("索引建立完成");
        ypts::logger::D("缓存索引:" + ypts::paths::temp() + "inpath_index.txt");
        for (const auto& entry : ypts_run_index) {
            std::string temp_ypts_run_index_file = entry.first + ">" + entry.second + "\n";
            std::string temp_ypts_run_index_path = ypts::paths::temp() + "inpath_index.txt";
            ypts::fio::file_write_c(temp_ypts_run_index_path, temp_ypts_run_index_file);
        }
        ypts::logger::D("缓存索引(debug)完成");
        ypts::logger::I("缓存内部值:" + ypts::paths::rep() + "index.txt");
        for (const auto& entry : ypts_run_index) {
            std::string temp_ypts_run_index_file = entry.first + "\n";
            std::string temp_ypts_run_index_path = ypts::paths::rep() + "index.txt";
            ypts::fio::file_write_c(temp_ypts_run_index_path, temp_ypts_run_index_file);
        }
        ypts::logger::I("缓存内部值完成");
		//下方启动内置func
		
		//==========
		return 0;
	}
}