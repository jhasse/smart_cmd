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
		size_t pos = 0;
		while ((pos = path.find("`", pos)) != std::string::npos) {
			path.replace(pos, 1, "``");
			pos += 2;
		}
		std::stringstream sstream;
		sstream << "%SystemRoot%\\system32\\WindowsPowerShell\\v1.0\\powershell.exe -NoLogo -NoExit -Command Set-Location -LiteralPath \"" << path << "\"";
		Debug(sstream.str() + "\n");
		system(sstream.str().c_str());
	}
}
