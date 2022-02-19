void cekButton() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonState == 0) {
    fullRunningOke();
  }
  else {
    center();
  }
}

void fullRunningOke() {
  for (int i = 0; i >= 0; i++) {
    //    kecepatan_servo = 600;
    //    delay_ms = 150;
    // Turn to East
    ambilSudut();
    for (int i = 0; i >= 0; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Home");
      display.display();      // Show initial text
      delay(100);
      ambilSudut();
      // Selatan -> Timur
      if (sudut >= 90 && sudut < 270) {
        kiri(20);
        Serial.println("Status 0");
      }
      // Utara -> Timur
      else if ((sudut >= 345) || (sudut >= 0 && sudut < 60)) {
        kanan(20);
        Serial.println("Status 0");
      }

      else {
        goto ONE;
      }
    }

ONE:
    // Move Forward
    for (int i = 0; i < 10; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Maju");
      display.display();      // Show initial text
      delay(100);
      //      kecepatan_servo = 400;
      move_y(40);
    }

    // Turn to North
    for (int i = 0; i >= 0; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Turn to Left");
      display.display();      // Show initial text
      delay(100);
      ambilSudut();
      //      display.clearDisplay();
      //      display.setTextSize(2); // Draw 2X-scale text
      //      display.setTextColor(SSD1306_WHITE);
      //      display.setCursor(10, 10);
      //      display.println(sudut);
      //      display.display();      // Show initial text
      //      delay(100);

      // Timur -> Utara
      if (sudut >= 60 && sudut < 150) {
        //        delay_ms = 100;
        //        kecepatan_servo = 300;
        kiri(20);
        Serial.println("Status 0");
      }
      else {
        goto TWO;
      }
    }

TWO:
    for (int i = 0; i < 5; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Turn to Left");
      display.display();      // Show initial text
      delay(100);
      //      kecepatan_servo = 400;
      move_y(40);
    }

    // Fix Direction
    for (int i = 0; i >= 0; i++) {
      ambilSudut();

      // Timur -> Utara
      if (sudut >= 30 && sudut < 60) {
        //        delay_ms = 100;
        //        kecepatan_servo = 300;
        kiri(20);
        Serial.println("Status 0");
      }
      else {
        goto TWO2;
      }
    }

TWO2:
    for (int i = 0; i < 5; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Turn to Left");
      display.display();      // Show initial text
      delay(100);
      //      kecepatan_servo = 400;
      move_y(40);
    }

    // Fix Direction
    for (int i = 0; i >= 0; i++) {
      ambilSudut();

      // Timur -> Utara
      if (sudut >= 20 && sudut < 30) {
        //        delay_ms = 100;
        //        kecepatan_servo = 300;
        kiri(20);
        Serial.println("Status 0");
      }
      else {
        goto THREE;
      }
    }

THREE:
    // Move Forward to Room 2
    for (int i = 0; i < 57; i++) {
      delay_ms = 100;
      step_z = 30;
      kecepatan_servo = 300;
      move_y(20);
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Move Forward");
      display.display();      // Show initial text
      delay(100);
      //      kecepatan_servo = 400;
      //      move_y(40);
    }
    //    move_y(40);
    //    if (srf1 < 155){
    //      goto FOUR;
    //    }

    // Turn to West
    for (int i = 0; i >= 0; i++) {
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println("Turn Left to Room 2");
      display.display();      // Show initial text
      delay(100);
      ambilSudut();
      // Utara -> Barat
      if ((sudut >= 0 && sudut < 20) || (sudut >= 330)) {
        kiri(10);
        Serial.println("Status 0");
      }
      else {
        goto FOUR;
      }
    }

FOUR:
    // UVtron Check
    if (uvstat < 10) {
      for (int i = 0; i < 4; i++) {
        //        kecepatan_servo = 400;
        move_y(20);
      }
    }
    else {
      goto FIVE;
    }

FIVE:
    if (uvstat < 10) {
      for (int i = 0; i < 400; i++) {
        menunduk();
        extinguisher();
      }
      goto FOUR;
    }
    else {
      goto SIX;
    }


    //FIVE:
    //    // Pixy Check
    //    if (pixyCheck >= 0) {
    //      victimCheck();
    //    }
    //    else {
    //      goto SIX;
    //    }
    //  }


    //// to home
SIX:
    //Move Backward
    for (int i = 0; i < 13; i++) {
      mundur(20);
    }

    // Move Forward from Room 2 until nabrak gapapa yang penting nda kurang oke
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i >= 0; i++) {
        ambilSudut();

        // Barat -> Selatan
        if (sudut >= 250 && sudut < 330) {
          kiri(10);
          Serial.println("Status 0");
        }
        else {
          goto TEN;
        }
      }
    }
    //
    //EIGHT:
    //    // Move Forward to Home
    //    for (int i = 0; i < 60; i++) {
    //      move_y(40);
    //    }
    //    //    move_y(40);
    //    //    if (srf1 < 155){
    //    //      goto FOUR;
    //    //    }
    //
    //    // Turn to West
    //    // SUDUTNYA BELUM DISESUAIIN
    //    for (int i = 0; i >= 0; i++) {
    //      ambilSudut();
    //      // Selatan -> Barat
    //      if (sudut >= 235 && sudut < 315) {
    //        kanan(10);
    //        Serial.println("Status 0");
    //      }
    //      else {
    //        goto NINE;
    //      }
    //    }
    //
    //NINE:
    //    // Move Forward to Home
    //    for (int i = 0; i < 8; i++) {
    //      move_y(40);
    //    }
    //
    //    for (int i = 0; i < 1000; i++) {
    //      center();
    //    }


    // to room 1
TEN:
    for (int i = 0; i < 20; i++) {
//      delay_ms = 100;
//      step_z = 30;
//      kecepatan_servo = 300;
      move_y(20);
      //      move_y(40);
    }

    // Turn to West
    for (int i = 0; i >= 0; i++) {
      ambilSudut();
      // Selatan -> Barat
      if ((sudut > 225 && sudut < 320)) {
        kiri(10);
        Serial.println("Status 0");
      }
      else {
        goto ELEVEN;
      }
    }

ELEVEN:
    for (int i = 0; i < 13; i++) {
      delay_ms = 100;
      step_z = 30;
      kecepatan_servo = 300;
      move_y(20);
    }

    for (int i = 0; i >= 0; i++) {
      ambilSudut();
      // Barat -> Selatan
      if (sudut >= 250 && sudut < 330) {
        kiri(10);
        Serial.println("Status 0");
      }
      else {
        goto TWELVE;
      }
    }

TWELVE:
    for (int i = 0; i < 5; i++) {
      delay_ms = 100;
      step_z = 30;
      kecepatan_servo = 300;
      move_y(20);
      //      move_y(40);
    }

    for (int i = 0; i >= 0; i++) {
      ambilSudut();
      // Selatan -> Barat
      if (sudut > 225 && sudut < 280) {
        kiri(10);
        Serial.println("Status 0");
      }
      else {
        goto THIRTEEN;
      }
    }

THIRTEEN:
    for (int i = 0; i < 500; i++) {
      center();
      extinguisher();
    }
  }
}
