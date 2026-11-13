
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    // Constructeur privé
    Configuration() {
        cheminFichier = "C:/Users/HP/config.txt";
        utilisateur = "admin";
        motDePasse = "12345";
    }

    // Supprimer le constructeur de copie
    Configuration(const Configuration&) = delete;

public:
    // Méthode statique
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    // Afficher les paramètres
    void afficherParametres() const {
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {
    Configuration& config = Configuration::getInstance();

    config.afficherParametres();

    return 0;
}
