# pragma once
# include <string>
# include <iostream>
# include <memory>

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
    const std::string name_;
    const int cost_;
    const Sauce sauce_;
    const Base base_;
    const Topping top_;
public:
    Product(const std::string &name, int cost, Sauce sauce, Base base, Topping top) : name_(name), cost_(cost),
                                                                                      sauce_(sauce), base_(base),
                                                                                      top_(top) {}

    std::string getName() const
    {
        return name_;
    }

    int getCost() const
    {
        return cost_;
    }

    Sauce getSauce() const
    {
        return sauce_;
    }

    Base getBase() const
    {
        return base_;
    }

    Topping getTopping() const
    {
        return top_;
    }

    virtual ~Product();

    friend void serveDish(const std::shared_ptr<Product>&);
};

Product::~Product(){}

class Pizza : public Product
{
private:
    const Cheese cheese_;
public:
    Pizza(const std::string &name, int cost, Sauce sauce,
           Base base, Topping top, Cheese cheese) : Product(name, cost, sauce, base, top),
                                                    cheese_(cheese) {}

    Cheese getCheese() const
    {
        return cheese_;
    }
};

class Sandwich : public Product
{
private:
    const Bread bread_;
public:
    Sandwich(const std::string &name, int cost, Sauce sauce, 
             Base base, Topping top, Bread bread) : Product(name, cost, sauce, base, top),
                                                    bread_(bread) {}

    Bread getBread() const
    {
        return bread_;
    }
};

void serveDish(const std::shared_ptr<Product> &prod)
{
    std::cout << "Served " << prod->name_ << "\n";
}