# pragma once
# include "Makers.hpp"

class HawaiiPizzaMaker : public PizzaMaker
{
public:
    void nameProduct()
    {
        product->setName("HawaiiPizza");
    }

    void addSauce()
    {
        product->setSauce(tomato);
    }

    void addBase()
    {
        product->setBase(ham);
    }

    void addTopping()
    {
        product->setTop(ananas);
    }

    void addCheese()
    {
        product->setCheese(mozzarella);
    }
};

class ChickenSandwichMaker : public SandwichMaker
{
public:
    void nameProduct()
    {

    }

    void addSauce()
    {
        product->setSauce(cheesy);
    }

    void addBase()
    {
        product->setBase(chicken);
    }

    void addTopping()
    {
        product->setTop(olive);
    }

    void addBread()
    {
        product->setCheese(white);
    }
};