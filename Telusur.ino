void telusur2() {
  for (int i = 0; i < 13; i++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward 1");
    display.display();      // Maju dari home

    move_y(40);
  }

  for (int j = 0; j < 4; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Kiri dikit
    kiri(40);
  }

  //  for (int k = 0; k < 7; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Move Forward 2");
  //    display.display();      // Maju dikit
  //    move_y(40);
  //  }

  //  for (int j = 0; j < 3; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri dua");
  //    display.display();      // Kiri buat lurusin
  //    kiri(40);
  //  }

  for (int k = 0; k < 60; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Maju Forward");
    display.display();      // Maju jalan
    move_y(40);
  }

  //  for (int j = 0; j < 10; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri dua");
  //    display.display();      // Kiri buat lurusin
  //    kiri(20);
  //  }
  //
  //  for (int j = 0; j < 50; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri dua");
  //    display.display();      // Kiri buat lurusin
  //    center();
  //  }

}

void telusur() {
  for (int i = 0; i >= 0; i++) {
    ambilSudut();
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println(sudut);
    display.display();      // Show initial text
    delay(100);

    // Utara -> Timur
    if ((sudut >= 340) || (sudut >= 0 && sudut < 50)) {
      kanan(10);
      Serial.println("Status 0");
    }

    // Selatan -> Timur
    if (sudut >= 90 && sudut < 270) {
      kiri(10);
      Serial.println("Status 0");
    }
  }

  /*
    Home ke ruang 1
  */

  for (int i = 0; i < 13; i++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward 1");
    display.display();      // Maju dari home

    move_y(40);
  }

  for (int j = 0; j < 6; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Kiri dikit
    kiri(20);
  }

  for (int k = 0; k < 5; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward 2");
    display.display();      // Maju dikit
    move_y(40);
  }

  for (int j = 0; j < 4; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Kiri dua");
    display.display();      // Kiri buat lurusin
    kiri(20);
  }

  for (int k = 0; k < 27; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Maju Forward");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int j = 0; j < 10; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Madep kiri gerak
    kiri(10);
  }

  for (int k = 0; k < 20; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward");
    display.display();      // Maju yang tengah
    move_y(40);
  }

  for (int j = 0; j < 7; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Enter Room 1");
    display.display();      // Ngambil kiri buat masuk ruangan 1
    kiri(20);
  }

  for (int k = 0; k < 4; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju yang tengah
    move_y(40);
  }

  for (int j = 0; j < 5; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Ngambil kiri buat masuk ruangan 1
    kiri(20);
  }

  for (int k = 0; k < 8; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Majuan dikit
    move_y(40);
  }

  for (int j = 0; j < 7; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Madep kanan
    kanan(20);
  }

  for (int j = 0; j < 100; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Center");
    display.display();      // Berenti bentar
    center();
    extinguisher();
  }

  /*
    Ruang 1 ke 2
  */

  for (int k = 0; k < 8; k++) {
    delay_ms = 100;
    digitalWrite(A19, LOW);
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Backward");
    display.display();      // Munduran mau keluar
    mundur(20);
  }

  for (int j = 0; j < 5; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Kanan dikit buat keluar
    kanan(20);
  }

  for (int k = 0; k < 3; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju dikit mau lurusin
    move_y(40);
  }

  for (int j = 0; j < 8; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Kanan sedang
    kanan(20);
  }

  for (int j = 0; j < 2; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju lurusin lagi
    move_y(40);
  }

  for (int j = 0; j < 5; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Show initial text
    kanan(20);
  }

  for (int k = 0; k < 15; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward");
    display.display();      // Maju dari tengah
    move_y(40);
  }

  for (int j = 0; j < 15; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Madep kiri dikit
    kiri(20);
  }

  for (int k = 0; k < 3; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju dikit
    move_y(40);
  }

  for (int j = 0; j < 8; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Ngambil kiri dikit buat lurusin
    kiri(20);
  }

  for (int k = 0; k < 25; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward to Room 2");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int j = 0; j < 11; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Enter Room 2");
    display.display();      // Kiri masuk ruangan 2
    kiri(20);
  }

  for (int k = 0; k < 15; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward");
    display.display();      // Maju masuk ruangan 2
    move_y(40);
  }

  for (int k = 0; k < 100; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Center");
    display.display();     // Berenti bentar
    center();
    extinguisher();
  }

  /*
       Ruang 2 ke home
  */

  for (int k = 0; k < 17; k++) {
    delay_ms = 100;
    digitalWrite(A19, LOW);
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Backward");
    display.display();      // Maju masuk ruangan 2
    mundur(20);
  }

  for (int j = 0; j < 8; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Kiri dikit
    kiri(20);
  }

  for (int k = 0; k < 2; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju dikit
    move_y(40);
  }

  for (int j = 0; j < 9; j++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Left");
    display.display();      // Kiri buat lurusin
    kiri(20);
  }

  for (int k = 0; k < 23; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward to Home");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int k = 0; k < 5; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward to Home");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int k = 0; k < 23; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Maju ke ruang 2");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int k = 0; k < 4; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Maju jalan
    kanan(20);
  }

  for (int k = 0; k < 3; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Fix Direction");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int k = 0; k < 6; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Turn Right");
    display.display();      // Maju jalan
    kanan(20);
  }

  for (int k = 0; k < 5; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Move Forward");
    display.display();      // Maju jalan
    move_y(40);
  }

  for (int k = 0; k < 100; k++) {
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Maju ke ruang 2");
    display.display();      // Maju jalan
    center();
  }

  //  for (int j = 0; j < 13; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri cek tengah");
  //    display.display();      // Madep kiri gerak
  //    kanan(10);
  //  }
  //
  //  for (int k = 0; k < 18; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju tengah");
  //    display.display();      // Maju yang tengah
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 4; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kanan dikit");
  //    display.display();      // Madep kanan gerak
  //    kanan(10);
  //  }
  //
  //  for (int k = 0; k < 18; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju tengah");
  //    display.display();      // Maju yang tengah
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 5; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kanan sedikit");
  //    display.display();      // Show initial text
  //    kiri(10);
  //  }
  //
  //  for (int j = 0; j < 8; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri satu");
  //    display.display();      // Kiri dikit
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 5; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju dua");
  //    display.display();      // Maju dikit
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 6; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri dua");
  //    display.display();      // Kiri buat lurusin
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 3; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju dikit");
  //    display.display();      // Maju dikit
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 4; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri lurusin");
  //    display.display();      // Kiri buat lurusin
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 35; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju lorong 2");
  //    display.display();      // Show initial text
  //    move_y(20);
  //  }
  //
  //  for (int j = 0; j < 8; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri satu");
  //    display.display();      // Kiri dikit
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 5; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju dua");
  //    display.display();      // Maju dikit
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 6; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri dua");
  //    display.display();      // Kiri buat lurusin
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 2; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju dikit");
  //    display.display();      // Maju dikit
  //    move_y(30);
  //  }
  //
  //  for (int j = 0; j < 2; j++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Kiri lurusin");
  //    display.display();      // Kiri buat lurusin
  //    kiri(10);
  //  }
  //
  //  for (int k = 0; k < 32; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Maju otw home");
  //    display.display();      // Maju jalan
  //    move_y(30);
  //  }
  //
  //  for (int k = 0; k < 70; k++) {
  //    display.clearDisplay();
  //    display.setTextSize(2); // Draw 2X-scale text
  //    display.setTextColor(SSD1306_WHITE);
  //    display.setCursor(10, 0);
  //    display.println("Center");
  //    display.display();     // Berenti bentar
  //    center();
  //  }

  /*
     sampe sini
  */
}
