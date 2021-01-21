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
  int it;
  for (it = 1; it < 100; ++it) {
    deleteStudent(students[it]);
    students[it] = 0;
  }

  numStudents = 0;
}


void saveStudents(int key)
{
  FILE *file;
  file = fopen("studentdata.txt", "w");
  if (file) {
    int it;
    char buff[256];
    for (it = 1; it < 100; ++it) {
      Student* st = students[it];
      sprintf(buff, "%s %s %d %ld", st->firstName, st->lastName, st->age, st->id);
      
      if (key != 0) {
        caesarEncrypt(buff, key);
      }
      
      fprintf(file, "%s\n", buff);
    }
    
    fclose(file);
  }
}


void loadStudents(int key)
{
  if (numStudents > 0) {
    deleteStudents();
  }
  
  FILE *file;
  file = fopen("studentdata.txt", "r");
  if(file) {
    char b1[256];
    char b2[256];
    char b3[256];
    char b4[256];

    int match = fscanf(file, "%s %s %s %s", b1, b2, b3, b4);
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
      sscanf(b3, "%ld", &id);

      createStudent(b1, b2, age, id);
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




