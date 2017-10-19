#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Game.h"
#include "player.h"

#define POINT_ZERO     0
#define POINT_ONE      10
#define POINT_TWO      20
#define POINT_THREE    30
#define POINT_FOUR     40
#define POINT_FIVE     50
#define POINT_SIX      60
#define POINT_SEVEN    70
#define POINT_EIGHT    80
#define POINT_NINE     90
#define POINT_TEN      100
#define POINT_ELEVEN   110
#define POINT_TWELVE   120
#define POINT_THIRTEEN 130
#define POINT_FOURTEEN 140
#define POINT_FIFTEEN  150

#define MAX_CARDS 800

typedef struct _move {
    Card toPlay;
    Card remainingHand[MAX_CARDS];
} *Move;

int getPossibeMoves(Game game, Move possibleMoves[MAX_CARDS]);
void getRemainingHand(Game game, Move move, int card);
int determindBestMove(Game game, Move possibleMoves[MAX_CARDS], int numPossibleMoves);
int currentHandPoints(Game game);
int handPoints(Card hand[800]);
int cardPoints(Card card);

playerMove decideMove(Game game) {
    Move possibleMoves[MAX_CARDS];
    int i = 0;

    while (i < MAX_CARDS) {
        possibleMoves[i] = NULL;
        i++;
    }

    // Get all legal moves
    int numLegalMoves = getPossibeMoves(game, possibleMoves);

    playerMove theMove;

    // Check if there are any legal moves, if not, try to draw a card
    if (numLegalMoves == 0) {
        theMove.action = END_TURN;
        // If end turn is not legal, then draw a card
        if (!isValidMove(game, theMove)) {
            theMove.action = DRAW_CARD;
        }
    } else {
        // We can play a card, determind which one to play
        int bestMoveIndex = determindBestMove(game, possibleMoves, numLegalMoves);
        theMove.action = PLAY_CARD;
        theMove.card = possibleMoves[bestMoveIndex]->toPlay;
    }

    return theMove;
}

// Populate the possibleMoves array with a list of legal moves
// Return the number of legal moves
int getPossibeMoves(Game game, Move possibleMoves[MAX_CARDS]) {
    playerMove tempMove;
    tempMove.action = PLAY_CARD;
    int legalMoveNum = 0;

    int numCards = handCardCount(game);
    int i = 0;

    while (i < numCards) {
        tempMove.card = handCard(game, i);
        if (isValidMove(game, tempMove)) {
            possibleMoves[legalMoveNum] = calloc(1, sizeof(struct _move));
            possibleMoves[legalMoveNum]->toPlay = tempMove.card;
            getRemainingHand(game, possibleMoves[legalMoveNum], i);
            legalMoveNum++;
        }
        i++;
    }

    return legalMoveNum;
}

// Copy current hand to a move without the card that is to be played
void getRemainingHand(Game game, Move move, int card) {
    int numCards = handCardCount(game);
    int fromIndex = 0;
    int toIndex = 0;

    while (fromIndex < numCards) {
        if (fromIndex != card) {
            move->remainingHand[toIndex] = handCard(game, fromIndex);
            toIndex++;
        }
        fromIndex++;
    }

    move->remainingHand[toIndex] == NULL;
}

// From all possible moves, find the best one
int determindBestMove(Game game, Move possibleMoves[MAX_CARDS], int numPossibleMoves) {
    int i = 0;
    int possibleHandPoints[MAX_CARDS] = {0};

    while (i < numPossibleMoves) {
        possibleHandPoints[i] = handPoints(possibleMoves[i]->remainingHand);
        i++;
    }
    i = 0;

    int bestMoveIndex = 0;
    int bestMovePoint = possibleHandPoints[0];

    while (i < numPossibleMoves) {
        if (bestMovePoint > possibleHandPoints[i]) {
            bestMovePoint = possibleHandPoints[i];
            bestMoveIndex = i;
        }
        i++;
    }

    return bestMoveIndex;
}

// Calculate the points of the current hand
int currentHandPoints(Game game) {
    int numCards = handCardCount(game);
    int i = 0;
    int points = 0;

    while (i < numCards) {
        Card cur = handCard(game, i);
        points += cardPoints(cur);
        i++;
    }

    return points;
}

// Calculate the point of the given hand
int handPoints(Card hand[800]) {
    int i = 0;
    int points = 0;

    while (hand[i] != NULL) {
        points += cardPoints(hand[i]);
        i++;
    }

    return points;
}


// Find the point of a card
int cardPoints(Card card) {
    int points = 0;

    if (cardValue(card) == ONE) {
        points = POINT_ONE;
    } else if (cardValue(card) == DRAW_TWO) {
        points = POINT_TWO;
    } else if (cardValue(card) == THREE) {
        points = POINT_THREE;
    } else if (cardValue(card) == FOUR) {
        points = POINT_FOUR;
    } else if (cardValue(card) == FIVE) {
        points = POINT_FIVE;
    } else if (cardValue(card) == SIX) {
        points = POINT_SIX;
    } else if (cardValue(card) == SEVEN) {
        points = POINT_SEVEN;
    } else if (cardValue(card) == EIGHT) {
        points = POINT_EIGHT;
    } else if (cardValue(card) == NINE) {
        points = POINT_NINE;
    } else if (cardValue(card) == ADVANCE) {
        points = POINT_TEN;
    } else if (cardValue(card) == BACKWARDS) {
        points = POINT_ELEVEN;
    } else if (cardValue(card) == CONTINUE) {
        points = POINT_TWELVE;
    } else if (cardValue(card) == DECLARE) {
        points = POINT_THIRTEEN;
    } else if (cardValue(card) == E) {
        points = POINT_FOURTEEN;
    } else if (cardValue(card) == F) {
        points = POINT_FIFTEEN;
    }

    return points;
}
