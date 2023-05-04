#include "gtest/gtest.h"
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "ChessBoard.h"

// Test cases go here

TEST(PawnTest, PawnMovement) {
	int colorStyle = 0;
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

TEST(RookTest, RookMovement) {
	Rook whiteRook(Team::White);
	Rook blackRook(Team::Black);

	Position from(3, 3);
	Position validMove(3, 7);
	Position invalidMove(4, 5);

	ASSERT_TRUE(whiteRook.isValidMove(from, validMove));
	ASSERT_FALSE(whiteRook.isValidMove(from, invalidMove));
}

TEST(KnightTest, KnightMovement) {
	Knight whiteKnight(Team::White);
	Knight blackKnight(Team::Black);

	Position from(3, 3);
	Position validMove(5, 4);
	Position invalidMove(3, 5);

	ASSERT_TRUE(whiteKnight.isValidMove(from, validMove));
	ASSERT_FALSE(whiteKnight.isValidMove(from, invalidMove));
}

TEST(BishopTest, BishopMovement) {
	Bishop whiteBishop(Team::White);
	Bishop blackBishop(Team::Black);

	Position from(3, 3);
	Position validMove(5, 5);
	Position invalidMove(3, 5);

	ASSERT_TRUE(whiteBishop.isValidMove(from, validMove));
	ASSERT_FALSE(whiteBishop.isValidMove(from, invalidMove));
}

TEST(QueenTest, QueenMovement) {
	Queen whiteQueen(Team::White);
	Queen blackQueen(Team::Black);

	Position from(3, 3);
	Position validMove1(5, 5);
	Position validMove2(3, 7);
	Position invalidMove(4, 6);

	ASSERT_TRUE(whiteQueen.isValidMove(from, validMove1));
	ASSERT_TRUE(whiteQueen.isValidMove(from, validMove2));
	ASSERT_FALSE(whiteQueen.isValidMove(from, invalidMove));
}

TEST(KingTest, KingMovement) {
	King whiteKing(Team::White);
	King blackKing(Team::Black);

	Position from(3, 3);
	Position validMove(4, 4);
	Position invalidMove(5, 5);

	ASSERT_TRUE(whiteKing.isValidMove(from, validMove));
	ASSERT_FALSE(whiteKing.isValidMove(from, invalidMove));
}