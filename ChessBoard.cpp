#pragma warning(disable : 5054)
#include <iostream>
#include <stdexcept> 

#include "ChessBoard.h"


void ChessBoard::generateOriginalBoard() {

	// Add white pieces
	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board[1][i]->updateLayout(pawn);
		board[1][i]->setPiece(pawn);
	}

	auto rook1 = std::make_shared<Rook>(White);
	board[0][0]->updateLayout(rook1);
	board[0][0]->setPiece(rook1);

	auto rook2 = std::make_shared<Rook>(White);
	board[0][7]->updateLayout(rook2);
	board[0][7]->setPiece(rook2);

	auto knight1 = std::make_shared<Knight>(White);
	board[0][1]->updateLayout(knight1);
	board[0][1]->setPiece(knight1);

	auto knight2 = std::make_shared<Knight>(White);
	board[0][6]->updateLayout(knight2);
	board[0][6]->setPiece(knight2);

	auto bishop1 = std::make_shared<Bishop>(White);
	board[0][2]->updateLayout(bishop1);
	board[0][2]->setPiece(bishop1);

	auto bishop2 = std::make_shared<Bishop>(White);
	board[0][5]->updateLayout(bishop2);
	board[0][5]->setPiece(bishop2);

	auto queen = std::make_shared<Queen>(White);
	board[0][3]->updateLayout(queen);
	board[0][3]->setPiece(queen);

	auto king1 = std::make_shared<King>(White);
	board[0][4]->updateLayout(king1);
	board[0][4]->setPiece(king1);

	// Add black pieces
	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board[6][i]->updateLayout(pawn);
		board[6][i]->setPiece(pawn);
	}

	auto rook3 = std::make_shared<Rook>(Black);
	board[7][0]->updateLayout(rook3);
	board[7][0]->setPiece(rook3);

	auto rook4 = std::make_shared<Rook>(Black);
	board[7][7]->updateLayout(rook4);
	board[7][7]->setPiece(rook4);

	auto knight3 = std::make_shared<Knight>(Black);
	board[7][1]->updateLayout(knight3);
	board[7][1]->setPiece(knight3);

	auto knight4 = std::make_shared<Knight>(Black);
	board[7][6]->updateLayout(knight4);
	board[7][6]->setPiece(knight4);

	auto bishop3 = std::make_shared<Bishop>(Black);
	board[7][2]->updateLayout(bishop3);
	board[7][2]->setPiece(bishop3);

	auto bishop4 = std::make_shared<Bishop>(Black);
	board[7][5]->updateLayout(bishop4);
	board[7][5]->setPiece(bishop4);

	auto queen2 = std::make_shared<Queen>(Black);
	board[7][3]->updateLayout(queen2);
	board[7][3]->setPiece(queen2);

	auto king2 = std::make_shared<King>(Black);
	board[7][4]->updateLayout(king2);
	board[7][4]->setPiece(king2);
}

