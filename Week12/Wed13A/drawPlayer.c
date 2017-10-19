
playerMove decideMove(Game game) {

    // Start out by making a move struct, to say what our move is.
    playerMove move;

    // Set our move to be END_TURN, and check whether that's
    // a valid move -- if it is, then just end our turn (for now).
    move.action = END_TURN;

    // If it's not valid to end turn, we must need to make
    // some other action...
    //
    // What actions are valid at this point?
    if (!isValidMove(move)) {
        move.action = DRAW_CARD;
    }

    return move;
}
