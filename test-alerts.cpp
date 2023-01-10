#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include"Check_Limit.h"
#include "Alert.h"

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





