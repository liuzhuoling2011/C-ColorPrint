/* ColorPrint
*
*  It is very small but useful, easy to use c++ to create colorful code
*
*  liuzhuoling2011@hotmail.com
*/

#pragma once
#include <iostream>

#ifdef _WIN32
	#include <windows.h>

	enum ConsoleColor {
		C_RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
		C_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		C_BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		C_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		C_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		C_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		C_BLACK = 0,
	};

	char setConsoleColor(ConsoleColor textColor = C_WHITE, ConsoleColor backgroundColor = C_BLACK)
	{
		//STD_ERROR_HANDLE;
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, textColor | backgroundColor);
		return '\r';
	}

	#define CC_RED setConsoleColor(C_RED)
	#define CC_GREEN setConsoleColor(C_GREEN)
	#define CC_BLUE setConsoleColor(C_BLUE)
	#define CC_YELLOW setConsoleColor(C_YELLOW)
	#define CC_CYAN setConsoleColor(C_CYAN)
	#define CC_BLACK setConsoleColor(C_BLACK)
	#define CC_WHITE setConsoleColor(C_WHITE)
	#define CC_RESET setConsoleColor()
#else
	#define CC_RED "\033[31m"
	#define CC_GREEN "\033[32m"
	#define CC_BLUE "\033[34m"
	#define CC_YELLOW "\033[33m"
	#define CC_CYAN "\033[36m"
	#define CC_WHITE "\033[37m"
	#define CC_BLACK "\033[30m"
	#define CC_RESET "\033[0m"
#endif // _WIN32

#ifndef NoMessage 
	#define PRINT(level,content) do{\
			switch (level) {\
				/* For Success */\
				case 'S': std::cout << CC_GREEN << "[SUCCESS " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; CC_RESET; break;\
				/* For Notice */\
				case 'N': std::cout << CC_CYAN << "[NOTICE " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; CC_RESET; break;\
				/* For Warn */\
				case 'W': std::cout << CC_YELLOW << "[WARNNING " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; CC_RESET; break;\
				/* For Error */\
				case 'E': std::cout << CC_RED << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; CC_RESET; break;\
				/* For Normal Info */\
				case 'I': std::cout << "[INFO " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; break;\
				default : break;\
			}\
		}while(0)
#else
	#define PRINT(level,content) do{\
		switch (level) {\
			/* For Error */\
			case 'E': std::cout << CC_RED << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "]" << content << std::endl; CC_RESET; break;\
			default : break;\
		}\
	}while(0)
#endif

