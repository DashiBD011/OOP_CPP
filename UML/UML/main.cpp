#include<iostream>
using namespace std;

const unsigned int DEFAUL_TANK_VOLUME = 60;
const unsigned int DEFAULT_ENGINE_CONSUMPTION = 8;
const unsigned int DEFAULT_MAX_SPEED = 250;

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
		cout << "Fuel level:  " << fuel_level << " liters\n";
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
		cout << "Engine consumes " << CONSUMPTION <<" liters per 100km"<< endl;
		cout << "Engine consumes " << consumption_per_second <<" liters per 1 second in IDLE"<< endl;
		cout << "Engine is " << (started ? "started" : "stopped") << endl;
	}
};

class Car
{
	Tank tank;
	Engine engine;
	unsigned int speed;
	unsigned int MAX_SPEED;
public:
	Car(unsigned int MAX_SPEED)
		:MAX_SPEED(MAX_SPEED >= 100 && MAX_SPEED <= 350 ? MAX_SPEED : DEFAULT_MAX_SPEED),
		engine(this->MAX_SPEED / 25),
		tank(this->MAX_SPEED / 5),
		speed(0)
	{
		cout << "Your car is ready to go. Press enter to get in.\t" << this << endl;
	}
	Car(double engine_consumption, unsigned int tank_volume) 
		:engine(engine_consumption), tank(tank_volume),speed(0)
	{
		cout << "Your car is ready to go. Press enter to get in.\t" << this << endl;
	}
	~Car()
	{
		cout << "Your car is over :-(\t" << this << endl;
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

	/*Car car(11,11);
	car.info();*/

}