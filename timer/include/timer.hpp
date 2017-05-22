#pragma once

#include <string>
#include <chrono>




class timer
{
	public:
		timer() = default;

		static std::string current();
		static std::string format(double elapsed);
		void start();
		double stop();

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
};
