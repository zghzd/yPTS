
#include "pch.h"

void plug_add(std::string& p) {
	ypts::fio::file_write_c(ypts::paths::data() + "plugs.ypts", p + "\n");
}
void plug_rm(std::string& p) {
	auto f = ypts::fio::file_read_lines(ypts::paths::data() + "plugs.ypts");
	f.erase(std::remove(f.begin(), f.end(), p), f.end());
	std::string content;
	for (const auto& line : f) {
		content += line + "\n";
	}
	ypts::fio::file_write_new(ypts::paths::data() + "plugs.ypts", content);
}


namespace ypts::plug::ForYPTS {
	int plug_main_(std::vector<std::string> argu) {
		if (argu.size() > 1 && argu[0] == std::string("able")) {
			plug_add(argu[1]);
		}
		else if (argu.size() > 1 && argu[0] == std::string("unable")) {
			plug_rm(argu[1]);
		}
		else if (argu.size() > 0 && argu[0] == std::string("unable_all")) {
			ypts::fio::file_write_new(ypts::paths::data() + "plugs.ypts", "");
		}
		else {
			ypts::logger::E("plug:未知指令");
			return -1;
		}
	}
	std::vector<std::string> list() {
		auto f = ypts::fio::file_read_lines(ypts::paths::data() + "plugs.ypts");
		return f;
	}
	void load(std::string plug_name, std::vector<std::string> argu) {
		//下方启动扩展func
		
		//==========
		return;
	}
}

namespace ypts::plug {

}