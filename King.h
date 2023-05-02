#include "ChessPiece.h"


class King : public ChessPiece
{
public:
	explicit King(Team team)
		: ChessPiece(team, "King")
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_KING));
		}
		else {
			label_.setText(QChar(WHITE_KING));
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

		// A king can move one square in any direction (horizontally, vertically, or diagonally)
		return (rowDifference <= 1) && (colDifference <= 1);
	}

private:
	mutable QLabel label_;
};