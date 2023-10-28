#include "../lab4.h"

float calcCumulative(float score1, float score2, float score3, int isFinal) {
	float validCount = 0;
	float sum = 0;
	
	// Get valid scores (not -1)
	if (score1 != -1) {
		sum += score1;
		validCount++;
	}
	if (score2 != -1) {
		sum += score2;
		validCount++;
	}
	if (score3 != -1) {
		sum += score3;
		validCount++;
	}
	
	// If final, set all -1 to 0
	if (isFinal) validCount = 3;
	
	// Prevent divide by 0
	if (validCount == 0) return -1;
	
	// Return average of valid grades
	return (sum / validCount);
}

