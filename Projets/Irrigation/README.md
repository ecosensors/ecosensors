# SmartIrrigation
## Pour planifier l'irrigation des cultures
L’objectif est de développer et mettre en pratique une solution, à bas coût, pour mieux surveiller et planifier l’irrigation des cultures en temps réel, et ainsi permettre aux exploitants d'augmenter leurs rendements.

## Des racines à votre smartphone
Les stations mesurent le taux hydrique du sol à une séquence définie ainsi que la température de la terre et les conditions atmosphériques. La passerelle collecte les mesures et les transmet au serveur qui va les sauvegarder dans une base de données. Grâce à ceci, nous pouvons tirer des statistiques, traiter les données sauvegardées et les afficher sur votre portable (smartphone, laptop, etc.).

### Des mesures au plus proche des racines	
![Sondes Watermark](Assets/images/irrigation-watermark-1.png "Sondes watermark")

 
* Trois sondes tensiométriques plantées à différentes profondeurs
* Un compteur de goutte
* Mesure l’humidité de l’air
* Mesure la température du sol
* Mesure la température de l'air
* Mesure la pression atmosphérique
* Mesure la luminosité
* Une infrastructure pour couvrir jusqu’à 5 kilomètres de rayon à surveiller 

### Un outil, des bénéfices
![Station de mesure](Assets/images/irrigation-station-1.png "Station de mesure")

* Mesure et visualisation en temps réel
* Simplification de la collecte et de l’interprétation des données
* Gestion des alarmes
* Performance du temps de réaction
* Augmentation du rendement


