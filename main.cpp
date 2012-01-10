#include <windows.h>
#include <stdexcept>
#include <sstream>

#ifdef DEBUG
#include <iostream>

template<class T>
void Debug(T m) {
	std::cout << m << std::flush;
}
#else
template<class T> void Debug(T m) {}
#endif

HWND getChild(HWND wnd, const char* name) {
	HWND child = FindWindowEx(wnd, NULL, name, NULL);
	if (child == NULL) {
		std::stringstream sstream;
		sstream << "Not found: " << name << " HWND: " << wnd;
		throw std::runtime_error(sstream.str());
	}
	return child;
}

std::string getExplorerPath() {
	HWND wnd = GetForegroundWindow();
	const int maxCount = 4096;
	char tmp[maxCount];
	GetClassName(wnd, tmp, maxCount);
	if (std::string(tmp) != "CabinetWClass") {
		Debug("No Explorer window active. Using FindWindowEx ...\n");
		wnd = FindWindow("CabinetWClass", NULL);
	}
	if (wnd == NULL) {
		Debug("No window found.\n");
	} else {
		try {
			wnd = getChild(getChild(getChild(getChild(wnd,
						"WorkerW"),
						"ReBarWindow32"),
						"Address Band Root"),
						"msctls_progress32");
			try {
				// This will only work if the address has been clicked on
				HWND edit = getChild(wnd, "ComboBoxEx32");
				Debug("Using ComboBoxEx32 ...\n");
				SendMessage(edit, WM_GETTEXT, maxCount, (LPARAM)tmp);
				if (tmp[0] == '\0') {
					throw std::runtime_error("Falling back to other method.");
				}
				return tmp;
			} catch (std::runtime_error& e) {
				Debug(e.what()); Debug("\n");
				wnd = getChild(getChild(wnd, "Breadcrumb Parent"), "ToolbarWindow32");
				SendMessage(wnd, WM_GETTEXT, maxCount, (LPARAM)tmp);
				// Window Text starts with "URL: " (or "Adresse: " in Germany).
				// So we need to remove it.
				Debug(tmp); Debug("\n");
				std::stringstream sstream(tmp);
				std::string url;
				sstream >> url;
				sstream.ignore(1); // Ignore space
				std::getline(sstream, url);
				return url;
			}
		} catch(std::runtime_error& e) {
			Debug(e.what()); Debug("\n");
		}
	}
	return "";
}

int main() {
	std::string path = getExplorerPath();
	if (path == "") {
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
