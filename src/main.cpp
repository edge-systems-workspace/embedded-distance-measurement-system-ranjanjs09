/**
* @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author Purendra Ranjan [ranjanjs09]
 * @date 19-02-2026
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */
#include <Arduino.h>

int trig_pin = 9;
int echo_pin = 10;

void setup() {
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trig_pin,LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin,LOW);
    long duration = pulseIn(echo_pin,HIGH);
    float distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");

    delay(500);
}