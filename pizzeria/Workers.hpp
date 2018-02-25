# pragma once
# include "ConcreteMakers.hpp"

class Cashier
{
private:
    Maker *maker_;
public:
    Cashier(){}

    void setMaker(Maker *maker)
    {
        maker_ = maker;
    }

    void conductOrder()
    {
        maker_->Construct();
        maker_->getResult();
        std::cout << "Order finished\n";
    }
};

class Cleaner
{
public:
    void clean()
    {
        std::cout << "Clean completed\n";
    }
};