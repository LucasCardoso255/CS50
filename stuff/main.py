import os

matriz = [
        [' ',' ','ㅤ'],
        [' ',' ','ㅤ'],
        [' ',' ','ㅤ']
]

def clear():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def oldHag():
    while True:
        clear()
        print(f" {matriz[0][0]} | {matriz[0][1]} | {matriz[0][2]} \n"
        "___|___|___ \n" \
        f" {matriz[1][0]} | {matriz[1][1]} | {matriz[1][2]} \n" \
        "___|___|___\n" \
        f" {matriz[2][0]} | {matriz[2][1]} | {matriz[2][2]} \n" \
        "   |   |   ")

        if winner_check() == 1:
            print(f"pode parar, que já foi gg")
            break
        
        try:
            linha_x = int(input("linha de 1 a 3: "))
            linha_x = linha_x - 1
            coluna_x = int(input("coluna de 1 a 3: "))
            coluna_x = coluna_x - 1
            matriz[linha_x][coluna_x] = "X"
        except ValueError:
            print("\nCaractere inválido")
            input("pressione enter para prosseguir")
        except IndexError:
            print("\nApenas números de 1 a 3!")
            input("pressione enter para prosseguir")

def winner_check():
    for linha in matriz:
        if linha[0] == linha[1] and linha[0] == linha[2] != ' ':
            return 1
 
oldHag()
