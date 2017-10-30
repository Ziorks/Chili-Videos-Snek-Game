#pragma once

#include"Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(int segments);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd)const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target)const;
	bool IsInTile(const Location& target)const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor0 = Colors::Green;
	static constexpr Color bodyColor1 = Colors::MakeRGB(0x32u, 0xCDu, 0x32u);
	static constexpr Color bodyColor2 = Colors::MakeRGB(0u, 0x64u, 0u);
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};
