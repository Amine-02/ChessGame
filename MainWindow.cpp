#include "MainWindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(int colorStyle, QWidget* parent) : QWidget(parent) {
	setWindowTitle("Chess Game");
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setAlignment(Qt::AlignCenter);

	chessBoard_ = new ChessBoard(colorStyle, this);
	layout->addWidget(chessBoard_);

	setLayout(layout);
}