#include <stdio.h>
#include <stdlib.h>

typedef int age;
typedef char *name;

struct studentInfo {
	age *studentAges;
	name *studentNames;
	int size;
};

typedef struct studentInfo StudentInfo;

void incrementAges(StudentInfo si);
void printStudents(StudentInfo si);
//void incrementAges(age *studentAges, int size);
//void printStudents(name *studentNames, age *studentAges, int size);

int main(int argc, char* argv[]) {
	
	StudentInfo class;

	class.size = 6;
	class.studentNames = (name*)malloc(sizeof(name*) * class.size);
	class.studentAges = (age*)malloc(sizeof(age*) * class.size);

	class.studentNames[0] = "Frank";
	class.studentNames[1] = "Moni";
	class.studentNames[2] = "Jimmy";
	class.studentNames[3] = "Chen";
	class.studentNames[4] = "Navim";
	class.studentNames[5] = "Faraq";

	class.studentAges[0] = 18;
	class.studentAges[1] = 19;
	class.studentAges[2] = 20;
	class.studentAges[3] = 19;
	class.studentAges[4] = 18;
	class.studentAges[5] = 19;

	// Increment their ages because we want to increase their age
	incrementAges(class);
	printStudents(class);

	free(class.studentNames);
	free(class.studentAges);
	class.studentNames = NULL;
	class.studentAges = NULL;

	return 0;
}

void incrementAges(StudentInfo si) {
	int i = 0;
	while (i < si.size) {
		si.studentAges[i] = si.studentAges[i] + 1;
		i++;
	}
}

void printStudents(StudentInfo si) {
	int i = 0;
	while (i < si.size) {
		printf("Student %s is of age %d\n", si.studentNames[i], si.studentAges[i]);
		i++;
	}
}
