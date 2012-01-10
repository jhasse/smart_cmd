#pragma once

#include <string>

#ifdef DEBUG
#include <iostream>

template<class T>
void Debug(T m) {
	std::cout << m << std::flush;
}
#else
template<class T> void Debug(T m) {}
#endif

std::string getExplorerPath();