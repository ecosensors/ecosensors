# Gateway LoRaWAN Waterproof avec deux Raspberry Pi3

*Publié le 24 octobre 2020*

*Keywords: Sixfab, IoT LoRa Hateway, Raspbbery, TTN, 3G/4G & LTE Base HAT, Quectel*

![Gateway LoRaWAN Waterproof avec deux Raspberry Pi3](Assets/images/gateway-sixfab-qmi-eth0.jpg "Gateway LoRaWAN Waterproof avec deux Raspberry Pi3")

Dans cet article, je vais vous montrer comment faire pour que deux Raspberry puissent établir un connexion sur un serveur distant via le premier Pi et comment créer sa passerelle LoRaWAN avec deux Raspberry Pi3.

Dans cet article, je vais prendre deux Raspberry Pi3 avec Rasbain Buster du 20-08.2020

* Sur le premier, je vais installer un chapeau sixfab 4G https://sixfab.com/product/raspberry-pi-base-hat-3g-4g-lte-minipcie-cards/ avec son module quectel https://sixfab.com/product/quectel-ec25-mini-pcle-4glte-module/ qui permettra à ce premeir raspberry de se connecter à internet. En partageant le port eth0, le deuxième Raspbbery pourra aussi se connecter à un serveur distant via le premier.
* Sur le deuxième Raspbbery, je vais installer un chapeau (HAT) LoRaWAN de pi-supply https://uk.pi-supply.com/products/iot-lora-gateway-hat-for-raspberry-pi?lang=fr. En le connectant avec un câble Ethernet sur le premier, vous réaliserez une passerelle LoRaWAN


## Matériel

* Deux Raspberry Pi3
* [PiSupply IoT LoRa Gateway](https://uk.pi-supply.com/products/iot-lora-gateway-hat-for-raspberry-pi?lang=fr) (Il semble que ce module a été remplacé par le [RAK2247](https://uk.pi-supply.com/products/iot-lora-gateway-hat-for-raspberry-pi?lang=fr))
* [Nebra IP67 weatherproof](https://uk.pi-supply.com/products/die-cast-outdoor-weatherproof-enclosure)
* [Glass fiber LoRa antenna](https://uk.pi-supply.com/products/rakwireless-glass-fiber-lora-gateway-antenna?_pos=4&_sid=3bbc78311&_ss=r)
* [2x N-Type connector (UFL/IPEX)](https://uk.pi-supply.com/products/ufl-ipex-to-n-type-bulkhead?_pos=1&_sid=a5f981cd4&_ss=r)
* DELOCK N-Type SMA Adapter
* Une antenne GSM
* [Raspberry Pi 3G/4G & LTE Base HAT](https://sixfab.com/product/raspberry-pi-base-hat-3g-4g-lte-minipcie-cards/)
* [Quectel EC25 Mini PCle 4G/LTE Module](https://sixfab.com/product/quectel-ec25-mini-pcle-4glte-module/)
* Power supply 5V/2A (MicroUSB)
* [2 fils femelle-femelle](https://www.adafruit.com/product/1919)
* un câble ethernet

## Information importante

> [Edit 09.2024] Cette passerelle (gateway) a été réalisée avec un Raspberry Pi4 et la carte IoT LoRa Gateway (RAK2247), et elle a très bien fonctionnée sur le terrain de mars 2020 a décembre 2021. Elle a notammenet été utilisée dans le cadre du Workshop 3: [15 bougies à pellets pour lutter contre le gel de printemps](https://github.com/ecosensors/ecosensors/tree/main/Projets/Gel%20de%20printemps/La%20bougie%20%C3%A0%20pellets/Workshop%203%20-%20Version%202). Depuis que The Things Network (TTN) a migré sur la version The things Stack V3](https://www.thethingsindustries.com/docs/), la passerelle a cessé de traiter les données reçues quand je l'ai migrée sur Stack V3. Selon Pi Supply, l'OS du Raspberry ne serait pas compatible avec Stack V3. Je n'ai pas investigué d'avantage car la passerelle TTOG me suffisait pour mes autres applications.
>
> Mi-septembre 2024, j'ai relu cet article et j'ai constaté que l'image fournie par Pi Supply, n'a pas été mise à jour depuis 2019. J'ai aussi lu une information que je n'avais pas vu (ou qui a été ajouté plus tard), indiquant que **le module "Pi Supply IoT LoRa Gateway" n'est pas compatible avec un Raspberry Pi4 8G**. (Pourtant ma passerelle a bien fonctionnée pour moi, avec un Raspberry Pi4)
>
> Pi Supply m'a aussi suggéré d'utiliser une autre image [rak_common_for_gateway](https://github.com/RAKWireless/rak_common_for_gateway?tab=readme-ov-file) qui est [compatible avec RAK2247](https://github.com/RAKWireless/rak_common_for_gateway?tab=readme-ov-file#supported-platforms).

Pour le moment, je laisserai cet article comme je l'ai écris en 2020 mais il serait intéressant de retravailler cette solution.

