import random

board = {1: ' ',2: ' ',3: ' ',4: ' ',5: ' ',6: ' ',7: ' ',8: ' ',9: ' '}
#list = [1,2,3,4]
def printBoard():
    print(board[1]+ "  |  " + board[2] + "  |  " + board[3])
    print("\n")
    print(board[4]+ "  |  " + board[5] + "  |  " + board[6])
    print("\n")
    print(board[7]+ "  |  " + board[8] + "  |  " + board[9])
    print("\n")
    return



user = 'O'
computer = 'X'

def checkWin(player):
    if board[1] == player and board[2] == player and board[3] == player:
        return True
    if board[4] == player and board[5] == player and board[6] == player:
        return True
    if board[7] == player and board[8] == player and board[9] == player:
        return True
    if board[1] == player and board[4] == player and board[7] == player:
        return True
    if board[2] == player and board[5] == player and board[8] == player:
        return True
    if board[3] == player and board[6] == player and board[9] == player:
        return True
    if board[1] == player and board[5] == player and board[9] == player:
        return True
    if board[3] == player and board[5] == player and board[7] == player:
        return True
    
    return False
    
def checkDraw():
    for block in board:
        if block == ' ':
            return False

    return True


def userTurn(player):
    index = int(input("Enter your choice for " + player + " : "))
    if(board[index] == ' '):   
        board[index] = player
    else:
        print("ReEnter : ")
        userTurn(player)
    
    
def compTurn(player):
    compMove = random.randint(1,9)
    if(board[compMove] != ' '):
        compTurn (player)
    else:
        board[compMove] = player    
    return 


def mainish():
    for i in range(9):
        
        if i%2 == 0:
            compTurn('X')
            printBoard()
            if checkWin('X'):
                printBoard()
                print("Computer won!!!!")
                return
                
        else :
            userTurn('O')
           
            if checkWin('O'):
                printBoard()
                print("you won!!!!")
                return
                
        
    if checkDraw():
        print("Draw")
    return
mainish()
