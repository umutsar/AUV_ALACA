void PID_Ayarlama()//*
{
  //***HAREKET KOMUTLARI YORUMLARI***
  String gecici_veri = "";
  byte sayici_2 = 5;
  byte sayici_3 = 0;

  float PID_Veri[10];
  //Serial.println("PID Test");

  while (true)
  {
    if (Gelen_Komutlar[sayici_2] == ' ')
    {
      PID_Veri[sayici_3] = gecici_veri.toFloat() / 10; //10^4 HASSASİYETİNDE
      sayici_3++;

      if (sayici_3 == 3) break;
      // Serial.println(gecici_veri);

      gecici_veri = "";
    }
    else gecici_veri += Gelen_Komutlar[sayici_2];
    sayici_2++;
  }
  if (PID_Veri[0] != 0 or PID_Veri[0] != '\0') {

    if (Gelen_Komutlar[3] == '1')
    {
      Kp_1 = PID_Veri[0];
    }
    else if (Gelen_Komutlar[3] == '2')
    {
      Kp_2 = PID_Veri[0];
    }
    else if (Gelen_Komutlar[3] == '3')
    {
      Kp_3 = PID_Veri[0];
    }
    else if (Gelen_Komutlar[3] == '4')
    {
      Kp_4 = PID_Veri[0];
    }

  }
  Serial.print("YUNUSLAMA Kp_1> "); Serial.println(Kp_1);
  Serial1.print("YUNUSLAMA Kp_1> "); Serial1.println(Kp_1);

  Serial.print("YATIŞ Kp_2> "); Serial.println(Kp_2);
  Serial1.print("YATIŞ Kp_2> "); Serial1.println(Kp_2);

  Serial.print("DERİNLİK Kp_3> "); Serial.println(Kp_3);
  Serial1.print("DERİNLİK Kp_3> "); Serial1.println(Kp_3);

  Serial.print("PUSULA Kp_4> "); Serial.println(Kp_4);
  Serial1.print("PUSULA Kp_4> "); Serial1.println(Kp_4);
}
