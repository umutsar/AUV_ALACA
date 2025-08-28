void pid_Ayarla() {
  //EULER VERİLERİNİN ALINMASI
  X_Acisi = Veri_Kontrol.Euler_X();  //Yunuslama Verisi - Pitch
  Y_Acisi = Veri_Kontrol.Euler_Y();  //Yatış Verisi - Roll
  Z_Acisi = Veri_Kontrol.Euler_Z();  //Pusula Verisi - Heading

  //GYRO VERİLERİNİN ALINMASI
  Gyro_X = Veri_Kontrol.GYRO_X();       //Yatış Verisi - Roll
  Gyro_Y = Veri_Kontrol.GYRO_Y() * -1;  //Yunuslama Verisi - Pitch
  Gyro_Z = Veri_Kontrol.GYRO_Z() * -1;  //Sapma Verisi - Yaw

  PID_Yat_Ref = (Ref_Yat - Y_Acisi) * 8;
  PID_Yun_Ref = (Ref_Yun - X_Acisi) * 8;
  PID_Pus_Ref = ((Ref_Pus - Z_Acisi) * -1) - sifirlama;
  PID_Der_Ref = Ref_Der;

  if (PID_Pus_Ref > 360) {
    PID_Pus_Ref -= 360;
  } else if (PID_Pus_Ref < 0) {
    PID_Pus_Ref += 360;
  }
  // Serial.print("PID_Pus_Ref: ");
  // Serial.print(PID_Pus_Ref);
  // Serial.print(" sifirlama: ");
  // Serial.print(sifirlama);
  // Serial.print(" ref_pus: ");
  // Serial.print(Ref_Pus);
  // Serial.print(" kalan_Aci: ");
  // Serial.println(kalan_Aci);

  kalan_Aci = Veri_Kontrol.Koord_A_Data(PID_Pus_Ref, Ref_Pus);

  if (millis() - f_ >= 10)  //100Hz
  {
    yunuslama = Veri_Kontrol.PID_1(PID_Yun_Ref - Gyro_Y, Kp_1, Ki_1, Kd_1, 50);
    yatis = Veri_Kontrol.PID_2(PID_Yat_Ref - Gyro_X, Kp_2, Ki_2, Kd_2, 50);
    derinlik = Veri_Kontrol.PID_4(PID_Der_Ref - Kab_Dept, Kp_3, Ki_3, Kd_3, 50);
    pusula = Veri_Kontrol.PID_5(kalan_Aci, Kp_4, Ki_4, Kd_4, 50);
    f_ = millis();
  }
}
