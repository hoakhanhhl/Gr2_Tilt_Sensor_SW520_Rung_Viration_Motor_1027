# Gr2_Tilt_Sensor_SW520_Rung_Viration_Motor_1027
##Link ảnh kết quả chạy và hướng dẫn lắp mạch:
https://drive.google.com/drive/folders/1vP19CbT87vgntLRjj6PF-Klm_SNKFDEN

##Nguyên lí hoạt động:
+ Cảm biến nghiêng TILT SW520: Cảm biến này được sử dụng để phát hiện nghiêng của một đối tượng. Khi đối tượng nghiêng hoặc thay đổi trạng thái nghiêng, cảm biến sẽ phát hiện và tạo ra tín hiệu điện trên chân OUT (SW520_OUT_PIN)(kí hiệu DO trên cảm biến). Tín hiệu này có thể là HIGH (1) hoặc LOW (0), tùy thuộc vào sự nghiêng của đối tượng.
+ Module rung Vibration Motor 1027: Đây là một module điều khiển motor rung. Nó được kết nối với ESP32 DevKit V1 thông qua chân IN (VIBRATION_MOTOR_PIN)(Kí hiệu IN trên module). Khi chân IN nhận được tín hiệu HIGH, module sẽ kích hoạt motor rung, và khi chân IN nhận được tín hiệu LOW, module sẽ tắt motor rung.

##HƯỚNG DẪN LẮP MẠCH:
Để nối cảm biến nghiêng TILT SW520 và module rung Vibration Motor 1027 thông qua ESP32 DevKit V1:
1. Cảm biến nghiêng TILT SW520:
Chân VCC của cảm biến nối với nguồn điện 3.3V trên ESP32.
Chân GND của cảm biến nối với chân GND trên ESP32 để tạo đường dẫn chung cho điện áp.
Chân OUT (DO) của cảm biến kết nối đến một chân GPIO trên ESP32 DevKit V1 (ví dụ: chân GPIO 27). Tôi chọn D32
2. Module rung Vibration Motor 1027:
Chân VCC của module nối với nguồn điện 3.3V trên ESP32.
Chân GND của module với chân GND trên ESP32 để tạo đường dẫn chung cho điện áp.
Chân IN của module rung kết nối đến một chân GPIO trên ESP32 DevKit V1 (ví dụ: chân GPIO 26). Tôi chọn D21

##Giải thích code:
// Khai báo chân GPIO
const int SW520_OUT_PIN = 32; // Chân OUT của cảm biến SW520
const int VIBRATION_MOTOR_PIN = 21; // Chân IN của module Rung Vibration Motor 1027
Khai báo hai hằng số (SW520_OUT_PIN và VIBRATION_MOTOR_PIN) để lưu trữ số chân GPIO được sử dụng cho cảm biến nghiêng SW520 và module rung Vibration Motor 1027.

void setup() {
  // Khởi tạo chân GPIO
  pinMode(SW520_OUT_PIN, INPUT); // Chân kết nối đến cảm biến được đặt là INPUT
  pinMode(VIBRATION_MOTOR_PIN, OUTPUT); // Chân kết nối đến module rung được đặt là OUTPUT
}
Trong hàm setup(), thiết lập chế độ hoạt động của các chân GPIO. pinMode(SW520_OUT_PIN, INPUT) đặt chân GPIO kết nối với cảm biến nghiêng SW520 là chế độ INPUT, đọc giá trị từ cảm biến. pinMode(VIBRATION_MOTOR_PIN, OUTPUT) đặt chân GPIO kết nối với module rung Vibration Motor 1027 là chế độ OUTPUT, điều khiển module rung.

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
Trong hàm loop(), đọc giá trị từ cảm biến nghiêng SW520 bằng cách sử dụng hàm digitalRead(SW520_OUT_PIN) và lưu trữ giá trị đó vào biến sw520Value.
Sau đó, chúng ta kiểm tra giá trị sw520Value nếu nó là HIGH. Nếu cảm biến SW520 phát hiện rung, chúng ta sử dụng digitalWrite(VIBRATION_MOTOR_PIN, HIGH) để kích hoạt module rung Vibration Motor 1027 thông qua chân GPIO tương ứng. Điều này sẽ làm cho motor rung hoạt động.
sw520Value không phải là HIGH, tức là cảm biến SW520 không phát hiện rung, chúng ta sử dụng digitalWrite(VIBRATION_MOTOR_PIN, LOW) để tắt module rung. Motor rung sẽ không hoạt động trong trường hợp này.
delay(100) để tạo một khoảng thời gian chờ 100ms trước khi đọc lại giá trị từ cảm biến nghiêng SW520. Điều này giúp tránh đọc giá trị quá nhanh và tạo ra hiệu ứng rung liên tục khi cảm biến nghiêng đang rung.
