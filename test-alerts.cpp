#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include"Check_Limit.h"
#include "Alert.h"
#include "BreachClassify.h"
#include "string.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to Normal") {
  REQUIRE(inferBreach(20, 10, 40) == NORMAL);
}
TEST_CASE("infers the breach according to high") {
  REQUIRE(inferBreach(60, 10, 40) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach passive cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach acive cooling cooling") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach medactive cooling") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach passive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach acive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach medactive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 60) == TOO_HIGH);
}

char buf[50];
TEST_CASE("send email alert high") {
  const char*src = "Hi, the temperature is too high\n";
  BatteryCharacter batteryCharTest;
batteryCharTest.coolingType = PASSIVE_COOLING;
checkAndAlert(TO_EMAIL,batteryCharTest,50,&buf[0]);
 REQUIRE(strcmp( buf,src)!=0);
  }

const char*src = "0xfeed : TOO_HIGH";
TEST_CASE("send controller alert high") {
  BatteryCharacter batteryCharTest;
batteryCharTest.coolingType = HI_ACTIVE_COOLING;
checkAndAlert(TO_CONTROLLER,batteryCharTest,60,&buf[0]);
 REQUIRE(strcmp( buf,src)!=0);
  }
  

