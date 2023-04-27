#pragma once
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QtGui>
#include <QMessageBox>
#include <utility>
#include <string>
#include <vector>
#include <stdexcept>

enum Team {White, Black};
using Position = QPair<int, int>;

const wchar_t WHITE_KING = 0x2654;
const wchar_t WHITE_QUEEN = 0x2655;
const wchar_t WHITE_ROOK = 0x2656;
const wchar_t WHITE_BISHOP = 0x2657;
const wchar_t WHITE_KNIGHT = 0x2658;
const wchar_t WHITE_PAWN = 0x2659;
const wchar_t BLACK_KING = 0x265A;
const wchar_t BLACK_QUEEN = 0x265B;
const wchar_t BLACK_ROOK = 0x265C;
const wchar_t BLACK_BISHOP = 0x265D;
const wchar_t BLACK_KNIGHT = 0x265E;
const wchar_t BLACK_PAWN = 0x265F;


	class ChessBoard;

	class ChessPiece : public QWidget
	{
		Q_OBJECT
	public:

		explicit ChessPiece(Team team, std::string name) : team_(team), name_(name) {}
		virtual ~ChessPiece() = default;
		// virtual std::vector<Position> possibleMoves(const Position& currentPosition) const = 0;
		virtual bool isValidMove(const Position& from, const Position& to) const = 0;
		Team getTeam() const { return team_; }
		std::string getName() const { return name_; }

		virtual QLabel* label() const = 0;

	protected:
		Team team_;
		std::string name_;
	};


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


	class Queen : public ChessPiece
	{
	public:
		explicit Queen(Team team)
			: ChessPiece(team, "Queen")
		{
			if (team_ == Team::Black) {
				label_.setText(QChar(BLACK_QUEEN));
			}
			else {
				label_.setText(QChar(WHITE_QUEEN));
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

			// A queen can move any number of squares along a rank, file, or diagonal
			return (from.first == to.first) || (from.second == to.second) || (rowDifference == colDifference);
		}
	private:
		mutable QLabel label_;
	};

	class Rook : public ChessPiece
	{
	public:
		explicit Rook(Team team)
			: ChessPiece(team, "Rook")
		{
			if (team_ == Team::Black) {
				label_.setText(QChar(BLACK_ROOK));
			}
			else {
				label_.setText(QChar(WHITE_ROOK));
			}
			label_.setFont(QFont("Arial", 30));
			label_.setAlignment(Qt::AlignCenter);
		}

		QLabel* label() const override {
			return &label_;
		}

		bool isValidMove(const Position& from, const Position& to) const override {
			// A rook can move any number of squares along a rank or file
			return (from.first == to.first) || (from.second == to.second);
		}
	private:
		mutable QLabel label_;
	};

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

			// A knight can move in an L-shape (two squares in a straight line and then one square perpendicular to that line, or vice versa)
			return (rowDifference == 2 && colDifference == 1) || (rowDifference == 1 && colDifference == 2);
		}

		Knight* getKnight() {
			return this;
		}

	private:
		mutable QLabel label_;
	};

	class ChessBoard;

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



