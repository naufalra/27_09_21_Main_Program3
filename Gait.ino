void kiri90() {
  for (int i = 0; i < 10; i++) {
    kiri(10);
  }
}

void move_y(float y)
{
  step_x = 0;
  step_y = y;
  jalan(0); //forward/backward
  //  getSRF();
}

void mundur(float y)
{
  step_x = 0;
  step_y = -y;
  jalan(0); //forward/backward
  //  getSRF();
}

void kanan(float z)
{
  step_x = 0;
  step_y = z;
  jalan(1); //turn
  //  getSRF();
}

void kiri(float z)
{
  step_x = 0;
  step_y = -z;
  jalan(1); //turn
  //  getSRF();
}

void gerak_ditempat()
{
  step_y = 0;
  step_x = 0;
  jalan(0);
  //  getSRF();
}

void jalan(int status_jalan)
{
  //Serial.println("okejalan");
  //  getSRF();
  switch (angkat)
  {
    case 0 :
      //Serial.print("langkah1 ");
      IK(0, 0, 0, step_z, status_jalan); //kaki kanan angkat
      IK(1, 0, 0, 0, status_jalan); //kaki kiri diam
      IK(2, 0, 0, step_z, status_jalan); //kaki kanan angkat
      IK(3, 0, 0, 0, status_jalan); //kaki kiri diam
      //getSRF();
      transmitPulsa(delay_ms); //timestep, delay

      //Serial.print("langkah 2 ");
      IK(0, step_x, step_y, step_z, status_jalan); //kaki kanan geser sejauh x,y
      IK(1, -step_x, -step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      IK(2, step_x, step_y, step_z, status_jalan); //kaki kanan geser sejauh x,y
      IK(3, -step_x, -step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      //getSRF();
      transmitPulsa(delay_ms);

      //Serial.print("langkah 3 ");
      IK(0, step_x, step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(1, -step_x, -step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      IK(2, step_x, step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(3, -step_x, -step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      //getSRF();
      transmitPulsa(delay_ms);
      angkat++;

      break;
    case 1 :

      //Serial.print("langkah 4 ");
      IK(0, 0, 0, 0, status_jalan); //kaki kanan angkat
      IK(1, 0, 0, step_z, status_jalan); //kaki kiri diam
      IK(2, 0, 0, 0, status_jalan); //kaki kanan angkat
      IK(3, 0, 0, step_z, status_jalan); //kaki kiri diam
      //      getSRF();
      transmitPulsa(delay_ms);

      //Serial.print("langkah 5 ");
      IK(0, -step_x, -step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(1, step_x, step_y, step_z, status_jalan); //kaki kiri geser sejauh -x,-y
      IK(2, -step_x, -step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(3, step_x, step_y, step_z, status_jalan); //kaki kiri geser sejauh -x,-y
      //      getSRF();
      transmitPulsa( delay_ms);

      //Serial.print("langkah 6 ");
      IK(0, -step_x, -step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(1, step_x, step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      IK(2, -step_x, -step_y, 0, status_jalan); //kaki kanan geser sejauh x,y
      IK(3, step_x, step_y, 0, status_jalan); //kaki kiri geser sejauh -x,-y
      //      getSRF();
      transmitPulsa(delay_ms);
      angkat++;
      break;
  }
  if (angkat > 1) angkat = 0;
}

void gerakStatis(float x, float y, float z, int time_step, int delay_ms)
{
  int i;
  for (i = 0; i < 4; i++)
  {
    IK(i, x, y, z, 0);
  }
  transmitPulsa(delay_ms);
}

//void menunduk() {
//  //kanan depan
//  Dynamixel.moveSpeed(0, deg2dyna(150), 200); // coxa
//  Dynamixel.moveSpeed(10, deg2dyna(150), 200); // femur
//  Dynamixel.moveSpeed(11, deg2dyna(150 - 15), 200); // tibia
//
//  //kiri depan
//  Dynamixel.moveSpeed(6, deg2dyna(150), 200); // coxa
//  Dynamixel.moveSpeed(7, deg2dyna(150), 200); // femur
//  Dynamixel.moveSpeed(8, deg2dyna(150 - 15), 200); // tibia
//
//  //kanan belakang
//
//  Dynamixel.moveSpeed(3, deg2dyna(150), 200);
//  Dynamixel.moveSpeed(4, deg2dyna(150), 200);
//  Dynamixel.moveSpeed(5, deg2dyna(150 + 30), 200);
//
//  //kiri belakang
//
//  Dynamixel.moveSpeed(9, deg2dyna(150), 200);
//  Dynamixel.moveSpeed(1, deg2dyna(150), 200);
//  Dynamixel.moveSpeed(211, deg2dyna(150 + 30), 200);
//}
