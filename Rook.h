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
		// A rook can move any number of squares along a rank or file
		return (from.first == to.first) || (from.second == to.second);
	}
private:
	mutable QLabel label_;
};