## Mais encore...
[Presentation sur Youtube](https://www.youtube.com/watch?v=QYvQ2LWMCxo&t=6s)

De nombreux types de capteurs et systèmes d’enregistrement de données ont été développés à cette fin. Leur adoption est encore limitée pour des raisons de coûts élevés et des difficultés dans la collecte et l’interprétation des données en temps opportun.

Les développements récents des microcontrôleurs Open Source (tel qu’Arduino), la communication sans fil, et l’Internet-of-Things (IoT) offrent des technologies intéressantes pour les agriculteurs, afin de

* réduire les coûts
* faciliter la collecte et l’interprétation des données
* visualiser l’état de ses cultures en temps réel
* mieux planifier l’irrigation des cultures

## Plus concrètement
La surveillance de l’irrigation des sols dans la production agricole est vital pour la durabilité économique et environnementale à long terme de l’agriculture. Il est donc important de développer des technologies d’irrigation efficaces pour les agriculteurs afin de leur permettre de gérer le traitement de leurs terres **quand**, **où** et dans **la quantité nécessaire**, pour maximiser leurs rendements.

Au fils des années, certaines technologies ont été développées pour aider les agriculteurs à planifier correctement l’irrigation. Ces technologies reposent généralement sur la surveillant des conditions météorologiques, en sondant les plantes et le sol.

Bien que beaucoup d’efforts ont été consacrés dans ce domaine, comme le développement des réseaux locaux de stations météorologiques et à la création de logiciels, les utilisations restent encore limitées.

Une étude récente avec des producteurs de maïs à grande échelle au Nebraska a montré que la surveillance de l’irrigation basé sur des capteurs a permis **d’économiser 33% d’eau** et le coût de pompage a été réduit considérablement.

Bien qu’une variété de capteurs et de systèmes de collecte et d’analyse de données sont actuellement disponibles dans le commerce, des solutions de surveillance en temps réelle, permettant de mieux planifier l’irrigation des cultures, sont encore rares. Ceci s’explique par des prix élevés, aux difficultés d’installation et de maintenance et à la difficulté de transmettre les mesures obtenus sur plusieurs kilomètres.

Le développement des microcontrôleurs à faible coût et OpenSource, leur capacité de gérer les technologies de communication sans fil, comme la radio, le téléphone cellulaire et le WiFi, offrent des possibilités très abordable. De plus, les récents développements dans les technologies de l’Internet des objets (Internet-of-Things) utilisés dans une grande variété d’applications, tel que les maisons intelligentes ou les villes intelligentes, apportent un complément non-négligeable, aux possibilités.

L’utilisation de ces technologies tel que l’Internet des objets (IoT) dans l’agriculture est encore très limitée. Mais ceci pourrait offrir des possibilités d’améliorer la planification de l’irrigation des cultures, grâce à des capteurs fournissant des données en temps réelles.

C’est pourquoi, l’objectif fixé de cet projet est de développer, tester et de mettre en pratique, une solution IoT de gestion de l’irrigation des cultures, à bas coût.

	Jusqu’à 3 à 10 km de couverture et une très faible consommation

Pour arriver à ces résultats, j’utilise une technologie promettante: LoRaWAN. Cette technologie est particulièrement intéressante car elle permet de transmettre des donnée par radio, dans un rayon de 3 à 10 kilomètres (en fonction de la configuration du terrain), à bas débit et surtout à une très faible consommation.

Dans l’expérience en cours, deux stations (nœuds) sont équipées de

* 3 sondes tensiométriques Watermark, pour mesurer le teneur en eau du sol en kPa (6 sondes Watermark pour la deuxième station)
* 1 sonde pour mesurer la température du sol
    un pluviomètre pour compter les gouttes versées par le système d’arrosage goutte-à-goutte.
* 1 sonde pour mesurer la température de l’air, la pression atmosphérique et l’humidité
* 1 sonde pour mesurer la luminosité
* un sonde IR pour mesurer la température (en phase de teste)
* Carte SD pour sauver les données et la journalisation

Sur la deuxième station, nous avons ajouté 3 sondes tensiométriques supplémentaires, soit 6 en tous, positionnées pour observer la formation de la bulbe d’eau qui va se forme avec l’arrivée des chaleurs et de l’arrosage.

Toutes les heures, les stations prennent les mesures et les envoient à la passerelle (gateway) qui traitera les données reçues et les transmettra à un serveur distant. Une interface web permettra aux propriétaires de visualiser l’état de leurs cultures, depuis leur smartphone, et en temps réel, depuis n’importe où, comme lors de votre petit-déjeuné, par exemple.

La passerelle, quant à elle, est autonome puisqu’elle est alimenté par une batterie de 12V/60A. Elle est connectée à un panneau solaire de 60W. Elle se trouve à 1 kilomètre des stations (nœuds). Pour plus de détail sur la passerelle, vous pouvez suivre ce lien: Passerelle pour la transmission des mesures.

Ainsi, il sera plus facile de choisir le bon moment pour irriguer vos sols, et de bien quantifier le besoin en eau.

** Perfectionnements apportés durant l’hiver 2019

Les circuits électroniques en place actuellement doivent être remplacés par un nouveau modèle amélioré, dont les modifications suivants ont été apportées:

* remplacement un circuit intégré trop gourmand
* modification de la programmation de micro-contrôleur pour améliorer l’autonomie (58 mn de veille sur 60 mn).
* amélioration du timing des prises des mesures avec un module RTC (Real Time Clock)
* amélioration du mode d’alimentation des sondes tensiométriques, pour avoir un résultat plus précis
* nouveau PCB personnalisé et plus petit
* intégration du baromètre et du luxmètre dans le PCB
* remplacement de certains connecteurs pour un montage et branchement des sondes plus simple
* amélioration des affichages des mesures sur un écran LCD (affichage page par page et mise en veil)
* utilisation de la carte SD pour enregistrer les paramètres de fonctionnalités du module

Enfin, j’ai refait l’application web pour un affichage plus convivial, sous forme de graphiques complets. Cette application web sera amenée à évoluer, notamment pour la gestion des alarmes, lorsque l’humidité du sol aura franchi le seuil critique.

# Expérience sur le terrain

Deux stations ont été installées, fin juin 2018, dans un verger genevois, au milieu des pommiers.

Les deux stations se trouvent au deux extrémités du verger. L’une au point le plus haut et la seconde au point le plus bas du verger. Toutes les deux mesurent:

* l’état hydrique du sol à 3 niveaux différents* grâce a trois sondes tensiométriques
* un compteur de goutte pour mesurer la quantité d’eau utilisée par arrosage
* l’humidité de l’air
* la température du sol
* la température de l’air
* la luminosité
* la pression atmosphérique
* l’état de la batterie

	Une sonde tensiométrique ne mesure pas l’humidité du sol mais la force de liaison entre l’eau avec le sol (exprimé en tension), autrement dit, la force de succion que la racine doit exercer pour extraire l’eau du sol

Toutes les heures, elles envoient les 10 mesures cités haut-dessus, à la passerelle qui elle se trouve à 1 kilomètre de la première station.

Les stations sont alimentées par une batterie au lithium de 3.7V/1000mA. Cette dernière est connectée à un petit panneau solaire de 3W qui suffit largement pour maintenir une tension de 4 à 4.3V sur 24h. A savoir qu’une batterie au lithium a une plage de fonctionnalité entre 3.6V et 4.3V. C’est à dire qu’en dessous de 3.6V, elle ne suffit plus pour alimenter une charge alors qu’à 4.3V, elle est entièrement chargée. Ce qui nous donne une marge dans le cas où des journées non ensoleillées devaient se suivent.

Les pommiers sont arrosés tous les deux-trois jours grâce à système d’arrosage goutte-à-goutte. En moyenne, 10 litres d’eau est versés par goutteur. Fin juillet, j’ai installé un pluviomètre sous le goutteur afin de compter le nombre de gouttes par heure.

