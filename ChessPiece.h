#pragma once
#pragma warning(disable : 5054)
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QtGui>
#include <QMessageBox>
#include <utility>
#include <string>
#include <vector>
#include <stdexcept>

enum Team { White, Black };
using Position = QPair<int, int>;

const wchar_t WHITE_KING = 0x2654;
const wchar_t WHITE_QUEEN = 0x2655;
const wchar_t WHITE_ROOK = 0x2656;
const wchar_t WHITE_BISHOP = 0x2657;
const wchar_t WHITE_KNIGHT = 0x2658;
const wchar_t WHITE_PAWN = 0x2659;
const wchar_t BLACK_KING = 0x265A;
const wchar_t BLACK_QUEEN = 0x265B;
const wchar_t BLACK_ROOK = 0x265C;
const wchar_t BLACK_BISHOP = 0x265D;
const wchar_t BLACK_KNIGHT = 0x265E;
const wchar_t BLACK_PAWN = 0x265F;


class ChessBoard;

class ChessPiece : public QWidget
{
	Q_OBJECT

public:
	explicit ChessPiece(Team team, std::string name) : team_(team), name_(name) {}
	virtual ~ChessPiece() = default;
	// virtual std::vector<Position> possibleMoves(const Position& currentPosition) const = 0;
	virtual bool isValidMove(const Position& from, const Position& to) const = 0;
	Team getTeam() const { return team_; }
	std::string getName() const { return name_; }

	virtual QLabel* label() const = 0;

protected:
	Team team_;
	std::string name_;
};


