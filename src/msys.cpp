#include <iostream>
#include <algorithm>

#include "path.h"

int main() {
    auto tmp = getExplorerPath();
    std::replace(std::begin(tmp), std::end(tmp), '\\', '/');
	std::cout << tmp;
}
