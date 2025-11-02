
# 🧮 Gestion des Exceptions

## 📘 Description

Ce document regroupe plusieurs projets C++ illustrant l’usage des exceptions personnalisées, de la validation d’entrée, et de la robustesse des traitements :

- Division sécurisée avec détection d’erreur

- Gestion de stock avec exception métier

- Lecture de fichier avec contrôle d’accès

- Opérations bancaires avec validation de montant et solde

## 📂 Project Structure
````
projets/
├── DivisionSecurisee/
│   └── DivisionSecurisee.cpp
├── GestionStockProduits/
│   └── GestionStockProduits.cpp
├── LectureFichier_GestionErreurs/
│   └── LectureFichier_GestionErreurs.cpp
├── SimulationBancaire_PlusieursExceptions/
│   └── SimulationBancaire_PlusieursExceptions.cpp
└── README.md
````


## ⚙️ Features

### **1.** Division – Sécurisation d’une opération critique
Fonction diviser(double, double)
- Vérifie si le dénominateur est nul

- Lance une exception de type const char* si la division est impossible

- Retourne le résultat sinon

Fonction main()
- Appelle diviser() avec plusieurs cas

- Capture l’exception et affiche un message d’erreur

### **2.** ProduitStock – Exception personnalisée pour stock insuffisant
Classe StockInsuffisantException
- Hérite de std::exception

- Surcharge what() : retourne un message explicite

Classe Produit
- Attributs privés : nom, prix, quantite

- Constructeur Produit(string, double, int)

Méthode vendre(int) :

- Vérifie la disponibilité du stock

- Lance StockInsuffisantException si la quantité demandée dépasse le stock

- Affiche un message de vente réussie sinon

Fonction main()
- Création de deux produits

- Tentative de vente avec gestion d’exception

### **3.** FichierLecture – Détection de fichier introuvable
Classe FichierIntrouvable
- Hérite de std::exception

- Surcharge what() : retourne un message explicite

Fonction lireFichier(string)
- Tente d’ouvrir un fichier en lecture

- Lance FichierIntrouvable si le fichier est inaccessible

- Affiche le contenu ligne par ligne sinon

Fonction main()
- Appelle lireFichier() avec gestion d’exception

### **4.** CompteBancaire – Validation de montant et solde
Classe MontantInvalideException
- Hérite de std::exception

- Surcharge what() : retourne un message explicite

Classe SoldeInsuffisantException
- Hérite de std::exception

- Surcharge what() : retourne un message explicite

Classe Compte
- Attributs privés : nom, code, solde

- Constructeur Compte(string, string, double)

Méthode deposer(double) :

- Vérifie que le montant est positif

- Lance MontantInvalideException si invalide

- Met à jour le solde et affiche les informations

Méthode retirer(double) :

- Vérifie que le montant est positif

- Vérifie que le solde est suffisant

- Lance l’exception appropriée si nécessaire

- Met à jour le solde et affiche les informations

Fonction main()
- Création d’un compte

- Dépôt et retrait avec gestion des exceptions
## 🖥️ Example Execution


###   Division sécurisée :
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/913bb946-8362-4080-ab0a-bc8bc3eb2ae4" />
###  Gestion d’un stock de produits : 
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/5b9f7d22-0d3d-4718-9e00-22072a549917" />
###  Lecture d’un fichier avec gestion d’erreurs :
##### le fichier existant :
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/5795f466-9553-4925-8841-0eb1509b3f9a" />
##### le fichier introuvable :
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/562c775c-9031-4ab5-9525-63484d88f6cc" />
### Simulation bancaire avec plusieurs exceptions :
##### montant invalid :
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/6be6ab83-a57e-45bf-bd75-155ddfa96450" />
##### sold insuffisant :
- <img width="480" height="504" alt="image" src="https://github.com/user-attachments/assets/d92d24d2-e8a4-4826-8418-9879f2bc3c3f" />
## 💡 Concepts Practiced

- Exceptions personnalisées (std::exception)

- -Validation d’entrée et contrôle métier

- Séparation des responsabilités par classe

- Robustesse des programmes face aux erreurs
## 🧑‍💻 Author

- 👤 Agouram Hassan
- 🏫 Programmation orientée objet : C++
- 🎓 Instructor	Mr.LACHGAR
- 📅 02	novembre 2025
