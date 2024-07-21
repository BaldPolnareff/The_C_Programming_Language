#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

char getword(char *word, int limit) {
  char c;
  char *w = word;

  while (isspace(c = getchar()))
    ;  // Skip whitespace

  if (c != EOF) {
    *w++ = c;
  }

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for (; --limit > 0; w++) {
    if (!isalpha(*w = getchar())) {
      ungetc(*w, stdin);
      break;
    }
  }

  *w = '\0';
  return word[0];
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
};

void freetree(struct tnode *p) {
  if (p != NULL) {
    freetree(p->left);
    freetree(p->right);
    free(p->word);
    free(p);
  }
}

struct tnode *addtree(struct tnode *p, char *w) {
  int cond;

  if (p == NULL) {
    p = talloc(); /*make a new node*/
    p->word = strdup(w);
    p->count = 1;
    p->left = NULL;
    p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }

  return p;
}

void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

int main(int argc, char *argv[])
{
  struct tnode *root;
  char curr_word[MAXWORD];
  
  root = NULL;
  while (getword(curr_word, MAXWORD) != EOF) {
    if (isalpha(curr_word[0])) {
      root = addtree(root, curr_word);
    }
  }
  treeprint(root);
  freetree(root);
  return EXIT_SUCCESS;
}
