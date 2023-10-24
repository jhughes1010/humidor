void setFan(int fan, int percent) {
  float value;
  value = 255 * (float)percent / 100;
  analogWrite(fan, (int)value);
}