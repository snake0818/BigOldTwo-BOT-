#ifndef CHECK_H
#define CHECH_H

class Check
{
public:
	bool isNumberInRpt(const double card) const;
	bool checkInRpt(double* cards);
	bool checkSame(double* cards);
	bool checkPairs(double* cards);
	bool checkTriples(double* cards);
	bool checkFlush(double* cards);
	bool checkStraight(double* cards);
	bool checkTiki(double* cards);
	bool checkStraightFlush(double* cards);
	bool checkSpecialStraight(double* cards);
	bool checkFullHouse(double* cards);
	int checkCardsType(double* cards, double* card);
	int checkCardsType(double* cards, int num);
	bool checkSingle(double* cards, double* card, double value);
	bool checkPairs(double* cards, double* card, double value);
	bool checkTriples(double* cards, double* card, double value);
	bool checkFlush(double* cards, double* card, double value);
	bool checkStraight(double* cards, double* card, double value);
	bool checkFullHouse(double* cards, double* card, double value);
	bool checkTiki(double* cards, double* card, double value);
	bool checkStraightFlush(double* cards, double* card, double value);
};

#endif
