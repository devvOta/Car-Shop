###README - Programme Car Shop by Yassir LAFRIZI, Younes DOUICI, Souleim GHOUDI MI5

##Ce programme est conçu pour gérer le stock de voitures dans un magasin. Il permet d'effectuer différentes opérations telles que l'ajout de voitures, le réapprovisionnement, la recherche d'informations sur le stock, l'achat de produits, la consultation de l'historique d'achat, et le mode de gestion pour l'administrateur.

#Fonctionnalités du programme :

1. Afficher les produits disponibles : La fonction "browseProducts" affiche les détails des voitures disponibles, tels que le nom, l'identifiant, la quantité et le prix.

2. Sauvegarder les données des voitures et des utilisateurs : Les fonctions "saveCar" et "saveUser" permettent de sauvegarder les informations des voitures et des utilisateurs respectivement dans des fichiers texte.

3. Charger les données des voitures et des utilisateurs : Les fonctions "loadCar" et "loadUser" permettent de charger les informations des voitures et des utilisateurs à partir des fichiers texte.

4. Calculer l'espace disponible : La fonction "place" calcule l'espace disponible dans le magasin en fonction des tailles des voitures et de leurs quantités.

5. Vérifier l'unicité de la référence : La fonction "isReferenceUnique" vérifie si une référence de voiture est unique parmi les voitures existantes.

6. Ajouter une voiture : La fonction "addCar" permet d'ajouter une nouvelle voiture au stock en demandant les détails tels que le nom, la référence, la quantité, le prix et la taille.

7. Réapprovisionner le stock : La fonction "resupply" permet d'ajouter du stock à une voiture existante en spécifiant sa référence et la quantité à ajouter.

8. Rechercher des informations sur le stock : La fonction "searchInformation" permet de rechercher des informations sur le stock d'une voiture en spécifiant son nom.

9. Supprimer un utilisateur : La fonction "deleteUser" permet de supprimer un utilisateur en spécifiant son identifiant.

10. Acheter des produits : La fonction "acheterProduits" permet à un utilisateur d'acheter des produits en spécifiant la référence du produit et la quantité désirée.

11. Consulter l'historique d'achat : La fonction "purchase_history" permet à un utilisateur de consulter les 3 derniers achats effectués.

12. Mode de gestion pour l'administrateur : La fonction "managementMode" permet à l'administrateur d'accéder à un mode de gestion spécial où il peut visualiser les produits avec un stock de 0, les voitures avec un stock faible, et l'espace disponible dans le magasin. L'administrateur peut également effectuer des opérations d'ajout de produits, de réapprovisionnement et de recherche d'informations sur le stock.

13. Le programme comporte des choix multiples, pour y répondre, il faudra sélectionner les boutons 1, 2, 3, et ainsi de suite s'il existe plus de propositions.

Instructions pour l'utilisation du programme :
- Assurez-vous d'avoir les fichiers "car.txt" et "user.txt" dans le même répertoire que le programme.
- Compilez et exécutez le programme.
- Suivez les instructions affichées à l'écran pour effectuer différentes opérations.

#Note : Ce programme utilise des fichiers texte pour sauvegarder les données des voitures et des utilisateurs. Assurez-vous que les fichiers ont les permissions appropriées pour lire et écrire les données.
