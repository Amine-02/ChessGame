#pragma warning(disable : 5054)
/*
L'avertissement C5054 concerne l'utilisation de l'opérateur ' & ' entre énumérations de types différents dans le fichier 'qsizepolicy.h' de la bibliothèque Qt.
Ce n'est pas notre code qui cause cet avertissement, il est déclenché en incluant certains composants Qt. Puisqu'il provient d'une bibliothèque tierce,
on peut le désactiver dans ce fichier spécifique avec "#pragma warning(disable : 5054)".
Attention, désactiver les avertissements n'est pas toujours recommandé car cela peut masquer des problèmes potentiels, mais dans ce cas précis, cela ne pose pas de souci.
*/
#include <QApplication>
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

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	Menu menu;
	menu.show();
	return app.exec();
}
