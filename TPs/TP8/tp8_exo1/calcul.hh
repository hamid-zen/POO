#pragma once

#include <QtWidgets>
#include <cmath>
#include <iostream>
#include <string>

class calcul : public QWidget
{
    Q_OBJECT
public:
    calcul();

public slots:
    void oncliccalculer();

private:

    QLineEdit* _operande1;
    QLineEdit* _operande2;
    QComboBox* _operateur;
    QLabel* _resultat;
    QPushButton* _calculer;
    QPushButton* _quitter;

};
