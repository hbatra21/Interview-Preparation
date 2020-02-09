class Solution {
public:
    double angleClock(int hour, int minutes) {
		double min_angle = (double)minutes * 6;
	double hr_angle = (double)hour * 30 + (double)minutes / 2;
	return min(abs(min_angle - hr_angle), 360 - abs(min_angle - hr_angle));
	}
};
