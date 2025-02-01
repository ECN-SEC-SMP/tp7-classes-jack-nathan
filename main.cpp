#include <iostream>
#include <assert.h>

#include "src/Point.hpp"
#include "src/Carre.hpp"
#include "src/Rectangle.hpp"
#include "src/Cercle.hpp"

using namespace std;

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

int main()
{
    // cout << "-- Tests de la classe Point --" << endl;
    // test_pointConstructeur();
    // test_pointTranslater();
    // test_pointOperateurPlusEgale();
    // test_pointOperateurCout();

    // cout << "-- Tests de la classe Rectangle --" << endl;
    // test_rectangleConstructeur();
    // test_rectangleSetLongueur();
    // test_rectangleSetLargeur();
    // test_rectanglePerimetre();
    // test_rectangleSurface();
    // test_rectangleOperateurCout();

    cout << "-- Tests de la classe Carre --" << endl;
    test_carreConstructeur();
    test_carreSetTaille();
    test_carreOperateurCout();
    return 0;
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
    Rectangle rect_1 = Rectangle();
    Rectangle rect_2 = Rectangle(3, 4);
    Rectangle rect_3 = Rectangle(3, 4, 2, 3);

    try
    {
        Rectangle rect_4 = Rectangle(0, 0, 2, 3);
        Rectangle rect_5 = Rectangle(0, 3, 2, 3);
        Rectangle rect_6 = Rectangle(3, 0, 2, 3);
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
    Carre carre_1 = Carre();
    Carre carre_2 = Carre(3);
    Carre carre_3 = Carre(7, 4, 5);

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
    cout << "test_carreConstructeur():\t:\tOK" << endl;
}

void test_carreSetTaille()
{
    Carre carre_1 = Carre();
    Carre carre_2 = Carre(3);
    Carre carre_3 = Carre(7, 4, 5);

    carre_1.setTaille(10);
    carre_3.setTaille(1);

    try
    {
        carre_2.setTaille(0);
        carre_2.setTaille(-1);
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
