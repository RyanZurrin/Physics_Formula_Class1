#include "Physics_World.h"
#include "RunTimer.h"




int main()
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer;
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************

	std::cout<< "exp: " << fastExponentiation(4, 11)%7 << std::endl;



	int arr[](1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 8, 9, 10);
	std::cout << y_minus_x(arr, 3, 10);

	cout << "ds: " << double_sum(5, 120, 11, 77) << endl;

		std::cout << "\n\nafter if statement" << std::endl;
	auto p = rgXRaw.EMAIL;
	auto valid = is_valid_format("marius@domain.com"s, p);

	reg_test("C:/fileformat/file", rgXRaw.ROOT_PATH);
	reg_test("/files/users/me.txt"s, rgXRaw.ROOT_PATH);
	reg_test("file.txt"s, rgXRaw.ROOT_PATH);
	reg_test("D:/files/test/help.txt"s, rgXRaw.ROOT_PATH);
	reg_test("01-23-45-67-AH"s, rgXRaw.MAC);
	reg_test("fffe:3465:efab:23fe:2235:6565:aaab:0001"s, rgXRaw.IPV6);



	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
