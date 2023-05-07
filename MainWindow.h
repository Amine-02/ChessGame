#pragma once
#pragma warning(disable : 5054)
#include <QMainWindow>
#include "ChessBoard.h"

class MainWindow : public QWidget {
	Q_OBJECT

public:
	MainWindow(int colorStyle, QWidget* parent = nullptr);

	ChessBoard* getBoard() {
		return chessBoard_;
	}

private:
	ChessBoard* chessBoard_;
	int color_;
};
