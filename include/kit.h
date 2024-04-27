#pragma once
#include <vector>
class Kitchen
{
public:
    std::vector<std::string> order = {"Pizza" ,  "Soup" , "Steak" ,  "Salat", "Sushi"}; // { " Pizza ", " Soup ", " Steak ", " Salat ", " Sushi " };
    int get_orderName();
    int  waitingTime(int lb, int ub);
    void orders();
    void priparingOrders();
    void deliveryOrders();

    void startSimulation();

    void Clear();
};
