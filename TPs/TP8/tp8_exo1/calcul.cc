#include "calcul.hh"


calcul::calcul()
    : QWidget(),
      _operande1(new QLineEdit("", this)),
      _operande2(new QLineEdit("", this)),
      _operateur(new QComboBox(this)),
      _resultat(new QLabel("", this)),
      _calculer(new QPushButton("Calculer", this)),
      _quitter(new QPushButton("Quitter", this)) {

    resize(450, 50);

    _operateur->addItem("+");
    _operateur->addItem("-");
    _operateur->addItem("*");
    _operateur->addItem("/");

    _operande1->setGeometry(10, 10, 70, 30);
    _operateur->setGeometry(90, 10, 50, 30);
    _operande2->setGeometry(150, 10, 70, 30);
    _calculer->setGeometry(230, 10, 50, 30);
    _resultat->setGeometry(290, 10, 100, 30);
    _quitter->setGeometry(370, 10, 70, 30);

    setWindowTitle("Caclulatrice");

    // On connecte le boutton quitter
    connect(_quitter, &QPushButton::clicked, this, &calcul::close);

    // On connecte le boutton calculer
    connect(_calculer, &QPushButton::clicked, this, &calcul::oncliccalculer);
}

void calcul::oncliccalculer()
{
    // On recupere les operandes
    std::string text_operande1 = _operande1->text().toStdString();
    std::string text_operande2 = _operande2->text().toStdString();

    float operande1 = ((text_operande1 == "") ? 0.0 : std::stof(text_operande1));
    float operande2 = ((text_operande2 == "") ? 0.0 : std::stof(text_operande2));

    // On recupere l'operation
    auto operation = _operateur->currentText().toStdString()[0];

    auto resultat(0.0);

    // On fait le calcul
    switch (operation) {
        case '+' :
            resultat = operande1+operande2;
            break;

        case '-' :
            resultat = operande1-operande2;
            break;

        case '*' :
            resultat = operande1*operande2;
            break;

        case '/' :
            if (operande2 != 0.0)
                resultat = operande1/operande2;
            break;

        default:
            break;
        }

        auto text_resultat = QString::fromStdString(
            std::to_string(std::round(resultat * 1000.0) / 1000.0));
        _resultat->setText(text_resultat);
}
