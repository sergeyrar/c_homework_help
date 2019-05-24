#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

typedef struct {
	char name[LEN];
	int grade;
} Student;

/* Functions prototypes */

Student **createArrayPointersToStudents(unsigned n);
void getStudentsFromUser(Student* p[], unsigned n);
void sorting( Student **name , int n);
char **createArrayPointersToNames(Student **name , int nex);
Student **getMostExcellentStudent( Student **s, int numStudent);
char** binaryList( char **name, char **mark, int h);
void sortNames( Student **name, int nex);
void getStudentsFromUser(Student* p[], unsigned n);
void printArrayStudents(Student **A, unsigned n);
void printExArrayStudents(char **eStudents, unsigned nex);
void printNewStudents(Student **str,char* p[],unsigned n);
void freeAlloc(void *p);
void removeNewLine(char *s);
void freeAllocations(Student **ptrStudents, int n);
char  **getExcellentStudentsFromUser(unsigned nex);
void clean();
static int read_user_selection();
//void mostExcellentStudent(Student **p, int *n, Student **toFire);

unsigned nex;

int main() {
	int numStudent;
	printf("Please enter how many students do you have in the software department: ");
	scanf("%d", &numStudent);
	printf("\nPlease enter how many excellent students do you have from the whole college: ");
	scanf("%d", &nex);

	Student **ptrStudents =(Student **) createArrayPointersToStudents(numStudent);
	char **names = (char **) createArrayPointersToNames(ptrStudents , numStudent);
	char **exStudents =(char **) getExcellentStudentsFromUser(nex);

	char selection;
	int choice;
        
            while(1)
            {
		// Displays all options
		printf("\n\n\nPlease choose one of the following options\n");
		printf("1 - Print all students from software dep\n");
		printf("2 - Print the college excellent students:\n");
		printf("3 - Sort the students from software dep. by name: \n");
		printf("4 -Search and print excellent students from software dep:\n");
		printf("5 -  Create and print a new array consists of excellent students from software \n");
		printf("E/e - Exit this program\n");
		printf("\n==================\n\n\n");
                
                
                switch (selection = read_user_selection())
                {
                    case '1':
                        printArrayStudents(ptrStudents, numStudent);
                        break;
                    
                    case '2':
                        printExArrayStudents(exStudents, nex);
                        break;
                    
                    case '3':
                        sortNames(ptrStudents , numStudent);
                        printArrayStudents(ptrStudents, numStudent);//sortNames(names, nex);
                        break;
                    
                    case'4':
                        printExArrayStudents(binaryList(names, exStudents, numStudent), nex);
                        break; 

                    case '5':
                        printNewStudents(ptrStudents,binaryList(names, exStudents, numStudent),numStudent);
                        break;

                    case 'e':
                    case 'E':
                        printf("This program will end now. goodbye.");
                        exit(0);
                        break;

                    default:
                        printf("\nWrong input number. try again:");
                        break;
                }	
            }

	return 0;
}

static int read_user_selection()
{
    int selection = getchar();
    if (getchar() == '\n')
        return selection;
}
void printNewStudents(Student **str,char* p[],unsigned n)
{
	int l = 0, i = 0;

	while (l < n) {
		int mid = (l + n) / 2;
		//char str1[LEN] = (char)str[i]->name;
		if (strcmp(p[mid], str[i]->name) == 0) {
			printf("\n%s\t%d",str[i]->name , str[i]->grade);
			i++; l = 0;

		}
		if (strcmp(p[mid], str[i]->name) < 0) {
			l = mid - 1;
		} else {
			l = mid + 1;
		}
	}
}


Student **createArrayPointersToStudents(unsigned n) {
   // printf("createArrayPointersToStudents start");
char tmp[LEN];
int grade , i;
Student **s = (Student**) malloc(n * sizeof(Student*));
if (s == NULL) {
	printf("\nNot enough memory...");
	exit(1);
}
for ( i = 0; i < n; i++) {
	printf("\n Please insert name for student #%d:", i);
	clean();
	fgets(tmp, LEN, stdin);
	removeNewLine(tmp);
	printf("\n Please insert grade for student #%d:", i);
	scanf("%d", &grade);
	s[i] = (Student*) malloc(1 * sizeof(Student));
	if (s[i] == NULL) {
		printf("\nNot enough memory...");
		exit(2);
	}
	strcpy(s[i]->name, tmp);
	s[i]->grade = grade;
}
 //printf("createArrayPointersToStudents start");
return s;
}

