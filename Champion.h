#pragma once

#include "Player.h"

class champion: public Player {
public:
	const string name() const override { return "Tomer Zaks"; }
	const Coordinate play(const Board& board) override;
};