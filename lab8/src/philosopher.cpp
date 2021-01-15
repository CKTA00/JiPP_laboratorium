#include <philosopher.h>
#include <thread>
#include <chrono>

using namespace std;

Philosopher::Philosopher(int id)
{
    this->id = id;
}

void Philosopher::eat()
{
    cout << "Filozof " << id+1 << " je." << endl;
    this_thread::sleep_for(chrono::milliseconds(10*(100+rand()%900)));
    cout << "Filozof " << id+1 << " zakonczyl jedzenie." << endl;
}

void Philosopher::think()
{
    cout << "Filozof " << id+1 << " mysli." << endl;
    this_thread::sleep_for(chrono::milliseconds(10*(100+rand()%900)));
    cout << "Filozof " << id+1 << " zglodnial." << endl;
}

int Philosopher::getid()
{
    return id;
}