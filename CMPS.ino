//int arah;
//int homecal;
float kompass;
unsigned char high_byte, low_byte, angle8;
char pitch, roll;
unsigned int angle16;
#define CMPS12_ADDRESS 0x60  // Address of CMPS12 shifted right one bit for arduino wire library
#define ANGLE_8  1           // Register to read 8bit angle from

void ambilSudut() {
  Wire.beginTransmission(CMPS12_ADDRESS);  //starts communication with CMPS12
  Wire.write(ANGLE_8);                     //Sends the register we wish to start reading from
  Wire.endTransmission();


  // Request 5 bytes from the CMPS12
  // this will give us the 8 bit bearing,
  // both bytes of the 16 bit bearing, pitch and roll
  Wire.requestFrom(CMPS12_ADDRESS, 5);

  while (Wire.available() < 5);       // Wait for all bytes to come back

  angle8 =  Wire.read();
  high_byte = Wire.read();
  low_byte = Wire.read();
  pitch = Wire.read();
  roll = Wire.read();

  angle16 = high_byte;                 // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;

  sudut = (angle16 / 10) + (angle16 % 10);
  //  sudut = (angle16);
}

void getSudutR()//compatible dengan program yang memakai fungsi IMU
{

  ambilSudut();
  delay(2);
  //  Serial.println(sudut);

  //// ============================= CMPS REGIONAL ======================
  if (sudut >= 35 && sudut < 125)  arah = TIMUR;
  if (sudut >= 35 && sudut < 125) arah = SELATAN;
  if ((sudut >= 300) || (sudut >= 0 && sudut < 35)) arah = UTARA;
  if (sudut >= 20 && sudut < 135)arah = BARAT;


  //  if (sudut >= 160 && sudut <= 218)  arah = UTARA;
  //  if (sudut >= 218 && sudut < 292) arah = TIMUR;
  //  if (sudut >= 120 && sudut < 160) arah = BARAT;
  //  if (sudut >= 20 && sudut < 120)arah = SELATAN;
}

void cmpsDebug()
{
  Serial.println(sudut);
  getSudutR();
  //  Serial.print("roll: ");
  //  Serial.print(roll, DEC);
  //
  //  Serial.print("    pitch: ");
  //  Serial.print(pitch, DEC);
  //
  //  Serial.print("    angle full: ");
  //  Serial.print(angle16 / 10, DEC);
  //  Serial.print(".");
  //  Serial.print(angle16 % 10, DEC);
  //
  //  Serial.print("    angle 8: ");
  //  Serial.println(angle8, DEC);
  //  delay(10);
  //  display.clearDisplay();
  //  display.setTextSize(2); // Draw 2X-scale text
  //  display.setTextColor(SSD1306_WHITE);
  //  display.setCursor(30, 30);
  //  display.println(sudut);
  //  display.display();      // Show initial text

  if (bacaArah() == UTARA) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("UTARA");
    display.display();      // Show initial text
    delay(100);
  }
  if (bacaArah() == SELATAN) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("SELATAN");
    display.display();      // Show initial text
    delay(100);
  }
  if (bacaArah() == BARAT) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("BARAT");
    display.display();      // Show initial text
    delay(100);
  }
  if (bacaArah() == TIMUR) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("TIMUR");
    display.display();      // Show initial text
    delay(100);
  }
}

int bacaArah()
{
  getSudutR();
  return arah;
}

void cmpsRotate() {
  int cmpsArah;
  ambilSudut();
  int status = 0;
  //  move_y(10);
  //  //  Serial.println("Lurus");

  if (sudut >= 160 && sudut <= 218) cmpsArah = 1;
  else if (sudut >= 211 || sudut < 130) cmpsArah = 2;
  else if (sudut >= 135 && sudut < 205) cmpsArah = 3;

  switch (cmpsArah) {
    // muter kanan 90
    case 1:
      if (status == 0) {
        for (int i = 0; i >= 0; i++) {
          ambilSudut();
          if (sudut >= 160 && sudut <= 218) {
            kanan(20);
            Serial.println("Status 0");
          }
          else {
            status = 1;
          }
        }
      }
    //      break;
    //      leftWallFollower();

    // muter kiri 90
    case 2:
      if (status == 0) {
        for (int i = 0; i >= 0; i++) {
          ambilSudut();
          if (sudut >= 211 || sudut < 130) {
            kiri(20);
            Serial.println("Status 0");
          }
          else {
            status = 1;
          }
        }
      }
      break;

    // muter kanan 180
    case 3:
      if (status == 0) {
        for (int i = 0; i >= 0; i++) {
          ambilSudut();
          if (sudut >= 135 && sudut < 205) {
            kanan(20);
            Serial.println("Status 0");
          }
          else {
            status = 1;
          }
        }
      }
      break;
  }
}
