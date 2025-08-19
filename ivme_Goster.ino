
void ivme_Goster() {
  Lia_X_Data = Veri_Kontrol.LIA_ACC_X();
  Lia_Y_Data = Veri_Kontrol.LIA_ACC_Y();
  Lia_Z_Data = Veri_Kontrol.LIA_ACC_Z();

  Serial.print(Lia_X_Data);
  Serial.print("    ");
  Serial.print(Lia_Y_Data);
  Serial.print("    ");
  Serial.print(Lia_Z_Data);

  Serial.println();
}

void motor_pwm_goster() {
  Serial.print("motor 1: ");
  Serial.println(Motor_1);
  Serial.print("motor 2: ");
  Serial.println(Motor_2);
  Serial.print("motor 3: ");
  Serial.println(Motor_3);
  Serial.print("motor 4: ");
  Serial.println(Motor_4);
  Serial.print("motor 5: ");
  Serial.println(Motor_5);
  Serial.print("motor 6: ");
  Serial.println(Motor_6);
  Serial.print("motor 7: ");
  Serial.println(Motor_7);
  Serial.print("motor 8: ");
  Serial.println(Motor_8);
}
