#pragma once
#pragma warning(disable : 5054)
#include <QMainWindow>
#include <QtWidgets>
#include <QPushButton>
#include <QString>
#include <stdexcept>
#include <QLabel>
#include <array>
#include <vector>
#include <tuple>
#include <memory>

#include "ChessPiece.h"
#include "Menu.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

const int ROW_NUM = 8;
const int COL_NUM = 8;
const int CASE_SIZE = 20;


class Case : public QPushButton, public std::enable_shared_from_this<Case>
{
	Q_OBJECT

public:
	Case(Position position, bool isWhite, int colorStyle, QWidget* parent =
		nullptr)
		: QPushButton(parent), position_(position)
	{
		setFixedSize(CASE_SIZE, CASE_SIZE);
		if (colorStyle == 0) { // Brown/Beige color style
			if (isWhite) {
				setStyleSheet("background-color: Peru;");
			}
			else {
				setStyleSheet("background-color: Wheat;");
			}
		}
		else if (colorStyle == 1) { // Gray/Blue color style
			if (isWhite) {
				setStyleSheet("background-color: LightGray;");
			}
			else {
				setStyleSheet("background-color: SlateGray;");
			}
		}
		else if (colorStyle == 2) { // Green/Cream color style
			if (isWhite) {
				setStyleSheet("background-color: LightGreen;");
			}
			else {
				setStyleSheet("background-color: DarkGreen;");
			}
		}
		else if (colorStyle == 3) { // Purple/Pink color style
			if (isWhite) {
				setStyleSheet("background-color: Thistle;");
			}
			else {
				setStyleSheet("background-color: MediumPurple;");
			}
		}
		layout_ = new QHBoxLayout();
		setLayout(layout_);
	}
	~Case() = default;

	QLayout* getLayout() const {
		return layout_;
	}

	std::shared_ptr<ChessPiece> getPiece() const {
		return piece_;
	}

	void setPiece(std::shared_ptr<ChessPiece> piece) {
		piece_ = piece;
	}

	void removePiece() {
		piece_ = nullptr;
	}

	Position getPosition() const {
		return position_;
	}

	void setPosition(Position position) {
		position_ = position;
	}

	void mousePressEvent(QMouseEvent* event) override;
	void updateLayout(std::shared_ptr<ChessPiece> piece);
	bool hasLayout();


signals:
	void caseClicked(int row, int col);


private:
	Position position_;
	bool occupied_ = false;
	std::shared_ptr<ChessPiece> piece_;
	QLayout* layout_;
};

class ChessBoard : public QWidget
{
	Q_OBJECT

public:
	ChessBoard(int colorStyle, QWidget* parent = nullptr)
		: QWidget(parent), colorStyle_(colorStyle)
	{

		QGridLayout* gridLayout = new QGridLayout(this);  // Set layout to 'this'
		gridLayout->setSpacing(0);

		setAutoFillBackground(true);
		QPalette palette = this->palette();
		palette.setColor(QPalette::Window, Qt::black);
		setPalette(palette);

		for (int row = 0; row < ROW_NUM; ++row)
		{
			for (int col = 0; col < COL_NUM; ++col)
			{
				total_ = row + col;
				bool isWhite = (total_ % 2 == 0);
				std::shared_ptr<Case> chessCase = std::make_shared<Case>(Position{ row, col }, isWhite, colorStyle);
				gridLayout->addWidget(chessCase.get(), row, col);
				board[row][col] = chessCase;

				// Add click handling for each case
				connect(chessCase.get(), &Case::caseClicked, this, &ChessBoard::onCaseClicked);
				connect(chessCase.get(), &Case::caseClicked, this, &ChessBoard::highlightValidMoves);

			}
		}

		setLayout(gridLayout);  // Set the layout for the ChessBoard widget

		// Add pieces to the board
		addPieces(index_);
	}

	std::shared_ptr<Case>& at(int row, int col);
	const std::shared_ptr<Case>& at(int row, int col) const;

	bool hasPiecesInWay(const Position& from, const Position& to) const;
	bool movePiece(const Position& from, const Position& to);

	std::array<std::array<std::shared_ptr<Case>, 8>, 8> getBoard() const {
		return board;
	}

	void addPieces(int config);
	void generateOriginalBoard();
	void rookConfiguration();
	void queenConfiguration();
	void bishopConfiguration();
	bool isOpponentPiece(Position to, Team team);
	void switchCurrentPlayer();
	void removeHighlightFromAllCases();
	Position findKing(Team team);
	bool isPositionAttacked(Position position, Team attackerTeam);
	bool isMoveResultingInCheck(const Position& from, const Position& to, const Position& kingPosition);
	bool isValidPosition(const Position& position);


public slots:
	void onCaseClicked(int row, int col);
	void highlightValidMoves(int row, int col);


protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	std::array<std::array<std::shared_ptr<Case>, 8>, 8> board;
	int total_ = 0;
	std::shared_ptr<Case> selectedCase_ = nullptr;
	Team currentPlayer_;
	int index_ = 0;
	int colorStyle_;

};