#include "ContextOptionsHandler.h"

/* Publics */
void ContextOptionsHandler::clearRegisteredValues(int type, bool print) {
	if (print == true) {
		std::cout << color::white("Removing options...\r");

		Sleep(800);
	}

	switch (type) {
		case OPTION_CONFIG:



			break;
	}

	if (print == true) {
		std::cout << color::white("Options removed!   ") << std::endl;
		Sleep(1000);
	}

}

int ContextOptionsHandler::registerOption(int type) {
	switch (type) {
		case OPTION_CONFIG:
			registerConfigOptions();

			break;
	}

	return 0;
}


/* Privates */
HKEY ContextOptionsHandler::setRegKeyValue(std::string fileExtension, std::string key, std::wstring name, std::wstring value) {
	HKEY reg;

	key = std::format("Software\\Classes\\DZCTXUtils{}\\{}", fileExtension, key);

	if (RegCreateKeyEx(HKEY_CURRENT_USER, std::wstring(key.begin(), key.end()).c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE | KEY_WOW64_64KEY, NULL, &reg, NULL) == ERROR_SUCCESS) {
		if (RegSetKeyValue(reg, NULL, name.empty() ? NULL : name.data(), REG_SZ, value.data(), static_cast<DWORD>(value.length() * sizeof TCHAR))) {

		}

		RegCloseKey(reg);
	} else {
		std::cout << color::red("Registry create error.\n") << std::endl;
	}

	return reg;
}
void ContextOptionsHandler::getRegKeyValue() {

}

/*LSTATUS ContextOptionsHandler::deleteRegKeyValue() {

};*/

int ContextOptionsHandler::registerConfigOptions() {
	setRegKeyValue(".bin", "\\shell\\open", L"open", L"17");

	system("pause");

	return 0;
}