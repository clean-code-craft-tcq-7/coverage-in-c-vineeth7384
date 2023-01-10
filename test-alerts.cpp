#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include"Check_Limit.h"
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to High") {
  REQUIRE(inferBreach(30, 10, 20) == TOO_LOW);
}
TEST_CASE("infers the breach according to Normal") {
  REQUIRE(inferBreach(20, 10, 40) == Normal);
}
TEST_CASE(" SendAlert messages to controller in high state") {
  REQUIRE(SendAlertMessage(TO_CONTROLLER, TOO_HIGH);
}
TEST_CASE(" SendAlert messages to controller in low state") {
  REQUIRE(SendAlertMessage(TO_CONTROLLER, TOO_LOW);
}
TEST_CASE(" SendAlert messages to email in high state") {
  REQUIRE(SendAlertMessage(TO_EMAIL, TOO_HIGH);
}
TEST_CASE(" SendAlert messages to controller in low state") {
  REQUIRE(SendAlertMessage(TO_EMAIL, TOO_LOW);
}



