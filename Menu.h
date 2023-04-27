#pragma once
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <memory>
#include <QMainWindow>
#include <qcombobox.h>


class MainWindow;

class Menu : public QMainWindow {
	Q_OBJECT

public:
	Menu(QMainWindow* parent = nullptr);

	~Menu() = default;

private:
	std::unique_ptr<MainWindow> windowPtr;
	QPushButton* start;
	QPushButton* quit;
	QComboBox* game;
	QComboBox* color;
	QLabel* title;
	QWidget* widget;
};