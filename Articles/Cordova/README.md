# Uploader Cordova sur GooglePlay et AppleStore

Cet article est uniquement *un aide mémoire* pour moi. Il ne vous sera probablement pas utile :).
Ces lignes de commande m'ont permis de téléverser mon application Cordova sur GooglePlay et AppleStore.

J'ai utilisé Cordova pour faire ma première application pour les Smartphones. Cordova n'est pas génial même si dans mon cas, il a répondu à mon besoin. Mais je ne vais pas m'investir dans un tutoriel. Ce article est juste des notes, dans le cas où j'en aurai besoin dans un avenir...

Référence: https://codesundar.com/publish-cordova-apps-to-playstore/

## Android

```
cd Documents/Cordova/myapp/
cordova build --release android
```

Cette commande va générer un fichier ‘app-release-unsigned.apk’ que je retrouve dans

> /Users/user/Documents/Cordova/smartbud/platforms/android/app/build/outputs/apk/release/app-release-unsigned.apk

Il est important de le renommer avec le nom de votre application. Mon application est smartbud, je la renomme donc

> smartbud.apk

Je déplace ce fichier dans un dossier où je classe mes versions, et où se trouve déjà mon fichier ‘smartbud.keystore’

```
cd Documents/Cordova-release/smartbud/PlayStoreKey/1-3-1/
jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore smartbud.keystore smartbud.apk smartbud
/Users/user/Library/Android/sdk/build-tools/30.0.0/zipalign -v 4 smartbud.apk smartbud-final.apk
```

Rendez-vous maintenant dans votre [console GooglePlay](https://play.google.com/console) et créer une nouvelle release avec le fichier ‘smartbud-final.apk’

## AppleStore

Ouvrir Xcode

* Sous ‘Target’ -> ‘Smart Bud’ et sous l’onglet ‘Genéral’, corriger la version de votre App dans les champs ‘Version’ et ‘Build’
* Sous ‘Target’ -> ‘OneSignalNotification’ et sous l’onglet ‘Genéral’, corriger aussi la version de votre App dans les champs ‘Version’ et ‘Build’
* Créer une archive depuis le menu ‘Product -> Archive’,
* Sélectionner votre dernière archive, et cliquer sur ‘Distribute App’
* Sélectionner ‘App Store Connect’, puis ‘Upload’
* Cocher ‘Upload your App’s symbols to receive symbolicated reports from Apple’ et cliquer ‘next’
* Sélectionner ‘Automatically manage signing’
* Saisissez les mots de passe (keychain) et cliquer sur ‘Upload’
