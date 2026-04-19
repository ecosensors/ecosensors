# Codes d'état d'API

## 20x - Success
* 200 OK - La requête est réussie
* 201 Crée - Nouvelle resource crée
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
* 409 Conflit - Discordance d'état/de version
* 422 Non traitable - Echec de vérification
* 429 Tros de requêtes - Débit limité

## 50x - Erreur serveur
* 500 Erreur interne - serveur planté
* 502 Mauvaise passerelle - échec en amont
* 503 Service indisponible 
* 504 Expiration du délai
