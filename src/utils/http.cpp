#include "http.h"

#include <HTTPClient.h>

// Function to fetch data using HTTPClient
String http_get_data(const String &server_url) {
  HTTPClient http;
  String payload = "";

  http.begin(server_url);      // Specify the URL
  int http_code = http.GET();  // Make the GET request

  if (http_code > 0) {
    // If the request was successful, get the payload
    payload = http.getString();
    Serial.println("Response: " + payload);
  } else {
    Serial.printf("GET request failed: %s\n", http.errorToString(http_code).c_str());
  }

  http.end();  // Free resources
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
