#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	explicit Rook(Team team)
		: ChessPiece(team, "Rook")
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_ROOK));
		}
		else {
			label_.setText(QChar(WHITE_ROOK));
		}
		label_.setFont(QFont("Arial", 30));
		label_.setAlignment(Qt::AlignCenter);
	}

	QLabel* label() const override {
		return &label_;
	}

	bool isValidMove(const Position& from, const Position& to) const override {

		// Une piece Rook peut se deplacer d'un nombre quelconque de cases le long d'une rangee ou d'une colonne.

		return (from.first == to.first) || (from.second == to.second);
	}
private:
	mutable QLabel label_;
};