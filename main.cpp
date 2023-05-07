////////////////////////////////////////////////////////////////////////////////
/// \file   main.cpp
/// \author Amine Mehmel 2181148
/// Ce code comprend les fonctions de bases pouvant générer un jeu d'échec
/// intéractif via la bibliothèque Qt repectant les règles de base.
////////////////////////////////////////////////////////////////////////////////

/*
L'avertissement C5054 est lié à l'utilisation de l'opérateur "&" entre des énumérations de
types différents dans le fichier d'en-tête de la bibliothèque Qt "qsizepolicy.h". Dans notre
code, nous ne causons pas directement cet avertissement, mais il est déclenché lorsque nous
incluons certains composants Qt. Étant donné que l'avertissement provient d'une bibliothèque
et non de notre propre code, nous pouvons supprimer l'avertissement dans ces fichiers spécifiques
en utilisant "#pragma warning(disable : 5054)".
*/
#pragma warning(disable : 5054)
#include <QApplication>
#include "gtest/gtest.h"
#include "MainWindow.h"
#include "Menu.h"

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);
	Menu menu;
	menu.show();
	return app.exec();
}
