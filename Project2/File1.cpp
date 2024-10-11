#include <iostream>
using namespace std;

class Engine  // ������
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

class Controller // ���������
{
public:
    Controller()
    {
        cout << "������� ������ �� ���������" << endl;
    }

    void on()
    {
        cout << "���������� ��������" << endl;
    }

    void off()
    {
        cout << "���������� ��������" << endl;
    }

    ~Controller()
    {
        cout << "���������� ������ ������� ���������" << endl;
    }
};

class RemoteControl  // ����� ���������
{
public:
    RemoteControl()
    {
        cout << "����� ��������� ��������" << endl;
    }

    void Speed(Engine& D)
    {
        int speed = D.getSpeed();
        cout << "�������� ����������� ��: " << speed << " ��/��." << endl;
    }

    void Time(int time)
    {
        cout << "��� ��������� ����������� �����: " << time << " ������." << endl;
    }

    ~RemoteControl()
    {
        cout << "����� ��������� ��������" << endl;
    }
};

class Blower // ����������
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