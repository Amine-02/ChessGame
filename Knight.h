#pragma once
#include "ChessPiece.h"


class Knight : public ChessPiece
{
public:
	explicit Knight(Team team)
		: ChessPiece(team, "Knight")
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_KNIGHT));
		}
		else {
			label_.setText(QChar(WHITE_KNIGHT));
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

		// La piece Knight peut se deplacer en "L" seulement dans toutes les directions.

		return (rowDifference == 2 && colDifference == 1) || (rowDifference == 1 && colDifference == 2);
	}

	Knight* getKnight() {
		return this;
	}

private:
	mutable QLabel label_;
};
