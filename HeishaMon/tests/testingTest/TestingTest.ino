#line 2 "TestingTest"

#include <AUnit.h>

using namespace aunit;

test(correct) {
  int x = 1;
  assertEqual(x, 1);
}

test(incorrect) {
  int x = 1;
  assertNotEqual(x, 1);
}

// -----------------------------------------------------------------------------
// Tests
// -----------------------------------------------------------------------------

testF(CustomTest, test_math) {
    float expected[] = {3};
    run_and_compare("5 2 * 3 + 5 mod", sizeof(expected)/sizeof(float), expected);
}

testF(CustomTest, test_math_advanced) {
    float expected[] = {1};
    run_and_compare("10 2 pow sqrt log10", sizeof(expected)/sizeof(float), expected);
}

testF(CustomTest, test_trig) {
    float expected[] = {1};
    run_and_compare("pi 4 / cos 2 sqrt *", sizeof(expected)/sizeof(float), expected);
}

testF(CustomTest, test_cast) {
    float expected[] = {2, 1, 3.1416, 3.14};
    run_and_compare("pi 2 round pi 4 round 1.1 floor 1.1 ceil", sizeof(expected)/sizeof(float), expected);
}

// void setup() {

//     Serial.begin(115200);
//     delay(2000);

//     Printer::setPrinter(&Serial);
//     //TestRunner::setVerbosity(Verbosity::kAll);

// }

//----------------------------------------------------------------------------
// setup() and loop()
//----------------------------------------------------------------------------

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // wait for stability on some boards to prevent garbage Serial
#endif
  Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
  while (!Serial); // for the Arduino Leonardo/Micro only
#if defined(EPOXY_DUINO)
  Serial.setLineModeUnix();
#endif

  //TestRunner::setVerbosity(Verbosity::kAll);

  Serial.println(F("This test should produce the following:"));
  Serial.println(
    F("3 passed, 1 failed, 0 skipped, 0 timed out, out of 4 test(s).")
  );
  Serial.println(F("----"));
}

void loop() {
  TestRunner::run();
}
