#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
	explicit Queen(Team team)
		: ChessPiece(team, "Queen")
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_QUEEN));
		}
		else {
			label_.setText(QChar(WHITE_QUEEN));
		}
		label_.setFont(QFont("Arial", 30));
		label_.setAlignment(Qt::AlignCenter);
	}

	QLabel* label() const override {
		return &label_;
	}

	bool isValidMove(const Position& from, const Position& to) const override {
		int rowDifference = std::abs(from.first - to.first);
		int colDifference = std::abs(from.second - to.second);

		/* La piece Queen peut se deplacer d'un nombre quelconque de cases le long d'une rangee,
		d'une colonne ou d'une diagonale. */

		return (from.first == to.first) || (from.second == to.second) || (rowDifference == colDifference);
	}
private:
	mutable QLabel label_;
};