#pragma once

typedef unsigned char byte;
#include <cmath>
class PixelPacked
{
public:
	byte blue;
	byte green;
	byte red;

	PixelPacked(byte b, byte g, byte r) : blue{ b }, green{ g }, red{ r } {};
	double CalculateDistance(const PixelPacked& pixelPacket)const
	{
		byte dGreen = abs(green - pixelPacket.green);
		byte dBlue = abs(blue - pixelPacket.blue);
		byte dRed = abs(red - pixelPacket.red);

		return sqrt(pow(dGreen, 2) + pow(dBlue, 2) + pow(dRed, 2));
	}
};