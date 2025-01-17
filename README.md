# ✈️ RADAR
Un projet du module MUL d'Epitech.
Le but ? Créer un simulateur de trafic aérien, avec des collisions, et des tours de contrôle dont la zone annule les collisions entre avions.
Les avions sont fournis par un fichier de configuration, généré par un script python.
Ce projet a pour d'approfondir la maitrise de la CSFML.

## Comment l'utiliser ?
Sur **linux**, clonez le repo, et faites juste un `make`. Ensuite, `./my_radar path-to-file`.
Sur windows et mac, il n'est pas disponible pour l'instant.
Les scripts .rdr sont fournis dans le dossier *scripts*.

## Utiliser le Générateur de scripts
Vous pouvez aussi utiliser le générateur de scripts en python, fourni dans le dossier *scripts*.

```./scripts/generator.py -p 30 -t 10 -f```

(Génère un fichier .rdr contenant 30 avions, 10 tours, et le délai de décollage des avions se fera en millisecondes)

## Le jeu
Mon radar contient un battle pass pour avoir des skins, des achievements et de la sauvegarde.
utilisez `ESC` pour accéder au menu.
