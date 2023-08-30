// FINGERING CHART PIC: https://i.pinimg.com/originals/75/6e/85/756e85ad78e1009c5106f1788345634e.jpg

// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
boolean C = false;
boolean D = false;
boolean E = false;
boolean F = false;
boolean G = false;
boolean A = false;
boolean B = false;

boolean h1 = false;
boolean h2 = false;
boolean h3 = false;
boolean h4 = false;
boolean h5 = false;
boolean h6 = false;
boolean h7 = false;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  SerialBT.begin("Recorder Hero Device"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  int touch_data1 = touchRead(T7);
  int touch_data2 = touchRead(T9);
  int touch_data3 = touchRead(T3);
  int touch_data4 = touchRead(T8);
  int touch_data5 = touchRead(T6);
  int touch_data6 = touchRead(T0);
  int touch_data7 = touchRead(T5);

  boolean h1 = false;
  boolean h2 = false;
  boolean h3 = false;
  boolean h4 = false;
  boolean h5 = false;
  boolean h6 = false;
  boolean h7 = false;

  if (touch_data1 < 30 && touch_data1 > 0) {
    h1 = true;
  }
  if (touch_data2 < 30 && touch_data2 > 0) {
    h2 = true;
  }
  if (touch_data3 < 30 && touch_data3 > 0) {
    h3 = true;
  }
  if (touch_data4 < 30 && touch_data4 > 0) {
    h4 = true;
  }
  if (touch_data5 < 30 && touch_data5 > 0) {
    h5 = true;
  }
  if (touch_data6 < 30 && touch_data6 > 0) {
    h6 = true;
  }
  if (touch_data7 < 30 && touch_data7 > 0) {
    h7 = true;
  }

  if (h1 == true && h2 == true && h3 == true && h4 == true && h5 == true && h6 == true && h7 == true) {
    //C = true;
    SerialBT.write(67);
  }
  else if (h1 == true && h2 == true && h3 == true && h4 == true && h5 == true && h6 == true && h7 == false) {
    //C = true;
    SerialBT.write(68);
  }
  else if (h1 == true && h2 == true && h3 == true && h4 == true && h5 == true && h6 == false && h7 == false) {
    //C = true;
    SerialBT.write(69);
  }
  else if (h1 == true && h2 == true && h3 == true && h4 == true && h5 == false && h6 == true && h7 == true) {
    //C = true;
    SerialBT.write(70);
  }
  else if (h1 == true && h2 == true && h3 == true && h4 == false && h5 == false && h6 == false && h7 == false) {
    //C = true;
    SerialBT.write(71);
  }
  else if (h1 == true && h2 == true && h3 == false && h4 == false && h5 == false && h6 == false && h7 == false) {
    //C = true;
    SerialBT.write(65);
  }
  else if (h1 == true && h2 == false && h3 == false && h4 == false && h5 == false && h6 == false && h7 == false) {
    //C = true;
    SerialBT.write(66);
  }
  else if (h1 == false && h2 == false && h3 == false && h4 == false && h5 == false && h6 == false && h7 == false) {
    SerialBT.write(78);
  }
  delay(20);
}
