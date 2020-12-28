# TallyArbiter-arduino-neopixel

This project allows an ESP8266 (Wemos D1 Mini) to respond to POST requests from [Joseph Adam's Tally Arbiter](https://github.com/josephdadams/TallyArbiter) in order to control Neopixel Strips.


## Arduino Configuration

In the main `Arduino_Tally.ino` some values need to be configured.
I used the [Arduino IDE](https://www.arduino.cc/en/software) to make changes and Flash the Wemos D1 Mini.

### Network Settings

The ssid and password for the wireless network must be set. Replace the `xxxxxx`s with the relevant values on each line.

`const char* ssid = "xxxxxx";`

`const char* pass = "xxxxxx";`

You can change the hostname from 'esp-tally' if required. This will change the address used to access the test web page.

### Pins and LED Settings

The inbuilt board LED and data pin used may need to be adjusted if not using a Wemos D1 Mini.

Set the `LED_COUNT` value to the number of LED's you wish to control. By default this is set to 10.

Then configure the grouping of LED's. Each group represents one individually controllable tally light.
The groups are defined in the `group[x][2]` array where x is the number of groups. 

For each group the start LED index and number of LED's in the group need to be set. See example below.

**5 LED's in 1 groups of 5 would look like:**

`#define LED_COUNT 5`

`int group[1][2] = {{0,5}};`

**10 LED's in 2 groups of 5 would look like:**

`#define LED_COUNT 10`

`int group[2][2] = {{0,5},{5,5}};`

This can be expanded for as many LED's and groups as requried. 

### Flash the Arduino

See [this](https://averagemaker.com/2018/03/wemos-d1-mini-setup.html) helpful guide to installing libraries and flashing the board if you've never done it before. The Adafruit Neopixel Library is also required. This can also be installed through the Arduino IDE in "Library Manager"

When the arduino boots the on board LED should flash indicating it is trying to connect to the WiFi Network. This will go solid when connected. If there are issues connecting check the network information configured and use the "Serial Monitor" in arduino IDE.

## Web Page Test 

Load <http://esp-tally.local> in a web browser. This simple web page will allow you to test the LED's are working in their groups. Group 0 will control all LED's together. Changing the group value will control the corresponding LED group.

## Tally Arbiter Configuration

Tally Arbiter can send POST requests via the 'outgoing webhook' action.

**Action Configuration**

| Option     | Value                                                             |
|------------|-------------------------------------------------------------------|
| IP Address | `IP or Hostname of board e.g. 'eps-tally.local'`                  |
| Port       | 80                                                                |
| Path       | *leave blank*                                                     |
| Mehtod     | POST                                                              |
| POST Data  | `LED Control Values e.g. 'led=ON&red=255&green=0&blue=0&group=1'` |

Some example POST Data (LED Control Values) for Tally Lights is contained in the `example-POST-data.txt` file.
