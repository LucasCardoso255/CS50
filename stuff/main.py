import os

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def oldHag():
    player = 'X' 
    while True:
        clear()
        print(f" {matriz[0][0]} | {matriz[0][1]} | {matriz[0][2]} \n"
              "___|___|___ \n"
              f" {matriz[1][0]} | {matriz[1][1]} | {matriz[1][2]} \n"
              "___|___|___\n"
              f" {matriz[2][0]} | {matriz[2][1]} | {matriz[2][2]} \n"
              "   |   |   ")

        if winner_check() == 1:
            print(f"pode parar, que já foi gg")
            break

        try:
            print(f"\nVez do {player}")
            linha = int(input("linha de 1 a 3: ")) - 1
            coluna = int(input("coluna de 1 a 3: ")) - 1

            if matriz[linha][coluna] != ' ':
                print("Já tem coisa ali, n ta vendo?")
                input("pressione enter pra continuar")
                continue

            matriz[linha][coluna] = player

            player = 'O' if player == 'X' else 'X'

        except ValueError:
            print("\nCaractere inválido")
            input("pressione enter pra continuar")
        except IndexError:
            print("\nApenas números de 1 a 3!")
            input("pressione enter pra continuar")

def winner_check():
    for array in matriz:
        if array[0] == array[1] == array[2] != ' ':
            return 1
        
    for i in range(3):
        if matriz[0][i] == matriz[1][i] == matriz[2][i] != ' ':
            return 1
    
    if matriz[0][0] == matriz[1][1] == matriz[2][2] != ' ':
        return 1
    if matriz[0][2] == matriz[1][1] == matriz[2][0] != ' ':
        return 1

matriz = [[' ' for _ in range(3)] for _ in range(3)]

oldHag()
