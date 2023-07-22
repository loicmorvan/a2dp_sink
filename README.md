| Supported Targets | ESP32 |
| ----------------- | ----- |

Bluetooth audio receiver and speaker
====================================

This is the example of API implementing Advanced Audio Distribution Profile to receive an audio stream.

This example involves the use of Bluetooth legacy profile A2DP for audio stream reception, AVRCP for media information notifications, and I2S for audio stream output interface.

Applications such as bluetooth speakers can take advantage of this example as a reference of basic functionalities.

## How to use this example

### Hardware Required

To play the sound, there is a need of loudspeaker and an external I2S codec.

This code was written using a PCM5102 chip, (yet other I2S boards and chips will probably work as well). The default I2S connections are shown below, but these can be changed in menuconfig:

| ESP pin   | I2S signal   |
| :-------- | :----------- |
| GPIO22    | LRCK         |
| GPIO25    | DATA         |
| GPIO26    | BCK          |

### Configure the project

```
idf.py menuconfig
```

* Enable Classic Bluetooth and A2DP under **Component config --> Bluetooth --> Bluedroid Enable**

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output.

```
idf.py -p PORT flash monitor
```

(To exit the serial monitor, type ``Ctrl-]``.)

## Example Output

After the program is started, the program starts inquiry scan and page scan, awaiting being discovered and connected. Other bluetooth devices such as smart phones can discover a device named "ESP_SPEAKER". A smartphone can be used to connect to the local device.

Once A2DP connection is set up, there will be a notification message with the remote device's bluetooth MAC address like the following:

```
I (106427) BT_AV: A2DP connection state: Connected, [64:a2:f9:69:57:a4]
```

If a smartphone is used to connect to local device, starting to play music with an APP will result in the transmission of audio stream. The transmitting of audio stream will be visible in the application log including a count of audio data packets, like this:

```
I (120627) BT_AV: A2DP audio state: Started
I (122697) BT_AV: Audio packet count 100
I (124697) BT_AV: Audio packet count 200
I (126697) BT_AV: Audio packet count 300
I (128697) BT_AV: Audio packet count 400

```

Also, the sound will be heard if a loudspeaker is connected and possible external I2S codec is correctly configured.

## Troubleshooting
* For current stage, the supported audio codec in ESP32 A2DP is SBC. SBC data stream is transmitted to A2DP sink and then decoded into PCM samples as output. The PCM data format is normally of 44.1kHz sampling rate, two-channel 16-bit sample stream. Other SBC configurations in ESP32 A2DP sink is supported but need additional modifications of protocol stack settings.
* As a usage limitation, ESP32 A2DP sink can support at most one connection with remote A2DP source devices. Also, A2DP sink cannot be used together with A2DP source at the same time, but can be used with other profiles such as SPP and HFP.
