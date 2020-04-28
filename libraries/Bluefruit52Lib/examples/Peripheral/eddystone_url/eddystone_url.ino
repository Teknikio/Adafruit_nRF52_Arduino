/*!
 * This is adapted by Teknikio from  Bluefruit52Lib examples for the Arduino platform.  It is
 * designed specifically to work with the Teknikio Bluebird boards.
 *
 * Originally written by and for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */
#include <bluefruit.h>

#define URL   "https://www.teknikio.com"

// Create an EddyStone URL with rssi at 0m = -40 and URL as defined above
EddyStoneUrl eddyUrl(-40, URL);

void setup() 
{
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb

  Serial.println("Bluebird EddyStone URL Example");
  Serial.println("---------------------------------\n");

  Bluefruit.begin();
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
  Bluefruit.setName("Bluebird");

  // Setup the advertising packet
  startAdv();

  Serial.println("Broadcasting EddyStone URL, open Google Physical Web app to test");
}

void startAdv(void)
{  
  // Advertising packet
  // Set the beacon payload using the BLEBeacon class populated
  // earlier in this example
  Bluefruit.Advertising.setBeacon(eddyUrl);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * Apple Beacon specs
   * - Type: Non connectable, undirected
   * - Fixed interval: 100 ms -> fast = slow = 100 ms
   */
  //Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_ADV_NONCONN_IND);
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(160, 160);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}

void loop() 
{
  // Toggle both LEDs every second

  delay(1000);
}

