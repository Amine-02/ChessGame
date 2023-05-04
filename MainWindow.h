#pragma once
#pragma warning(disable : 5054)
#include <QMainWindow>
#include "ChessBoard.h"

//namespace window {
class MainWindow : public QWidget {
	Q_OBJECT

public:
	MainWindow(int colorStyle, QWidget* parent = nullptr);

	ChessBoard* getBoard() {
		return chessBoard;
	}

private:
	ChessBoard* chessBoard;
	int color_;
};
//}