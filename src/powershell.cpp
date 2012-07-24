#include "path.h"

#include <sstream>
#include <windows.h>

int main() {
	Wow64EnableWow64FsRedirection(FALSE);
	std::string path = getExplorerPath();
	if (path == "" || path.size() < 2 || path[1] != ':') {
		Debug("No valid path found.\n");
		system("powershell -NoExit");
	} else {
		Debug("Using path: '"); Debug(path); Debug("'\n");
		size_t pos = 0;
		while ((pos = path.find("`", pos)) != std::string::npos) {
			path.replace(pos, 1, "``");
			pos += 2;
		}
		std::stringstream sstream;
		sstream << "powershell -NoExit -Command Set-Location -LiteralPath \\\"" << path << "\\\"";
		Debug(sstream.str() + "\n");
		system(sstream.str().c_str());
	}
}
