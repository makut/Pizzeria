# pragma once
# include <string>
# include <iostream>

enum Sauce 
{
    tomato, cheesy, pesto, mayones
};

enum Base
{
    meat, peperoni, chicken, ham
};

enum Topping
{
    cheese, mushrooms, olive, ananas
};

enum Bread
{
    black, white, sesame
};

enum Cheese
{
    mozzarella, cheddar, parmesan
};

class Product
{
private:
    std::string name_;
    int cost_;
    Sauce sauce_;
    Base base_;
    Topping top_;
public:
    Product() : cost_(0) {}

    std::string getName() const
    {
        return name_;
    }

    int getCost() const
    {
        return cost_;
    }

    Sauce getSauce()
    {
        return sauce_;
    }

    Base getBase()
    {
        return base_;
    }

    Topping getTopping()
    {
        return top_;
    }

    void setName(std::string name)
    {
        name_ = name;
    }

    void setPrice(int new_price)
    {
        cost_ = new_price;
    }

    virtual ~Product();

    void setSauce(Sauce sauce)
    {
        sauce_ = sauce;
    }

    void setBase(Base base)
    {
        base_ = base;
    }

    void setTop(Topping top)
    {
        top_ = top;
    }

    virtual void setCheese(Cheese) {}
    virtual void setBread(Bread) {}
};

Product::~Product(){}

class Pizza : public Product
{
private:
    Cheese cheese_;
public:
    Cheese getCheese()
    {
        return cheese_;
    }

    void setCheese(Cheese cheese)
    {
        cheese_ = cheese;
    }
};

class Sandwich : public Product
{
private:
    Bread bread_;
public:
    Bread getBread()
    {
        return bread_;
    }

    void setBread(Bread bread)
    {
        bread_ = bread;
    }
};