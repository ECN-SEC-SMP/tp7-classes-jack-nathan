#include <iostream>
#include <assert.h>
#include <vector>

#include "src/Point.hpp"
#include "src/Carre.hpp"
#include "src/Rectangle.hpp"
#include "src/Cercle.hpp"
#include "src/ListeFormes.hpp"

using namespace std;

int surfaceTotal(vector<Forme *> list)
{
    int surfaceTotal = 0;
    for (Forme *forme : list)
    {
        surfaceTotal += forme->surface();
    }

    return surfaceTotal;
}

// Test des points
void test_pointConstructeur(void);
void test_pointTranslater(void);
void test_pointOperateurPlusEgale(void);
void test_pointOperateurCout(void);

// Test des rectangles
void test_rectangleConstructeur(void);
void test_rectangleSetLongueur(void);
void test_rectangleSetLargeur(void);
void test_rectanglePerimetre(void);
void test_rectangleSurface(void);
void test_rectangleOperateurCout(void);

// Test des carres
void test_carreConstructeur(void);
void test_carreSetTaille(void);
void test_carreOperateurCout(void);

// Test des cercles
void test_cercleConstructeur(void);
void test_cercleSetRayon(void);
void test_cerclePerimetre(void);
void test_cercleSurface(void);
void test_cercleOperateurCout(void);

// Test ListeFormes
void test_listeFormesConstructeur(void);
void test_listeFormesSurfaceTotal(void);
void test_listeFormesBoiteEnglobante(void);

int main()
{
    cout << "-- Tests de la classe Point --" << endl;
    test_pointConstructeur();
    test_pointTranslater();
    test_pointOperateurPlusEgale();
    test_pointOperateurCout();

    cout << "-- Tests de la classe Rectangle --" << endl;
    test_rectangleConstructeur();
    test_rectangleSetLongueur();
    test_rectangleSetLargeur();
    test_rectanglePerimetre();
    test_rectangleSurface();
    test_rectangleOperateurCout();

    cout << "-- Tests de la classe Carre --" << endl;
    test_carreConstructeur();
    test_carreSetTaille();
    test_carreOperateurCout();

    cout << "-- Tests de la classe Cercle --" << endl;
    test_carreConstructeur();
    test_carreSetTaille();
    test_carreOperateurCout();

    cout << "-- Tests de la classe cercle --" << endl;
    test_cercleConstructeur();
    test_cercleSetRayon();
    test_cerclePerimetre();
    test_cercleSurface();
    test_cercleOperateurCout();

    cout << "-- Tests liste de formes --" << endl;
    test_listeFormesConstructeur();
    test_listeFormesSurfaceTotal();
    test_listeFormesBoiteEnglobante();
    return 0;
}

void test_listeFormesConstructeur(void)
{
    Cercle *cerc = new Cercle(2, 5, 6);
    Rectangle *rect_1 = new Rectangle(3, 3);
    Rectangle *rect_2 = new Rectangle(7, 5);

    ListeFormes *liste = new ListeFormes();

    cout << "==> Test ListeFormes" << endl;

    cout << "Taille liste vide : " << liste->length() << endl;

    cout << "Ajout cercle" << endl;
    liste->add(cerc);
    assert(liste->length() == 1);
    cout << "Taille avec 1 cercle : " << liste->length() << endl;
    cout << "Surface Cercle : " << liste->at(0)->surface() << endl;

    cout << "Ajout 2 rectangles" << endl;
    liste->add(rect_1);
    liste->add(rect_2);
    assert(liste->length() == 3);
    cout << "Nouvelle taille de la liste : " << liste->length() << endl;
    cout << "Perimetre du rectangle(3, 3) : " << liste->at(1)->perimetre() << endl;

    cout << "Fin test ListeFormes" << endl;
    delete cerc;
    delete rect_1;
    delete rect_2;
    delete liste;
}

