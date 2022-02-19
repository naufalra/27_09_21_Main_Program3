void SerialReadSlave()
{
  uvstat = analogRead(A20);
  static unsigned char data[500] = {0};
  int i, msg;
  msg = Serial5.available();

  if (msg > 255) msg = 0; //protection buffer
  if (msg > 0) {
    for (i = 0; i < msg; i++) {
      data[i] = Serial5.read();
    }
  }

  if (data[0] == 255 && data[11] == 254) //packet data
  {
    srf1     = data[1];
    srf2     = data[2];
    srf3     = data[3];
    //    srf4     = data[4];
    //    srf5     = data[5];
    //    srf6     = data[6];
    srf7     = data[7];
    srf8     = data[8];

    sgp1     = data[9];
    sgp2     = data[10];
    sgp3     = data[11];
    //    sgp4     = data[12];
    //    sgp5     = data[13];
    //    sgp6     = data[14];
    sgp7     = data[15];
    sgp8     = data[16];
  }
  Serial5.flush();



}

void SerialRead() {
  //=================== Line Get =========================
  static unsigned char dataLine[255] = {0};
  int k, msgLine;
  msgLine = Serial1.available();

  if (msgLine > 255) msgLine = 0; //protection buffer
  if (msgLine > 0) {
    for (k = 0; k < msgLine; k++) {
      dataLine[k] = Serial1.read();
    }
  }

  if (dataLine[0] == 251 && dataLine[4] == 252) //packet data
  {
    line1     = dataLine[1];
    line2     = dataLine[2];
    line3     = dataLine[3];
  }
  Serial1.flush();


  //=================== MUX Get =========================
  static unsigned char dataMUX[255] = {0};
  int j, msgMUX;
  msgMUX = Serial3.available();

  if (msgMUX > 255) msgMUX = 0; //protection buffer
  if (msgMUX > 0) {
    for (j = 0; j < msgMUX; j++) {
      dataMUX[j] = Serial3.read();
    }
  }

  if (dataMUX[0] == 253 && dataMUX[16] == 254) //packet data
  {
    mux1     = dataMUX[1];
    mux2     = dataMUX[2];
    mux3     = dataMUX[3];
    mux4     = dataMUX[4];
    mux5     = dataMUX[5];
    mux6     = dataMUX[6];
    mux7     = dataMUX[7];
    mux8     = dataMUX[8];
    mux9     = dataMUX[9];
    mux10    = dataMUX[10];
    mux11    = dataMUX[11];
    mux12    = dataMUX[12];
    mux13    = dataMUX[13];
    mux14    = dataMUX[14];
    mux15    = dataMUX[15];
  }
  Serial3.flush();
}

void lineDebug() {
  Serial.print(line1); Serial.print("\t");
  Serial.print(line2); Serial.print("\t");
  Serial.print(line3); Serial.print("\t"); Serial.println("\t");
}

void muxDebug() {
  Serial.print(mux1); Serial.print("\t");
  Serial.print(mux2); Serial.print("\t");
  Serial.print(mux3); Serial.print("\t");
  Serial.print(mux4); Serial.print("\t");
  Serial.print(mux5); Serial.print("\t");
  Serial.print(mux6); Serial.print("\t");
  Serial.print(mux7); Serial.print("\t");
  Serial.print(mux8); Serial.print("\t");
  Serial.print(mux9); Serial.print("\t");
  Serial.print(mux10); Serial.print("\t");
  Serial.print(mux11); Serial.print("\t");
  Serial.print(mux12); Serial.print("\t");
  Serial.print(mux13); Serial.print("\t");
  Serial.print(mux14); Serial.print("\t");
  Serial.println(mux15);
}

void srfDebug() {
  Serial.print(srf1); Serial.print("\t");
  Serial.print(srf2); Serial.print("\t");
  Serial.print(srf3); Serial.print("\t");
//  Serial.print(srf4); Serial.print("\t");
//  Serial.print(srf5); Serial.print("\t");
//  Serial.print(srf6); Serial.print("\t");
  Serial.print(srf7); Serial.print("\t");
  Serial.print(srf8); Serial.print("\t"); Serial.println("\t");
}

void sgpDebug() {
  Serial.print(sgp1); Serial.print("\t");
  Serial.print(sgp2); Serial.print("\t");
  Serial.print(sgp3); Serial.print("\t");
//  Serial.print(sgp4); Serial.print("\t");
//  Serial.print(sgp5); Serial.print("\t");
//  Serial.print(sgp6); Serial.print("\t");
  Serial.print(sgp7); Serial.print("\t");
  Serial.println(sgp8);
}
