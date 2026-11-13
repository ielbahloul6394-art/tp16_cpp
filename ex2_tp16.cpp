
#include <iostream>
#include <memory>
#include <string>
using namespace std;


class Forme {
public:
    virtual void afficher() const = 0;
    virtual ~Forme() {}
};

// Classe Cercle
class Cercle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Cercle." << endl;
    }
};


class Carre : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Carre." << endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Triangle." << endl;
    }
};

class FabriqueForme {
public:
    static unique_ptr<Forme> creerForme(string type) {
        if (type == "cercle") {
            return make_unique<Cercle>();
        }
        else if (type == "carre") {
            return make_unique<Carre>();
        }
        else if (type == "triangle") {
            return make_unique<Triangle>();
        }
        else {
            return nullptr;
        }
    }
};

int main() {

    unique_ptr<Forme> f1 = FabriqueForme::creerForme("cercle");
    unique_ptr<Forme> f2 = FabriqueForme::creerForme("carre");
    unique_ptr<Forme> f3 = FabriqueForme::creerForme("triangle");

    if (f1) f1->afficher();
    if (f2) f2->afficher();
    if (f3) f3->afficher();

    return 0;
}
