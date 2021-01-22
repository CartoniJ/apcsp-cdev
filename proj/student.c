 //
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  Student* st = (Student*)malloc(sizeof(Student));

  st->firstName = (char*)malloc((strlen(fname)+1)*sizeof(char));
  st->lastName = (char*)malloc((strlen(lname)+1)*sizeof(char));

  strcpy(st->firstName, fname);
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;

  students[numStudents] = st;
  numStudents++;
}


void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  int i;
  for (i = 0; i < numStudents; i++) {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  FILE* fp;

  fp = fopen(STUFILE, "w");
  if(fp) {
    char buff[1024];
    char b1[128];
    char b2[128];
    char b3[128];
    char b4[128];

    for (int i = 0; i < numStudents; i++) {
      Student* st = students[i];
      sprintf(b1, "%s", st->firstName);
      sprintf(b2, "%s", st->lastName);
      sprintf(b3, "%d", st->age);
      sprintf(b4, "%ld", st->id);

      if (key != 0) {
        caesarEncrypt(b1, key);
        caesarEncrypt(b2, key);
        caesarEncrypt(b3, key);
        caesarEncrypt(b4, key);
      }

      int age;
      long id;
      sscanf(b3, "%d", &age);
      sscanf(b4, "%ld", &id);

      sprintf(buff, "%s %s %d %ld", b1, b2, age, id);

      fprintf(fp, "%s\n", buff);
    }

    fclose(fp);
  }
}


void loadStudents(int key)
{
  if (numStudents > 0) {
    deleteStudents();
  }

  FILE* fp;

  fp = fopen(STUFILE, "r");
  if(fp) {
    while (1) {
      char b1[256];
      char b2[256];
      char b3[256];
      char b4[256];

      int match = fscanf(fp, "%s %s %s %s", b1, b2, b3, b4);
      if (match == 4) {
        if (key != 0) {
          caesarDecrypt(b1, key);
          caesarDecrypt(b2, key);
          caesarDecrypt(b3, key);
          caesarDecrypt(b4, key);
        }

        int age;
        long id;
        sscanf(b3, "%d", &age);
        sscanf(b4, "%ld", &id);

        createStudent(b1, b2, age, id);
      }
      else {
        fclose(fp);
        break;
      }
    }
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id);
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




