#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asmCheck(int want, char have);
int asmInc(int *n);
void countDNA(char *dna);

int asmCheck(int want, char have) {

  int t = have;      // Copy have to t

  asm (
    "cmp %1, %0\n\t" // Compare t and want
    "je true\n\t"    // Jump to true if they're equal
    "add $1, 0\n\t"  // Add 1 to t otherwise
    "true:\n\t"
    : "=r"(t)        // Set inputs for asm
    : "r"(want)
    : "cc"
  );

  if (t == have) {   // If t == have, the asm code must have eval'd to true
    return 1;
  } else {
    return 0;
  }

}

int asmInc(int *n) {

  int c = *n;         // Copy n

  asm volatile (      // Volatile is a great description for this program
    "add $1, %0\n\t"  // Literally just add one to c. Absolutely crucial
    : "=r"(c)         // Set inputs for asm
  );

  return c;

}

void countDNA(char *dna) {

  // Reserve space in memory for read/write and to prevent SIGSEGV
  int *a = 0; int *c = 0; int *g = 0; int *t = 0;
  a = (int *)malloc(sizeof(a));
  c = (int *)malloc(sizeof(c));
  g = (int *)malloc(sizeof(g));
  t = (int *)malloc(sizeof(t));

  for (int i = 0; i < strlen(dna); i++) {
    // i[dna] == dna[i] via pointer identity
    if (asmCheck('A', i[dna])) { *a = asmInc(a); }
    else if (asmCheck('C', i[dna])) { *c = asmInc(c); }
    else if (asmCheck('G', i[dna])) { *g = asmInc(g); }
    else if (asmCheck('T', i[dna])) { *t = asmInc(t); }
  }

  printf("A: %d, C: %d, G: %d, T: %d\n", *a, *c, *g, *t);

  // Malloc should be paired with free when done
  free(a); free(c); free(g); free(t);

}

// Take first commandline arguement to program and sort it
// Assumes input is an arbitrarily long string purely of A C T and G characters
// all other characters are ignored
void main(int argc, char ** argv) {

  if (argc > 1) {        // Program SIGSEGV's if no arguments are given
    countDNA(1[argv]);   // Already off to a good start
  }

}