void test_listeFormesSurfaceTotal()
{
    ListeFormes liste;
    Rectangle *rect_2 = new Rectangle(3, 3);
    Rectangle *rect_3 = new Rectangle(7, 5);

    cout << "==> Test surface totale" << endl;
    cout << "Ajout rectangles (3, 3) et (7, 5)" << endl;

    liste.add(rect_2);
    liste.add(rect_3);

    assert(liste.surfaceTotale() == 44);
    cout << "Surface totale attendu/obtenu : 44/" << liste.surfaceTotale() << endl;

    delete rect_2;
    delete rect_3;
}

void test_listeFormesBoiteEnglobante(void)
{
    ListeFormes liste;
    Cercle *cerc = new Cercle(2, 5, 6);
    Rectangle *rect_1 = new Rectangle(3, 3);
    Rectangle *rect_2 = new Rectangle(7, 5);

    Rectangle box;

    float xMin, xMax, yMin, yMax;

    liste.add(cerc);
    liste.add(rect_1);
    liste.add(rect_2);

    cout << "==> Test boite englobante" << endl;

    liste.at(0)->limites(&xMin, &xMax, &yMin, &yMax);
    cout << *cerc << endl;
    cout << "Limites (xmin, xmax, ymin, ymax) : " << xMin << ", " << xMax << ", " << yMin << ", " << yMax << endl;
    liste.at(1)->limites(&xMin, &xMax, &yMin, &yMax);
    cout << *rect_1 << endl;
    cout << "Limites (xmin, xmax, ymin, ymax) : " << xMin << ", " << xMax << ", " << yMin << ", " << yMax << endl;
    liste.at(2)->limites(&xMin, &xMax, &yMin, &yMax);
    cout << *rect_2 << endl;
    cout << "Limites (xmin, xmax, ymin, ymax) : " << xMin << ", " << xMax << ", " << yMin << ", " << yMax << endl;

    liste.getBox(&box);
    cout << "Boite englobante point: " << endl;
    cout << *box.getPoint() << endl;
    cout << "Boite englobante: " << endl;
    cout << box << endl;
    box.limites(&xMin, &xMax, &yMin, &yMax);
    cout << "Limites (xmin, xmax, ymin, ymax) : " << xMin << ", " << xMax << ", " << yMin << ", " << yMax << endl;
    delete cerc;
    delete rect_1;
    delete rect_2;
}

void test_pointConstructeur()
{
    Point pts_1 = Point();
    Point pts_2 = Point(1, 2);
    Point pts_3 = pts_2;

    // Test du constructeur par défaut
    assert(pts_1.getX() == 0);
    assert(pts_1.getY() == 0);

    // Test du constructeur surcharger (float x, float y)
    assert(pts_2.getX() == 1);
    assert(pts_2.getY() == 2);

    // Test du constructeur par recopie
    assert(pts_3.getX() == 1);
    assert(pts_3.getY() == 2);

    cout << "test_pointConstructeur()\t : \tOK" << endl;
}
void test_pointTranslater()
{
    Point pts_1 = Point();       // Point initialisé en (0, 0)
    Point pts_2 = Point(5, 5);   // Point initialisé en (5, 5)
    Point pts_3 = Point(2, 3);   // Point initialisé en (2, 3)
    Point pts_4 = Point(5, 6);   // Point initialisé en (5, 6)
    Point pts_5 = Point(1, 3);   // Point initialisé en (1, 3)
    Point pts_6 = Point(-3, -1); // Point initialisé en (-3, -3)

    pts_1.translater(3, 4);   // Translate en (3,4)
    pts_2.translater(-6, -6); // Translate en (-1, -1)
    pts_3.translater(-2, -3); // Translate en (0, 0)
    pts_4.translater(pts_5);  // Translate en (6, 9)
    pts_5.translater(pts_6);  // Translate en (-2, 2)

    // Test point_1
    assert(pts_1.getX() == 3);
    assert(pts_1.getY() == 4);

    // Test point_2
    assert(pts_2.getX() == -1);
    assert(pts_2.getY() == -1);

    // Test point_3
    assert(pts_3.getX() == 0);
    assert(pts_3.getY() == 0);

    // Test point_4
    assert(pts_4.getX() == 6);
    assert(pts_4.getY() == 9);

    // Test point_5
    assert(pts_5.getX() == -2);
    assert(pts_5.getY() == 2);

    cout << "test_pointTranslater()\t\t : \tOK" << endl;
}

