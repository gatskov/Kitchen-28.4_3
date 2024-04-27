#include <iostream>
#include "kit.h"
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <mutex>
#include <cstdlib>
#include <random>

std::mutex kt;
 
int Kitchen::waitingTime(int lb, int ub)
{
    std::srand(std::time(0));
    return (rand() % (ub - lb + 1)) + 2;
}
    void Kitchen::orders()
{
    std::string dish;
      std::srand(std::time(0)); 
      dish = order[rand() % order.size()];
     std::cout << "received order-> " << dish <<"\n";
     std::this_thread::sleep_for(std::chrono::seconds(waitingTime(5, 10)));
}

void Kitchen::priparingOrders()
{
    std::cout << "order-> accepted\n";
    std::this_thread::sleep_for(std::chrono::seconds(waitingTime(5, 15)));
    std::cout << "order-> ready\n";
}

void Kitchen::deliveryOrders()
{
    std::this_thread::sleep_for(std::chrono::seconds(8));
    std::cout << "orders-> sent for delivery\n";
    std::this_thread::sleep_for(std::chrono::seconds(18));
    std::cout << "orders-> delivered\n";
}

void Kitchen::startSimulation()
{
   for(int i(0);i < 9; ++i)
    {
        orders();
     std::unique_lock<std::mutex> ul(kt);
     std::thread kit([&]()
                      { priparingOrders(); });
     kit.detach();
     ul.unlock();
     deliveryOrders(); 
std::cout << "++++++++++++++++++\n";
}
    std::cout << std::endl;
    std::cout << "     +----------------+\n";
    std::cout << "     | Kitchen closed |\n";
    std::cout << "     +----------------+\n";
    std::cin.get();
}

void Kitchen::Clear()
{
    std::cout << "\033[2J\033[1;1H";
}
