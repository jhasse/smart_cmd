#include <iostream>
#include <algorithm>

#include "path.h"

int main() {
    auto tmp = getExplorerPath();
    if (tmp.size() > 1 && tmp[1] != ':') {
        tmp = std::string(getenv("USERPROFILE")) + "/" + tmp;
    }
    std::replace(std::begin(tmp), std::end(tmp), '\\', '/');
	std::cout << tmp;
}
