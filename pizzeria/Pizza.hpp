# pragma once
# include <string>

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
    int getCost() const
    {
        return cost_;
    }

    std::string getName() const
    {
        return name_;
    }

    void setName(std::string name) : name_(name) {}

    void setPrice(int new_price) : cost_(new_price) {}
    {
        cost = new_price;
    }

    virtual ~Product();

    void setSauce(Sauce sauce) : sauce_(sauce) {}

    void setBase(Base base) : base_(base) {}

    void setTop(Topping top) : top_(top) {}
};

Product::~Product(){}

class Pizza : public Product
{
private:
    Cheese cheese_;
public:
    void setCheese(Cheese cheese) : cheese_(cheese) {}
};

class Sandwich : public Product
{
private:
    Bread bread_;
public:
    void setBread(Bread bread) : bread_(bread) {}
};