Je présente [des articles](https://github.com/ecosensors/ecosensors/tree/main/Articles) (tutoriels) sur Arduino, LoRa, Raspberry et différents [projets](https://github.com/ecosensors/ecosensors/tree/main/Projets) LoRaWAN (IoT) que j'ai réalisé ces dernières années, notamment pour lutter contre le gel de printemps ou pour surveiller la teneur en eau dans le sol des cultures. Mais vous trouverez encore:

* Des exemples de scripts pour Arduino (**The repositories and examples of codes are written in english**)
* Mon propre micro-contrôleur EcoBoard basé sur un processeur ATSAMD21G, le même utilisé par l’Arduino Zero
* Une passerelle LoRaWAN autonome sur une remorque fonctionnant avec des paneaux solaires
* Un workshop pour surveiller en temps réel, **la teneur en eau dans le sol des culture**
* Un workshop **pour lutter contre le gel de preintemps** (surveillance de la température des bourgeons
 en temps réel)
* Une station LoRaWAN pour surveiller la poluttion
* Une station météo LoRaWAN dans un abri Stevensom
* la liste de mon matériel

# Qui suis-je?

Il y a bien 8-9 ans, alors que nous étions à un festival avec nos enfants de bas âge, nous discutions entre parents. Les enfants étaient dans notre champs de vision, mais dès la tombée de la nuit, nous ne pouvions plus tenir sur place, inquiet de la « position » de nos enfants. Je me suis exclamé en disant, en rigolant, « mettons leur un GPS, et dès qu’ils sortent d’une zone de sécurité, on est alarmé sur nos portables ».
Bien entendu, ceci était une blague, mais l’idée d’être alarmé quand un cher disparaît et de le localiser immédiatement, m’a trotté dans la tête. On a tous vécu une fois le stresse de perdre son enfant, ou de ne pas retrouver une personne d’un certain âge qui ne retrouve plus son chemin de retour.

Mais comment faire un module qui vous alerte quand un sujet sort d’un périmètre de sécurité? C’est là, que j’ai commencé de zéro, même le mot Arduino, je ne le connaissais pas.

On m’a montré un Arduino. On m’a montré comment afficher « Hello World » sur le terminal, et j’ai commandé ma première carte Arduino, j’ai découvert le langage C/C++. Quelques mois plus tard, je développe [un prototype qui permet de géolocaliser un sujet](https://github.com/ecosensors/ecosensors/tree/main/Articles/Arduino/G%C3%A9olocalisation%20d%E2%80%99objets).

**Technologies utilisées**

* C/C++, Mosqitto (MQTT), RabbitMQ, Leaflet
* Adafruit Feather, SIM808 (GPS, GPRS)

## Les objets connectés

Ces deux premières années m’ont permis de replonger dans l’électronique, qui est ma formation de base, mais surtout d’acquérir une expertise dans [les systèmes embarquées](https://fr.wikipedia.org/wiki/Syst%C3%A8me_embarqu%C3%A9) et de développer mes propres librairies.

Alors que je terminais le prototype du module de géolocalisation, un ami m’a demandé si je connaissais Laura et de ses avantages en se référant à mon prototype. En réalité, il ne me parlait pas de Laura mais de LoRa, qui est un réseau basé sur la technologie LoRaWAN (Low Range Wild Area Network).

Curieux de découvrir ce protocole, je commande des capteurs d’humidité du sol par détection capacitive et je m’amuse à mesurer le taux hydrique de plusieurs plantes de mon appartement et de transmettre les mesures grâce à LoRaWAN. Je met en place [un petit système d’arrosage automatique pour un bonsaï](https://github.com/ecosensors/ecosensors/tree/main/Articles/Arduino/Arrosage%20d'un%20bonsa%C3%AF).

### Smart Irrigation
Ces expériences se faisant dans mon appartement, je me trouve vite limité par la puissance de LoRaWAN, puisque la particularité de ce protocole est de transmettre les données sur une longue portée et à une faible consommation. Il est encore bien d’ajouter que la transmission des données est à très faible débit. On ne transmet donc pas de la voix, du son ou des images, mais des chaînes de caractères regroupant des mesures.

Exemple: `a456b341c34d33e678f128e7692g1h22`

Je contacte alors une amie d’enfance viticultrice pour pouvoir mettre en application mon travail en situation réel, dans une vigne avec de nouvelles sondes tensiométrique WATERMARK.

C’est là que naît le projet [SMART IRRIGATION](https://github.com/ecosensors/ecosensors/tree/main/Projets/Irrigation), qui va mesurer, en temps réel, le taux hydrique des sols des cultures.

### Smart Bud
Grâce à une campagne de financement participatif réussie, je finance le matériel nécessaire et je développe de nouvelles stations. Je réalise moi-même mes propres circuits imprimés des stations et je fais évoluer plusieurs versions.

Durant ce projet, je savais déjà que le gel de printemps pouvait causé de gros dégâts aux cultures et l’idée d’ajouter une solution pour surveiller la température des bourgeons qui émergent, en temps réel, me trottait dans la tête.

Fort des nouvelles expériences acquises durant ce projet, je prends contact avec deux autres domaines viticoles et je leur propose de mettre en place [une structure de surveillance en temps réel](https://github.com/ecosensors/ecosensors/tree/main/Projets/Gel%20de%20printemps), qui leur permettront d’être alarmé dès qu’une station mesure une température critique, au plus proche des bourgeons.

J’ai également travaillé sur un abri Stevenson ainsi qu’une bougie à pellets. Je me suis donc « improvisé » comme menuisier pour fabriquer les abris Stevenson et comme serrurier pour souder l’acier afin d’avoir une belle bougie à pellets.

![Abris Stevenson](stevenson1.jpg "Abri Stevenson")

![Bougie à Pellets](bougie-a-pellers.jpg "Bougie à pellets")

### Technologies utilisées

Pour mener à bien ces projets (SMART IRRIGATION et SMART BUD), qui sont deux projets « jumeaux », j’ai été amené à utiliser divers technologies et langages de programmation

Pour la partie web ([bud.eco-sensors.ch](http://bud.eco-sensors.ch/))

* HTML, PHP, MySQL, javascript, jQuery, [chartjs](https://www.chartjs.org/), [leaftlet](https://leafletjs.com/)

Pour l’application Smartphone (IOS et Android)

* HTML, javascript, jquerymobile, chartjs, leaftlet
* Cordova, [onesignal](https://onesignal.com/)

Pour la transmission des données

* LoRaWAN, Z-wave

Pour les stations et les sondes

* Mes propres micro-contrôleurs basés sur le chip ATSAMD21G18 ARM Cortex M0 programmé avec le langage C/C++
* un pyranomètre Davis
* un anémomètre Davis
* un baromètre BME280
* un pluviomètre
* une sonde de température DS18B20
* un détecteur de gel par rayonnement
* des sondes WATERMARK
* Réalisation de PCB avec le software Eagle PCB ainsi qu’une PnP (Pick and Place)

## Qui suis-je alors?

J’aime à dire que je ne suis pas un ingénieur, ni un expert, car mes différents travaux me poussent à découvrir des technologies nouvelles qui répondent aux besoins de mes projets. De ce fait, je passe mon temps à apprendre et à solutionner pour présenter une application.

En dehors de cela, j'ai travaillé pour une institution fédérale en tant que responsable informatique. J’ai eu une petite agence web. Plus anciennement, j’ai voyagé dans différents continents qui m’ont permis d’apprendre 3 langues (EN/ES/DE), en plus de ma langue maternelle.

J’aime relever des défis sportifs: j’ai traversé la France à vélo et de partir sans savoir ou aller, me convient aussi , pour autant qu’il y ait un but et d’étudier son chemin.

> Le plus important n’est pas d’atteindre son but, mais le chemin qui nous y mène