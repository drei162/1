#include <iostream>
#include <thread>
#include <chrono>

void NumberOne() {
	for (int a = 1; a <=10; a++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout <<"Thread 1: "<< a << std::endl;
	}
}

void NumberTwo() {
	for (int b = 5; b <=50; b+=5) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout <<"Thread 2: "<< b << std::endl;
	}
}

void NumberThree() {
	for (int c = 2; c <=32; c*=2) {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout <<"Thread 3: "<< c << std::endl;
	}
}
int main()
{

	std::thread add(NumberOne);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread addition(NumberTwo);
	//std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread multiply(NumberThree);
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	multiply.join();
	add.join();
	addition.join();

	return 0;
}