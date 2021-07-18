#include<iostream>
#include<thread>
#include<conio.h>
using namespace std;
using namespace std::literals::chrono_literals;

const unsigned int DEFAUL_TANK_VOLUME = 60;
const unsigned int MIN_FUEL_LEVEL = 5;
const unsigned int DEFAULT_ENGINE_CONSUMPTION = 8;
const unsigned int DEFAULT_MAX_SPEED = 250;

enum Keys
{
	Escape = 27,
	Enter = 13,
	Space = 32,
	ArrowUp = 72,
	ArrowDown = 80,
	ArrowLeft = 75,
	ArrowRight = 77,
};
class Tank
{
	// Топливный бак
	const unsigned int VOLUME;   // объем бака
	double fuel_level;           // уровень топлива

public:
	unsigned int get_volume()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	void fill(double amount)
	{
		// amount - кол-во топлива
		if (amount < 0)return;
		if (fuel_level + amount < VOLUME)fuel_level += amount;
		else fuel_level = VOLUME;
	}
	double give_fuel(double amount)
	{
		if (fuel_level - amount > 0)fuel_level -= amount;
		else fuel_level = 0;
		return fuel_level;
	}
	Tank(const unsigned int VOLUME) :VOLUME(VOLUME >= 20 && VOLUME <= 80 ? VOLUME : DEFAUL_TANK_VOLUME), fuel_level(0)
	{
		cout << "Tank is ready\t" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over\t" << this << endl;

	}
	void info()const
	{
		cout << "Tank volume: " << VOLUME << " liters\n";
		cout << "Fuel level:  " << fuel_level << " liters\n\n";
	}
};

class Engine
{
	// Этот класс описывает двигатель

	const double CONSUMPTION;       // расход 100км
	double consumption_per_second;  // расход за одну секунду

	bool started;

public:
	const double get_consumption()const
	{
		return CONSUMPTION;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	bool is_started()const
	{
		return started;
	}
	void start()
	{
		started = true;
	}
	void stop()
	{
		started = false;
	}
	Engine(const double CONSUMPTION) :CONSUMPTION(CONSUMPTION >= 4 && CONSUMPTION <= 25 ? CONSUMPTION : DEFAULT_ENGINE_CONSUMPTION)
	{
		this->consumption_per_second = this->CONSUMPTION * 5e-5;
		started = false;
		cout << "Engine is ready\t" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over\t" << this << endl;

	}
	void info()const
	{
		cout << "Engine consumes " << CONSUMPTION << " liters per 100km" << endl;
		cout << "Engine consumes " << consumption_per_second << " liters per 1 second in IDLE" << endl;
		cout << "Engine is " << (started ? "started" : "stopped\n") << endl;
	}
};

class Car
{
	Tank tank;
	Engine engine;
	unsigned int speed;
	unsigned int MAX_SPEED;

	bool driver_inside;

	struct Control
	{
		std::thread main_thread;
		std::thread panel_thread;
		std::thread idle_thread;
	}control;
public:
	/*Car(unsigned int MAX_SPEED)
		:MAX_SPEED(MAX_SPEED >= 100 && MAX_SPEED <= 350 ? MAX_SPEED : DEFAULT_MAX_SPEED),
		engine(this->MAX_SPEED / 25),
		tank(this->MAX_SPEED / 5),
		speed(0)

	{
		cout << "Your car is ready to go. Press enter to get in.\t" << this << endl;
	}*/
	Car(double engine_consumption, unsigned int tank_volume)
		:engine(engine_consumption), tank(tank_volume), speed(0), driver_inside(false)
	{
		cout << "Your car is ready to go. Press enter to get in.\t" << this << endl;
	}
	~Car()
	{
		cout << "Your car is over :-(\t" << this << endl;
	}
	void get_in()
	{
		driver_inside = true;
		control.panel_thread = thread(&Car::panel, this);    // Запускаем метод panel в потоке
	}
	void get_out()
	{
		driver_inside = false;
		if (control.panel_thread.joinable())control.panel_thread.join();   // Останавливаем поток, отображающий панель приборов 

	}
	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			cout << "Engine is " << (engine.is_started() ? "started" : "stopped") << endl;
			cout << "Fuel level: " << tank.get_fuel_level() << " liters ";
			if (tank.get_fuel_level() < MIN_FUEL_LEVEL)cout << "LOW FUEL";
			cout << endl;
			cout << "Speed: " << speed << " km/h" << endl;
			std::this_thread::sleep_for(1s);
		}
		system("CLS");
		cout << "This is your car, Press Enter to get in" << endl;
	}
	void control_car()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case Enter: driver_inside ? get_out() : get_in();//Вход/Выход из машины
				break;
			case 'F':case 'f':  // Fill - заправка
				double amount;
				cout << "How much?"; cin >> amount;
				tank.fill(amount);
				break;
			case 'I': case 'i': //Ignition - зажигание
				engine.is_started() ? engine.stop() : engine.start();
				break;
			case 'W':case 'w':case ArrowUp:  //Gas

				break;
			case ArrowDown:case Space:case 'S':case 's':
				break;
			case Escape:
				get_out();
			}
		} while (key != 27);
	}
	void info()const
	{
		tank.info();
		engine.info();
		cout << "Max speed:\t" << MAX_SPEED << "km/h\n";
		cout << "Current speed:\t" << speed << "km/h\n";
	}



};

//#define TANK_CHECK
//#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHECK
	Tank tank(11);
	//tank.info();
	//tank.fill(3);
	//tank.info();
	//tank.fill(30);
	//tank.info();
	//tank.fill(30);
	//tank.info();
#endif // TANK_CHECK

#ifdef ENGINE_CHECK
	Engine engine(6);
	//engine.info();
	//engine.info();
	//engine.start();
#endif // ENGINE_CHECK

	Car car(8, 40);
	car.info();
	car.control_car();
	/*for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}*/

}