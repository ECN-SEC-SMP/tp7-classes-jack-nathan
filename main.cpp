#include <iostream>
#include "src/Point.hpp"
#include <assert.h>

using namespace std;

// Test des points
void test_pointConstructeur(void);
void test_pointTranslater(void);
void test_pointOperateurPlusEgale(void);
void test_pointOperateurCout(void);

int main()
{
    cout << "-- Teste de la classe Point --" << endl;
    test_pointConstructeur();
    test_pointTranslater();
    test_pointOperateurPlusEgale();
    test_pointOperateurCout();
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