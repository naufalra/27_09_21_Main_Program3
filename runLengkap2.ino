////Home -> Room 2 -> Room 1 _> Home
//void fullRunningOke2() {
//  for (int i = 0; i >= 0; i++) {
//    // Turn to East
//    for (int i = 0; i >= 0; i++) {
//      ambilSudut();
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 10);
//      display.println(sudut);
//      display.display();      // Show initial text
//      delay(100);
//
//      // Utara -> Timur
//      if ((sudut >= 345) || (sudut >= 0 && sudut < 60)) {
//        kanan(10);
//        Serial.println("Status 0");
//      }
//
//      // Selatan -> Timur
//      if (sudut >= 100 && sudut < 270) {
//        kiri(10);
//        Serial.println("Status 0");
//      }
//      else {
//        goto SATU;
//      }
//    }
//
//SATU:
//    // Move Forward
//    for (int i = 0; i < 13; i++) {
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 0);
//      display.println("Move Forward 1");
//      display.display();      // Maju dari home
//      move_y(40);
//    }
//
//    // Turn to North
//    for (int i = 0; i >= 0; i++) {
//      ambilSudut();
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 10);
//      display.println(sudut);
//      display.display();      // Show initial text
//      delay(100);
//
//      // Timur -> Utara
//      if (sudut >= 60 && sudut < 150) {
//        kiri(10);
//        Serial.println("Status 0");
//      }
//      else {
//        goto DUA;
//      }
//    }
//
//DUA:
//    for (int i = 0; i < 5; i++) {
//      move_y(40);
//    }
//
//    // Fix Direction
//    for (int i = 0; i >= 0; i++) {
//      ambilSudut();
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 10);
//      display.println(sudut);
//      display.display();      // Show initial text
//      delay(100);
//
//      // Timur -> Utara
//      if (sudut >= 0 && sudut < 60) {
//        kiri(10);
//        Serial.println("Status 0");
//      }
//      else {
//        goto TIGA;
//      }
//    }
//
//TIGA:
//    // Move Forward to Room 2
//    for (int i = 0; i < 60; i++) {
//      move_y(40);
//    }
//    //    move_y(40);
//    //    if (srf1 < 155){
//    //      goto FOUR;
//    //    }
//
//    // Turn to West
//    for (int i = 0; i >= 0; i++) {
//      ambilSudut();
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 10);
//      display.println(sudut);
//      display.display();      // Show initial text
//      delay(100);
//
//      // Utara -> Barat
//      if ((sudut >= 0 && sudut < 25) || (sudut >= 310)) {
//        kiri(10);
//        Serial.println("Status 0");
//      }
//      else {
//        goto EMPAT;
//      }
//    }
//
//EMPAT:
//    // UVtron Check
//    if (uvstat < 10) {
//      for (int i = 0; i < 3; i++) {
//        move_y(40);
//      }
//      extinguisher();
//    }
//    else {
//      goto LIMA;
//    }
//
//LIMA:
//    // Pixy Check
//    if (pixyCheck >= 0) {
//      victimCheck();
//    }
//    else {
//      goto ENAM;
//    }
//  }
//
//  /*
//     ROOM 2 TO ROOM 1
//  */
//
//
//ENAM:
//  //Turn to East
//
//
//SEVEN:
//  // Move Forward from Room 2 until nabrak gapapa yang penting nda kurang oke
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i < 10; i++) {
//    for (int i = 0; i >= 0; i++) {
//      ambilSudut();
//      display.clearDisplay();
//      display.setTextSize(2); // Draw 2X-scale text
//      display.setTextColor(SSD1306_WHITE);
//      display.setCursor(10, 10);
//      display.println(sudut);
//      display.display();      // Show initial text
//      delay(100);
//
//      // Timur -> Selatan
//      if (sudut >= 60 && sudut < 150) {
//        kiri(10);
//        Serial.println("Status 0");
//      }
//      else {
//        goto DELAPAN;
//      }
//    }
//  }
//
//EIGHT:
//  // Move Forward to Home
//  for (int i = 0; i < 40; i++) {
//    move_y(40);
//  }
//  //    move_y(40);
//  //    if (srf1 < 155){
//  //      goto FOUR;
//  //    }
//
//  // Turn to West
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i >= 0; i++) {
//    ambilSudut();
//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(SSD1306_WHITE);
//    display.setCursor(10, 10);
//    display.println(sudut);
//    display.display();      // Show initial text
//    delay(100);
//
//    // Selatan -> Barat
//    if ((sudut >= 0 && sudut < 25) || (sudut >= 310)) {
//      kiri(10);
//      Serial.println("Status 0");
//    }
//    else {
//      goto SEMBILAN;
//    }
//  }
//
//SEMBILAN:
//  // Move Forward to Home
//  for (int i = 0; i < 27; i++) {
//    move_y(40);
//  }
//
//  // Turn to South
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i >= 0; i++) {
//    ambilSudut();
//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(SSD1306_WHITE);
//    display.setCursor(10, 10);
//    display.println("Enter Room 1");
//    display.display();      // Show initial text
//    delay(100);
//
//    // Barat -> 1/2 Selatan
//    if (sudut >= 60 && sudut < 150) {
//      kiri(10);
//      Serial.println("Status 0");
//    }
//    else {
//      goto SEPULUH;
//    }
//  }
//
//SEPULUH:
//  // Maju lurusin ke selatan
//  for (int i = 0; i < 5; i++) {
//    move_y(40);
//  }
//
//  // Fix Direction -> Full to South
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i >= 0; i++) {
//    ambilSudut();
//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(SSD1306_WHITE);
//    display.setCursor(10, 10);
//    display.println(sudut);
//    display.display();      // Show initial text
//    delay(100);
//
//    // Barat -> Selatan
//    if (sudut >= 0 && sudut < 60) {
//      kiri(10);
//      Serial.println("Status 0");
//    }
//    else {
//      goto SEBELAS;
//    }
//  }
//
//SEBELAS:
//  // Move Forward Enter Room 1
//  for (int i = 0; i < 6; i++) {
//    move_y(40);
//  }
//
//  // Turn to West Dikit, kalau mau make pixy ganti ini
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i >= 0; i++) {
//    ambilSudut();
//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(SSD1306_WHITE);
//    display.setCursor(10, 10);
//    display.println("Fire Check");
//    display.display();      // Show initial text
//    delay(100);
//
//    // Selatan -> Barat
//    if (sudut >= 0 && sudut < 60) {
//      kiri(10);
//      Serial.println("Status 0");
//    }
//    else {
//      goto DUABELAS;
//    }
//  }
//
//DUABELAS:
//  // UVtron Check
//  if (uvstat < 10) {
//    //    for (int i = 0; i < 3; i++) {
//    //      move_y(40);
//    //    }
//    extinguisher();
//  }
//  else {
//    goto TIGABELAS;
//  }
//
//TIGABELAS:
//  //  if (uvstat > 10) {
//  // Turn Right to North
//  // SUDUTNYA BELUM DISESUAIIN
//  for (int i = 0; i >= 0; i++) {
//    ambilSudut();
//    display.clearDisplay();
//    display.setTextSize(2); // Draw 2X-scale text
//    display.setTextColor(SSD1306_WHITE);
//    display.setCursor(10, 10);
//    display.println("Fire Check");
//    display.display();      // Show initial text
//    delay(100);
//
//    // Selatan -> Barat
//    if (sudut >= 0 && sudut < 60) {
//      kanan(10);
//      Serial.println("Status 0");
//    }
//  }
//  else
//  }
//
//
////}
