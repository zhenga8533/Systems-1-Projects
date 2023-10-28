#ifndef LAB4_HEADER
#define LAB4_HEADER

// Structure definitions
struct CatGrade {
	float score1;
	float score2;
	float score3;
	float cumulative;
};

struct Data {
	char studentName[40];
	int studentID;
	struct CatGrade Cat1;
	struct CatGrade Cat2;
	struct CatGrade Cat3;
	struct CatGrade Cat4;
	float currentGrade;
	float finalGrade;
};

typedef struct Node {
	struct Data Student;
	struct Node *next;
} Node;

// Functions to format data
void printHeader(char *Category_Names[4]);
void printLine(struct Data StudentData);

// Functions for node, linked list, and file manipulation
Node *findID(Node *head, int studentID);
Node *populateNode(struct Data StudentData);
void insertNode(Node **head, struct Data studentData);
void freeMemory(Node *head);

// The ten user options
void requestID(char *categories[4], Node *head);
void requestName(char *categories[4], Node *head);
void printScores(char *categories[4], Node *head);
void recalcID(char *categories[4], Node *head);
void recalcScores(char *categories[4], Node *head);
void scoreID(char *categories[4], Node *head);
void calcFinals(char *categories[4], Node *head);
void addStudent(char *categories[4], Node *head);
void deleteNode(Node **head);
void writeData(Node *head, char *outputFile, char *title);

// Functions to help with calculations
float calcCumulative(float score1, float score2, float score3, int isFinal);
float calcFinal(float cum1, float cum2, float cum3, float cum4, int isFinal);
void recalcScore(Node *body);

#endif
