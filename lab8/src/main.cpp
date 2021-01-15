#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <exception>
#include <stdexcept>

#include <philosopher.h>

using namespace std;

static bool loop = true;
static mutex forks[5];
static mutex table;
static mutex full;
//static exception_ptr globalExceptionPtr = nullptr;

static int seats = 4;

bool try_sit()
{
    bool ret = false;
    table.lock();
    if(seats>0)
    {
        --seats;
        ret = true;
    }
    table.unlock();
    return ret;
}

void stand()
{
    table.lock();
    ++seats;
    table.unlock();
}

void f(int id)
{
    Philosopher p(id);
    while(loop)
    {
        try{
            p.think();
            //while (!try_sit());
            try_sit();
            forks[id].lock();
            forks[(id+1)%5].lock();
            p.eat();
            forks[(id+1)%5].unlock();
            forks[id].unlock();
            stand();
        }
        catch(...)
        {
            cout << "Blad fliozofa " << id << ". Konczenie watku." << endl;
            //globalExceptionPtr = current_exception();
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    cout << "Nacisnij enter by zaczac. Nacisnij ponownie by zakonczyc program." << endl;
    std::cin.get();// zaczekaj na enter
    srand(time(NULL));
    thread f1(f,0);
    thread f2(f,1);
    thread f3(f,2);
    thread f4(f,3);
    thread f5(f,4);

    std::cin.get();// zaczekaj na enter

    loop=false;
    f1.join();
    f2.join();
    f3.join();
    f4.join();
    f5.join();

    // if (globalExceptionPtr)
    // {
        
    //     try
    //     {
    //         cout << "A?" << endl;
    //         throw(globalExceptionPtr);
    //         cout << "B?" << endl;
    //     }
    //     catch (const exception &ex)
    //     {
    //         cout << "Thread exited with exception: " << ex.what() << "\n";
    //     }
    // }
    return 0;
}