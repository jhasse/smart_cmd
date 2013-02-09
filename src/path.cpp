#include "path.h"

#include <windows.h>
#include <stdexcept>
#include <sstream>

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
			bool ignore = true;
			try {
				wnd = getChild(getChild(getChild(getChild(getChild(getChild(wnd,
							"WorkerW"),
							"ReBarWindow32"),
							"Address Band Root"),
							"msctls_progress32"),
							"Breadcrumb Parent"),
							"ToolbarWindow32");
			} catch (std::runtime_error& e) {
				Debug(e.what()); Debug("\nSecond try ...\n");
				wnd = getChild(getChild(getChild(getChild(getChild(wnd,
							"WorkerW"),
							"ReBarWindow32"),
							"ComboBoxEx32"),
							"ComboBox"),
							"Edit");
				ignore = false;
			}
			SendMessage(wnd, WM_GETTEXT, maxCount, (LPARAM)tmp);
			Debug(tmp); Debug("\n");
			std::stringstream sstream(tmp);
			std::string url;
			if (ignore) {
				// Window Text starts with "URL: " (or "Adresse: " in Germany).
				// So we need to remove it.
				sstream >> url;
				sstream.ignore(1); // Ignore space
			}
			std::getline(sstream, url);
			return url;
		} catch(std::runtime_error& e) {
			Debug(e.what()); Debug("\n");
		}
	}
	return "";
}
