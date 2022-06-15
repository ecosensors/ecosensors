Hi, I’m @ecosensors
- I’m interested in building IoT applicatiom with LoRaWAN devises for agriculture
- I’m currently working on sensors to monitor temperature of the buds that emerge during the spring frost, to allow operators to be immediately alarmed and to take the necessary action to protect their crops [Read more (french)](https://eco-sensors.ch/smart-bud/). I am also working on similar PCB to monitor the water content in the soil of crops to allow operator to control the irrigation in order to save on the cost of pumping and increase the operator's yield [Read more (french)](https://eco-sensors.ch/smart-irrigation/). Finally, I developed LoRaWAN Meteo station [Read more (french)](https://eco-sensors.ch/meteo/)

How to reach me : [EcoSensors](https://www.eco-sensors.ch)

# List of materials
This is a not-exhaustive list of my LoRaWAN structure and board elements

## LoRaWAN Gateway 1 (solar)
* TTIG [Read More](https://www.thethingsindustries.com/docs/gateways/thethingsindoorgateway/)
* 3x60W second hand solar panel
* MPTT Regulator (Victron MPTT 75 | 15)
* 12V/110Ah solar battery (Victron)
* 4G/WiFi router (netgear)
* Antenna SIRO GP 868 C

## LoRaWAN Gateway 2
* TTOG [Read more](https://www.thethingsindustries.com/docs/gateways/thethingsoutdoor/)

## LoRaWAN Gateway 3
* Rasoberry Pi3
* IC880a Concentrator
* Antenna: 824-896 MHz, 50Ohm, 2dBi, RF power handling: 50 W

## LoRaWAN Gateway 4
[Read more](https://eco-sensors.ch/passerelle-lorawan-avec-deux-raspberry-pi3/)

* Nebra IP67 weatherproof

### 4G router
* Rasperry Pi3
* Raspberry Pi 3G/4G & LTE Base HAT
* Quectel EC25 Mini PCIe 4G/LTE Module
* 2 LTE antenna

### LoRaWAN gateway
* Rasperry Pi3
* IoT Gateway HAT for Raspberry Pi (868MHz/915MHz) (PiSupply)
* Glass fiber LoRa antenna


## LoRaWAN Meteo stations
### Main board
* PCB Version: Eco-lora-v2.1
* LoRaWAN Library: Arduino-lmic 4.1.1
* LoRaWAN Chip: RFM95, Band ISM, 868Mhz
* Microcontroller: ATSAMD21G18-MF ARM Cortex M0 at 48Mhz, 256K of FLASH, 32K of RAM
* EEPROM: 24LC64-I/SN
* GPIO Port Expander: PCF8574
* Lipo Changer: MCP73831
* 4 analog inputs powered by either 3.3V or a control pin through a MOSFET-P
* 2 I2C connectors
* 1 UART connector
* 1 U.FL connector
* 1 microUSB
* 1 Micro SD card
* 1 debuger/programmer connector
* 1 reset buton
* 1 programable buton
* 1 switch ON/OFF Button
* 4 LEDs

### Solar board
* PCB version: Eco-solar-v2
* Solar chip: MCP73871
* 5 analog input or 1-WIRE
* 2 I2C connector
* 1 MicroUSB connector
* 1 UART connector
* 1 18650 battery holder
* 1 Battery input
* 1 DC inout
* solar panel input
* 3 status LEDs (power/charging/done)
* Raspberry connector

### Sensors
* Pyranometer: Davis Instrument 8450
* Anenometer: Davis Instrument 6410
* Barometer: Boesch BME280
* Pluviometer
* Solar Panel: 5W

## LoRaWAN Irrigation stations (Smart Irrigation)
* PCB Version: fox-board_full_mcp-v3
* LoRaWAN Library: Arduino-lmic 4.1.1
* LoRaWAN Chip: RFM95, Band ISM, 868Mhz
* Microcontroller: ATSAMD21G18-MF ARM Cortex M0 at 48Mhz, 256K of FLASH, 32K of RAM
* EEPROM: 24LC64-I/SN
* GPIO Port Expander: PCF8574
* **DS3231 (RTC) with a CR1220 battery holder**
* **TSL2561 sensor (Luminosity)**
* **DS18B20**
* **BM280 (Barometer)**
* 3 WATERMARK sensors input
* 3 Timer/Oscillator (LMC555)
* 1-Wire input
* 4 analog inputs powered by either 3.3V or a control pin through a MOSFET-P
* 3 I2C connectors
* 1 I2C inout for an OLED screen
* 1 OLED button
* 1 UART connector
* 1 U.FL connector
* 1 input for watering
* 1 microUSB
* 1 Micro SD card holder
* 1 debuger/programmer connector
* 1 reset buton
* 1 programable buton
* 1 switch ON/OFF Button
* 7 status LEDs
* Lipo Changer: MCP73831
* Solar charger: MCP73871
* Solar panel input
* Battery input

### Sensors
* 3 WATERMARK tensiometric sensors

## LoRaWAN BUD Stations (Smart Bud)
* PCB Version: Eco-lora-v2.1 (some station have the version Eco-lora-v2.0)
* LoRaWAN Library: Arduino-lmic 4.1.1
* LoRaWAN Chip: RFM95, Band ISM, 868Mhz
* Microcontroller: ATSAMD21G18-MF ARM Cortex M0 at 48Mhz, 256K of FLASH, 32K of RAM
* EEPROM: 24LC64-I/SN
* GPIO Port Expander: PCF8574
* Lipo Changer: MCP73831
* 4 analog inputs powered by either 3.3V or a control pin through a MOSFET-P
* 2 I2C connectors
* 1 UART connector
* 1 U.FL connector
* 1 microUSB
* 1 Micro SD card
* 1 debuger/programmer connector
* 1 reset buton
* 1 programable buton
* 1 switch ON/OFF Button
* 4 LEDs

### Sensors
* 4 1-Wire DS18B20 waterproof temperature sensors




