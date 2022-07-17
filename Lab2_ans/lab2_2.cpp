#include <iostream>
#include <string>

int main()
{
	std::cout << "Please input the range of Celsius temperature values: ";

	int ceil = 0;
	int floor = 0;

	std::cin >> floor >> ceil;

	std::cout << "Celsius\tFahrenheit\n";
	++ceil;
	for (int celsius = floor; celsius != ceil; ++celsius)
	{
		std::cout << celsius << "\t" << celsius * (9. / 5.) + 32 << std::endl;
	}
}