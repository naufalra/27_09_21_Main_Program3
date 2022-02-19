void limabelas()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(211), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void empatbelas()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(203), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void tigabelas()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(195), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void duabelas()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(187), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void sebelas()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(179), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void sepuluh()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(171), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void sembilan()
{
  Dynamixel.moveSpeed(12, deg2dyna(163), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void delapan()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(155), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void tujuh()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(147), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void enam()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(139), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void lima()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(131), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void empat()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(123), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void tiga()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(115), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void dua()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(107), 500);
  digitalWrite(A19, HIGH);
  //  delay(500);
}

void satu()
{
  menunduk();
  Dynamixel.moveSpeed(12, deg2dyna(99), 500);
  digitalWrite(A19, HIGH);
}

void extinguisher() {
  if (mux1 < 100) {
    satu();
  }
  else if (mux2 < 100) {
    dua();
    //    digitalWrite(A19, HIGH);
  }
  else if (mux3 < 100) {
    tiga();
    //    digitalWrite(A19, HIGH);
  }
  else if (mux4 < 100) {
    empat();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux5 < 100) {
    lima();
    //    digitalWrite(A19, HIGH);
  }
  else if (mux6 < 100) {
    enam();
    //    digitalWrite(A19, HIGH);
  }
  else if (mux7 < 100) {
    tujuh();
    //    digitalWrite(A19, HIGH);
  }
  else if (mux8 < 100) {
    delapan();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux9 < 100) {
    sembilan();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux10 < 100) {
    sepuluh();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux11 < 100) {
    sebelas();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux12 < 100) {
    duabelas();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux13 < 100) {
    tigabelas();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux14 < 100) {
    empatbelas();
    //    digitalWrite(A19, HIGH);
  }

  else if (mux15 < 100) {
    limabelas();
    //    digitalWrite(A19, HIGH);
  }

  else {
    Dynamixel.moveSpeed(12, deg2dyna(155), 500);
    digitalWrite(A19, LOW);
  }
}