void ChessBoard::rookConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board[0][4]->updateLayout(king1);
	board[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board[7][4]->updateLayout(king2);
	board[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board[1][i]->updateLayout(pawn);
		board[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board[6][i]->updateLayout(pawn);
		board[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Rook>(White);
		board[0][i]->updateLayout(rook);
		board[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Rook>(Black);
		board[7][i]->updateLayout(rook);
		board[7][i]->setPiece(rook);
	}
}

void ChessBoard::bishopConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board[0][4]->updateLayout(king1);
	board[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board[7][4]->updateLayout(king2);
	board[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board[1][i]->updateLayout(pawn);
		board[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board[6][i]->updateLayout(pawn);
		board[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Bishop>(White);
		board[0][i]->updateLayout(rook);
		board[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Bishop>(Black);
		board[7][i]->updateLayout(rook);
		board[7][i]->setPiece(rook);
	}
}

void ChessBoard::queenConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board[0][4]->updateLayout(king1);
	board[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board[7][4]->updateLayout(king2);
	board[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board[1][i]->updateLayout(pawn);
		board[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board[6][i]->updateLayout(pawn);
		board[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Queen>(White);
		board[0][i]->updateLayout(rook);
		board[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Queen>(Black);
		board[7][i]->updateLayout(rook);
		board[7][i]->setPiece(rook);
	}
}

void ChessBoard::addPieces(int config) {
	// Clear the board
	for (auto& row : board) {
		for (auto& square : row) {
			square->removePiece();
		}
	}

	switch (config) {
	case 0: // Classic
		generateOriginalBoard();
		break;
	case 1: // The Crazy Bishops
		bishopConfiguration();
		break;
	case 2: // Rook Takeover
		rookConfiguration();
		break;
	case 3: // The Queens Game
		queenConfiguration();
		break;
	default:
		throw std::runtime_error("Invalid configuration");
	}
}

void ChessBoard::switchCurrentPlayer() {
	currentPlayer_ = (currentPlayer_ == White) ? Black : White;
}

void ChessBoard::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	int minDimension = std::min(width(), height());
	int newCaseSize = minDimension;

	// Iterate through the board and set the new size for each case
	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			board[row][col]->setFixedSize(newCaseSize, newCaseSize);
		}
	}

	// Update the size of the ChessBoard widget
	setFixedSize(newCaseSize * 8, newCaseSize * 8);
}

void Case::mousePressEvent(QMouseEvent* event) {
	QPushButton::mousePressEvent(event);
	emit caseClicked(position_.first, position_.second);
}

bool Case::hasLayout() {
	return (getLayout() != nullptr);
}

void Case::updateLayout(std::shared_ptr<ChessPiece> piece) {

	if (layout_->isEmpty()) {
		layout_->addWidget(piece->label());
		piece_ = piece;
	}
	else {
		layout_->removeWidget(piece->label());
		piece_ = nullptr;
	}
}

std::shared_ptr<Case>& ChessBoard::at(int row, int col) {
	return board[row][col];
}

const std::shared_ptr<Case>& ChessBoard::at(int row, int col) const {
	return board[row][col];
}

bool ChessBoard::isOpponentPiece(Position to, Team team) {
	std::shared_ptr<ChessPiece> piece = board[to.first][to.second].get()->getPiece();
	if (piece == nullptr) {
		return false;
	}

	if (piece.get()->getTeam() != team) {
		return true;
	}

	return false;
}

bool ChessBoard::hasPiecesInWay(const Position& from, const Position& to) const {
	int dx = to.first - from.first;
	int dy = to.second - from.second;
	int xdir = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
	int ydir = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);

	int x = from.first + xdir;
	int y = from.second + ydir;

	while (x != to.first || y != to.second) {
		if (at(x, y)->getPiece() != nullptr) {
			return true;
		}
		x += xdir;
		y += ydir;
	}

	return false;
}

Position ChessBoard::findKing(Team team) {
	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			std::shared_ptr<ChessPiece> piece = at(row, col)->getPiece();
			if (piece && piece->getName() == "King" && piece->getTeam() == team) {
				return Position(row, col);
			}
		}
	}
	return Position(-1, -1);
}


// Add this method to check if a given position is attacked by the opponent
bool ChessBoard::isPositionAttacked(Position position, Team attackerTeam) {
	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			std::shared_ptr<ChessPiece> attacker = at(row, col)->getPiece();
			if (attacker && attacker->getTeam() == attackerTeam) {
				Position attackerPosition(row, col);
				if (attacker->isValidMove(attackerPosition, position)) {
					if (attacker->getName() == "Knight" || !hasPiecesInWay(attackerPosition, position)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool ChessBoard::isValidPosition(const Position& position) {
	int row = position.first;
	int col = position.second;

	// Check if the row and column are within the bounds of the chessboard
	if (row >= 0 && row < ROW_NUM && col >= 0 && col < COL_NUM) {
		return true;
	}
	else {
		return false;
	}
}

bool ChessBoard::isMoveResultingInCheck(const Position& from, const Position& to, const Position& kingPosition) {

	std::shared_ptr<Case>& originCase = this->getBoard()[from.first][from.second];
	std::shared_ptr<Case>& destinationCase = this->getBoard()[to.first][to.second];

	// Simulate the move
	auto attacker = originCase->getPiece();
	auto capturedPiece = destinationCase->getPiece();
	destinationCase->setPiece(originCase->getPiece());
	originCase->setPiece(nullptr);

	// Check if the king is in check
	bool kingInCheck = isPositionAttacked(kingPosition, currentPlayer_ == White ? Black : White);

	// Revert the move 
	destinationCase->setPiece(capturedPiece);
	originCase->setPiece(attacker);

	return kingInCheck;
}

bool ChessBoard::movePiece(const Position& from, const Position& to) {
	std::shared_ptr<Case>& originCase = this->getBoard()[from.first][from.second];

	if (originCase->getPiece() == nullptr || !(originCase->getPiece()->isValidMove(from, to))) {
		return false;
	}

	std::shared_ptr<Case>& destinationCase = this->getBoard()[to.first][to.second];

	if (destinationCase->getPiece() != nullptr && destinationCase->getPiece()->getTeam() == originCase->getPiece()->getTeam()) {
		return false;
	}

	if (originCase.get()->getPiece().get()->getName() != "Knight" && hasPiecesInWay(from, to)) {
		return false;
	}

	Position kingPosition;
	if (originCase->getPiece()->getName() == "King") {
		kingPosition = to;
	}
	else {
		kingPosition = findKing(currentPlayer_);
	}

	bool kingInCheck = isMoveResultingInCheck(from, to, kingPosition);

	if (kingInCheck) {
		QMessageBox warning = QMessageBox();
		warning.setIcon(QMessageBox::Warning);
		warning.setWindowTitle("Warning");
		warning.setText("King is in check. Move not allowed.");
		warning.setStandardButtons(QMessageBox::Ok);
		warning.exec();
		return false;
	}

	// Move the piece
	destinationCase->setPiece(originCase->getPiece());
	originCase->setPiece(nullptr);

	// Update the layouts
	originCase->updateLayout(destinationCase->getPiece());
	destinationCase->updateLayout(destinationCase->getPiece());

	// Turn Pawn into Queen
	if (destinationCase->getPiece()->getName() == "Pawn" && (to.first == 0 || to.first == 7)) {
		auto queen = std::make_shared<Queen>(currentPlayer_);
		destinationCase->updateLayout(queen);
		destinationCase->setPiece(queen);
	}

	return true;
}

void ChessBoard::onCaseClicked(int row, int col) {
	Position clickedPosition(row, col);
	std::shared_ptr<Case> clickedCase = at(clickedPosition.first, clickedPosition.second);

	if (!selectedCase_) {
		if (clickedCase->getPiece() && clickedCase->getPiece()->getTeam() == currentPlayer_) {
			selectedCase_ = clickedCase;
			clickedCase->setStyleSheet("background-color: lightsalmon;");
		}
	}
	else {
		Position from = selectedCase_->getPosition();
		Position to = clickedCase->getPosition();

		// Check if it's the current player's turn
		if (selectedCase_->getPiece()->getTeam() == currentPlayer_) {
			if (movePiece(from, to)) { // Check if the move was successful
				// Switch the current player
				currentPlayer_ = (currentPlayer_ == White) ? Black : White;
			}
		}

		// Reset the selected case's style
		bool isWhite = (selectedCase_->getPosition().first + selectedCase_->getPosition().second) % 2 == 0;
		//selectedCase_->setStyleSheet(isWhite ? "background-color: Peru;" : "background-color: Wheat;");
		if (colorStyle_ == 0) { // Brown/Beige color style
			if (isWhite) {
				selectedCase_->setStyleSheet("background-color: Peru;");
			}
			else {
				selectedCase_->setStyleSheet("background-color: Wheat;");
			}
		}
		else if (colorStyle_ == 1) { // Gray/Blue color style
			if (isWhite) {
				selectedCase_->setStyleSheet("background-color: LightGray;");
			}
			else {
				selectedCase_->setStyleSheet("background-color: SlateGray;");
			}
		}
		else if (colorStyle_ == 2) { // Green/Cream color style
			if (isWhite) {
				selectedCase_->setStyleSheet("background-color: LightGreen;");
			}
			else {
				selectedCase_->setStyleSheet("background-color: DarkGreen;");
			}
		}
		else if (colorStyle_ == 3) { // Purple/Pink color style
			if (isWhite) {
				selectedCase_->setStyleSheet("background-color: Thistle;");
			}
			else {
				selectedCase_->setStyleSheet("background-color: MediumPurple;");
			}
		}
		selectedCase_ = nullptr;
	}
}
