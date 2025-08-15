#include "ALACAKART.h"
ALACA_KART Veri_Kontrol;

//PWM ÇOĞALTICI
#include "Servo_Ext_ALC.h"
Servo_Ext Ext_Servo_Kontrol;

//BASINÇ SENSÖRÜ
#include "MS5837.h"
MS5837 sensor;

//MİLLİS KONTROL
unsigned long f_, e_, h_zaman;

//VERİ İŞLEME
char Gelen_Komutlar[100];
int veri_sayisi = 0 , veri[5];
int tam_deger = 360,  sifirlama = 0;
bool hareket_Durum = false;

//İTKİ
int ileri_Komut = 0, geri_Komut = 0, sol_Komut = 0, sag_Komut = 0, arti_Komut = 0, eksi_Komut = 0;

//DERİNLİK
float Arac_Dept, Kalb_Deger_Dept, Kab_Dept;
bool Derinlik_Kabl = false;

//SINIR DEĞERLER
int Motor_Hiz = 1550; // Stop PWM
int Mak_deger = 1980; // Maksimum PWM
int Min_deger = 1120; // Minimum PWM

//MOTORLAR
int Motor_1, Motor_2, Motor_3, Motor_4; // İtiş Motorları
int Motor_5, Motor_6, Motor_7, Motor_8; // Batış Motorları
bool motor_Aktif = false;
int Ref_Pus2 = 0;

//PID
float PID_Yun_Ref, PID_Yat_Ref, PID_Sap_Ref, PID_Der_Ref, PID_Pus_Ref, PID_kalan_aci;
float Ref_Yun = 0, Ref_Yat = 0, Ref_Der = 0, Ref_Pus = 0;
float X_Acisi, Y_Acisi, Z_Acisi, Gyro_X, Gyro_Y, Gyro_Z;
int yunuslama, yatis, sapma, derinlik, pusula, kalan_Aci;

//YUNUSLAMA / PITCH PID KATSAYILARI: 100Hz
float Kp_1 = 3.0;
float Ki_1 = 0.000;
float Kd_1 = 0.5;

//YATIŞ PID / ROLL KATSAYILARI: 100Hz
float Kp_2 = 0.8;
float Ki_2 = 0.001;
float Kd_2 = 0.004;

//DERİNLİK PID / 100Hz
float Kp_3 = 8.0;
float Ki_3 = 0.000;
float Kd_3 = 0.000;

//PUSULA PID / YAW KATSAYILARI: 100Hz
float Kp_4 = 3;
float Ki_4 = 0.000;
float Kd_4 = 0.000;


void setup() {
  setup_Ayarla();
}


void loop() {
  veri_Isleme();
  derinlik_Hesapla();
  pid_Ayarla();
  motor_Ayarla();
  ekranda_Goster();
}
