import sys 

board = {
    1: ' ', 2: ' ', 3: ' ',
    4: ' ', 5: ' ', 6: ' ',
    7: ' ', 8: ' ', 9: ' ',
}
player = 'X'
spots_taken = 0


def print_winner(player):
    print("{} is the winner, congratulations!".format(player))
    sys.exit()


def print_welcome():
    print("\n\nWelcome to Tic-Tac-Toe \n\nWhen selecting a spot, please insert the spot number. \nGood Luck!\n")


def print_board():
    print(board[1] + '|' + board[2] + '|' + board[3] + "   1 2 3")
    print("-+-+-")
    print(board[4] + '|' + board[5] + '|' + board[6] + "   4 5 6")
    print("-+-+-")
    print(board[7] + '|' + board[8] + '|' + board[9] + "   7 8 9")
    print('\n')


def check_winner(board, player):
    for i in range (1, 10, 3): #rows
        if(board[i] != ' ' and (board[i] == board[i+1] == board[i+2])):
            print_winner(player)

    for i in range (1, 4): #columns
        if(board[i] != ' ' and (board[i] == board[i+3] == board[i+6])):
            print_winner(player)
    
    if((board[1] != ' ' and (board[1] == board[5] == board[9])) or #diagonal
       (board[3] != ' ' and (board[3] == board[5] == board[7]))):
        print_winner(player)
        

def select_position(board, player, spots_taken):
    for _ in range(1, 10):
        print('It is {} turn, please select a spot.'.format(player))
        position = int(input())
        print('\n')
        if(board[position] ==  ' '):
            board[position] = player
            print_board()

        check_winner(board, player)
        player = 'O' if player == 'X' else 'X'
        spots_taken += 1
        if(spots_taken >= 9):
            print("It is a tie, a good game from both of you!")



if __name__  == "__main__":
    print_welcome()
    print_board()
    select_position(board, player, spots_taken)