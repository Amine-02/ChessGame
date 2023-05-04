#include "gtest/gtest.h"
#include "ChessPiece.h"
#include "Pawn.h"
#include "ChessBoard.h"

// Test cases go here

TEST(PawnTest, PawnMovement) {
	int colorStyle = 0; // Choose a color style
	ChessBoard chessBoard(colorStyle);
	Pawn whitePawn(Team::White, chessBoard);
	Pawn blackPawn(Team::Black, chessBoard);

	Position from(1, 4);
	Position validMove(2, 4);
	Position invalidMove(0, 4);

	ASSERT_TRUE(whitePawn.isValidMove(from, validMove));
	ASSERT_FALSE(whitePawn.isValidMove(from, invalidMove));

	from = Position(2, 4);
	invalidMove = Position(4, 4);
	ASSERT_FALSE(whitePawn.isValidMove(from, invalidMove));

	from = Position(5, 4);
	invalidMove = Position(3, 4);
	ASSERT_FALSE(blackPawn.isValidMove(from, invalidMove));

	from = Position(6, 4);
	validMove = Position(5, 4);
	invalidMove = Position(7, 4);

	ASSERT_TRUE(blackPawn.isValidMove(from, validMove));
	ASSERT_FALSE(blackPawn.isValidMove(from, invalidMove));
}

