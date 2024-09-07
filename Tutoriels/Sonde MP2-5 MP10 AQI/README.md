# Sonde pour mesurer de la qualité de l’air (PM2.5/PM10) avec Python3

*Publié le 11 juin 2020*

Dans cet article, je vais vous montrer comment préparer un Raspberry et Python3 pour mesurer les poussières fines PM2.5 et PM10 et comment transmettre les mesures à un serveur distant grâce à LoRaWAN

J'attire votre attention que cet article n'est pas un tutoriel, mais mes notes. Il vous apportera les outils et des astuces pour le faire, mais il vous sera demandé un minimum de compétences. Cet article est donc mené à être modifier et améliorer.

**N'hésitez pas à me laisser vos commentaires pour améliorer cet article**

Dans cet article, nous verrons comment

* Installer et configurer votre Raspberry Zero
* préparer votre script python
* installer l'écran OLED LCD
* installer du capteur SDS011
* installation du capteur MH-Z19B
* installer un serveur lighttpd et tinylora
* préparer LoRaWAN et créer votre application TTN
* envoyez les données
* sauvez les mesures dans un fichier JSON
* Installer et configurer un GPS (PG-735)
* Installer un carte pour gérer la charge de la batterie avec un panneau solaire
* Economiser la consomation du Raspberry en déactivant le bluetooth, le HDMI et les LEDs de la carte

## Matériels

* [Raspberry Zero W](https://www.raspberrypi.org/products/raspberry-pi-zero-w/) (CHF 24.--)
* [RFM 95 Lorawan/TTN hat with OLED LCD](https://www.tindie.com/products/electronictrik/lorawanttn-kit-for-the-raspberry-pi/) ($40.--)
* [Nova SDS011](https://www.conrad.ch/fr/p/module-capteur-joy-it-feunstaubsensor-uart-sen-sds011-1-pc-s-1884873.html?gclid=Cj0KCQjw4dr0BRCxARIsAKUNjWT3VCLIRbORVSSGzu8LDaWvpKLrUchu98nh14xlgFnS5BYh1SNIBccaAujLEALw_wcB&utm_source=google-shopping-fr&utm_medium=search&utm_campaign=shopping-online-fr&utm_content=shopping-ad_cpc&WT.srch=1&ef_id=Cj0KCQjw4dr0BRCxARIsAKUNjWT3VCLIRbORVSSGzu8LDaWvpKLrUchu98nh14xlgFnS5BYh1SNIBccaAujLEALw_wcB%3AG%3As) (CHF 38.--)
* [MH-Z19D](https://www.winsen-sensor.com/d/files/PDF/Infrared%20Gas%20Sensor/NDIR%20CO2%20SENSOR/MH-Z19%20CO2%20Ver1.0.pdf)
* Un adaptateur USB -> MicroUSB
* [GPS GP-735](https://www.digikey.com/catalog/en/partgroup/gps-receiver-gp-735-56-channel/66012)
* [Solar Power management](https://www.waveshare.com/solar-power-manager.htm)
* [Panneau solaire 6V/5W](https://www.waveshare.com/solar-panel-6v-5w.htm)
* Batterie Li-ion 15'000mAh

## Préparation du Raspberry
Commencer par télécharger la dernière version de Rasbian Buster Desktop que vous pouvez [télécharger ici](https://www.waveshare.com/solar-panel-6v-5w.htm)

Téléchargez et installez la dernière version d'[Etcher](https://www.balena.io/etcher/) et créez l’image sur la carte SD

![Etcher](Assets/images/iot-schema.jpg "Etcher")

*Etcher (2019-09-2...-lite.img est représentatif, vous devriez voir quelque chose comme 2020-02-1...lite.zip)*

Une fois fait, retirez et réinsérez la carte SD dans votre Mac, et créez un fichier ‘ssh’ dans le dossier boot, pour activer ssh lors du premier démarrage du Raspberry (L’exemple est donné depuis un Mac)

```
touch /Volumes/boot/ssh
```

Ceci vous permettra d'accéder à votre Raspberry en ligne de commande, avant d'avoir configurer votre Raspberry

```
ssh pi@raspberrypi.local 
#Le mot de passe de ‘pi’ par défaut est ‘raspberry’
```

Ceci est particulièrement utile si vous êtes à l'aise avec les lignes de commande et si vous ne pouvez/voulez pas connecter un écran à votre Raspberry.

Éjectez votre carte SD et insérez la dans le Raspberry.
Puis connectez votre Raspberry au routeur à l’aide du câble Ethernet. Connectez votre souris, clavier et écran à votre Raspberry.

Si vous avez créé le dossier `/Volumes/boot/ssh` vous pouvez vous passer de votre écran.

### Mise à jour

