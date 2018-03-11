# include "pizzeria/Pizzeria.hpp"
# include <gtest/gtest.h>

TEST(PizzaTest, HawaiiPizza)
{
    testing::internal::CaptureStdout();
    HawaiiPizzaMaker maker;
    maker.construct();
    std::shared_ptr<Product> result = maker.getResult();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Baking HawaiiPizza\n");
    EXPECT_EQ(result->getName(), "HawaiiPizza");
    EXPECT_EQ(result->getSauce(), tomato);
    EXPECT_EQ(result->getBase(), ham);
    EXPECT_EQ(result->getTopping(), ananas);
}

TEST(StuffTest, CleanerTest)
{
    testing::internal::CaptureStdout();
    std::shared_ptr<StuffBrigade> brigade(new FirstShift);
    brigade->createCleaner();
    brigade->makeClean();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "First Shift Cleaner hired\nClean completed\n");
}

TEST(StuffTest, CashierTest)
{
    testing::internal::CaptureStdout();
    std::shared_ptr<StuffBrigade> brigade(new SecondShift);
    brigade->createCashier();
    brigade->makeOrder(new HawaiiPizzaMaker);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Second Shift Cashier hired\nBaking HawaiiPizza\nServed HawaiiPizza\nOrder finished\n");
}