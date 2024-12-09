#include "http.h"

#include <HTTPClient.h>

// Function to fetch data using HTTPClient
String http_get_data(const String &server_url) {
  HTTPClient http;
  String payload = "";

  http.begin(server_url); // Specify the URL

  unsigned long start_time = millis(); // Bắt đầu đo thời gian
  int http_code = http.GET();          // Thực hiện yêu cầu GET
  unsigned long end_time = millis();   // Kết thúc đo thời gian

  unsigned long latency = end_time - start_time; // Tính toán độ trễ
  Serial.printf("%lu\n", latency);

  if (http_code > 0) {
    // Nếu yêu cầu thành công, lấy payload
    payload = http.getString();
  } else {
    Serial.printf("GET request failed: %s\n", http.errorToString(http_code).c_str());
  }

  http.end(); // Giải phóng tài nguyên
  return payload;
}
// Function to send data to the server using POST request
String http_post_data(const String &server_url, const String &data) {
  HTTPClient http;

  http.begin(server_url);                                               // Specify the URL
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  // Set content type

  // Create the POST data
  String post_data = "input=" + data;

  // Send POST request
  int http_code = http.POST(post_data);
  String payload;
  // Check the response
  if (http_code > 0) {
    payload = http.getString();
    Serial.println("Response: " + payload);
  } else {
    Serial.println("Error on sending POST: " + String(http.errorToString(http_code).c_str()));
  }

  http.end();  // Free resources
  return payload;
}
