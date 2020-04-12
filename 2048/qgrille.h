#ifndef QGRILLE_H
#define QGRILLE_H

#include <QObject>
#include <QWidget>
#include "grille.h"

class QGrille : public QObject
{
    Q_OBJECT
public:
    QGrille(Grille GrilleG=Grille(), QObject *parent=nullptr);
    Q_INVOKABLE void Coup(int coup);
    Q_INVOKABLE void NewGame();
    Q_INVOKABLE void getlist();
    void afficher();
    Grille GrilleG;
    int length;
    int cases[16];

private:


};

#endif // QGRILLE_H
