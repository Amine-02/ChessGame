#include "ChessBoard.h"
#include "ChessPiece.h"

bool Pawn::isValidMove(const Position& from, const Position& to) const {
	int rowDifference = to.first - from.first;
	int colDifference = std::abs(from.second - to.second);

	/* La piece Pawn peut se deplacer normalement d'une case vers l'avant. Dans le cas que le pion
	se situe dans sa rangee initiale, il peut se deplacer de deux cases vers l'avant. Dans le cas
	d'une capture d'une piece adverse, le pion peut seulement executer cette tache en se deplacant
	en diagonale vers l'avant d'une seule case. */

	if (team_ == White) {
		return ((colDifference == 0 && rowDifference == 1) && !chessBoard_.isOpponentPiece(to, Team::Black)) ||
			(colDifference == 0 && from.first == 1 && rowDifference == 2 && !chessBoard_.isOpponentPiece(to, Team::Black)) ||
			(colDifference == 1 && rowDifference == 1 && chessBoard_.isOpponentPiece(to, Team::Black));
	}
	else {
		return ((colDifference == 0 && rowDifference == -1) && !chessBoard_.isOpponentPiece(to, Team::White)) ||
			(colDifference == 0 && from.first == 6 && rowDifference == -2 && !chessBoard_.isOpponentPiece(to, Team::White)) ||
			(colDifference == 1 && rowDifference == -1 && chessBoard_.isOpponentPiece(to, Team::White));
	}
}

