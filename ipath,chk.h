#pragma once
#include <iostream>
#include <string>
namespace ypts::ipath {
	void ipath_add(std::string& p);
	void ipath_rm(std::string& p);
	void ipath_list();
}
namespace ypts::chk {
	bool chk();
}