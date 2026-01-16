import subprocess
import os
import shutil
from pyshortcuts import make_shortcut

def zagolovok_okna(nazvanie_okna):
    os.system(f"title {nazvanie_okna}")

zagolovok_okna("UnSa")

ic = os.path.join(os.getcwd(), 'icon.ico')

while True:
    print("Добро пожаловать в UnSa! Программа для редактирования файла сохранения Undertale.")
    print("\n" + "="*40)
    print("Основные данные - 1. Инвентарь - 2. Персонажи - 3. Настройки - 4. Файлы сохранения - 5.")

    save_papka = os.path.join(os.getenv('LOCALAPPDATA'), 'UNDERTALE')
    save = os.path.join(save_papka, 'file0')
    save2 = os.path.join(save_papka, 'file9')
    save3 = os.path.join(save_papka, 'file8')
    save4 = os.path.join(save_papka, 'undertale.ini')
    ll = False

    def i_hate_python(stroka, znachenie):
        try:
            with open(save, "r", encoding="utf-8") as f:
                linii = f.readlines()


            while len(linii) <= stroka:
                linii.append("\n")

            linii[stroka] = f"{znachenie}\n"

            with open(save, "w", encoding="utf-8") as f:
                f.writelines(linii)
        finally:
            print("Файл сохранения был перезаписан")


    if not os.path.exists(save_papka):
        print("У вас нету паки сохранения Undertale!")
        exit()

    rezhim = input("Выберите и введите номер команды:")

    if rezhim=="1":
        print("Изменить имя упавшего - 11. Изменить уровень - 12. Изменить количество здоровья - 13. Изменить максимальное количество здоровья - 14. Атака - 15. Значение атаки у оружия - 16. Значение защиты - 17. Значение защиты от брони - 18. Номер комнаты, в которой находится человек - 19. Количество золота - 21. Количество убитых монстров - 22. Экипированное оружие - 23. Экипированная броня - 24. Количество проведенного в игре времени - 25.")

        osnova = input("Выберите действие:")

        if osnova=="11":
            nick = input("Введите имя упавшего человека:")

            i_hate_python(0, nick)

        elif osnova=="12":

            while True:

                oz = input("Введите значение уровня:")

                if oz in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"]:
                    i_hate_python(1, oz)
                else:
                    print("Число должно быть меньше или равно 20!")

        elif osnova=="13":

            kolzdo = input("Введите количество здоровья:")

            while True:

                if kolzdo in [ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111" ]:
                    i_hate_python(2, kolzdo)
                    break
                else:
                    print("Число должно быть меньше или равно 111!")

        elif osnova=="14":

            maxkolzdo = input("Введите максимальное количество здоровья:")

            while True:

                if maxkolzdo in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
                                 "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
                                 "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44",
                                 "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58",
                                 "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72",
                                 "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86",
                                 "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"]:
                    i_hate_python(2, maxkolzdo)
                    break
                else:
                    print("Число должно быть меньше или равно 99!")

        elif osnova=="15":

            Attacka = input("Введите значение атаки:")

            while True:

                if Attacka in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
                                 "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
                                 "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44",
                                 "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58",
                                 "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72",
                                 "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86",
                                 "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99",]:
                    i_hate_python(3, Attacka)
                    break
                else:
                    print("Число должно быть меньше или равно 99!")

        elif osnova=="16":

            Attor = input("Введите значение атаки у оружия, которым снаряжен человек:")

            while True:

                if Attor in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]:
                    i_hate_python(4, Attor)
                    break
                else:
                    print("Число должно быть меньше или равно 15!")

        elif osnova=="17":

            zasita = input("Введите значение защиты:")

            while True:

                if zasita in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]:
                    i_hate_python(6, zasita)
                    break
                else:
                    print("Число должно быть меньше или равно 15!")

        elif osnova=="18":
            zasbro = input("Введите значение защиты от брони:")

            while True:

                if zasbro in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]:
                    i_hate_python(4, zasbro)
                    break
                else:
                    print("Число должно быть меньше или равно 15!")

        elif osnova=="19":
            print("Показать - 1. Не показывать - 2")

            vibor4ik = input("Вы хотите прочитать список, где расписаны комнаты и их ID?:")

            if vibor4ik == "1":
                subprocess.Popen(["notepad.exe", "Room - ID.txt"])
            else:

                room = input("Введите номер комнаты:")

                while True:

                    if room in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]:
                        i_hate_python(547, room)
                        break
                    else:
                        print("Комнаты с таким ID и сохранением нету!")

        elif osnova=="21":
            zoloto = input("Введите желаемое количество золота:")

            while True:

                if zoloto in [str(i) for i in range(1, 10000)]:
                    i_hate_python(11, zoloto)
                    break
                else:
                    print("Число должно быть меньше или равно 9999!")

        elif osnova=="22":
            ybistva = input("Введите количество убитых человеком монстров:")

            while True:

                if ybistva in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]:
                    i_hate_python(4, ybistva)
                    break
                else:
                    print("Перезаписано!")
                    break

        elif osnova=="23":

            EkOr = input("Введите ID предмета, который будет использоваться в качестве оружия:")

            while True:

                if EkOr in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
                                 "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
                                 "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44",
                                 "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58",
                                 "59", "60", "61", "62", "63", "64"]:
                    i_hate_python(28, EkOr)
                    break
                else:
                    print("Число должно быть меньше или равно 64!")

        elif osnova=="24":

            EkBr = input("Введите ID предмета, который будет использоваться в качестве брони:")

            while True:

                if EkBr in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
                                 "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
                                 "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44",
                                 "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58",
                                 "59", "60", "61", "62", "63", "64"]:
                    i_hate_python(29, EkBr)
                    break
                else:
                    print("Число должно быть меньше или равно 64!")

        if osnova=="25":
            Vremya = input("Введите количество сыгранного времени (в секундах):")

            i_hate_python(548, Vremya)

    elif rezhim == "2":
        print("Показать - 1. Не показывать - 2.")
        inv = input("Вы хотите прочитать список, где расписаны обьекты и их ID?:")

        if inv == "1":
            subprocess.Popen(["notepad.exe", "Object - ID.txt"])

        elif inv == "2":

            slot = input("Выберите слот:")

            if slot == "1":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[12] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "2":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[14] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")


            if slot == "3":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[16] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "4":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[18] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "5":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[20] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "6":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[22] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "7":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[24] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

            if slot == "8":

                vib = input("Введите ID обьекта:")

                try:
                    try:
                        with open(save, "r", encoding="utf-8") as f:
                            linii = f.readlines()
                    except FileNotFoundError:
                        linii = []

                    while len(linii) <= 12:
                        linii.append("\n")

                    linii[26] = f"{vib}\n"

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    print("Файл сохранения был перезаписан")

    elif rezhim == "3":
        print("Манекен - 1. Напстаблук - 2. Ториель - 3. Папи/айрус - 4.")

        vi = input("Выберите персонажа:")

        if vi == "1":
            print("Убежали - 0. Убит - 1. Разговор - 2. Утомлен - 3.")

            man = input("Выберите номер команды:")

                
            while True:

                if man in ["0", "1", "2", "3"]:
                    i_hate_python(42, man)
                    break
                else:
                    print("Число должно быть меньше или равно 3!")


        elif vi == "2":
            print("Пощажен - 1. Встречен позже - 2.")
            nap = input("Выберите номер команды:")

            while True:

                if nap in ["1", "2"]:
                    i_hate_python(66, nap)
                    break
                else:
                    print("Число должно быть меньше или равно 2!")     

        elif vi == "3":

                print("Вы вошли в дом Ториель первый раз - 0. Вы пытались выйти из Руин - 1. Вы сражались с Ториель - 3. Вы убили Ториель - 4. Вы пощадили Ториель - 5")

                tor = input("Выберите номер команды:")

                while True:

                
                    if tor in ["0", "1", "3", "4", "5"]:
                        i_hate_python(75, tor)
                        break
                    else:
                        print("Число должно быть меньше или равно 5!")
                        
        elif vi == "4":
            print("Вы пощадили Папи/айруса - 0. Вы убили Папи/айруса - 1. Папи/айрус пощадил вас - 3.")
                
            Pap = input("Введите номер команды:")
                
            while True:

                
                if Pap in ["0", "1", "3"]:
                    i_hate_python(97, Pap)
                    break
                else:
                    print("Число должно быть меньше или равно 3!")
                    
    elif rezhim == "4":
        print("Создать ярлык на рабочем столе - 1. Язык - 2. О программе - 3.")

        vvv = input("Выберите номер команды:")

        if vvv == "1":
            pp = os.path.join(os.getcwd(), 'UnSa_1.3.exe')
            imya_yarlika = 'UnSa'

            make_shortcut(script=pp, name=imya_yarlika, terminal=True, desktop=True, icon=ic)

        elif vvv == "2":
            print("Пока не готово, сорри)")

        elif vvv == "3":
            print("UnSa - Программа для изменения данных внутри сохранения Undertale. Версия:1.3. Создано Chitora (https://www.youtube.com/@ChitoraMusic). Связаться со мной:chitoramusic (Discord). Исходный код:https://github.com/cucuberstwo-commits/UnSa")

            aaarrrtt = '''               ::::
                                        +%%=
                                     -*@*==#@*:
                                    -*@*==#@*:
                                   =*#*=--=#@*:
                                  =%@*:::=#@*:
                                 =%@*:::=+#*+-:
                                 =#%+:::::-*@#-                                
                       :+@@@@@@@@#=--:::::-*@#-                                
                =*###*++++++++=-:::::::-=+*####=:                           
           -=+++*****=-:::::::::::::::::::=*****++++-                       
           -*%%%*+===--:::::::::::::::::::::::-+#%%#+===-:                  
                +%@@@*-::::::::::::::::::::::::::::-*@@@%=                  
                :---=*%%%%%%+-::::::::::::::::-+#%%%+----:                  
                    :-++++++**+-:::::::-=*******++++-                       
                           :*@#=:::::-=+**####*=:                           
                           :*@#=:::::=#@*:                                  
                           :*@#=:::::=#@*:                                  
                           :-=+*#+:+**+=-:                                  
                              =%@*:*%%=                                     
                              =%@*:*%%=                                     
                              =#%*-*%#=                                     
                              :-=*%*=-:                                     
                                -*@*-                                       
                                :=#=:                                       '''

            print(aaarrrtt)
    elif rezhim == "5":
            print("Экспорт - 1. Импорт - 2.")
            v = input("Выберите, что хотите сделать с файлами сохранения:")
            arh = 'Export Save'

            if v == "1":

                shutil.make_archive(arh, 'zip', save_papka)
                print("Сохранение экспортировано!")

            elif v == "2":

                shutil.unpack_archive(arh, save_papka)


            

            