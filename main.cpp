#include "pch.h"
#include <filesystem>
#include <vector>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
	std::cout << "usage:ypts (plug|run|add-path|rm-path|list-path) [arguments]\n    plug able <plug_name>\n    plug unable <plug_name>\n    plug unable_all\n    run <name>\n    (add-path|rm-path) <any_path>\n    list-path" << std::endl;
	ypts::backtofilepath::SetCurrentDirToExecutableDir();
	std::filesystem::create_directory(ypts::paths::bin());
	std::filesystem::create_directory(ypts::paths::data());
	std::filesystem::create_directory(ypts::paths::log());
	std::filesystem::create_directory(ypts::paths::rep());
	std::filesystem::create_directory(ypts::paths::res());
	std::filesystem::create_directory(ypts::paths::temp());
	std::vector<std::string>arguments;
	for (int i = 0; i < argc; i++) {
		arguments.push_back(argv[i]);
	}
	if (! ypts::chk::chk()) {
		ypts::logger::E("检查失败");
		std::exit(-1);
	}
	std::string p_s_a;
	p_s_a = "add-path";
	if (arguments.size() > 2 && arguments[1] == p_s_a) {
		ypts::logger::I("add-input-path:" + arguments[2]);
		ypts::ipath::ipath_add(arguments[2]);
		return 0;
	}
	p_s_a = "rm-path";
	if (arguments.size() > 2 && arguments[1] == p_s_a) {
		ypts::logger::I("rm-input-path:" + arguments[2]);
		ypts::ipath::ipath_rm(arguments[2]);
		return 0;
	}
	p_s_a = "list-path";
	if (arguments.size() > 1 && arguments[1] == p_s_a) {
		ypts::ipath::ipath_list();
		return 0;
	}
	p_s_a = "plug";
	if (arguments.size() > 1 && arguments[1] == p_s_a) {
		std::vector<std::string>arguformrun;
		for (int i = 2; i < argc; i++) {
			arguformrun.push_back(argv[i]);//去除ypts和plug
		}
		ypts::plug::ForYPTS::plug_main_(arguformrun);
		return 0;
	}
	p_s_a = "run";
	if (arguments.size() > 2 && arguments[1] == p_s_a) {
		std::vector<std::string>arguformrun;
		for (int i = 2; i < argc; i++) {
			arguformrun.push_back(argv[i]);//去除ypts和run
		}
		ypts::run_main(arguformrun);
		return 0;
	}
	ypts::logger::E("参数错误");
	return -1;
}