# pragma once
# include "Workers.hpp"

class StuffBrigade
{
protected:
    std::shared_ptr<Cashier> cashier_;
    std::shared_ptr<Cleaner> cleaner_;
public:
    virtual void createCashier() = 0;
    virtual void createCleaner() = 0;
    virtual void makeOrder(Maker*) = 0;
    virtual void makeClean() = 0;
    virtual ~StuffBrigade() = 0;
};
StuffBrigade::~StuffBrigade(){}

class FirstShift : public StuffBrigade
{
public:
    virtual void createCashier()
    {
        cashier_ = std::shared_ptr<Cashier>(new Cashier);
        std::cout << "First Shift Cashier hired\n";
    }

    virtual void createCleaner()
    {
        cleaner_ = std::shared_ptr<Cleaner>(new Cleaner);
        std::cout << "First Shift Cleaner hired\n";
    }

    virtual void makeOrder(Maker *maker)
    {
        cashier_->setMaker(maker);
        cashier_->conductOrder();
    }

    virtual void makeClean()
    {
        cleaner_->clean();
    }
};

class SecondShift : public StuffBrigade
{
public:
    virtual void createCashier()
    {
        cashier_ = std::shared_ptr<Cashier>(new Cashier);
        std::cout << "Second Shift Cashier hired\n";
    }

    virtual void createCleaner()
    {
        cleaner_ = std::shared_ptr<Cleaner>(new Cleaner);
        std::cout << "Second Shift Cleaner hired\n";
    }

    virtual void makeOrder(Maker *maker)
    {
        cashier_->setMaker(maker);
        cashier_->conductOrder();
    }

    virtual void makeClean()
    {
        cleaner_->clean();
    }
};