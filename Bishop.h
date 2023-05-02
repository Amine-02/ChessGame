#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
	explicit Bishop(Team team)
		: ChessPiece(team, "Bishop")
	{
		if (team_ == Team::Black) {
			label_.setText(QChar(BLACK_BISHOP));
		}
		else {
			label_.setText(QChar(WHITE_BISHOP));
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

		// A bishop can move any number of squares diagonally
		return rowDifference == colDifference;
	}
private:
	mutable QLabel label_;
};