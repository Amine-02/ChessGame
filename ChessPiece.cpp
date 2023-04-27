#include "ChessPiece.h"
#include "ChessBoard.h"

bool Pawn::isValidMove(const Position& from, const Position& to) const {
    int rowDifference = to.first - from.first;
    int colDifference = std::abs(from.second - to.second);

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

