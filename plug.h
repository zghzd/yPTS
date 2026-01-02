#pragma once
#include <vector>
#include <string>
namespace ypts::plug {
	namespace ForYPTS {
		int plug_main_(std::vector<std::string> argu);//ÒÑÈ¥³ýyptsºÍplug
		std::vector<std::string> list();
		void load(std::string plug_name, std::vector<std::string> argu);
	}

}