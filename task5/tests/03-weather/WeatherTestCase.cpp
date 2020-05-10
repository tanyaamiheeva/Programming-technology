//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "cpr/cpr.h"
#include "WeatherMock.h"

using ::testing::Return;

void WeatherTestCase::SetUp()
{
    Kyoto.status_code = 200;
    Kyoto.text = "{\"cod\":\"200\",\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":11.00}}]}";
    Tokyo.status_code = 200;
    Tokyo.text = "{\"cod\":\"200\",\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":19.00}}]}";
    Error404.status_code = 404;
}

TEST_F(WeatherTestCase, FirstTest)
{
    EXPECT_CALL(weather, Get("Kyoto"))
        .Times(1)
        .WillRepeatedly(Return(Kyoto));
    ASSERT_NO_THROW(weather.Get("Kyoto"));
}

TEST_F(WeatherTestCase, SecondTest)
{
    EXPECT_CALL(weather, Get("None"))
        .Times(1)
        .WillRepeatedly(Return(Error404));
    ASSERT_THROW(weather.GetResponseForCity("None"), std::invalid_argument);
}

TEST_F(WeatherTestCase, ThirdTest)
{
    EXPECT_CALL(weather, Get("Kyoto"))
        .Times(1)
        .WillRepeatedly(Return(Kyoto));
    EXPECT_CALL(weather, Get("Tokyo"))
        .Times(1)
        .WillRepeatedly(Return(Tokyo));
    
    ASSERT_EQ(weather.GetDifferenceString("Kyoto", "Tokyo"), "Weather in Kyoto is colder than in Tokyo by 8 degrees");
}

TEST_F(WeatherTestCase, FourthTest)
{
    EXPECT_CALL(weather, Get("Kyoto"))
        .Times(1)
        .WillRepeatedly(Return(Kyoto));
    EXPECT_CALL(weather, Get("Tokyo"))
        .Times(1)
        .WillRepeatedly(Return(Tokyo));
    
    ASSERT_EQ(weather.GetDifferenceString("Tokyo", "Kyoto"), "Weather in Tokyo is warmer than in Kyoto by 8 degrees");
}

TEST_F(WeatherTestCase, API)
{
    ASSERT_NO_THROW(weather.SetApiKey("key"));
}


