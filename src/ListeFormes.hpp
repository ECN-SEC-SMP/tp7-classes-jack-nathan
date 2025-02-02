#ifndef LISTE_FORMES_H_
#define LISTE_FORMES_H_

#include <vector>

#include "Forme.hpp"

class ListeFormes
{
private:
    
    vector<Forme*> liste;

public:
    ListeFormes(void);
    ~ListeFormes();

    unsigned int length(void);
    void add(Forme* forme);
    Forme* at(unsigned int index);

};


#endif // LISTE_FORMES_H_
