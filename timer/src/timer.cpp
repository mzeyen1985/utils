#include <timer.hpp>

#include <ctime>
#include <sstream>




std::string timer::current()
{
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(time, "%F %T %z");

	return ss.str();
}


std::string timer::format(double elapsed)
{
	std::chrono::seconds time(elapsed);

	std::stringstream ss;
	ss << std::chrono::hours(time).count() << "h:"
	   << std::chrono::minutes(time).count() << "m:"
	   << std::chrono::seconds(time).count() << "s:"
	   << std::chrono::milliseconds(time).count() << "ms:"
	   << std::chrono::microseconds(time).count() << "us:"
	   << std::chrono::nanoseconds(time).count() << "ns";

	return ss.str();
}


void timer::start()
{
	this->start = std::chrono::high_resolution_clock::now();
}


double timer::stop()
{
	this->end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = this->end - this->start;
	
	return elapsed.count();
}
