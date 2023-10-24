// Khai báo chân GPIO
const int SW520_OUT_PIN = 32;  // Chân OUT của cảm biến SW520
const int VIBRATION_MOTOR_PIN = 21;  // Chân IN của module Rung Vibration Motor 1027

void setup() {
  // Khởi tạo chân GPIO
  pinMode(SW520_OUT_PIN, INPUT);
  pinMode(VIBRATION_MOTOR_PIN, OUTPUT);
}

void loop() {
  // Đọc tín hiệu từ cảm biến SW520
  int sw520Value = digitalRead(SW520_OUT_PIN);

  if (sw520Value == HIGH) {
    // Khi cảm biến SW520 phát hiện rung, kích hoạt motor rung
    digitalWrite(VIBRATION_MOTOR_PIN, HIGH);
  } else {
    // Khi cảm biến SW520 không phát hiện rung, tắt motor rung
    digitalWrite(VIBRATION_MOTOR_PIN, LOW);
  }
  
  delay(100); // Đợi một khoảng thời gian trước khi đọc lại tín hiệu từ cảm biến SW520
}