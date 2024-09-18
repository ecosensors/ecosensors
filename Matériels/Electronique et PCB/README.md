# List of the materials (LoRaWAN Gateways and nodes)

This is a not-exhaustive list of my LoRaWAN structure and board elements

## LoRaWAN gateways

### LoRaWAN Gateway 1 (solar)

![MPTT Regulator](https://eco-sensors.ch/wp-content/uploads/2022/04/ttig-box.jpg "MPTT Regulator")

* TTIG [Read More](https://www.thethingsindustries.com/docs/gateways/thethingsindoorgateway/)
* 3x60W solar panel (Second hand)
* MPTT Regulator (Victron MPTT 75 | 15)
* 12V/110Ah solar battery (Victron)
* 4G/WiFi router (netgear)
* Antenna SIRO GP 868 C

### LoRaWAN Gateway 2
* TTOG [Read more](https://www.thethingsindustries.com/docs/gateways/thethingsoutdoor/)
* [Glass fiber LoRa antenna](https://uk.pi-supply.com/products/rakwireless-glass-fiber-lora-gateway-antenna?_pos=4&_sid=3bbc78311&_ss=r)

### LoRaWAN Gateway 3
* Rasoberry Pi3
* IC880a Concentrator
* Antenna: 824-896 MHz, 50Ohm, 2dBi, RF power handling: 50 W

### LoRaWAN Gateway 4
* Nebra IP67 weatherproof
* Rasperry Pi3
* IoT Gateway HAT for Raspberry Pi (868MHz/915MHz) (PiSupply)
* [Glass fiber LoRa antenna](https://uk.pi-supply.com/products/rakwireless-glass-fiber-lora-gateway-antenna?_pos=4&_sid=3bbc78311&_ss=r)

[Read more](https://eco-sensors.ch/passerelle-lorawan-avec-deux-raspberry-pi3/)

## 4G router
* Rasperry Pi3
* Raspberry Pi 3G/4G & LTE Base HAT
* Quectel EC25 Mini PCIe 4G/LTE Module
* 2 LTE antenna


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

#### Sensors
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

## Toutes les sondes

### Pyranomètre
*Marque : Davis Instrument, Réf: 6450*

![Pyranomètre](Assets/images/IMG_5925-600x538.jpg "Pyranomètre")

*Un pyranomètre de Davis Instrument*

Un pyranomètre mesure le rayonnement solaire en W/m2.

* Plages de température : -40°F à 150°F (-40°C à 65°C)
* Résolution et Unités : 1 W/m2
* Plage de mesure : 0 à 1 800 W/m2
* Précision : ±5% à pleine échelle (Référence: Eppley PSP à 1000 W/m2) plus 45 W/m2 par câble additionnel de 100 ‘ (30 m)
* Dérive : jusqu’à ±2% par an
* Intervalle de mise à jour : 50 secondes à 1 minute


### Anémomètre
*Marque: Davis Instrument, réf: 6410*

![Anémomètre](Assets/images/anemomter.jpg "Anémomètre")

*Anémomètre pour mesurer la direction et la vitesse du vent*

L’anémomètre Davis (référence: 07911) est conçu pour mesurer à la fois la vitesse et la direction du vent. Le capteur de vitesse du vent utilise un interrupteur magnétique qui se déclenche une fois par tour des coups à vent. La direction du vent est mesurée à l’aide d’un potentiomètre.

* Plages de température: 40° to +149°F (-40° to +65°C
* Wind Direction
	* Display Resolution: 16 points (22.5°) on compass rose, 1° in numeric display
	* Précision: ±5°
* Wind Speed
	* Résolution et unités :mesuré en 1 mph. Les autres unités sont converties de mph et arrondies à 1 km / h, 0,1 m / s ou 1 nœud le plus proche
	* Plage de mesures : 1 to 200 mph, 1 to 173 knots, 0.5 to 89 m/s, 1 to 322 km/h
    * Précision: 2 mph (2 nœuds, 3 km / h, 1 m / s) ou ± 5%
* Input / Output Connections
    * Black . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Wind speed open drain to ground
    * Red . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Ground
    * Green . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Wind direction pot wiper (20KΩ potentiometer)
    * Yellow . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Pot supply voltage
    * Wind Speed Translation Formula . . . . . . . . . . . . . . . . . . 1600 rev/hr = 1 mph
    * V = P(2.25/T) (V = speed in mph, P = no. of pulses per sample period
    * T = sample period in seconds)
    * Wind Direction Translation . . . . . . . . . . . . . . . . . . . . . . . Variable resistance 0 – 20KΩ; 10KΩ = south, 180°

### Détecteur de gel par rayonnement
Cette sonde n’est plus utilisée pour la saison 2022

*Marque: Apogee Instruments, Réf: SF-110*

![SF-110](Assets/images/SF-110.jpg "SF-110")

*un capteur de température innovant conçu pour imiter les feuilles et les boutons de fleurs / fruits*

Les capteurs de température des feuilles et des bourgeons Apogee modèle SF-110 sont conçus pour estimer approximativement les températures des feuilles et des boutons floraux des plantes pour la prévision des événements de gel. Ils sont destinés aux applications dans les champs et les vergers cultivés lorsque la température de l’air est proche du point de congélation et lorsque les mesures de la température de l’air ne sont pas un bon prédicteur de la formation de gel.

Les capteurs de température des feuilles et des bourgeons d’Apogee Instruments SF-110 se composent de deux thermistances de précision, l’une combinée à une feuille simulée et l’autre à un bourgeon simulé, dans un seul boîtier.

Les détecteurs sont résistants aux intempéries et sont conçus pour mesurer en continu la température dans les mêmes conditions environnementales auxquelles les plantes sont exposées

* Temps d’équilibre : 10s
* plages de température : -50 to 70 C; 0 to 100 % humidité relative
* Précision: 0.02°C

### Sonde Température étanche (pour les bourgeons)
*Marque: Maxim Integrated, Modèle: DS18B20*

![DS18B20](Assets/images/ds18b20.jpg "DS18B20")

*Capteur de température étanche*

La sonde DS18B20 étanche mesure en degrés Celsius avec une précision de 9 à 12-bit,-55C à 125C (+ /-0.5C). Chaque capteur possède un numéro unique de 64-bit de série programmé dans ce qui permet un grand nombre de capteurs pour être utilisé sur un bus de données. Le DS18B20 communique via le bus1-Wire.

* Interface: 1-Wire
* plages de température -55°C to +125°C
* Précision: ±0.5°C de -10°C à +85°C

### Baromètre
*Marque: Bosch, Modèle: BME280*

![BME280](Assets/images/bme280-600x567.jpg "BME280")

*BME280*

Le BME280 est un capteur d’humidité spécialement développé pour les applications mobiles et les appareils portables où la taille et la faible consommation d’énergie sont des paramètres de conception clé. Le capteur d’humidité offre un temps de réponse extrêmement rapide et prend donc en charge les exigences de performance pour les applications émergentes telle que la connaissance du contexte et une précision élevée sur une large plage de températures.

* Plages de fonctionnement
	* Pression: 300…1100 hPa
	* Température: -40…85°C
* Interface : I2C
* Humidité
	* Temps de réponse: 1s
	* Précision: ±3%
