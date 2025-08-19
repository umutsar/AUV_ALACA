void derinlik_Setup()
{
  while (!sensor.init()) {
    Serial.println("Sensör Hatası!");
    Serial.println("Bağlantıları Kontrol Ediniz...");
    delay(2000);
  }
  sensor.setModel(MS5837::MS5837_30BA);
  sensor.setFluidDensity(997);

}

void derinlik_Hesapla()
{
  // Sensörün sıcaklık ve basınç verileri güncellenir:
  sensor.read();
  Arac_Dept = sensor.depth();

  //KALİBRASYON İŞLEMİ:
  if (Derinlik_Kabl == true)
  {
    Kalb_Deger_Dept = Arac_Dept;
    Derinlik_Kabl = false;
  }
  else
  {
    Kab_Dept = Arac_Dept - Kalb_Deger_Dept;
    Kab_Dept *= 100; //CM ÇEVİRME
    if(derinlik_flag) {
      Serial.print("Derinlik: ");
      Serial.println(Kab_Dept);
    }
    
  }
}

void derinlik_Ayarlama()
{
  String gecici_veri = "";
  byte sayici_2 = 2;

  while (true)
  {
    if (Gelen_Komutlar[sayici_2] == ' ')
    {
      Ref_Der = gecici_veri.toInt();
      break;
      // Serial.println(gecici_veri);
    }
    else gecici_veri += Gelen_Komutlar[sayici_2];
    sayici_2++;
  }

  //Serial.println(Ref_Der); //DERİNLİK VERİSİ
}
