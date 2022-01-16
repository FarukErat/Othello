# Othello/Reversi (UNSTABLE)
A Simple Othello Game
This game is playable against cpu. However, cpu makes completely random moves.

-----------------------HOW TO PLAY-------------------------------------

There is two sides which are black, which makes move the first, and white.
The game begins with four disks placed in a square in the middle of the grid with the same-colored disks on a diagonal.
Convention has this such that the dark-side-up disks are to the north-east and south-west (from both players' perspectives).
Dark must place a piece (dark-side-up) on the board and so that there exists at least one straight (horizontal, vertical, or diagonal) occupied line between the new piece and another dark piece, with one or more contiguous light pieces between them.
Play always alternates. After placing a dark disk, dark turns over (flips to dark, captures) the single disk (or chain of light disks) on the line between the new piece and an anchoring dark piece.
A valid move is one where at least one piece is reversed (flipped over).
Players take alternate turns. If one player can not make a valid move, play passes back to the other player. When neither player can move, the game ends.
This occurs when the grid has filled up or when neither player can legally place a piece in any of the remaining squares.
This means the game may end before the grid is completely filled.
The player with the most pieces on the board at the end of the game wins.

Here are some links to check out the rules better.

https://en.wikipedia.org/wiki/Reversi#Rules

https://www.worldothello.org/about/about-othello/othello-rules/official-rules/english


------------------------------BUGS------------------------------

1) It ends the game, even though the game is not over. (generally)
2) The turn does not change, even when supposed to. (a bit often)
3) It flips some illegal tiles. (rarely)


-----------------------------NEEDED-----------------------------

The biggest drawback of this program is GUI.
It is played over terminal.
