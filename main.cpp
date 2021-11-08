#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <chrono> //for time
#include "RenderWindow.hpp"

const char *CAR_IMG_PATH = "C:\\Users\\smniv\\Desktop\\pranav\\ie\\pictures\\car.png";

void detCheck()
{
#if INTPTR_MAX == INT64_MAX
	// 64-bit
	std::cout << "64-bit"
			  << " ";
#elif INTPTR_MAX == INT32_MAX
	// 32-bit
	std::cout << "32-bit"
			  << " ";
#else
	std::cout << "Unknown"
			  << " ";
#endif

	if (__cplusplus == 201703L)
		std::cout << "C++17\n";
	else if (__cplusplus == 201402L)
		std::cout << "C++14\n";
	else if (__cplusplus == 201103L)
		std::cout << "C++11\n";
	else if (__cplusplus == 199711L)
		std::cout << "C++98\n";
	else
		std::cout << "pre-standard C++\n";
}

long long int getMs()
{
	using namespace std::chrono;
	milliseconds ms = duration_cast<milliseconds>(
		system_clock::now().time_since_epoch());
	long int sc = time(0);
	long long int milsec = ms.count();

	return milsec;
}

void game(SDL_Window *win)
{
	//game loop
	bool quit = false;
	while (!quit)
	{
	}
}

bool initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "error initializing SDL:" << SDL_GetError() << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cout << "Failed to init sdl_image" << IMG_GetError() << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	std::cout << "Code Starting..." << std::endl;
	long long int START_TIME = getMs();
	detCheck();
	initSDL();

	// SDL_Window *win = SDL_CreateWindow("GAME",
	// 								   SDL_WINDOWPOS_CENTERED,
	// 								   SDL_WINDOWPOS_CENTERED,
	// 								   500, 500, 0);

	// game(win);

	RenderWindow window("Game V1.0.0", 500, 500);
	std::cout << "Code Exited Properly.";
	return 0;
}