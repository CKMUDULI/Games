import random

youwin = 0
compwin = 0
tie = 0

def calwinner(you, comp):
    if you == comp:
        return None
    elif you == 1 and comp == 2:
        return True
    elif you == 2 and comp == 3:
        return True
    elif you == 3 and comp == 1:
        return True
    else:
        return False

def game():
    mydict = {1: "SNAKE",
              2: "WATER",
              3: "GUN"}
    global youwin
    global compwin
    global tie
    you = int(input('''Your turn...
        Choose one:
            1. Snake
            2. Water
            3. Gun
>>> '''))
    print(f"You choose {mydict[you]}")
    print("\nComputer's turn...")
    comp = random.randint(1, 3)
    print(f"Computer choose {mydict[comp]}")
    result = calwinner(you, comp)
    if result == None:
        print("\n>>> The game is a tie!\n")
        tie += 1
    elif result:
        print("\n>>> You Win!\n")
        youwin += 1
    else:
        print("\n>>> You Lose!\n")
        compwin += 1

n = int(input("How many times you want to play the game??? "))
for i in range(n):
    print(f"Game {i+1}:")
    game()
else:
    print("Game Completed...")
    print(
        f"Game Stats:\n\tYou won {youwin} times.\n\tComputer won {compwin} times.\n\tGame tied {tie} times.")
    if youwin > compwin:
        print('\nComputer : "Galti ho gayi Bhaiya..."\n')
    elif youwin < compwin:
        print('\nComputer : "Jhuk k rehna padega mere samne..."\n')
    else:
        print('\nComputer : "Jaata kaha he thaale... Ek aur match aaja."\n')