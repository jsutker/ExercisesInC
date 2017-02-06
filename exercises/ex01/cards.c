// Joe Sutker
// Refactoring of cards.c from Head First C

#include <stdio.h>
#include <stdlib.h>

int evaluate(char card_name[3]) {
  // Given the card name as a char array, returns a value
  int val = 0;
  switch(card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    val = 10;
    return val;
  case 'A':
    val = 11;
    return val;
  case 'X':
    return val;
  default:
    val = atoi(card_name);
    if ((val < 1) || (val > 10)) {
      puts("I don't understand that value!");
    }
  return val;
  }
}

int change_count(int count, int val) {
  // Given the current count and the card value,
  // decides what the new count should be
  if ((val > 2) && (val < 7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
  return count;
}

int main() {
  char card_name[3];
  int count = 0;
  int val = 0;
  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    val = evaluate(card_name);
    count = change_count(count, val);
    printf("Current count: %i\n", count);
  }
  return 0;
}