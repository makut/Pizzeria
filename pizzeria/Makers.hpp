# pragma once
# include <memory>
# include <iostream>
# include <string>
# include "Pizza.hpp"

class Maker
{
protected:
    std::string name_;
    int cost_;
    Sauce sauce_;
    Base base_;
    Topping top_;

    Maker(std::string name, int cost, Sauce sauce, Base base, Topping top) : name_(name), cost_(cost), sauce_(sauce),
                                                                             base_(base), top_(top) {}
public:

    virtual ~Maker() = 0;

    virtual void construct() = 0;

    virtual std::shared_ptr<Product> getResult() = 0;

    virtual void reset() = 0;
};

Maker::~Maker(){}

class PizzaMaker : public Maker
{
protected:
    Cheese cheese_;
public:
    PizzaMaker() : Maker("MargaritaPizza", 100, tomato, peperoni, olive),
                   cheese_(mozzarella) {}

    virtual void reset()
    {
        name_ = "MargaritaPizza";
        cost_ = 100;
        sauce_ = tomato;
        base_ = peperoni;
        top_ = olive;
        cheese_ = mozzarella;
    }

    virtual void nameProduct() = 0;
    virtual void addSauce() = 0;
    virtual void addBase() = 0;
    virtual void addTopping() = 0;
    virtual void addCheese() = 0;

    virtual void construct()
    {
        nameProduct();
        addSauce();
        addBase();
        addTopping();
        addCheese();
    }

    virtual std::shared_ptr<Product> getResult()
    {
        std::shared_ptr<Product> res(dynamic_cast<Product*>(new Pizza(name_, cost_, sauce_, base_, top_, cheese_)));
        reset();
        std::cout << "Baking " << res->getName() << "\n";
        return res;
    }
};

class SandwichMaker : public Maker
{
protected:
    Bread bread_;
public:
    SandwichMaker() : Maker("SausageSandwich", 50, mayones, peperoni, cheese),
                      bread_(white) {}

    virtual void reset()
    {
        name_ = "SausageSandwich";
        cost_ = 50;
        sauce_ = mayones;
        base_ = peperoni;
        top_ = cheese;
        bread_ = white;
    }

    virtual void nameProduct() = 0;
    virtual void addSauce() = 0;
    virtual void addBase() = 0;
    virtual void addTopping() = 0;
    virtual void addBread() = 0;

    virtual void construct()
    {
        nameProduct();
        addSauce();
        addBase();
        addTopping();
        addBread();
    }

    virtual std::shared_ptr<Product> getResult()
    {
        std::shared_ptr<Product> res(dynamic_cast<Product*>(new Sandwich(name_, cost_, sauce_, base_, top_, bread_)));
        reset();
        return res;
    }
};