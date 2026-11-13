
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;


class StrategieTri {
public:
    virtual void trier(vector<string>& elements) = 0;
    virtual ~StrategieTri() {}
};


class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end());
    }
};

// Tri decroissant
class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end(), greater<string>());
    }
};


class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end(),
            [](const string& a, const string& b) {
                return a.length() < b.length();
            });
    }
};


class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    GestionnaireTri(StrategieTri* s) {
        strategie = s;
    }

    void changerStrategie(StrategieTri* s) {
        strategie = s;
    }

    void executerTri(vector<string>& elements) {
        strategie->trier(elements);
    }
};


int main() {

    vector<string> mots = {"Banane", "Kiwi", "Orange", "Fraise", "Pomme"};

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur longueur;

    GestionnaireTri gestionnaire(&croissant);

    cout << "Tri croissant :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";
    
    cout << endl << endl;

    gestionnaire.changerStrategie(&decroissant);

    cout << "Tri decroissant :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";

    cout << endl << endl;

    gestionnaire.changerStrategie(&longueur);

    cout << "Tri par longueur :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";

    cout << endl;

    return 0;
}
