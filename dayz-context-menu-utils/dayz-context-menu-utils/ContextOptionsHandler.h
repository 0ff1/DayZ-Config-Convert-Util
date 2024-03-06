#include "includes.h"

class ContextOptionsHandler {
public:
	void clearRegisteredValues(int type, bool print = true);
	int registerOption(int type);

private:
	int selectedOptions = 0;

	HKEY setRegKeyValue(std::string fileExtension, std::string key, std::wstring name, std::wstring value);
	void getRegKeyValue();
	LSTATUS deleteRegKeyValue();
	int registerConfigOptions();
};