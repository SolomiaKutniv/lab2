#include <iostream>
using namespace std;

class Engine  // Двигун
{
private:
    int speed;

public:
    Engine() : speed(0) {}

    void setSpeed(int s)
    {
        speed = s;
    }

    int getSpeed()
    {
        return speed;
    }

    ~Engine(){}
};

class Controller // Контролер
{
public:
    Controller()
    {
        cout << "Система готова до керування" << endl;
    }

    void on()
    {
        cout << "Вентилятор увімкнено" << endl;
    }

    void off()
    {
        cout << "Вентилятор вимкнено" << endl;
    }

    ~Controller()
    {
        cout << "Завершення роботи системи керування" << endl;
    }
};

class RemoteControl  // Пульт керування
{
public:
    RemoteControl()
    {
        cout << "Пульт керування ввімкнено" << endl;
    }

    void Speed(Engine& D)
    {
        int speed = D.getSpeed();
        cout << "Швидкість встановлена на: " << speed << " об/хв." << endl;
    }

    void Time(int time)
    {
        cout << "Час вимкнення встановлено через: " << time << " хвилин." << endl;
    }

    ~RemoteControl()
    {
        cout << "Пульт керування вимкнено" << endl;
    }
};

class Blower // Вентилятор
{
private:
    Engine* engine;          
    Controller* controller;
    RemoteControl* remote;

public:
    Blower()
    {
        engine = new Engine();         
        controller = new Controller();
        remote = new RemoteControl();
    }

    void start(int speed, int time)
    {
        controller->on();
        engine->setSpeed(speed);
        remote->Speed(*engine);
        remote->Time(time);
    }

    void stop()
    {
        controller->off();
    }

    ~Blower()
    {
        delete engine;
        delete remote;
        delete controller;
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    Blower blower;
    blower.start(1500, 45);
    blower.stop();

    return 0;
}