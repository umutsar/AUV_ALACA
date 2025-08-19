void ekranda_Goster()
{
  if (millis() - e_ >= 1000) //100Hz
  {
    //Serial.print("Motor_1 > "); Serial.println(Motor_1);
    //Serial.print("Motor_2 > "); Serial.println(Motor_2);
    //Serial.print("Motor_3 > "); Serial.println(Motor_3);
    //Serial.print("Motor_4 > "); Serial.println(Motor_4);
    //Serial.println(" ");
    //Serial.print("Motor_5 > "); Serial.println(Motor_5);
    //Serial.print("Motor_6 > "); Serial.println(Motor_6);
    //Serial.print("Motor_7 > "); Serial.println(Motor_7);
    //Serial.print("Motor_8 > "); Serial.println(Motor_8);
    //Serial.println(" ");
    //Serial.print("PID_Yat_Ref > "); Serial.println(PID_Yat_Ref);
    //Serial.print("PID_Yun_Ref > "); Serial.println(PID_Yun_Ref);
    //Serial.print("PID_Der_Ref > "); Serial.println(PID_Der_Ref);
    //Serial.print("PID_Pus_Ref > "); Serial.println(PID_Pus_Ref);
    //Serial.print("Ref_Pus > "); Serial.println(Ref_Pus);

    //Serial.print("Gyro_X > "); Serial.println(Gyro_X);
    //Serial.print("Gyro_Y > "); Serial.println(Gyro_Y);
    //Serial.print("Gyro_Z > "); Serial.println(Gyro_Z);

    //Serial.print("X_Acisi > "); Serial.println(X_Acisi);
    //Serial.print("Y_Acisi > "); Serial.println(Y_Acisi);
    //Serial.print("Z_Acisi > "); Serial.println(Z_Acisi);

    //Serial.print("Yunuslama > "); Serial.println(yunuslama);
    //Serial.print("Yatış > "); Serial.println(yatis);
    //Serial.print("Sapma > "); Serial.println(sapma);
    //Serial.print("Derinlik > "); Serial.println(derinlik);
   //Serial.print("Pusula > "); Serial.println(pusula);

   //Serial.print("Kalan Açı > "); Serial.println(kalan_Aci);
    //Serial.print("PID_kalan_aci > "); Serial.println(PID_kalan_aci);
    e_ = millis();
  }
}
