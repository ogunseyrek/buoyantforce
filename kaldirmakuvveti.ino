//Hilmi Ogün SEYREK
//ogunseyrek@gmail.com

#include <hx711.h>  //ağırlık sensörü için kütüphane
#include <Wire.h>  //lcd ekran haberleşmesi üçün kütüphane
#include <LiquidCrystal_I2C.h>  //lcd ekran kütüphanesi
LiquidCrystal_I2C lcd(0x3f,20,4);  //lcd ekranı tanımlıyoruz

Hx711 scale(A1, A0);  //bağlantı pinleri

void setup() {
  Serial.begin(9600);  //seri haberleşme hızını ayarlıyoruz.
  scale.setOffset(8579315);  //ağırlık sensöründe ağırlık yokken boşta okunan değer.
  scale.setScale(2217.001f);  //(w-offset)/1000 formülünden hesapladığımız ratio değeri. w=1kg ağırlık konduğunda okunan değer.
  lcd.begin();  //lcd ekranı başlatıyoruz
  lcd.backlight();  //lcd ekranın arka ışığını yakıyoruz
/*  lcd.setCursor(0,1);  //yazılan yazının x ve y koordinatları
  lcd.print("    FIZIK DERSI");  //lcd ekrana yazı yazdırıyoruz
    lcd.setCursor(0,2);  //yazılan yazının x ve y koordinatları
  lcd.print("  MUHAMMED OZDEMIR");  //lcd ekrana yazı yazdırıyoruz
  delay(3000);  //üç saniye bekliyoruz
  lcd.clear();  //ekranı temizliyoruz
  lcd.setCursor(0,1);  //yazılan yazının x ve y koordinatları
  lcd.print("     SIVILARDA");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(0,2);  //yazılan yazının x ve y koordinatları
  lcd.print("  KALDIRMA KUVVETI");  //lcd ekrana yazı yazdırıyoruz*/
  delay(3000);  //üç saniye bekliyoruz
  lcd.clear();  //ekranı temizliyoruz
}

void loop() {
  float weight = scale.getGram()-300;  //beherin ve içindeki suyun kütlesini çıkartıyoruz

if(weight>1)  //ölçülen kütle 1 gramdan büyükse kaldırma kuvvetini hesaplamasını söylüyoruz
{ 
  lcd.clear();  //ekranı temizliyoruz
  lcd.setCursor(0,0);  //yazılan yazının x ve y koordinatları
  lcd.print("  Kaldirma Kuvveti");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(4,1);  //yazılan yazının x ve y koordinatları
  lcd.print((weight)/100, 2);  //ölçülen kütle değerini gramdan kilograma çevirip yer çekimi ivmesiyle çarpıp cisme etki eden kaldırma kuvvetini newton cinsinden hesaplıyoruz
  lcd.setCursor(10,1);  //yazılan yazının x ve y koordinatları
  lcd.print("Newton");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(2,3);  //yazılan yazının x ve y koordinatları
  lcd.print("BILNET  OKULLARI");  //lcd ekrana yazı yazdırıyoruz
  delay(100);  //6 salise bekliyoruz
}

if(weight>=0 && weight<=1)  //ölçülen kütle 0 ile 1 gram arasındaysa ekrana cismi yavaşça bırak yazdırıyoruz
{
  lcd.clear();  //ekranı temizliyoruz
  lcd.setCursor(0,0);  //yazılan yazının x ve y koordinatları
  lcd.print("  Cismi sivi icine");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(0,1);  //yazılan yazının x ve y koordinatları
  lcd.print("   Yavasca birak");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(2,3);  //yazılan yazının x ve y koordinatları
  lcd.print("BILNET  OKULLARI");  //lcd ekrana yazı yazdırıyoruz
  delay(100);  //6 salise bekliyoruz
}

if(0>weight)  //ölçülen kütle 0 gramdan küçük bir değer çıkıyorsa behere eklememiz gereken sıvının miktarını ekrana yazdırıyoruz
{
  lcd.clear();  //ekranı temizliyoruz
  lcd.setCursor(4,0);  //yazılan yazının x ve y koordinatları
  lcd.print((weight)/-1, 2);  //behere eklememiz gereken sıvının miktarını lcd ekrana yazdırıyoruz
  lcd.setCursor(11
  ,0);  //yazılan yazının x ve y koordinatları
  lcd.print("gram");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(5,1);  //yazılan yazının x ve y koordinatları
  lcd.print("sivi ekle");  //lcd ekrana yazı yazdırıyoruz
  lcd.setCursor(2,3);  //yazılan yazının x ve y koordinatları
  lcd.print("BILNET  OKULLARI");  //lcd ekrana yazı yazdırıyoruz
  delay(100);  //6 salise bekliyoruz
}
}
