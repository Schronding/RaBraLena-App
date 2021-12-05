# Luhn Algorithm

Identificador = {"AmericanExpress": 3, "Visa": 4, "MasterCard": 5, "Discover": 6}

ArregloTarjeta = [4, 7, 4, 1, 7, 5, 1, 7, 1, 7, 2, 2, 8, 8, 9, 8]
ArregloTarjeta2 = [3, 3, 7, 9, 5, 1, 3, 5, 6, 1, 1, 0, 8, 7, 9, 5]
ArregloTarjeta3 = [4, 8, 4, 7, 3, 5, 2, 9, 8, 9, 2, 6, 3, 0, 9, 4]

ArregloLuhn = []
for number in range(1, 17):
    if number % 2 != 0:
        ArregloLuhn.append(2)
    else:
        ArregloLuhn.append(1)
print(ArregloLuhn)

def LuhnAlgorithm(tarjeta):
    ArregloSuma = []
    total = 0
    i = 0
    bancoEmisor = ""
    if tarjeta[0] == 3: bancoEmisor = "American Express"
    elif tarjeta[0] == 4: bancoEmisor = "Visa"
    elif tarjeta[0] == 5: bancoEmisor = "Master Card"
    elif tarjeta[0] == 6: bancoEmisor = "Discovery"
    elif tarjeta[0] != 3 or 4 or 5 or 6: bancoEmisor = "Issuing bank not identified"

    for digit in tarjeta:
        if tarjeta[i] * ArregloLuhn[i] >= 10:
            masDe10 = tarjeta[i] * ArregloLuhn[i]
            masDeDiez = str(masDe10)
            numOne = masDeDiez[0]
            numTwo = masDeDiez[1]
            num1 = int(numOne)
            num2 = int(numTwo)
            suma = num1 + num2
            ArregloSuma.append(suma)
            i += 1
        else:
            suma = tarjeta[i] * ArregloLuhn[i]
            ArregloSuma.append(suma)
            i += 1
    print(ArregloSuma)
    j = 0
    for suma in ArregloSuma:
        total += ArregloSuma[j]
        j += 1
    if total % 10 == 0:
        print("Your " + bancoEmisor + " credit card is valid")
    elif (len(tarjeta) != 15 or 16) or tarjeta[0] != 3 or 4 or 5 or 6:
        print("Your card is invalid")

    return total

print(LuhnAlgorithm(ArregloTarjeta))
print(LuhnAlgorithm(ArregloTarjeta2))
print(LuhnAlgorithm(ArregloTarjeta3))
