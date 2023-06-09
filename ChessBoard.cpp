#include <iostream>
#include <stdexcept> 

#include "ChessBoard.h"

void ChessBoard::generateOriginalBoard() {


	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board_[1][i]->updateLayout(pawn);
		board_[1][i]->setPiece(pawn);
	}

	auto rook1 = std::make_shared<Rook>(White);
	board_[0][0]->updateLayout(rook1);
	board_[0][0]->setPiece(rook1);

	auto rook2 = std::make_shared<Rook>(White);
	board_[0][7]->updateLayout(rook2);
	board_[0][7]->setPiece(rook2);

	auto knight1 = std::make_shared<Knight>(White);
	board_[0][1]->updateLayout(knight1);
	board_[0][1]->setPiece(knight1);

	auto knight2 = std::make_shared<Knight>(White);
	board_[0][6]->updateLayout(knight2);
	board_[0][6]->setPiece(knight2);

	auto bishop1 = std::make_shared<Bishop>(White);
	board_[0][2]->updateLayout(bishop1);
	board_[0][2]->setPiece(bishop1);

	auto bishop2 = std::make_shared<Bishop>(White);
	board_[0][5]->updateLayout(bishop2);
	board_[0][5]->setPiece(bishop2);

	auto queen = std::make_shared<Queen>(White);
	board_[0][3]->updateLayout(queen);
	board_[0][3]->setPiece(queen);

	auto king1 = std::make_shared<King>(White);
	board_[0][4]->updateLayout(king1);
	board_[0][4]->setPiece(king1);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board_[6][i]->updateLayout(pawn);
		board_[6][i]->setPiece(pawn);
	}

	auto rook3 = std::make_shared<Rook>(Black);
	board_[7][0]->updateLayout(rook3);
	board_[7][0]->setPiece(rook3);

	auto rook4 = std::make_shared<Rook>(Black);
	board_[7][7]->updateLayout(rook4);
	board_[7][7]->setPiece(rook4);

	auto knight3 = std::make_shared<Knight>(Black);
	board_[7][1]->updateLayout(knight3);
	board_[7][1]->setPiece(knight3);

	auto knight4 = std::make_shared<Knight>(Black);
	board_[7][6]->updateLayout(knight4);
	board_[7][6]->setPiece(knight4);

	auto bishop3 = std::make_shared<Bishop>(Black);
	board_[7][2]->updateLayout(bishop3);
	board_[7][2]->setPiece(bishop3);

	auto bishop4 = std::make_shared<Bishop>(Black);
	board_[7][5]->updateLayout(bishop4);
	board_[7][5]->setPiece(bishop4);

	auto queen2 = std::make_shared<Queen>(Black);
	board_[7][3]->updateLayout(queen2);
	board_[7][3]->setPiece(queen2);

	auto king2 = std::make_shared<King>(Black);
	board_[7][4]->updateLayout(king2);
	board_[7][4]->setPiece(king2);
}

