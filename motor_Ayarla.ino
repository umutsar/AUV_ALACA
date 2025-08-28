// Motor yönünü ters çevirmek için fonksiyon
int tersCevir(int deger) {
  return (2 * Motor_Hiz) - deger;
}

void motor_Ayarla() {
  if(pusula_flag) {
    pusula *= -1;
  }
  
  Motor_1 = Motor_Hiz  + ileri_Komut - geri_Komut - sol_Komut - sag_Komut - arti_Komut + eksi_Komut + pusula;
  if (Motor_1 >= Mak_deger) Motor_1 = Mak_deger;
  else if (Motor_1 <= Min_deger) Motor_1 = Min_deger;
  Motor_1 = tersCevir(Motor_1); // Yön ters çevrildi

  Motor_2 = Motor_Hiz  + ileri_Komut - geri_Komut + sol_Komut + sag_Komut + arti_Komut - eksi_Komut - pusula;
  if (Motor_2 >= Mak_deger) Motor_2 = Mak_deger;
  else if (Motor_2 <= Min_deger) Motor_2 = Min_deger;

  Motor_3 = Motor_Hiz  + ileri_Komut - geri_Komut - sol_Komut - sag_Komut + arti_Komut - eksi_Komut + pusula;
  if (Motor_3 >= Mak_deger) Motor_3 = Mak_deger;
  else if (Motor_3 <= Min_deger) Motor_3 = Min_deger;
  Motor_3 = tersCevir(Motor_3); // Yön ters çevrildi

  Motor_4 = Motor_Hiz  + ileri_Komut - geri_Komut + sol_Komut + sag_Komut - arti_Komut + eksi_Komut - pusula;
  if (Motor_4 >= Mak_deger) Motor_4 = Mak_deger;
  else if (Motor_4 <= Min_deger) Motor_4 = Min_deger;

  //**************************************************************
  Motor_5 = Motor_Hiz + yatis + yunuslama + derinlik;
  if (Motor_5 >= Mak_deger) Motor_5 = Mak_deger;
  else if (Motor_5 <= Min_deger) Motor_5 = Min_deger;

  Motor_6 = Motor_Hiz - yatis + yunuslama + derinlik;
  if (Motor_6 >= Mak_deger) Motor_6 = Mak_deger;
  else if (Motor_6 <= Min_deger) Motor_6 = Min_deger;

  Motor_7 = Motor_Hiz + yatis - yunuslama + derinlik;
  if (Motor_7 >= Mak_deger) Motor_7 = Mak_deger;
  else if (Motor_7 <= Min_deger) Motor_7 = Min_deger;
  Motor_7 = tersCevir(Motor_7); // Yön ters çevrildi

  Motor_8 = Motor_Hiz - yatis - yunuslama + derinlik;
  if (Motor_8 >= Mak_deger) Motor_8 = Mak_deger;
  else if (Motor_8 <= Min_deger) Motor_8 = Min_deger;
  Motor_8 = tersCevir(Motor_8); // Yön ters çevrildi

  if (motor_Aktif == true) {
    Ext_Servo_Kontrol.Ext_Servo(0, Motor_1);
    Ext_Servo_Kontrol.Ext_Servo(1, Motor_2);
    Ext_Servo_Kontrol.Ext_Servo(2, Motor_3);
    Ext_Servo_Kontrol.Ext_Servo(3, Motor_4);
    Ext_Servo_Kontrol.Ext_Servo(4, Motor_5);
    Ext_Servo_Kontrol.Ext_Servo(5, Motor_6);
    Ext_Servo_Kontrol.Ext_Servo(6, Motor_7);
    Ext_Servo_Kontrol.Ext_Servo(7, Motor_8);
    
  } else {
    for (int i = 0; i < 8; i++) {
      Ext_Servo_Kontrol.Ext_Servo(i, Motor_Hiz);
    }
  }
  //Serial.print("kp4: ");
  //Serial.println(Kp_4);
}
