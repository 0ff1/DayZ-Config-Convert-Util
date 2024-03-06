#if !defined( CONSOLE_MANIP_H__INCLUDED )
#define CONSOLE_MANIP_H__INCLUDED

#include <format>

namespace color {
	static class Codes {
		public:
			static std::string getColoredText(int type, std::string text, bool reset = true) {
				int* rgb = new int[3];

				switch (type) {
					case COLOR_WHITE: 
						rgb[0] = 255;
						rgb[1] = 255;
						rgb[2] = 255;

						break;

					case COLOR_BLUEVIOLET:
						rgb[0] = 138;
						rgb[1] = 43;
						rgb[2] = 226;

						break;

					case COLOR_RED:
						rgb[0] = 255;
						rgb[1] = 0;
						rgb[2] = 0;

						break;

					case COLOR_YELLOW:
						rgb[0] = 255;
						rgb[1] = 255;
						rgb[2] = 0;

						break;

					case COLOR_GRAY:
						rgb[0] = 90;
						rgb[1] = 90;
						rgb[2] = 90;

						break;

					case COLOR_GREEN:
						rgb[0] = 0;
						rgb[1] = 120;
						rgb[2] = 0;

						break;
				}

				if (reset == true) {
					return std::format("\x1b[38;2;{};{};{}m{}\x1b[0m", rgb[0], rgb[1], rgb[2], text);
				}
				else {
					return std::format("\x1b[38;2;{};{};{}m{}", rgb[0], rgb[1], rgb[2], text);
				}
			}
	};

	inline std::string white(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_WHITE, text, reset);
	};

	inline std::string blueViolet(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_BLUEVIOLET, text, reset);
	};

	inline std::string red(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_RED, text, reset);
	};

	inline std::string yellow(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_YELLOW, text, reset);
	};

	inline std::string gray(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_GRAY, text, reset);
	};

	inline std::string green(std::string text, bool reset = true) {
		return Codes::getColoredText(COLOR_GREEN, text, reset);
	};
}


#endif