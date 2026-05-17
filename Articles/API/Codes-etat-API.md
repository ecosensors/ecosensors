# Codes d'état d'API

## 10X - Information
* 100 Continue - La requête est en cours de traitement.
* 101 - Le serveur accepte le changement de protocole spécifié par l'entête 
* 102 Processing - Traitement en cours (évite que le client dépasse le temps d’attente limite). 
* 103 Early Hints - (Expérimental) Dans l'attente de la réponse définitive, le serveur renvoie des liens que le client peut commencer à télécharger.

## 20x - Success
* 200 OK - La requête est réussie
* 201 Crée - Nouvelle resource crée
* 202 Accepted - reçue et acceptée pour traitement, mais que celui-ci n'est pas encore terminé
* 203 Non-Authoritative Information indique que la requête a réussi, mais que la réponse a été modifiée par un proxy ou un intermédiaire
* 204 Pas de contenu - Succès sans rien retrouné

## 30x - Redirection
* 301 Déplacé de façon permanente
* 302 trouvé - rediection temporaire
* 304 Non modifié - (version en cache)

## 4xx - Erreur client
* 400 Mauvaise requête - saisie non valide
* 401 Non authorisé - authentification manquante/invalide
* 403 Interdit - Auth OK, pas de permission
* 404 Non trouvé
* 406 Not accepted
* 409 Conflit - Discordance d'état/de version
* 422 Non traitable - Echec de vérification
* 429 Tros de requêtes - Débit limité

## 50x - Erreur serveur
* 500 Erreur interne - serveur planté
* 502 Mauvaise passerelle - échec en amont
* 503 Service indisponible 
* 504 Expiration du délai
