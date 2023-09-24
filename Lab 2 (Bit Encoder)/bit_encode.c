/*BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE WORK TO CREATE
THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS FILE MYSELF WITH NO ASSISTANCE
FROM ANY PERSON (OTHER THAN THE INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY
ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.*/
#include <stdio.h>
/** 
 * Author: Allen Zheng
 * This program implements an elementary bit stream cipher. It will encrypt 1 byte of plain text at a time. This one uses a given
 * 4-bit bit pattern as the key. The size of the encrypted message that we want to be able to send has a maximum length of 200
 * characters.
 */
int main(void)
{
	char input[201];
	int size = 0;
	char c;
	
	// Get cleartext input as well as input size
	#ifdef PROMPT
		printf("Please input the cleartext to be encrypted: ");
	#endif
	while ((c = getchar()) != '\n' && c != '\r' && c != EOF && size < sizeof(input)) input[size++] = c;
	#ifdef PROMPT
		printf("\nCleartext entered is: %s\n", input);
	#endif
	
	// Print char hex encodings
	#ifdef PROMPT
		printf("Hex encoding is:");
		for (int i = 0; i < size; i++) {
			if (i % 10 == 0) printf("\n");
			printf("%02x ", input[i]);
		}
		printf("\n");
	#endif
	
	// Get bit key
	unsigned char key;
	char bits[5];
	do {
		int valid = 1;
	
		#ifdef PROMPT
			printf("\nPlease enter a 4-bit key: ");
		#endif
		scanf("%4s", bits);
		
		// Check if valid key
		for (int i = 0; i < 4; i++) {
			// Invalid key if any char is not 0 or 1
			if (bits[i] != '0' && bits[i] != '1') {
				#ifdef PROMPT
					printf("Invalid key!\n");
				#endif
				valid = 0;
				
				// Clear bit key and input stream
				key = 0;
				while (getchar() != '\n');
				break;
			}
			
			// Shift left 1 bit
			key = (key << 1) | (bits[i] == '0' ? 0 : 1);
		}
		
		// Break do while if valid 4 bit key
		if (valid) {
			key = (key << 4) | key;
			break;
		}
	} while (1);
	
	// Encode input
	#ifdef PROMPT
		printf("Hex ciphertext is:");
	#endif
	for (int i = 0; i < size; i++) {
		#ifdef PROMPT
			if (i % 10 == 0) printf("\n");
		#endif
		// Encrypt using key and print it out
		printf("%02x ", input[i]^key);
	}
	printf("\n");
	
	return 0;
}

