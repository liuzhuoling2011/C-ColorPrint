/* ColorPrint
*
*  It is very small but useful, easy to use c++ to create colorful code
*
*  liuzhuoling2011@hotmail.com
*/

#pragma once
#include <iostream>
#include <stdio.h>

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

	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	#define CC_RED SetConsoleTextAttribute(handle,C_RED|C_BLACK)
	#define CC_GREEN SetConsoleTextAttribute(handle,C_GREEN|C_BLACK)
	#define CC_BLUE SetConsoleTextAttribute(handle,C_BLUE|C_BLACK)
	#define CC_YELLOW SetConsoleTextAttribute(handle,C_YELLOW|C_BLACK)
	#define CC_CYAN SetConsoleTextAttribute(handle,C_CYAN|C_BLACK)
	#define CC_BLACK SetConsoleTextAttribute(handle,C_BLACK|C_BLACK)
	#define CC_WHITE SetConsoleTextAttribute(handle,C_WHITE|C_BLACK)
	#define CC_RESET SetConsoleTextAttribute(handle,C_WHITE|C_BLACK)

	#ifndef NoMessage 
		#define PRINT(level,content) do{\
			switch (level) {\
				/* For Success */\
				case 'S': CC_GREEN; std::cout << "[SUCCESS " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; CC_RESET; break;\
				/* For Notice */\
				case 'N': CC_CYAN;  std::cout << "[NOTICE " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; CC_RESET; break;\
				/* For Warn */\
				case 'W': CC_YELLOW; std::cout << "[WARNNING " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; CC_RESET; break;\
				/* For Error */\
				case 'E': CC_RED; std::cout << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; CC_RESET; break;\
				/* For Normal Info */\
				case 'I': std::cout << "[INFO " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; break;\
				default : break;\
			}\
		}while(0)
		#define PRINTF(level,format,...) do{\
			switch (level) {\
				/* For Success */\
				case 'S': CC_GREEN; printf("[SUCCESS %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				/* For Notice */\
				case 'N': CC_CYAN;  printf("[NOTICE %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				/* For Warn */\
				case 'W': CC_YELLOW; printf("[WARNNING %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				/* For Error */\
				case 'E': CC_RED; printf("[ERROR %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				/* For Normal Info */\
				case 'I': printf("[INFO %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				default: break; \
			}\
		}while (0)
	#else
		#define PRINT(level,content) do{\
			switch (level) {\
				/* For Error */\
				case 'E': CC_RED; std::cout << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; CC_RESET; break;\
				default : break;\
			}\
		}while(0)
		#define PRINTF(level,format,...) do{\
			switch (level) {\
				/* For Error */\
				case 'E': CC_RED; printf("[ERROR %s:%d] " format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); CC_RESET; break; \
				default : break;\
			}\
		}while(0)
	#endif

#else
	#define CC_RED "\033[31m"
	#define CC_GREEN "\033[32m"
	#define CC_BLUE "\033[34m"
	#define CC_YELLOW "\033[33m"
	#define CC_CYAN "\033[36m"
	#define CC_WHITE "\033[37m"
	#define CC_BLACK "\033[30m"
	#define CC_RESET "\033[0m"

	#ifndef NoMessage 
		#define PRINT(level,content) do{\
			switch (level) {\
				/* For Success */\
				case 'S': std::cout << CC_GREEN << "[SUCCESS " << __FUNCTION__ << ":" << __LINE__ << "] " << content << CC_RESET << std::endl; break;\
				/* For Notice */\
				case 'N': std::cout << CC_CYAN << "[NOTICE " << __FUNCTION__ << ":" << __LINE__ << "] " << content << CC_RESET << std::endl; break;\
				/* For Warn */\
				case 'W': std::cout << CC_YELLOW << "[WARNNING " << __FUNCTION__ << ":" << __LINE__ << "] " << content << CC_RESET << std::endl; break;\
				/* For Error */\
				case 'E': std::cout << CC_RED << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "] " << content << CC_RESET << std::endl; break;\
				/* For Normal Info */\
				case 'I': std::cout << "[INFO " << __FUNCTION__ << ":" << __LINE__ << "] " << content << std::endl; break;\
				default : break;\
			}\
		}while(0)
		#define PRINTF(level,format,...) do{\
			switch (level) {\
				/* For Success */\
				case 'S': printf(CC_GREEN "[SUCCESS %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				/* For Notice */\
				case 'N': printf(CC_CYAN "[NOTICE %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				/* For Warn */\
				case 'W': printf(CC_YELLOW "[WARNNING %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				/* For Error */\
				case 'E': printf(CC_RED "[ERROR %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				/* For Normal Info */\
				case 'I': printf("[INFO %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				default: break; \
			}\
		}while (0)
	#else
		#define PRINT(level,content) do{\
			switch (level) {\
				/* For Error */\
				case 'E': std::cout << CC_RED << "[ERROR " << __FUNCTION__ << ":" << __LINE__ << "] " << content << CC_RESET << std::endl; break;\
				default : break;\
			}\
		}while(0)
		#define PRINTF(level,format,...) do{\
			switch (level) {\
				/* For Error */\
				case 'E': printf(CC_RED "[ERROR %s:%d] " format CC_RESET "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); break; \
				default: break; \
			}\
		}while (0)
	#endif
#endif // _WIN32
