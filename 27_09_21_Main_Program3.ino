#include <Wire.h>
#include <math.h>
#include <DynamixelSerial.h>
#define buzzer 5
#include <TimerOne.h>
#include <TimerThree.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Pixy2SPI_SS.h>
Pixy2SPI_SS pixy;

// For teensy
//IntervalTimer myTimer;
#define cycle_time1 10000 //us
#define cycle_time3 10000 //us

// Inverse Kinematics
#define rad_per_deg 0.017453293
#define deg_per_rad 57.29577951
#define pulse_per_deg 10.0

#define l1 45
#define l2 115

#define ON 1
#define OFF 0
#define AX 0
#define XL 1

int buttonState = 0;
const int buttonPin = 24;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Compass
int KANAN, KIRI;
//#define   BARAT     135
//#define   TIMUR     220
//#define   UTARA     180
//#define   SELATAN   105

#define   BARAT     295
#define   TIMUR     125
#define   UTARA     360
#define   SELATAN   235

// IK Variable
float step_x, step_y, step_z;
float teta, teta1, teta2;
int setpoint_kaki[8][3], koordinat_awal[6][3];
int pulsa_kaki[6][3];
float dx[6], dy[6];

char kaki_kiri[100], kaki_kanan[100] ;
char angkat = 0;
int delay_ms = 100;

int srf1, srf2, srf3, srf4, srf5, srf6, srf7, srf8;
int sgp1, sgp2, sgp3, sgp4, sgp5, sgp6, sgp7, sgp8;
int mux1, mux2, mux3, mux4, mux5, mux6, mux7, mux8, mux9, mux10, mux11, mux12, mux13, mux14, mux15;
int line1, line2, line3;
int arah, uvstat;
float sudut;

float deadZone = 0.15;

void cek_buzzer()
{ digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial3.begin(115200);
  Serial5.begin(115200);
  first_setup();
  XLsetup();
  pixy.init();
  pinMode(29, OUTPUT);  //define enable pin here
  digitalWrite(29, ON); //and here too

  Dynamixel.setSerial(&Serial4); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
  Dynamixel.begin(1000000, 29); // Inicialize the servo at 1 Mbps and Pin Control 2

  armInit();

  pinMode(buzzer, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(A19, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  setPosisi90();
  step_z = 20; //use this to change height step//Higher the nuumber, higher the step//default is 20
  center();
  setPosisi();
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();
  //  delay(3000);

  Timer1.initialize(cycle_time1);
  Timer1.attachInterrupt(SerialReadSlave);
  Timer3.initialize(cycle_time3);
  Timer3.attachInterrupt(SerialRead);
}

void loop()
{
  //    extinguisher();
  //        muxDebug();
  //  Serial.println(mux10);

  //  for (int i = 0; i >= 0; i++) {
  //    ambilSudut();
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 10);
  //    display.println(sudut);
  //    display.display();      // Show initial text
  //    delay(100);
  //  }

  //    // Utara -> Timur
  //    if ((sudut >= 345) || (sudut >= 0 && sudut < 70)) {
  //      kanan(10);
  //      Serial.println("Status 0");
  //    }
  //
  //    // Selatan -> Timur
  //    if (sudut >= 100 && sudut < 270) {
  //      kiri(10);
  //      Serial.println("Status 0");
  //    }
  //  }

  //    for (int i = 0; i >= 0; i++) {
  //      ambilSudut();
  //      display.clearDisplay();
  //      display.setTextSize(2); // Draw 2X-scale text
  //      display.setTextColor(SSD1306_WHITE);
  //      display.setCursor(10, 10);
  //      display.println(sudut);
  //      display.display();      // Show initial text
  //      delay(100);
  //    }

  cekButton();
}
