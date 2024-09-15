# Pi Supply IoT LoRa Gateway pour Raspberry

*Publié le 2 mars 2020*

*Keywords: Pi Supp, IoT LoRa Hateway, Raspbbery, TTN*

![Pi Supply IoT LoRa Gateway](Assets/images/IoT-LoRa-Gateway-HAT.png "Pi Supply IoT LoRa Gateway")

Dans cet article, je vais vous montrer comment réaliser une passerelle LoRaWAN avec un raspberry PI4, un chapeau IoT LoRaWAN. En supplément, je présente comment j’ai essayé d’utiliser un module 4G pour la transmission des données.

Dans cet article, nous allons voir

* comment ajouter une passerelle à votre console TTN (The Things Network)
* comment préparer votre Raspberry
* En supplément: comment la connecter à un autre Raspebrry avec un module 4G, via les ports ethernet (eth0)


## Information importante

> ATTENTION: Cet article a été écrit avant que The Things Network (TTN) migre sur la version [The things Stack V3](https://www.thethingsindustries.com/docs/). Tous les équipements enregistrés dans la version V2 ont dû être migrés sur la version V3 **avant le 1er décembre 2021**. Dans cet exercise, pour installer l'OS du Raspbbery/Gateway vous allez télécharger une image fournie par Pi Supply. La gateway installée avec cet OS est malheureusement plus compatible avec la version The Things Stack V3. Pi Supply m'avait indiqué qu'il allait mettre à jour leur image. Donc dès le 1 décembre 2021 ma passerelle équipé du "Pi Supply IoT LoRa Gateway" ne fonctionne plus, même **si elle a très bien fonctionné jusqu'au 1er décembre 2024**. Elle a notammenet été utilisée dans le cadre du Workshop 3: [15 bougies à pellets pour lutter contre le gel de printemps](https://github.com/ecosensors/ecosensors/tree/main/Projets/Gel%20de%20printemps/La%20bougie%20%C3%A0%20pellets/Workshop%203%20-%20Version%202). Depuis, je n'ai plus eu besoin de cette gateway même si je la garde précieusement.
>
> Le 15 septembre 2024, j'ai relu cet article et j'ai constaté que l'image n'avait toujours pas été mise à jour. Cependant, j'ai lu une information que je n'avais pas vu (ou qui a été ajouté plus tard), indiquant que **le module "Pi Supply IoT LoRa Gateway" n'est pas compatible avec un Raspberry Pi4 8G**. Il se trouve que dans le cadre de cette exercise, j'ai bien utilisé un Raspbbery Pi4. Mais comme je l'ai indiqué plus haut, j'ai utilisé cette passerelle/gateway, constituée d'un Raspberry Pi 4 et d'un chapeau "Pi Supply IoT LoRa Gateway" sur le terrain, pendannt plusieur mois.
>
> Il serait donc intéressant de **(re)faire cette exercise avec un Raspberry Pi3** sans garantie que la passerelle fonctionnera avec The Things Stack V3.
>
>Actuellement, je ne travaille plus avec cette passerelle, mais ca serait bien que je trouve un petit moment pour clarifié ceci et refaire cet exercise avec un Pi3

## Matériel

* Raspberry Pi3 (Cet exercise a été fait avant le 1er décembre 2021 avec un Pi4)
* [Pi Supply IoT LoRa Gateway HAT for Raspberry Pi](https://uk.pi-supply.com/products/iot-lora-gateway-hat-for-raspberry-pi?lang=fr) (EUR 143.50) avec l’antenne
* 1x SD card (min 8G)
* 1x câble Ethernet
* un clavier et une souris ainsi qu’un écran




