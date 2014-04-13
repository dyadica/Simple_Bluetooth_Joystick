void setup()
{
  // Delay to facilitate start up of Xbee usually about 
  // 5 seconds. Comment out if using wired serial etc.
  delay(6000);  
  // Initialise the serial port. 115200 is the default
  // baudrate of both the BluetoothMate & BlueSmirf
  Serial.begin(115200); 
}

void loop()
{
  // Read in the joystick x  
  float x = analogRead(A0);  
  // Read in the joystick y  
  float y = analogRead(A1);  
  // Read in the button press
  boolean p = digitalRead(11);  
  // Map the read in values to the
  // desired joystick range.
  x = map(x, 0, 1023, -100.0, 100.0);
  y = map(y, 0, 1023, -100.0, 100.0);  
  // Output the data via serial
  outputSerialData();
}

void outputSerialData()
{
  // Joystick x
  Serial.print(x); Serial.print(",");
  // Joystick y
  Serial.print(y); Serial.print(",");
  // Button press and line return
  Serial.print(p); Serial.println();
}
