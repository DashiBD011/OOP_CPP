#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;
using namespace std::chrono_literals;
bool finish = false;

void hello()
{
	while (!finish)
	{
		cout << "Hello ";
		//cout << "+ ";
		//std::this_thread::sleep_for(1s);
		Sleep(1000);
	}
}
void world()
{
	while (!finish)
	{
		cout << "world " << endl;
		//cout << "- ";
		//std::this_thread::sleep_for(1s);
		Sleep(1000);
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	std::thread thread_hello(hello);
	std::thread thread_world(world);

	std::cin.get();   // ожидает нажатия клавиши enter
	finish = true;

	thread_world.join();
	thread_hello.join();

}