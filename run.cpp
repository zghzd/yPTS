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
		//下方启动内置func
		
		//==========
		return 0;
	}
}