# Comment inclure un capteur dans Jeedom

*Publié le 4 décembre 2019*

Dans cet article, nous allons voir comment inclure un capteur dans votre domotique Jeedom, comme une ampoule, un détecteur de porte (ouverture/fermeture) et un détecteur de mouvements.

## Prérequis
Vous devez avoir un contrôleur Jeedom fonctionnel. Cet article se base sur un contrôleur équipé d’un Raspberry Pi4 et d’une carte d’extension RazBerry. L’installation et la configuration de ce contrôleur a été réalisée suivant cet article: [Installation de Jeedom sur un Raspberry Pi4](../installation-jeedom)

Vous devez avoir installé le plugin Z-wave.

## Matériel

* Un détecteur de mouvements [Fibaro Motion Sensor – FGMS-001](https://jeedom.github.io/documentation/zwave/fr_FR/fibaro.fgms001_-_Motion)
* Un détecteur [Door/Window Sensor 2](https://manuals.fibaro.com/fr/door-window-sensor-2/)
* Une ampoule Aeotec [LED Bulb 6 Multi-Color (ZWA002)](https://aeotec.com/z-wave-led-lightbulb/)

## Précautions

Pour des raisons de sécurité, je vous conseille vivement de modifier la clé de sécurité Z-Wave avant l’inclusion. Pour réaliser cette opération, vous pouvez lire l’article [Installation de Jeedom sur un Raspberry Pi4](../installation-jeedom), en bas de page. Cette étape est importante de le faire avant l’inclusion du premier capteur, faute de quoi, vous devrez les exclure et le ré-inclure, pour que tous les modules soient associés à cette nouvelle clé.
