#pragma once

#include "Player.h"

class Champion: public Player {
private:
    int checkRowsCol(const Board& b, char c,int rowCol);
    Coordinate block(const Board& b, uint index, int rowCol) const;
public:
    Champion(){}
	const string name() const override { return "Tomer Zaks"; }
	const Coordinate play(const Board& board) override;
};