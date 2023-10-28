#include "../lab4.h"

float calcFinal(float cum1, float cum2, float cum3, float cum4, int isFinal) {
	float sum = 0;
	
	// Get valid scores (not -1) and use weight for category cumulatives
	if (cum1 != -1) sum += cum1 * 0.15;
	else if (!isFinal) sum += 0.15;
	
	if (cum2 != -1) sum += cum2 * 0.30;
	else if (!isFinal) sum += 0.30;
	
	if (cum3 != -1) sum += cum3 * 0.20;
	else if (!isFinal) sum += 0.20;
	
	if (cum4 != -1) sum += cum4 * 0.35;
	else if (!isFinal) sum += 0.35;
	
	// Return current grade with weights
	return sum;
}