void test_pointOperateurPlusEgale()
{
    Point pts_1 = Point();       // Point initialisé en (0, 0)
    Point pts_2 = Point(5, 5);   // Point initialisé en (5, 5)
    Point pts_3 = Point(2, 3);   // Point initialisé en (2, 3)
    Point pts_4 = Point(1, 3);   // Point initialisé en (1, 3)
    Point pts_5 = Point(-3, -1); // Point initialisé en (-3, -3)

    pts_1 += pts_2; // (0, 0) + (5, 5) = (5, 5)
    pts_2 += pts_3; // (5, 5) + (2, 3) = (7, 8)
    pts_4 += pts_5; // (1, 3) + (-3, -1) = (-2, 2)

    assert(pts_1.getX() == 5);
    assert(pts_1.getY() == 5);

    assert(pts_2.getX() == 7);
    assert(pts_2.getY() == 8);

    assert(pts_4.getX() == -2);
    assert(pts_4.getY() == 2);

    cout << "test_pointOperateurPlusEgale()\t : \tOK" << endl;
}

void test_pointOperateurCout()
{
    Point pts_1 = Point();       // Point initialisé en (0, 0)
    Point pts_2 = Point(5, 5);   // Point initialisé en (5, 5)
    Point pts_3 = Point(-3, -1); // Point initialisé en (-3, -3)

    cout << "test_pointOperateurCout - Affichage des points" << endl;
    cout << pts_1 << endl;
    cout << pts_2 << endl;
    cout << pts_3 << endl;
}

