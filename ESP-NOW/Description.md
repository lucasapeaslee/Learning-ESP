# Description
The <i>sender</i> program sends a "1" to the recieving ESP32 when pin 12 comes in contact with pin 13 (or if pin 12 is written HIGH at all), while the <i>reciever</i> program turns on the built-in LED when it recieves the "1."

# Requirements
<ol>
  <li>Install the "WiFi" library. The "esp_now" library should already be included with the ESP board package.</li>
  <li>In line 9 of <i>sender.ino</i>, insert the MAC address of the recieving ESP32 in hexadecimal format (ex: 0xFF). The MAC address can be found by running "esptool chip_id" in a command-line while the chip is plugged in.</li>
</ol>

# References (non-formal)
ESPNOW API Reference: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html <br>
ESPNOW for beginners!: https://www.youtube.com/watch?v=Ydi0M3Xd_vs
