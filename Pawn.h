#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
	explicit Pawn(Team team, ChessBoard& chessBoard)
		: ChessPiece(team, "Pawn"), chessBoard_(chessBoard)
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_PAWN));
		}
		else {
			label_.setText(QChar(WHITE_PAWN));
		}
		label_.setFont(QFont("Arial", 30));
		label_.setAlignment(Qt::AlignCenter);
	}

	QLabel* label() const override {
		return &label_;
	}

	bool isValidMove(const Position& from, const Position& to) const override;

private:
	mutable QLabel label_;
	ChessBoard& chessBoard_;
};