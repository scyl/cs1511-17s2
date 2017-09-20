// Comments

#include <stdio.h>
#include <stdlib.h>
#include "Card.h"

int main(int argc, char *argv[]) {

    Card card1 = newCard(3, GREEN, DIAMONDS);
    assert(cardSuit(card1) == DIAMONDS);

    return EXIT_SUCCESS;
}
