# Competitive Minesweeper #
## Jackie Li, Lynne Wang, Tiffany Zhong (Pd 5) ##

## Project Description ##
Competitive Minesweeper is a twist on the classic minesweeper game. Clients will compete with other clients to get the highest score in one session. Clients' scores are passed back to the server, and the winner receives a message of congratulations. Clients can play in different terminal windows.

## Running the Server ##
1. Clone the repo using the following link:
`https://github.com/ennylgnaw/SystemsFinalProj.git`
2. Run `make`
3. To run the server, use `./server`
4. To connect as a client with the test ip, use `./client` in another terminal window
5. Otherwise, use `./client server-address`

## User Interaction ##
- The user will first see an empty minesweeper board
- They will have to enter in the coordinates (row, column, separated by a space), when prompted. This will open up that space, and perhaps other empty ones.
- Symbols: `-` is an empty space, `*` is a mine, and numbers indicate how many mines the space is surrounded by
- Opening up a space with a mine will cost you many points, whereas opening up safe spaces will earn you points
- The game ends when everyone has finished their game, and scores will be calculated