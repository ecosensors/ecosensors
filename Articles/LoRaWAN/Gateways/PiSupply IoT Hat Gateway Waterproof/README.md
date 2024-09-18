# Gateway LoRaWAN Waterproof avec deux Raspberry Pi3

*Publié le 24 octobre 2020*

*Keywords: Sixfab, IoT LoRa Hateway, Raspbbery, TTN, 3G/4G & LTE Base HAT, Quectel*

![Gateway LoRaWAN Waterproof avec deux Raspberry Pi3](Assets/images/gateway-sixfab-qmi-eth0.jpg "Gateway LoRaWAN Waterproof avec deux Raspberry Pi3")

Dans cet article, je vais vous montrer comment faire pour que deux Raspberry puissent établir un connexion sur un serveur distant via le premier Pi et comment créer sa passerelle LoRaWAN avec deux Raspberry Pi3.

Dans cet article, je vais prendre deux Raspberry Pi3 avec Rasbain Buster du 20-08.2020

* Sur le premier, je vais installer un chapeau sixfab 4G https://sixfab.com/product/raspberry-pi-base-hat-3g-4g-lte-minipcie-cards/ avec son module quectel https://sixfab.com/product/quectel-ec25-mini-pcle-4glte-module/ qui permettra à ce premeir raspberry de se connecter à internet. En partageant le port eth0, le deuxième Raspbbery pourra aussi se connecter à un serveur distant via le premier.
* Sur le deuxième Raspbbery, je vais installer un chapeau (HAT) LoRaWAN de pi-supply https://uk.pi-supply.com/products/iot-lora-gateway-hat-for-raspberry-pi?lang=fr. En le connectant avec un câble Ethernet sur le premier, vous réaliserez une passerelle LoRaWAN
