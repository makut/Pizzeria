# include "Workers.hpp"

class StuffBrigade
{
protected:
    Cashier *cashier_;
    Cleaner *cleaner_;
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
        cashier_ = new Cashier;
        std::cout << "First Shift Cashier hired\n";
    }

    virtual void createCleaner()
    {
        cleaner_ = new Cleaner;
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
        cashier_ = new Cashier;
        std::cout << "Second Shift Cashier hired\n";
    }

    virtual void createCleaner()
    {
        cleaner_ = new Cleaner;
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