# Gateway LoRaWAN

La passerelle (Gateway) est un routeur équipé d’un concentrateur LoRa qui peut recevoir des packets (ou messages) LoRa. La passerelle est l’élément qui se trouvera sur le terrain et collectera les données de tous les stations  qui se trouvent dans le périmètre de couverture de la passerelle.

On appelle aussi nœuds (ou nodes en anglais) pour désigner une station. Une station est l’élément qui prendra les mesures avec les capteurs connectés à cette dernière.


J'ai 4 differentes passerelle:

* The Things Outdoor Gateway (TTOG)
* The Thing Indoor gateway (TTIG)
* Gateway IC800a
* Chapeau LoRaWANN pour Raspberry Pi

(les deux dernières ne sont plus utilisées)

## The Things Outdoor Gateway (TTOG)

![TTOG](Assets/images/ttog-field.png "TTOG")

C’est la passerelle que j’utilise principalement sur le terrain et j’en suis pleinement statisfait. 


### Key features:

* IP67 waterproof enclosure
* 3G/4G backhaul support
* EU868 frequency band
* Transmit power upto +27dBm
* Supports LBT (Listen Before Talk)
* 802.3at Power-over-Ethernet
* Certifications: FCC, CE, RCM (Australia), Telec (Japan), NCC (Taiwan), RCM (Australia), Malaysia
* Dimensions: 230 x 200 x 68mm
* Weight: 2.05kg

## The Things Indoor Gateway (TTIG)

![TTIG](Assets/images/TTIG2.jpg "TTIG")

Elle est actuellement fixée sur une remorque « fixe », parquée au milieu des vignes. Une batterie solaire au gel de 12V/110Ah ainsi que 3 panneaux solaire de 60W sont nécessaires pour faire fonctionner cette passerelle 24h/24h.

Pour qu'elle fonctionne, j'ai dû adapter la passerelle pourqu'on puisse connecter une antenne exertne, car cette option n'est pas prévue. encore ajouté quelque périphlrique

* Un régulateur MPTT (Victron MPTT 75 | 15)
* Un routeur 4G/WiFi (NetGear)
* Antenne Sirio GP 868 C

![TTIG](Assets/images/ttig-box.jpg "TTIG")


Grâce a ceci, elle fonctionne 24h/24 et 365j par année, été comme hiver

Pour plus d'information voir [l'aarticle "Gateway LoRaWAN solaire"]()



