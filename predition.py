
def Investments():
    bonds = 8
    stocks = 2
    realState = 6

    invest = float(input("How much money do you have to invest?\n"))

    profitB = (bonds/100)*invest
    profitS = (stocks/100)*invest
    profitRS = (realState/100)*invest

    print("the possible profits that you can obtain with the most common investments are:\nBonds: $ " + str(profitB) + "\nStocks: $ " + str(profitS) + "\nReal State: $ " + str(profitRS))


def Savings():
    save = float(input("How much money do you want to allocate to this savings fund?\n"))
    spend = float(input("What is your goal of this savings fund?\n"))

    goalTime = spend/save

    print("You need to allocate the same amount of money every month to this saving fund to achieve your goal in " + str(goalTime) + " monts")


Investments()
Savings()