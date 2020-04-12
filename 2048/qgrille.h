#ifndef QGRILLE_H
#define QGRILLE_H

#include <QObject>
#include <QWidget>
#include "grille.h"
#include <string>
#include <iostream>
#include <QString>
#include <math.h>
using namespace std;

class QGrille : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString case0 READ case0)
    Q_PROPERTY(QString case1 READ case1)
    Q_PROPERTY(QString case2 READ case2)
    Q_PROPERTY(QString case3 READ case3)
    Q_PROPERTY(QString case4 READ case4)
    Q_PROPERTY(QString case5 READ case5)
    Q_PROPERTY(QString case6 READ case6)
    Q_PROPERTY(QString case7 READ case7)
    Q_PROPERTY(QString case8 READ case8)
    Q_PROPERTY(QString case9 READ case9)
    Q_PROPERTY(QString case10 READ case10)
    Q_PROPERTY(QString case11 READ case11)
    Q_PROPERTY(QString case12 READ case12)
    Q_PROPERTY(QString case13 READ case13)
    Q_PROPERTY(QString case14 READ case14)
    Q_PROPERTY(QString case15 READ case15)
    Q_PROPERTY(QString QScore READ Getscore)



public:
    QGrille(Grille GrilleG=Grille(), QObject *parent=nullptr);
    Q_INVOKABLE void coup(int coup);
    Q_INVOKABLE void newGame();
    Q_INVOKABLE void getlist();
    Q_INVOKABLE QString color(QString string);
    Q_INVOKABLE QString colortext(QString string);
    void afficher();
    Grille GrilleG;
    int length;
    int cases[16];
    QString colors[12]={"#cdc1b4","#eee4da","#f2b179","#f2b179","#f59563","#f67c60","#f65e3b","#edcf73","#edcc62","#edc850","#edc53f","#edc22d"};
    QString colorstext[12]={"#474543","#474543","#474543","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4","#f9f8f4"};
    QString case0() {
        if(cases[0]==0){
            return "";
        }
        return QString::number(cases[0]);
    }
    QString case1() {
        if(cases[1]==0){
            return "";
        }
        return QString::number(cases[1]);
    }
    QString case2() {
        if(cases[2]==0){
            return "";
        }
        return QString::number(cases[2]);
    }
    QString case3() {
        if(cases[3]==0){
            return "";
        }
        return QString::number(cases[3]);
    }
    QString case4() {
        if(cases[4]==0){
            return "";
        }
        return QString::number(cases[4]);
    }
    QString case5() {
        if(cases[5]==0){
            return "";
        }
        return QString::number(cases[5]);
    }
    QString case6() {
        if(cases[6]==0){
            return "";
        }
        return QString::number(cases[6]);
    }
    QString case7() {
        if(cases[7]==0){
            return "";
        }
        return QString::number(cases[7]);
    }
    QString case8() {
        if(cases[8]==0){
            return "";
        }
        return QString::number(cases[8]);
    }
    QString case9() {
        if(cases[9]==0){
            return "";
        }
        return QString::number(cases[9]);
    }
    QString case10() {
        if(cases[10]==0){
            return "";
        }
        return QString::number(cases[10]);
    }
    QString case11() {
        if(cases[11]==0){
            return "";
        }
        return QString::number(cases[11]);
    }
    QString case12() {
        if(cases[12]==0){
            return "";
        }
        return QString::number(cases[12]);
    }
    QString case13() {
        if(cases[13]==0){
            return "";
        }
        return QString::number(cases[13]);
    }
    QString case14() {
        if(cases[14]==0){
            return "";
        }
        return QString::number(cases[14]);
    }
    QString case15() {
        if(cases[15]==0){
            return "";
        }
        return QString::number(cases[15]);
    }
    QString Getscore() {
        return QString::number(GrilleG.getScore());
    }

    QString color0(){
        if (cases[0]==0){
            return colors[0];
        }
        return colors[int(log2(cases[0]))];
    }

    QString color1(){
        if (cases[1]==0){
            return colors[0];
        }
        return colors[int(log2(cases[1]))];
    }
    QString color2(){
        if (cases[2]==0){
            return colors[0];
        }
        return colors[int(log2(cases[2]))];
    }
    QString color3(){
        if (cases[3]==0){
            return colors[0];
        }
        return colors[int(log2(cases[3]))];
    }
    QString color14(){
        if (cases[14]==0){
            return colors[0];
        }
        return colors[int(log2(cases[14]))];
    }
    QString color4(){
        if (cases[4]==0){
            return colors[0];
        }
        return colors[int(log2(cases[4]))];
    }
    QString color5(){
        if (cases[5]==0){
            return colors[0];
        }
        return colors[int(log2(cases[5]))];
    }
    QString color6(){
        if (cases[6]==0){
            return colors[0];
        }
        return colors[int(log2(cases[6]))];
    }
    QString color7(){
        if (cases[7]==0){
            return colors[0];
        }
        return colors[int(log2(cases[7]))];
    }
    QString color8(){
        if (cases[8]==0){
            return colors[0];
        }
        return colors[int(log2(cases[8]))];
    }
    QString color9(){
        if (cases[9]==0){
            return colors[0];
        }
        return colors[int(log2(cases[9]))];
    }
    QString color10(){
        if (cases[10]==0){
            return colors[0];
        }
        return colors[int(log2(cases[10]))];
    }
    QString color11(){
        if (cases[11]==0){
            return colors[0];
        }
        return colors[int(log2(cases[11]))];
    }
    QString color12(){
        if (cases[12]==0){
            return colors[0];
        }
        return colors[int(log2(cases[12]))];
    }
    QString color13(){
        if (cases[13]==0){
            return colors[0];
        }
        return colors[int(log2(cases[13]))];
    }
    QString color15(){
        if (cases[15]==0){
            return colors[0];
        }
        return colors[int(log2(cases[15]))];
    }

private:
    QString score;

};

#endif // QGRILLE_H

