void setPosisi90()
{
  setpoint_kaki[0][0] = l1;
  setpoint_kaki[0][1] = 0;
  setpoint_kaki[0][2] = -l2;

  setpoint_kaki[1][0] = l1;
  setpoint_kaki[1][1] = 0;
  setpoint_kaki[1][2] = -l2;

  setpoint_kaki[2][0] = l1;
  setpoint_kaki[2][1] = 0;
  setpoint_kaki[2][2] = -l2;

  setpoint_kaki[3][0] = l1;
  setpoint_kaki[3][1] = 0;
  setpoint_kaki[3][2] = -l2;
}

int deg2dyna(float deg) {
  int dyna = map(deg, 0, 300, 0, 1023);
  return dyna;
}

int offset_awal = 25;
void center()
{
  //kanan depan
  Dynamixel.moveSpeed(0, deg2dyna(150), 200); // coxa
  Dynamixel.moveSpeed(1, deg2dyna(150), 200); // femur
  Dynamixel.moveSpeed(2, deg2dyna(150 + offset_awal), 200); // tibia

  //kanan belakang

  Dynamixel.moveSpeed(3, deg2dyna(150), 200);
  Dynamixel.moveSpeed(4, deg2dyna(150), 200);
  Dynamixel.moveSpeed(5, deg2dyna(150 + offset_awal), 200);


  //kiri depan
  Dynamixel.moveSpeed(6, deg2dyna(150), 200); // coxa
  Dynamixel.moveSpeed(7, deg2dyna(150), 200); // femur
  Dynamixel.moveSpeed(8, deg2dyna(150 + offset_awal), 200); // tibia

  //kiri belakang

  Dynamixel.moveSpeed(9, deg2dyna(150), 200);
  Dynamixel.moveSpeed(10, deg2dyna(150), 200);
  Dynamixel.moveSpeed(11, deg2dyna(150 + offset_awal), 200);
}

//void cek_move()
//{
//  Dynamixel.moveSpeed(0, deg2dyna(160), 200);
//  Dynamixel.moveSpeed(1, deg2dyna(160), 200);
//   Dynamixel.moveSpeed(2, deg2dyna(160), 200);
//  delay(500);
//  Dynamixel.moveSpeed(0, deg2dyna(140), 200);
//  Dynamixel.moveSpeed(1, deg2dyna(140), 200);
//   Dynamixel.moveSpeed(2, deg2dyna(140), 200);
//  delay(500);
//}



int kecepatan_servo = 200;

void transmitPulsa(int delay_ms)
{
  //  getSRF();
  //kanan depan
  Dynamixel.moveSpeed(0, deg2dyna(150 + pulsa_kaki[0][0]), kecepatan_servo);
  Dynamixel.moveSpeed(1, deg2dyna(150 + pulsa_kaki[0][1]), kecepatan_servo);
  Dynamixel.moveSpeed(2, deg2dyna(150 + pulsa_kaki[0][2] - 40), kecepatan_servo);
  //  getSRF();
  //  ////kiri belakang
  Dynamixel.moveSpeed(9, deg2dyna(150 + pulsa_kaki[2][0]), kecepatan_servo);
  Dynamixel.moveSpeed(10, deg2dyna(150 + pulsa_kaki[2][1] ), kecepatan_servo);
  Dynamixel.moveSpeed(11, deg2dyna(150 + pulsa_kaki[2][2] - 40), kecepatan_servo);
  //  getSRF();
  //  //kiri
  Dynamixel.moveSpeed(6, deg2dyna(150 + pulsa_kaki[1][0]), kecepatan_servo);
  Dynamixel.moveSpeed(7, deg2dyna(150 + pulsa_kaki[1][1]), kecepatan_servo);
  Dynamixel.moveSpeed(8, deg2dyna(150 + pulsa_kaki[1][2] - 40), kecepatan_servo);
  //
  //  getSRF();
  //  //kanan belakang
  Dynamixel.moveSpeed(3, deg2dyna(150 + pulsa_kaki[3][0]), kecepatan_servo);
  Dynamixel.moveSpeed(4, deg2dyna(150 + pulsa_kaki[3][1]), kecepatan_servo);
  Dynamixel.moveSpeed(5, deg2dyna(150 + pulsa_kaki[3][2] - 40), kecepatan_servo);
  //  getSRF();
  delay(delay_ms);
}

void setPosisi()
{
  setpoint_kaki[0][0] = l1;
  setpoint_kaki[0][1] = 0;
  setpoint_kaki[0][2] = -l2;

  setpoint_kaki[1][0] = l1;
  setpoint_kaki[1][1] = 0;
  setpoint_kaki[1][2] = -l2;

  setpoint_kaki[2][0] = l1;
  setpoint_kaki[2][1] = 0;
  setpoint_kaki[2][2] = -l2;

  setpoint_kaki[3][0] = l1;
  setpoint_kaki[3][1] = 0;
  setpoint_kaki[3][2] = -l2;
  gerakStatis(0, 0, 0, 80, 2000);
}
