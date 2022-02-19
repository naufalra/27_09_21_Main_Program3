void armInit() {
  first_setup();
  XLsetup();
  pixy.init();
  // init before extinguishing
  converter(13, 20, 105);  //Higher is UPPER
  converter(14, 20, 50); //Higher is LOWER
  converter(15, 20, 180); //tutup 180, lower is open
  packet_builder(XL);
}

void armFirstPos() {
  first_setup();
  XLsetup();
  pixy.init();

  // after extinguishing
  converter(13, 20, 90);  //Higher is UPPER
  converter(14, 20, 105);  //Higher is LOWER
  converter(15, 20, 180); //tutup 180, 120 is open
  packet_builder(XL);
}

void victimDetected() {
  first_setup();
  XLsetup();
  pixy.init();

  // Move Forward, Gripper: Open
  converter(13, 20, 90);  //Higher is UPPER
  converter(14, 20, 60);  //Higher is LOWER
  converter(15, 20, 100); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);

  // Move Forward, Gripper: Open
  converter(13, 20, 135);  //Higher is UPPER
  converter(14, 20, 165);  //Higher is LOWER
  converter(15, 20, 100); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);

  // Gripper: Closed
  converter(15, 20, 180); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);

  converter(13, 20, 180);  //Higher is lower
  converter(14, 20, 180); //Lower is upper
  converter(15, 20, 180); //tutup 180, lower is open
  packet_builder(XL);
  delay(200);
}

void victimRescue() {
  first_setup();
  XLsetup();
  pixy.init();
  converter(13, 20, 120);  //Higher is UPPER
  converter(14, 20, 130);  //Higher is LOWER
  converter(15, 20, 180); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);
  converter(15, 20, 120); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);
  converter(13, 20, 90);  //Higher is UPPER
  converter(14, 20, 60);  //Higher is LOWER
  converter(15, 20, 180); //tutup 180, 120 is open
  packet_builder(XL);
  delay(1000);
}

void victimCheck() {
  armFirstPos();
  int pixyStatus = 0;
  float korban = pixyCheck();
  if (korban > - deadZone && korban < deadZone) {
    korban = 0;
  }

  if (korban > 0.95) { //Forward
    center();
    Serial.print("Detected");
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    //    display.setCursor(10, 0);
    //    display.println("Detected");
    display.setCursor(10, 0);
    display.println(pixyCheck());
    display.display();      // Show initial text

    victimDetected();
    if (pixyStatus == 0) {
      for (int i = 0; i >= 0; i++) {
        korban = 0;
        if (korban = 0) {
          korban++;
          victimDetected();
          Serial.println(pixyCheck());
        }
        else {
          Serial.println(pixyCheck());
          pixyStatus = 1;
          converter(13, 20, 180);  //Higher is lower
          converter(14, 20, 180); //Lower is upper
          converter(15, 20, 180); //tutup 180, lower is open
          packet_builder(XL);
        }
      }
    }
  }

  else if (korban >= 0.4 && korban < 0.95) {
    Serial.print("Victim Detected!");
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    //    display.setCursor(10, 0);
    //    display.println("Victim Detected!");
    display.setCursor(10, 0);
    display.println(pixyCheck());
    display.display();      // Show initial text

    converter(13, 20, 90);  //Higher is UPPER
    converter(14, 20, 105);  //Higher is LOWER
    converter(15, 20, 100); //tutup 180, 120 is open
    packet_builder(XL);

    move_y(5);
  }

  else if (korban <= 0.0) { // Forward
    armFirstPos();

    Serial.print("Waiting");
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    //    display.setCursor(10, 0);
    //    display.println("Waiting");
    display.setCursor(10, 0);
    display.println(pixyCheck());
    display.display();      // Show initial text

    move_y(5);
  }
}

struct data_servo
{
  byte position_H, speed_H, position_L, speed_L;
};

data_servo data[200];
byte packet_data[200];
int S;
uint16_t CRC = 0;
uint16_t CRC_L = 0;
uint16_t CRC_H = 0;

enum eInstruction
{
  R_GoalPosition = 0x1E,
  R_SyncWrite = 0x83,
  R_Torsi = 0x18,
};

enum Serial
{
  Baudrate = 1000000, //Servo Baudrate
};

////=====================Interface Fungsi===================================
////void first_setup();
////void XLSetup(void);
////void converter(int speed, int position);
////void packet_servo(int id, int position, int speed);
////void packet_builder(int jenis_servo, byte instruction, int speed, int position, int id, int banyak_servo);
////void packet_sender(int jenis_servo, byte *packet_ready, int length);
////void packet_builder(int jenis_servo);
////void torsiXL(int torsi_status);
////uint16_t update_crc(uint16_t crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);
////========================================================================

void first_setup()
{
  Serial.begin(9600);
  delay(1000);
  pinMode(29, OUTPUT);  //define enable pin here
  digitalWrite(29, ON); //and here too
}


void XLsetup(void)
{
  Serial4.begin(Baudrate, SERIAL_8N1);
  torsiXL(ON);
}

