#include "path.h"

#include <cstdlib>
#include <sstream>

int main() {
	std::string path = getExplorerPath();
	if (path == "" || path.size() < 2 || path[1] != ':') {
		Debug("No valid path found.\n");
		system("cmd.exe");
	} else {
		Debug("Using path: '"); Debug(path); Debug("'\n");
		std::stringstream sstream;
		sstream << "cmd /K \"" << path[0] << ": & cd " << path << "\"";
		Debug(sstream.str() + "\n");
		system(sstream.str().c_str());
	}
}
