// The playing card implementation.
//
// This is an implementation of the Card ADT, which represents a single
// playing card in the game of Final Card-Down.
//
// By ... (z0000000)
//    ... (z0000000)
// Written on 2017-09-??
// Tutor (dayHH-lab)


#include "Card.h"

// The following typedef is included in Card.h:
//         typedef struct _card *Card;
// This means that a struct card has to be implemented *somewhere*, but
// not necessarily in the .h file, as we have done with concrete types.
//
// The way we implement this in an ADT is that you design your own card
// struct, with the fields etc that you need to implement your ADT.

typedef struct _card {
    char num;
    color col;
    suit type;

} card;

// Place the prototypes for your own functions here.
// Don't forget to make them static!



// The interface functions are below. You need to implement these.

// Create a new card.
// These values can only be set at creation time.
// The number should be between 0x0 and 0xF.
Card newCard(char number, color color, suit suit) {
    Card new = calloc(1, sizeof(struct _card));
    assert(new != NULL);
    new->num = number;
    new->col = color;
    new->type = suit;
    
    return new;
}

// Destroy an existing card.
void destroyCard(Card card) {
    assert(card != NULL);
    free(card);
    return;
}

// Get the card suit (HEARTS, DIAMONDS, etc).
suit cardSuit(Card card) {
    return HEARTS; // Replace this with your own code.
}

// Get the card number (0x0 through 0xF).
char cardNumber(Card card) {
    return card->num; // Replace this with your own code.
}

// Get the card's color (RED, BLUE, etc).
color cardColor(Card card) {
    return RED; // Replace this with your own code.
}


// Implement your own functions here, don't forget to make them static!