void converter(int id, int speed, int position)
{
  int position_bit = (1023 / 300) * position, //in degree
      speed_bit = (1023 / 100) * speed;       // speed just between 0 - 100
  packet_servo(id, position_bit, speed_bit);
}

void packet_servo(int id, int position, int speed)
{
  data[id].position_L = position;
  data[id].position_H = position >> 8;
  data[id].speed_L = speed;
  data[id].speed_H = speed >> 8;
}

void packet_sender(int jenis_servo, byte *packet_ready, int length)
{
  if (jenis_servo == XL)
  {
    Serial4.clear();
    Serial4.write(packet_ready, length);
    Serial4.flush();
  }

  for (int i = 0; i < length; i++)
  {
    //Serial.println(packet_ready[i]);
  }

  for (int i = 0; i < length; i++)
  {
    packet_ready[i] = 0; //clean up packet tracer
  }

  S = 0;
}

uint16_t update_crc(uint16_t crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size)
{
  uint16_t i, j;
  uint16_t crc_table[256] = {
    0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
    0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
    0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
    0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
    0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
    0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
    0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
    0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
    0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
    0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
    0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
    0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
    0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
    0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
    0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
    0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
    0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
    0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
    0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
    0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
    0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
    0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
    0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
    0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
    0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
    0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
    0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
    0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
    0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
    0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
    0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
    0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
  };

  for (j = 0; j < data_blk_size; j++)
  {
    i = ((uint16_t)(crc_accum >> 8) ^ data_blk_ptr[j]) & 0xFF;
    crc_accum = (crc_accum << 8) ^ crc_table[i];
  }
  return crc_accum;
}

void packet_builder(int jenis_servo)
{
  if (jenis_servo == 1)
  {
    S = 0;
    packet_data[S++] = 0xFF;                   //Header 1
    packet_data[S++] = 0xFF;                   //Header 2
    packet_data[S++] = 0xFD;                   //Header 3
    packet_data[S++] = 0x00;                   //Reserved
    packet_data[S++] = 0xFE;                   //ID (Broadcast 0xFE)
    packet_data[S++] = ((3 * 5) + 3 + 4);      //length
    packet_data[S++] = ((3 * 5) + 3 + 4) >> 8; //length (HIGH)
    packet_data[S++] = R_SyncWrite;            //Instruction, SyncWrite 0x83
    packet_data[S++] = R_GoalPosition;         //adress instruksi yang akan di syncwrite goal potition 30 (0x1E)
    packet_data[S++] = R_GoalPosition >> 8;    //adress instruksi yang akan di syncwrite goal potition 30 (0x1E) (HIGH)
    packet_data[S++] = 0x04;                   //panjang data per servo, Posisi sama speed jadi 4 buah
    packet_data[S++] = 0x04 >> 8;              //panjang data per servo, Posisi sama speed jadi 4 buah (HIGH)

    for (int i = 13; i < (13 + 3); i++)
    {
      packet_data[S++] = i;                  //servo ID
      packet_data[S++] = data[i].position_L; //
      packet_data[S++] = data[i].position_H; //
      packet_data[S++] = data[i].speed_L;    //
      packet_data[S++] = data[i].speed_H;    //
    }
    CRC = update_crc(0, packet_data, S);
    CRC_L = (CRC & 0x00FF);
    CRC_H = (CRC >> 8) & 0x00FF;
    packet_data[S++] = CRC_L;
    packet_data[S++] = CRC_H;
    packet_sender(XL, packet_data, S);
  }
}

/*
   Jangan Diganti, fungsi ini digunakan untuk mengirim

*/
void torsiXL(int torsi_status)
{
  int S = 0;
  packet_data[S++] = 0xFF;                   //Header 1
  packet_data[S++] = 0xFF;                   //Header 2
  packet_data[S++] = 0xFD;                   //Header 3
  packet_data[S++] = 0x00;                   //Reserved
  packet_data[S++] = 0xFE;                   //ID (Broadcast 0xFE)
  packet_data[S++] = (3 * 2) + 3 + 4;        //length
  packet_data[S++] = ((3 * 2) + 3 + 4) >> 8; //length (HIGH)
  packet_data[S++] = R_SyncWrite;            //Instruction, SyncWrite 0x83
  packet_data[S++] = R_Torsi;                //adress instruksi yang akan di syncwrite torsi (0x40E)
  packet_data[S++] = R_Torsi >> 8;           //adress instruksi yang akan di syncwrite goal potition 30 (0x1E) (HIGH)
  packet_data[S++] = 0x01;                   //panjang data per servo, Posisi sama speed jadi 4 buah
  packet_data[S++] = 0x01 >> 8;              //panjang data per servo, Posisi sama speed jadi 4 buah (HIGH)

  for (int i = 13; i < 16; i++)
  {
    packet_data[S++] = i;
    packet_data[S++] = torsi_status;
  }
  CRC = update_crc(0, packet_data, S);
  CRC_L = (CRC & 0x00FF);
  CRC_H = (CRC >> 8) & 0x00FF;
  packet_data[S++] = CRC_L;
  packet_data[S++] = CRC_H;
  //  Serial.println("-> Torsi XL sudah nyala!");
  packet_sender(XL, packet_data, S);
}
