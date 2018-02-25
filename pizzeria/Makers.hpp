# pragma once
# include <memory>
# include <iostream>
# include "Pizza.hpp"

class Maker
{
protected:
    std::shared_ptr<Product> product;
public:
    virtual ~Maker() = 0;

    std::shared_ptr<Product> getResult()
    {
        std::cout << "Baking " << product->getName() << "\n";
        return product;
    }

    virtual void createNew() = 0;

    virtual void Construct() = 0;
};

Maker::~Maker(){}

class PizzaMaker : public Maker
{
public:
    virtual void createNew()
    {
        product.reset(dynamic_cast<Product*>(new Pizza));
    }

    virtual void nameProduct() = 0;
    virtual void addSauce() = 0;
    virtual void addBase() = 0;
    virtual void addTopping() = 0;
    virtual void addCheese() = 0;

    void Construct()
    {
        nameProduct();
        addSauce();
        addBase();
        addTopping();
        addCheese();
    }
};

class SandwichMaker : public Maker
{
public:
    virtual void createNew()
    {
        product.reset(dynamic_cast<Product*>(new Sandwich));
    }

    virtual void nameProduct() = 0;
    virtual void addSauce() = 0;
    virtual void addBase() = 0;
    virtual void addTopping() = 0;
    virtual void addBread() = 0;

    void Construct()
    {
        nameProduct();
        addSauce();
        addBase();
        addTopping();
        addBread();
    }
};