void ChessBoard::rookConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board_[0][4]->updateLayout(king1);
	board_[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board_[7][4]->updateLayout(king2);
	board_[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board_[1][i]->updateLayout(pawn);
		board_[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board_[6][i]->updateLayout(pawn);
		board_[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Rook>(White);
		board_[0][i]->updateLayout(rook);
		board_[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Rook>(Black);
		board_[7][i]->updateLayout(rook);
		board_[7][i]->setPiece(rook);
	}
}

void ChessBoard::bishopConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board_[0][4]->updateLayout(king1);
	board_[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board_[7][4]->updateLayout(king2);
	board_[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board_[1][i]->updateLayout(pawn);
		board_[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board_[6][i]->updateLayout(pawn);
		board_[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Bishop>(White);
		board_[0][i]->updateLayout(rook);
		board_[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Bishop>(Black);
		board_[7][i]->updateLayout(rook);
		board_[7][i]->setPiece(rook);
	}
}

void ChessBoard::queenConfiguration() {

	auto king1 = std::make_shared<King>(White);
	board_[0][4]->updateLayout(king1);
	board_[0][4]->setPiece(king1);

	auto king2 = std::make_shared<King>(Black);
	board_[7][4]->updateLayout(king2);
	board_[7][4]->setPiece(king2);

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(White, *this);
		board_[1][i]->updateLayout(pawn);
		board_[1][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		auto pawn = std::make_shared<Pawn>(Black, *this);
		board_[6][i]->updateLayout(pawn);
		board_[6][i]->setPiece(pawn);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Queen>(White);
		board_[0][i]->updateLayout(rook);
		board_[0][i]->setPiece(rook);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			continue;
		}
		auto rook = std::make_shared<Queen>(Black);
		board_[7][i]->updateLayout(rook);
		board_[7][i]->setPiece(rook);
	}
}

void ChessBoard::addPieces(int config) {

	// Efface l'echiquier (mesure de securite)
	for (auto& row : board_) {
		for (auto& square : row) {
			square->removePiece();
		}
	}

	// Genere les piece de l'echiquier par rapport a la configuration choisie.
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
	}
}

void ChessBoard::switchCurrentPlayer() {
	currentPlayer_ = (currentPlayer_ == White) ? Black : White;
}

void ChessBoard::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	int minDimension = std::min(width(), height());
	int newCaseSize = minDimension;

	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			board_[row][col]->setFixedSize(newCaseSize, newCaseSize);
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
	return board_[row][col];
}

const std::shared_ptr<Case>& ChessBoard::at(int row, int col) const {
	return board_[row][col];
}

bool ChessBoard::isOpponentPiece(Position to, Team team) {
	std::shared_ptr<ChessPiece> piece = board_[to.first][to.second].get()->getPiece();
	if (piece == nullptr) {
		return false;
	}

	if (piece.get()->getTeam() != team) {
		return true;
	}

	return true;
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


bool ChessBoard::isPositionAttacked(Position position, Team team) {
	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			Position attacker(row, col);
			std::shared_ptr<ChessPiece> attackerPiece = at(attacker.first, attacker.second)->getPiece();

			if (!attackerPiece || attackerPiece->getTeam() != team) {
				continue;
			}

			if (attackerPiece->getName() == "Pawn") {
				int rowDifference = position.first - attacker.first;
				int colDifference = std::abs(position.second - attacker.second);

				if (team == White) {
					if (colDifference == 1 && rowDifference == 1) {
						return true;
					}
				}
				else {
					if (colDifference == 1 && rowDifference == -1) {
						return true;
					}
				}
			}
			else if (attackerPiece->isValidMove(attacker, position)) {
				if (attackerPiece->getName() == "Knight" || !hasPiecesInWay(attacker, position)) {
					return true;
				}
			}
		}
	}
	return false;
}


bool ChessBoard::isValidPosition(const Position& position) {
	int row = position.first;
	int col = position.second;

	// Verifie si les rangees et les colonnes sont a l'interieur de l'echiquier.
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

	// Simule le deplacement.
	auto attacker = originCase->getPiece();
	auto capturedPiece = destinationCase->getPiece();
	destinationCase->setPiece(originCase->getPiece());
	originCase->setPiece(nullptr);

	// Verifie si le roi est en echec.
	bool kingInCheck = isPositionAttacked(kingPosition, currentPlayer_ == White ? Black : White);


	// Retourne a la position initiale.
	destinationCase->setPiece(capturedPiece);
	originCase->setPiece(attacker);

	return kingInCheck;
}

void generateWarning(QString message) {

	QMessageBox warning = QMessageBox(); // Generation d'une fenetre d'erreur typique.
	warning.setIcon(QMessageBox::Warning);
	warning.setWindowTitle("Warning");
	warning.setText(message);
	warning.setStandardButtons(QMessageBox::Ok);;
	QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	QGridLayout* layout = (QGridLayout*)warning.layout();
	layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
	warning.setMinimumSize(400, 200);

	warning.exec();
}

void ChessBoard::highlightValidMoves(int row, int col) {
	Position clickedPosition(row, col);
	std::shared_ptr<ChessPiece> piece = at(clickedPosition.first, clickedPosition.second)->getPiece();
	if (!piece || piece->getTeam() != currentPlayer_) {
		return;
	}

	for (int i = 0; i < ROW_NUM; ++i) {
		for (int j = 0; j < COL_NUM; ++j) {
			Position destination(i, j);
			std::shared_ptr<ChessPiece> destinationPiece = at(destination.first, destination.second)->getPiece();

			// Ne considere pas les positions avec des pieces de la meme equipe.
			if (destinationPiece && destinationPiece->getTeam() == currentPlayer_) {
				continue;
			}

			if (piece->isValidMove(clickedPosition, destination)) {
				bool canHighlight = false;
				if (piece->getName() == "King") {
					Team opponentTeam = piece->getTeam() == White ? Black : White;
					canHighlight = !isPositionAttacked(destination, opponentTeam);
				}
				else {
					if (piece->getName() == "Knight") {
						canHighlight = !isMoveResultingInCheck(clickedPosition, destination, findKing(currentPlayer_));
					}
					else {
						canHighlight = !hasPiecesInWay(clickedPosition, destination) && !isMoveResultingInCheck(clickedPosition, destination, findKing(currentPlayer_));
					}
				}

				if (canHighlight) {
					board_[i][j]->setStyleSheet("background-color: rgba(255, 255, 0, 0.5);"); // Illustre les positions possibles d'une piece.
				}
			}
		}
	}
}





void ChessBoard::removeHighlightFromAllCases() {
	for (int row = 0; row < ROW_NUM; ++row) {
		for (int col = 0; col < COL_NUM; ++col) {
			std::shared_ptr<Case> currentCase = at(row, col);
			bool isWhite = (currentCase->getPosition().first + currentCase->getPosition().second) % 2 == 0;
			if (colorStyle_ == 0) {
				currentCase->setStyleSheet(isWhite ? "background-color: Peru;" : "background-color: Wheat;");
			}
			else if (colorStyle_ == 1) {
				currentCase->setStyleSheet(isWhite ? "background-color: LightGray;" : "background-color: SlateGray;");
			}
			else if (colorStyle_ == 2) {
				currentCase->setStyleSheet(isWhite ? "background-color: LightGreen;" : "background-color: DarkGreen;");
			}
			else if (colorStyle_ == 3) {
				currentCase->setStyleSheet(isWhite ? "background-color: Thistle;" : "background-color: MediumPurple;");
			}
		}
	}
}



bool ChessBoard::movePiece(const Position& from, const Position& to) {
	std::shared_ptr<Case>& originCase = this->getBoard()[from.first][from.second];

	if (originCase->getPiece() == nullptr || !(originCase->getPiece()->isValidMove(from, to))) {
		generateWarning("Invalid Move!");
		removeHighlightFromAllCases();
		return false;
	}

	std::shared_ptr<Case>& destinationCase = this->getBoard()[to.first][to.second];

	if (destinationCase->getPiece() != nullptr && destinationCase->getPiece()->getTeam() == originCase->getPiece()
		->getTeam()) {
		generateWarning("Invalid Move!");
		removeHighlightFromAllCases();
		return false;
	}

	if (originCase.get()->getPiece().get()->getName() != "Knight" && hasPiecesInWay(from, to)) {
		generateWarning("Invalid Move!");
		removeHighlightFromAllCases();
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
		generateWarning("King is in check. Move not allowed.");
		removeHighlightFromAllCases();
		return false;
	}

	// Deplace la piece.
	destinationCase->setPiece(originCase->getPiece());
	originCase->setPiece(nullptr);

	// Met a jour l'interface.
	originCase->updateLayout(destinationCase->getPiece());
	destinationCase->updateLayout(destinationCase->getPiece());

	// Transforme un pion en une reine Queen.
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
			removeHighlightFromAllCases();
			selectedCase_ = clickedCase;
			clickedCase->setStyleSheet("background-color: lightsalmon;"); // Illustre en rose la case selectionnee.
		}
	}
	else {
		if (clickedCase->getPiece() && clickedCase->getPiece()->getTeam() == currentPlayer_) {
			removeHighlightFromAllCases();

			selectedCase_ = clickedCase;
			clickedCase->setStyleSheet("background-color: lightsalmon;");
		}
		else {
			Position from = selectedCase_->getPosition();
			Position to = clickedCase->getPosition();

			// Verifie le tour du joueur.
			if (selectedCase_->getPiece()->getTeam() == currentPlayer_) {
				if (movePiece(from, to)) { // Verifie la validite du deplacement
					// Change de joueur.
					removeHighlightFromAllCases();
					currentPlayer_ = (currentPlayer_ == White) ? Black : White;
				}
			}


			// Reinitialise la couleur de la case selectionnee.
			bool isWhite = (selectedCase_->getPosition().first + selectedCase_->getPosition().second) % 2 == 0;
			if (colorStyle_ == 0) {
				if (isWhite) {
					selectedCase_->setStyleSheet("background-color: Peru;");
				}
				else {
					selectedCase_->setStyleSheet("background-color: Wheat;");
				}
			}
			else if (colorStyle_ == 1) {
				if (isWhite) {
					selectedCase_->setStyleSheet("background-color: LightGray;");
				}
				else {
					selectedCase_->setStyleSheet("background-color: SlateGray;");
				}
			}
			else if (colorStyle_ == 2) {
				if (isWhite) {
					selectedCase_->setStyleSheet("background-color: LightGreen;");
				}
				else {
					selectedCase_->setStyleSheet("background-color: DarkGreen;");
				}
			}
			else if (colorStyle_ == 3) {
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
}