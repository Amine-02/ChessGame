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

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	//cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);
	bibliotheque_cours::executerGoogleTest(argc, argv);
	Menu menu;
	menu.show();
	return app.exec();
}
