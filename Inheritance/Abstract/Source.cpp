#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;   // Чисто виртуальная функция
};

class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void takeoff() = 0;
	virtual void land() = 0;
};

class Airplain :public AirVehicle
{
public:
	void move()
	{
		cout << "Летит по воздуху" << endl;
	}
	void takeoff()
	{
		cout << "Для взлета нужна взлетная полоса" << endl;
		cout << "Взлетаем" << endl;
	}
	void land()
	{
		cout << "Для посадки нужна взлетная полоса" << endl;
		cout << "Захожу на посадку" << endl;
	}
	
};

class Helicopter :public AirVehicle
{
public:
	void takeoff()
	{
		cout << "Могу взлететь где угодно" << endl;
	}
	void move()
	{
		cout << "Плавненько перемещаюсь по воздуху" << endl;
	}
	void land()
	{
		cout << "Могу сесть хоть в поле" << endl;
	}
};

class LandVehicle :public Vehicle
{
	virtual void move() = 0;
};

class Car :public LandVehicle
{
public:
	void move()
	{
		cout << "Едет на дороге на четырех колесах" << endl;
	}
};

class Bike :public LandVehicle
{
public:
	void move()
	{
		cout << "Едет по дороге на двух колесах" << endl;
	}
};

class WaterVehicle : public Vehicle
{
	virtual void move() = 0;
};

class Boat : public WaterVehicle
{
public:
	void move()
	{
		cout << "Плывет по воде" << endl;
	}
};

#define delimiter "\n--------------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;     // Невозможно создать экземпляр абстрактного класса
	//AirVehicle av; // этот класс так же является абстрактным, поскольку 
	                 // наследует чисто виртуальный метод move(),
	                 // и не реализует его
	Airplain plain;
	plain.takeoff();
	plain.move();
	plain.land();

	cout << delimiter << endl;

	Helicopter copter;
	copter.takeoff();
	copter.move();
	copter.land();

	cout << delimiter << endl;

	Car car;
	car.move();

	Bike bike;
	bike.move();

	Boat boat;
	boat.move();
}