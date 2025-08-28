
void veri_Isleme() {
  veri_sayisi = 0;
  bool Veri_Gelme_Durumu = false;
  //***************************************************************
  //Gelen veri sıfırlama işlemi:
  for (int i = 0; i < 30; i++) Gelen_Komutlar[i] = ' ';

  while (Serial.available()) {
    Gelen_Komutlar[veri_sayisi] = (char)Serial.read();
    veri_sayisi++;
    delayMicroseconds(200);
    Veri_Gelme_Durumu = true;

    if (veri_sayisi >= 100) break;
  }
  //******************************************************************
  while (Serial1.available()) {
    Gelen_Komutlar[veri_sayisi] = (char)Serial1.read();
    veri_sayisi++;
    delayMicroseconds(200);
    Veri_Gelme_Durumu = true;

    if (veri_sayisi >= 100) break;
  }
  //*****************************************************************

  if (Veri_Gelme_Durumu == true) {
    for (int i = 0; i < veri_sayisi; i++) Serial.print(Gelen_Komutlar[i]);
    Serial.println();

    //İŞLEM YORUMLAMA:
    //***MOTOR AÇMA - KAPATMA DURUMLARI***
    if (Gelen_Komutlar[0] == 'A' && Gelen_Komutlar[1] == 'B') {
      // digitalWrite(LED_G, 1);
      digitalWrite(LED_R, 0);
      motor_Aktif = true;
      Derinlik_Kabl = true;
      sifirlama = Z_Acisi;
      Ref_Pus = 0.00;

    } else if (Gelen_Komutlar[0] == 'A' && Gelen_Komutlar[1] == 'K') {
      motor_Aktif = false;
      digitalWrite(LED_B, 1);
    }

    //***HAREKET KOMUTLARI YORUMLARI***
    String gecici_veri = "";
    byte sayici_2 = 3;
    byte sayici_3 = 0;

    if (Gelen_Komutlar[0] == 'P') {
      PID_Ayarlama();
    } else if (Gelen_Komutlar[0] == 'D') {
      if (Gelen_Komutlar[1] == 'K') {
        Derinlik_Kabl = true;
        Serial.println("oe");
      } else {

        derinlik_Ayarlama();
      }
    } else if (Gelen_Komutlar[0] == 'T')  //Görev atama komutu ayıklama işlemi
    {
      float gelen_sayi = (String(Gelen_Komutlar).substring(String(Gelen_Komutlar).indexOf(' ') + 1)).toInt();
      if (gelen_sayi == 91) ivme_goster_flag = 1;
      else if (gelen_sayi == 92) ivme_goster_flag = 0;
      else if (gelen_sayi == 93) pusula_goster_flag = 1;
      else if (gelen_sayi == 94) pusula_goster_flag = 0;
      else if (gelen_sayi == 95) motor_pwm_goster_flag = 1;
      else if (gelen_sayi == 96) motor_pwm_goster_flag = 0;
      else if (gelen_sayi == 97) derinlik_flag = 1;
      else if (gelen_sayi == 98) derinlik_flag = 0;
      else if (gelen_sayi == 99) pusula_flag = 1;
      else if (gelen_sayi == 100) pusula_flag = 0;
      else if (gelen_sayi == 101) filtre_acik_flag = 1;
      else if (gelen_sayi == 102) filtre_acik_flag = 0;
      else if (gelen_sayi == 103) donus_flag = 1;
      else if (gelen_sayi == 104) donus_flag = 2;

      else {
        //PID_Pus_Ref = 0;

        Serial.print("Gelen Sayi: ");
        Serial.println(gelen_sayi);
        Ref_Pus += (String(Gelen_Komutlar).substring(String(Gelen_Komutlar).indexOf(' ') + 1)).toInt() / 2;
        Serial.print("Ref_Pus: ");
        Serial.println(Ref_Pus);

        if (Ref_Pus > 360) {
          Ref_Pus -= 360;
        } else if (Ref_Pus < 0) {
          Ref_Pus += 360;
        }
      }
    }


    else if (Gelen_Komutlar[0] == 'F') {
      float gelen_sayi = (String(Gelen_Komutlar).substring(String(Gelen_Komutlar).indexOf(' ') + 1)).toInt();
      derinlik_fark += gelen_sayi;
      Serial.print("Malafat: ");
      Serial.println(derinlik_fark);

    }



    else {
      while (true) {
        if (Gelen_Komutlar[sayici_2] == ' ') {
          veri[sayici_3] = gecici_veri.toInt();
          sayici_3++;

          if (sayici_3 == 2) break;
          //Serial.println(gecici_veri);

          gecici_veri = "";
        } else gecici_veri += Gelen_Komutlar[sayici_2];
        sayici_2++;
      }


      Serial.print("Motor Güc");
      Serial.println(veri[0]);  //MOTOR GÜÇ VERİSİ
      Serial.print("Zaman");
      Serial.println(veri[1]);  //ZAMANLAMA VERİSİ
      Serial1.print("Motor Güc");
      Serial1.println(veri[0]);  //MOTOR GÜÇ VERİSİ
      Serial1.print("Zaman");
      Serial1.println(veri[1]);  //ZAMANLAMA VERİSİ

      if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == 'F') {
        ileri_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      } else if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == 'B') {
        geri_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      } else if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == 'L') {
        sol_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      } else if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == 'R') {
        sag_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      }

      else if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == '-') {
        arti_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      } else if (Gelen_Komutlar[0] == 'H' && Gelen_Komutlar[1] == '+') {

        // 8 - 11 > - | 9 - 10 > +
        eksi_Komut = (veri[0] * 300) / 100;  // %100 => 300ms
        h_zaman = millis();
        hareket_Durum = true;
      }
    }

    Veri_Gelme_Durumu = false;
  }

  //***zamanlaması**********

  if (Gelen_Komutlar[0] == 'A' && Gelen_Komutlar[1] == 'S') {
    donus_flag = 0;
  }
  
  if (hareket_Durum == true) {
    Serial.println("Hareket durum true");

    if (Gelen_Komutlar[0] == 'A' && Gelen_Komutlar[1] == 'S') {
      Serial.println("AS GELDİ");
      ileri_Komut = 0;
      geri_Komut = 0;
      sag_Komut = 0;
      sol_Komut = 0;
      arti_Komut = 0;
      eksi_Komut = 0;
      hareket_Durum = false;
    }
    if (millis() - h_zaman >= veri[1]) {
      ileri_Komut = 0;
      geri_Komut = 0;
      sag_Komut = 0;
      sol_Komut = 0;
      arti_Komut = 0;
      eksi_Komut = 0;
      hareket_Durum = false;
    }
  }
}
