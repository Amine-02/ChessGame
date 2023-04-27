#include "Menu.h"
#include "MainWindow.h"

Menu::Menu(QMainWindow* parent)
	: QMainWindow(parent), windowPtr(nullptr) 
{
	setWindowTitle("Chess");
	setFixedSize(1000, 1000);
	widget = new QWidget(this);
	
	QPixmap backgroundImage(":/image/board.png");
	QPalette palette;
	palette.setBrush(QPalette::Window, backgroundImage);
	widget->setPalette(palette);
	widget->setAutoFillBackground(true);
	widget->setFixedSize(1000, 1000);

	title = new QLabel(widget);
	title->setGeometry(300, 100, 400, 100);
	title->setText("チェス");
	title->setFont(QFont("TA Fuga-Fude", 30));
	title->setAlignment(Qt::AlignCenter);

	start = new QPushButton(widget);
	start->setGeometry(300, 550, 400, 50);
	start->setText("START");
	start->setFont(QFont("Arial", 16, QFont::Bold));
	start->setStyleSheet(
		"QPushButton {"
		"  background-color: #3D3D3D;"
		"  color: white;"
		"  border: 2px solid #2A2A2A;"
		"  border-radius: 10px;"
		"  padding: 5px;"
		"}"
		"QPushButton:hover {"
		"  background-color: #4D4D4D;"
		"}"
		"QPushButton:pressed {"
		"  background-color: #2A2A2A;"
		"}"
	);

	quit = new QPushButton(widget);
	quit->setGeometry(300, 650, 400, 50);
	quit->setText("QUIT");
	quit->setFont(QFont("Arial", 16, QFont::Bold));
	quit->setStyleSheet(
		"QPushButton {"
		"  background-color: #3D3D3D;"
		"  color: white;"
		"  border: 2px solid #2A2A2A;"
		"  border-radius: 10px;"
		"  padding: 5px;"
		"}"
		"QPushButton:hover {"
		"  background-color: #4D4D4D;"
		"}"
		"QPushButton:pressed {"
		"  background-color: #2A2A2A;"
		"}"
	);

	QLabel* configLabel = new QLabel("CONFIGURATIONS", widget);
	configLabel->setFont(QFont("Arial", 12, QFont::Bold));
	configLabel->setGeometry(300, 250, 400, 50); // Adjust position and size as needed
	configLabel->setAlignment(Qt::AlignCenter);

	game = new QComboBox(widget);
	game->setGeometry(300, 300, 400, 50);
	game->setFont(QFont("Arial", 12, QFont::Bold));
	game->addItems(QStringList{ "CLASSIC", "THE CRAZY BISHOPS", "ROOK TAKEOVER", "THE QUEENS GAME" });

	for (int i = 0; i < game->count(); ++i) {
		game->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
	}

	game->setStyleSheet(
		"QComboBox {"
		"   background-color: white;"
		"   color: black;"
		"   border: 1px solid gray;"
		"   border-radius: 3px;"
		"   padding: 5px;"
		"   min-width: 200px;"
		"}"
		"QComboBox::drop-down {"
		"   subcontrol-origin: padding;"
		"   subcontrol-position: top right;"
		"   width: 30px;"
		"   border-left-width: 1px;"
		"   border-left-color: gray;"
		"   border-left-style: solid;"
		"   border-top-right-radius: 3px;"
		"   border-bottom-right-radius: 3px;"
		"}"
		"QComboBox::down-arrow {"
		"   image: url(:/image/arrow.png);"
		"   width: 20px;"
		"   height: 20px;"
		"}"
		"QComboBox QAbstractItemView {"
		"   selection-background-color: lightgray;"
		"   selection-color: black;"
		"   border: 1px solid gray;"
		"   border-radius: 3px;"
		"}"
	);

	QLabel* colorLabel = new QLabel("STYLES", widget);
	colorLabel->setFont(QFont("Arial", 12, QFont::Bold));
	colorLabel->setGeometry(300, 350, 400, 50); // Adjust position and size as needed
	colorLabel->setAlignment(Qt::AlignCenter);

	color = new QComboBox(widget);
	color->setGeometry(300, 400, 400, 50);
	color->setFont(QFont("Arial", 12, QFont::Bold));
	color->addItems(QStringList{ "ClassicWood", "SilverMoon", "EmeraldGarden", "LavenderDreams"});
	color->setStyleSheet(
		"QComboBox {"
		"   background-color: white;"
		"   color: black;"
		"   border: 1px solid gray;"
		"   border-radius: 3px;"
		"   padding: 5px;"
		"   min-width: 200px;"
		"}"
		"QComboBox::drop-down {"
		"   subcontrol-origin: padding;"
		"   subcontrol-position: top right;"
		"   width: 30px;"
		"   border-left-width: 1px;"
		"   border-left-color: gray;"
		"   border-left-style: solid;"
		"   border-top-right-radius: 3px;"
		"   border-bottom-right-radius: 3px;"
		"}"
		"QComboBox::down-arrow {"
		"   image: url(:/image/arrow.png);"
		"   width: 20px;"
		"   height: 20px;"
		"}"
		"QComboBox QAbstractItemView {"
		"   selection-background-color: lightgray;"
		"   selection-color: black;"
		"   border: 1px solid gray;"
		"   border-radius: 3px;"
		"}"
	);

	connect(start, &QPushButton::clicked, [this]() {
		int configIndex = game->currentIndex(); 
	int colorStyleIndex = color->currentIndex(); 
	windowPtr = std::make_unique<MainWindow>(colorStyleIndex); 
	windowPtr->getBoard()->addPieces(configIndex);
	windowPtr->show();
		});

	connect(quit, &QPushButton::clicked, [this]() {
		if (windowPtr) {
			windowPtr->close();
		}
	close();
		});
};