void setup_Ayarla() {
  //SERİ EKRAN BAŞLATMA
  Serial.begin(57600);
  Serial1.begin(57600);

  
  //VERİ ALMA
  Veri_Kontrol.Sensor_begin();
  Veri_Kontrol.LED_begin();
  Ext_Servo_Kontrol.begin(); //Harici Servo Kullanımını Aktifleştirme
  Ext_Servo_Kontrol.Ext_Servo_Fr(60); //Harici Servo için Çalışma Frekans Belirleme

  //KALİBRASYON DEĞERİ
  Ext_Servo_Kontrol.Ext_Servo(0, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(1, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(2, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(3, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(4, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(5, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(6, Motor_Hiz);
  Ext_Servo_Kontrol.Ext_Servo(7, Motor_Hiz);

  //PID FONKSİYONLARI:
  Veri_Kontrol.setup_PID_1();
  Veri_Kontrol.setup_PID_2();
  Veri_Kontrol.setup_PID_3();
  Veri_Kontrol.setup_PID_4();

  //DERİNLİK AYARLAMA
  derinlik_Setup();

  //ARAÇ HAZIR SİNYALİ
  digitalWrite(LED_R, 1);
  digitalWrite(LED_G, 0);
  digitalWrite(LED_B, 0);
  Serial1.println("Sistem Başlatılıyor");
  Serial.println("Sistem Başlatılıyor");
  timer_donus = millis();
}