void getStudentsFromUser(Student* p[], unsigned n) {
// const Student **tmp[n];
int i ;
Student **p1 = (Student**) malloc(n * sizeof(Student*));
for (i = 0; i < n; i++, p1++)
	p1[i] = p[i]; //*p
for (i = 0; i < n; i++) {
	if (!(p1[i]->grade >= 0 && p1[i]->grade <= 100)) {
		printf("Enter grade of student name = %s", p1[i]->name);
		scanf("%d", &p1[i]->grade);
	}
}
}

char **createArrayPointersToNames(Student **name , int nex) {
    int i;
    printf("createArrayPointersToNames start");
char **Names = (char **) malloc((nex) * sizeof(char *) * LEN); //if not work delete red
	for (i = 0; i < nex; i++) {
        Names[i] = strdup(name[i]->name);
	}printf("createArrayPointersToNames end");
return Names; // & //NAMES[i]
}

char **getExcellentStudentsFromUser(unsigned nex) 
{
    int i;
    char recv_buf[LEN];
    char **Names = (char **) malloc((nex) * sizeof(char*));
    for ( i = 0; i < nex; i++) {
	    printf("Please insert name of excellent student: # %d", (i + 1));
	    scanf("\n %s",recv_buf);
	    Names[i] = strdup(recv_buf);
    }

    return Names;
}

/*Char **getExcellentStudentsFromUser(int *num){
 int num;
 char **arr = malloc(sizeof(char *) * num);
 *ret_num = num;
 return arr;
 }
 */

char** binaryList(char **name, char **mark, int h)

{
char **ename;
int l = 0, i = 0;
//sortNames(name, nex); // my fix (: add argument nex
while (l < h) {

	int mid = (l + h) / 2;
	if (strcmp(name[mid], mark[i]) == 0) {
		strcpy(ename[i], name[mid]);
		i++; l = 0;
	}
	if (strcmp(name[mid], mark[i]) < 0) {
		l = mid - 1;
	} else {
		l = mid + 1;
	}
}
return ename;
}

void sortNames(Student **name, int nex){
printf("sortNames start");
Student **Names12 = (Student**) malloc(nex * sizeof(Student*));
//char Names12[nex][LEN] ;//= (char) malloc((nex) * sizeof(char) * LEN);
printf("sortNames start1..");
Student *temp = (Student*) malloc(nex * sizeof(Student));//  = (char *) malloc((nex) * sizeof(char) * LEN);printf("sortNames start2..");
int i, j;

for (i = 0; i < nex; i++)
	strcpy(Names12[i]->name, name[i]->name);printf("sortNames 1");
	
for(i = 0; i < nex; i++)
    printf("\n%s",Names12[i]->name);
    
for (i = 0; i < nex - 1; i++)
	for (j = 0; j < nex - i - 1; j++) {printf("sortNames 2");
		if (strcmp(Names12[i]->name, Names12[j]->name) > 0) {
			strcpy(temp->name, Names12[i]->name);
			strcpy(Names12[i]->name, Names12[j]->name);
			strcpy(Names12[j]->name, temp->name);
		}
	}printf("sortNames end");
/*printf("Order of Sorted Strings:");
for (i = 0; i <= nex; i++)
	puts(Names[i]);
*/
}

void printArrayStudents(Student **students, unsigned n) {
    int i;
for ( i = 0; i < n; i++)
	printf("\n %s %d", students[i]->name, students[i]->grade);
}
void printExArrayStudents(char **eStudents, unsigned nex){
    int i;
    for(i = 0 ; i < nex ; i++)
        printf("\n%s",eStudents[i]);

}
//Student **getMostExcellentStudent(const Student **p, int n) {
//	const Student **tmp = p;
//	for (int i = 1; i < n; i++) {
//		if (p[i]->grade > (*tmp)->grade) {
//			tmp = p + i;
//		}
//	}
//	return (Student**) tmp;
//}
//
//void mostExcellentStudent(Student **p, int *n, Student **toFire) {
//	Student *tmp = (*toFire);
//	// Free the Student
//	free(tmp);
//	// Update the pointer to point now to the last Student
//	*toFire = p[*n - 1];
//	// Decreasing the total amount of Students in the array
//	--*n;
//	// Deletes the last pointer from the array of pointers by using realloc
//	p = realloc(p, *n * sizeof(Student *));
//}

void removeNewLine(char *s) {
char *p;
if ((p = strchr(s, '\n')) != NULL)
	*p = 0;
}

void freeAlloc(void *p) {
free(p);
}

void freeAllocations(Student **ptrStudents, int numStudent) {
    int i;
for ( i = 0; i < numStudent; i++)
	freeAlloc(ptrStudents[i]);
if (numStudent > 0)
	free(ptrStudents);
}

void clean() {
char c;
do {
	c = getchar();
} while (c != '\n');
}