void test_rectangleConstructeur()
{
    Rectangle rect_1 = Rectangle();           // Constructeur par défaut
    Rectangle rect_2 = Rectangle(3, 4);       // Définition de longueur, largeur
    Rectangle rect_3 = Rectangle(3, 4, 2, 3); // Définition de longueur, largeur, X, Y
    Rectangle rect_7 = rect_3;                // Par recopie

    try
    {
        Rectangle rect_4 = Rectangle(0, 0, 2, 3); // Largeur et longueur à 0
        Rectangle rect_5 = Rectangle(0, 3, 2, 3); // Longueur à 0
        Rectangle rect_6 = Rectangle(3, 0, 2, 3); // Largeur à 0
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    assert(rect_1.getLargeur() == 0);
    assert(rect_1.getLongeur() == 0);
    assert(rect_1.getPoint()->getX() == 0);
    assert(rect_1.getPoint()->getY() == 0);

    assert(rect_2.getLongeur() == 3);
    assert(rect_2.getLargeur() == 4);
    assert(rect_2.getPoint()->getX() == 0);
    assert(rect_2.getPoint()->getY() == 0);

    assert(rect_3.getLongeur() == 3);
    assert(rect_3.getLargeur() == 4);
    assert(rect_3.getPoint()->getX() == 2);
    assert(rect_3.getPoint()->getY() == 3);

    assert(rect_7.getLongeur() == 3);
    assert(rect_7.getLargeur() == 4);
    assert(rect_7.getPoint()->getX() == 2);
    assert(rect_7.getPoint()->getY() == 3);
    cout << "test_rectangleConstructeur():\t:\tOK" << endl;
}

void test_rectangleSetLongueur()
{
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle();
    Rectangle rect_3 = Rectangle(3, 3);

    rect_1.setLongeur(10);

    try
    {
        rect_2.setLongeur(0);
        rect_3.setLongeur(-1);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(rect_1.getLongeur() == 10); // Longueur 0 vers 10 => 10
    assert(rect_2.getLongeur() == 0);  // Longueur 0 vers 0 => 0
    assert(rect_3.getLongeur() == 3);  // Longueur 3 vers -1 => 3

    cout << "test_rectangleSetLongueur():\t:\tOK" << endl;
}

void test_rectangleSetLargeur()
{
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle();
    Rectangle rect_3 = Rectangle(3, 3);

    rect_1.setLargeur(10);

    try
    {
        rect_2.setLargeur(0);
        rect_3.setLargeur(-1);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(rect_1.getLargeur() == 10); // Largeur 0 vers 10 => 10
    assert(rect_2.getLargeur() == 0);  // Largeur 0 vers 0 => 0
    assert(rect_3.getLargeur() == 3);  // Largeur 3 vers -1 => 3

    cout << "test_rectangleSetLongueur():\t:\tOK" << endl;
}

void test_rectanglePerimetre()
{
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle(3, 3);
    Rectangle rect_3 = Rectangle(7, 5);

    try
    {
        assert(rect_1.perimetre() == 0); // longueur et largeur à 0 => Exception
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(rect_2.perimetre() == 12); // Longueur 3 et largeur 3 => 12
    assert(rect_3.perimetre() == 24); // Longueur 7 et largeur 5 => 24

    cout << "test_rectanglePerimetre():\t:\tOK" << endl;
}

void test_rectangleSurface()
{
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle(3, 3);
    Rectangle rect_3 = Rectangle(7, 5);

    try
    {
        assert(rect_1.surface() == 0); // longueur et largeur à 0 => Exception
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(rect_2.surface() == 9);  // Longueur 3 et largeur 3 => 9
    assert(rect_3.surface() == 35); // Longueur 7 et largeur 5 => 24

    cout << "test_rectanglePerimetre():\t:\tOK" << endl;
}

void test_rectangleOperateurCout()
{
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle(3, 3);
    Rectangle rect_3 = Rectangle(7, 5, 4, 5);
    cout << "Surcharge opérateur <<" << endl;
    cout << rect_1 << endl;
    cout << rect_2 << endl;
    cout << rect_3 << endl;
}

void test_carreConstructeur()
{
    Carre carre_1 = Carre();        // Constructeur par défaut
    Carre carre_2 = Carre(3);       // Définition de la taille
    Carre carre_3 = Carre(7, 4, 5); // Définition de la taille et positionX et positionY
    Carre carre_4 = carre_3;        // Par recopie

    assert(carre_1.getLargeur() == 0);
    assert(carre_1.getLongeur() == 0);
    assert(carre_1.getPoint()->getX() == 0);
    assert(carre_1.getPoint()->getY() == 0);

    assert(carre_2.getLargeur() == 3);
    assert(carre_2.getPoint()->getX() == 0);
    assert(carre_2.getPoint()->getY() == 0);

    assert(carre_3.getLargeur() == 7);
    assert(carre_3.getPoint()->getX() == 4);
    assert(carre_3.getPoint()->getY() == 5);

    assert(carre_4.getLargeur() == 7);
    assert(carre_4.getPoint()->getX() == 4);
    assert(carre_4.getPoint()->getY() == 5);
    cout << "test_carreConstructeur():\t:\tOK" << endl;
}

void test_carreSetTaille()
{
    Carre carre_1 = Carre();
    Carre carre_2 = Carre(3);
    Carre carre_3 = Carre(7, 4, 5);

    carre_1.setTaille(10); // Cas normal
    carre_3.setTaille(1);  // Cas normal

    try
    {
        carre_2.setTaille(0);  // Taille impossible
        carre_2.setTaille(-1); // Taille impossible
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(carre_1.getLargeur() == 10);
    assert(carre_1.getLargeur() == 10);

    assert(carre_2.getLargeur() == 3);
    assert(carre_2.getLargeur() == 3);

    assert(carre_3.getLargeur() == 1);
    assert(carre_3.getLargeur() == 1);
    cout << "test_carreSetTaille():\t\t:\tOK" << endl;
}

void test_carreOperateurCout()
{
    Carre carre_1 = Carre();
    Carre carre_2 = Carre(3);
    Carre carre_3 = Carre(7, 5, 4);

    cout << "Surcharge opérateur <<" << endl;
    cout << carre_1 << endl;
    cout << carre_2 << endl;
    cout << carre_3 << endl;
}

void test_cercleConstructeur()
{
    Cercle cercle_1 = Cercle();        // Initialisation cercle par défaut
    Cercle cercle_3 = Cercle(1);       // Initialisation cercle de rayon 1
    Cercle cercle_4 = Cercle(2, 1, 1); // Initialisation cercle de rayon 2 au point (1, 1)
    Cercle cercle_5 = cercle_4;        // Copie de cercle 4
    try
    {
        Cercle cercle_2 = Cercle(0);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    try
    {
        Cercle cercle_2 = Cercle(-1);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    // Initialisation cercle par défaut
    assert(cercle_1.getRayon() == 0);
    assert(cercle_1.getPoint()->getX() == 0);
    assert(cercle_1.getPoint()->getY() == 0);

    // Initialisation cercle de rayon 1
    assert(cercle_3.getRayon() == 1);
    assert(cercle_3.getPoint()->getX() == 0);
    assert(cercle_3.getPoint()->getY() == 0);

    // Initialisation cercle de rayon 2 au point (1, 1)
    assert(cercle_4.getRayon() == 2);
    assert(cercle_4.getPoint()->getX() == 1);
    assert(cercle_4.getPoint()->getY() == 1);

    // Copie de cercle_4
    assert(cercle_5.getRayon() == 2);
    assert(cercle_5.getPoint()->getX() == 1);
    assert(cercle_5.getPoint()->getY() == 1);

    cout << "test_cercleConstructeur():\t\t:\tOK" << endl;
}
void test_cercleSetRayon()
{
    Cercle cercle_1 = Cercle();  // Initialisation cercle par défaut
    Cercle cercle_2 = Cercle(1); // Initialisation cercle de rayon 1

    assert(cercle_1.getRayon() == 0);

    cercle_1.setRayon(10);

    assert(cercle_1.getRayon() == 10);

    try
    {
        cercle_2.setRayon(0);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    try
    {
        cercle_2.setRayon(-1);
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "test_cercleSetRayon():\t\t:\tOK" << endl;
}

void test_cerclePerimetre()
{
    Cercle cercle_1 = Cercle();        // Initialisation cercle par défaut
    Cercle cercle_2 = Cercle(1);       // Initialisation cercle de rayon 1
    Cercle cercle_3 = Cercle(2, 1, 1); // Initialisation cercle de rayon 2 au point (1, 1)

    try
    {
        cercle_1.perimetre();
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(cercle_2.perimetre() == (float)6.28);
    assert(cercle_3.perimetre() == (float)12.57);
    cout << "test_cerclePerimetre():\t\t:\tOK" << endl;
}

void test_cercleSurface()
{
    Cercle cercle_1 = Cercle();        // Initialisation cercle par défaut
    Cercle cercle_2 = Cercle(1);       // Initialisation cercle de rayon 1
    Cercle cercle_3 = Cercle(4, 1, 1); // Initialisation cercle de rayon 2 au point (1, 1)

    try
    {
        cercle_1.perimetre();
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    assert(cercle_2.surface() == (float)3.14);
    assert(cercle_3.surface() == (float)50.27);
    cout << "test_cercleSurface():\t\t:\tOK" << endl;
}

void test_cercleOperateurCout()
{
    Cercle cercle_1 = Cercle(1);       // Initialisation cercle de rayon 1
    Cercle cercle_2 = Cercle(4, 1, 1); // Initialisation cercle de rayon 2 au point (1, 1)

    cout << "Surcharge opérateur <<" << endl;
    cout << cercle_1 << endl;
    cout << cercle_2 << endl;
}
