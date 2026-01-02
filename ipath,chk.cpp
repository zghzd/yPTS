#include "ipath,chk.h"
#include <filesystem>
#include "pch.h"

namespace ypts::ipath {
	void ipath_add(std::string& p) {
		ypts::fio::file_write_c(ypts::paths::data() + "inpaths.ypts", p + "\n");
	}
	void ipath_rm(std::string& p) {
		auto f = ypts::fio::file_read_lines(ypts::paths::data() + "inpaths.ypts");
		f.erase(std::remove(f.begin(), f.end(), p), f.end());
		std::string content;
		for (const auto& line : f) {
			content += line + "\n";
		}
		ypts::fio::file_write_new(ypts::paths::data() + "inpaths.ypts", content);
	}
	void ipath_list() {
		auto f = ypts::fio::file_read_lines(ypts::paths::data() + "inpaths.ypts");
		for (auto& i : f) {
			ypts::logger::I("list:input_path");
			std::cout << "\t" << i << std::endl;
		}
	}
}
namespace ypts::chk {
	bool chk() {
		auto f = ypts::fio::file_read_lines(ypts::paths::data() + "inpaths.ypts");
		for (auto& i : f) {
			ypts::logger::I("check:input_path->" + i);
			try {
				if (!std::filesystem::exists(i)) {
					ypts::logger::E("路径不存在:" + i);
					return false;
				}
				if (!std::filesystem::is_directory(i)) {
					ypts::logger::E("不是目录:" + i);
					return false;
				}
			}
			catch (const std::filesystem::filesystem_error& e) {
				ypts::logger::E("文件系统错误:" + std::string(e.what()));
				return false;
			}
		}
		return true;
	}
}