#include <chrono>
#include <iostream>
#include <vector>

/* Parameters */
#define VALIDATE		1					// should we run the valide test
#define PERFORMANCE		1					// should we run the performance test
#define FIRST			"solution.cpp"		// first contender
#define SECOND			"bruteforce.cpp"	// second contented
static int kAmount =	10;					// amount of input test values to generate

/* Problem settings */

// Define the solution input parameter type
//typedef std::vector<int> input_type;
typedef int input_type;
typedef std::vector< input_type > input_list_type; // a list of input values

// Define the solution return type
//typedef std::vector<int> result_type;
typedef int result_type;

// code to generate an vector with input for testing
void generate_input_list(input_list_type &input_list)
{
	for (int i = 0; i < kAmount; i++)
		input_list.push_back(i);
}

// code to compare the result from two solutions for one iteration
bool compare_result(result_type &resultA, result_type &resultB)
{
	return resultA == resultB;
}

/* Internal */
typedef std::chrono::high_resolution_clock Clock;
typedef long long Milliseconds;
typedef std::chrono::duration<Milliseconds, std::milli> Duration;

namespace first
{
	const char *name = FIRST;
	#include FIRST
}

namespace second
{
	const char *name = SECOND;
	#include SECOND
}

template<typename F>
Milliseconds profiler(F &func, input_list_type &input_list)
{
	auto start = Clock::now();
	for (auto input : input_list)
		func(input);

	return std::chrono::duration_cast<Duration>(Clock::now() - start).count();
}

template<typename F>
bool validate(F &func, F &prove, input_list_type &input_list)
{
	bool passed = true;
	for (auto input : input_list)
	{
		auto v = func(input);
		auto r = prove(input);

		std::cout << (compare_result(v, r) ? "[  OK  ]" : "[FAILED]") << " Got: " << v << " Expected: " << r << std::endl;
		passed = passed && v == r;
	}
	return passed;
}

int main(int, char **)
{
	input_list_type inputs;
	generate_input_list(inputs);

#if VALIDATE
	validate(first::solution, second::solution, inputs);
	std::cout << std::endl;
#endif

#if PERFORMANCE
	std::cout << "Timing for " << first::name << ": " << profiler(first::solution, inputs) << "ms" << std::endl;
	std::cout << "Timing for " << second::name << ": " << profiler(second::solution, inputs) << "ms" << std::endl;
#endif

	return 0;
}
