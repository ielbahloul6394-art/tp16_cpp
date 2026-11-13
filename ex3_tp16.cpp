
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() {}
};


class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    void supprimerObservateur(Observateur* obs) {
        observateurs.erase(
            remove(observateurs.begin(), observateurs.end(), obs),
            observateurs.end()
        );
    }

    void notifierObservateurs() {
        for (Observateur* obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void modifierDonnees(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;

        notifierObservateurs();
    }
};


class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Temperature : " << t << " C" << endl;
    }
};


class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Humidite : " << h << " %" << endl;
    }
};

// Observateur Pression
class AffichagePression : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Pression : " << p << " hPa" << endl;
    }
};


int main() {

    StationMeteo station;

    AffichageTemperature temp;
    AffichageHumidite humidite;
    AffichagePression pression;

    station.ajouterObservateur(&temp);
    station.ajouterObservateur(&humidite);
    station.ajouterObservateur(&pression);

    cout << "=== Premiere mise a jour ===" << endl;
    station.modifierDonnees(25, 60, 1013);

    cout << endl;

    cout << "=== Deuxieme mise a jour ===" << endl;
    station.modifierDonnees(30, 70, 1010);

    return 0;
}
