# Comment ça fonctionne
## Des stations

![IoT Station](assets/images/iot-comment-ca-fonctionne/station.png "IoT Station")

Les stations (ou les nœuds) prennent les mesures à une séquence définie. Les données sont périodiquement envoyées à la passerelle. 

## Une passerelle

![LoRaWAN Gateway](assets/images/iot-comment-ca-fonctionne/gateway.png "LoRaWAN Gateway")

La passerelle (Gateway en anglais) est l’élément qui se trouve sur le terrain et collectera les données de toutes les stations qui se trouvent dans le périmètre de couverture de la passerelle. En fonction de la configuration du terrain, elle peut couvrir un rayon allant jusqu'à 12km, voir plus.

## Un serveur
![Remote server](assets/images/iot-comment-ca-fonctionne/network-server.png "Remote server")

Le serveur est le périphérique qui ne se trouve pas sur le terrain mais dans une salle de serveur. Il recevra les données envoyées par la passerelle, les traitera et les sauvera dans une base de donnée. 


## Votre smartphone
![Devises](assets/images/iot-comment-ca-fonctionne/devises.png "Devise")

Ainsi, depuis vos périphériques préférés, comme votre smartphone, vous pouvez suivre l'évolution de la zone à surveiller en **temps réel, recevoir des alarmes et agir en temps importun**. 