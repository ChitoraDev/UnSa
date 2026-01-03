from logging import exception
import subprocess
import psutil
import os
from datetime import datetime

def zagolovok_okna(nazvanie_okna):
    os.system(f"title {nazvanie_okna}")

zagolovok_okna("UnSa")

while True:
    print("Добро пожаловать в UnSa! Программа для редактирования файла сохранения Undertale.")
    print("\n" + "="*40)
    print("О программе - 1. Основные данные - 2. Инвентарь - 3. Файлы сохранения - 4.")

    save_papka = os.path.join(os.getenv('LOCALAPPDATA'), 'UNDERTALE')
    save = os.path.join(save_papka, 'file0')
    save2 = os.path.join(save_papka, 'file9')
    save3 = os.path.join(save_papka, 'file8')
    save4 = os.path.join(save_papka, 'undertale')

    if not os.path.exists(save_papka):
        print("У вас нету паки сохранения Undertale!")
        exit()

    rezhim = input("Выберите и введите номер команды:")

    if rezhim=="1":
        print("UnSa - Программа для изменения данных внутри сохранения Undertale. Версия:1.0. Создано Chitora (https://www.youtube.com/@ChitoraMusic). Связаться со мной:chitoramusic (Discord). Исходный код:https://github.com/cucuberstwo-commits/UnSa-V.-C-")
        print("Для выхода из программы нажмите любую клавишу")
    elif rezhim=="2":
        print("Изменить имя упавшего - 11. Изменить уровень - 12. Изменить количество здоровья - 13. Изменить максимальное количество здоровья - 14. Атака - 15. Значение атаки у оружия - 16. Значение защиты - 17. Значение защиты от брони - 18. Номер комнаты, в которой находится человек - 19. Количество золота - 21. Количество убитых монстров - 22. Экипированное оружие - 23. Экипированная броня - 24. Количество проведенного в игре времени - 25.")

        osnova = input("Выберите действие:")

        if osnova=="11":
            nick = input("Введите имя упавшего человека:")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[0] = f"{nick}\n"

                else:
                    linii.append(f"{nick}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:("Файл сохранения был перезаписан")

        elif osnova=="12":

            while True:

                oz = input("Введите значение уровня:")

                if oz.isdigit():
                    if int(oz)<=20:
                        break
                    else:
                        print("Число должно быть меньше или равно 20!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                        linii = f.readlines()

                if len(linii) > 0:
                    linii[1] = f"{oz}\n"

                else:
                    linii.append(f"{oz}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")
        elif osnova=="13":

            while True:

                tekkolzdo = input("Введите количество здоровья:")

                if tekkolzdo.isdigit():
                    if int(tekkolzdo)<=99:
                        break
                    else:
                        print("Количество здоровья превышает 99!")
                try:

                    with open(save, "r", encoding="utf-8") as f:
                        linii = f.readlines()

                    if len(linii) > 0:
                        linii[2] = f"{tekkolzdo}\n"

                    else:
                        linii.append(f"{tekkolzdo}\n")

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    ("Файл сохранения был перезаписан")

        elif osnova=="14":

            while True:
                if maxkolzdo.isdigit():
                    if int(maxkolzdo)<=99:
                        break
                    else:
                        print("Число максимального количества здоровья должно быть меньше или равно 99!")

            maxkolzdo = input("Введите максимальное количество здоровья:")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[3] = f"{maxkolzdo}\n"

                else:
                    linii.append(f"{maxkolzdo}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="15":

            Attacka = input("Введите значение атаки:")

            while True:
                if Attacka.isdigit():
                    if int(Attacka) <= 99:
                        break
                    else:
                        print("Число должно быть меньше или равно 99!")


            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[4] = f"{Attacka}\n"

                else:
                    linii.append(f"{Attacka}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="16":

            Attor = input("Введите значение атаки у оружия, которым снаряжен человек:")

            while True:
                if Attor.isdigit():
                    if int(Attor) <= 15:
                        break
                    else:
                        print("Число должно быть меньше или равно 15!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[5] = f"{Attor}\n"

                else:
                    linii.append(f"{Attor}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")
        elif osnova=="17":

            zasita = input("Введите значение защиты:")

            while True:
                if zasita.isdigit():
                    if int(zasita) <= 15:
                        break
                    else:
                        print("Число должно быть меньше или равно 15!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[6] = f"{zasita}\n"

                else:
                    linii.append(f"{zasita}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="18":
            zasbro = input("Введите значение защиты от брони:")

            while True:
                if zasbro.isdigit():
                    if int(zasbro) <= 15:
                        break
                    else:
                        print("Число должно быть меньше или равно 15!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[7] = f"{zasbro}\n"

                else:
                    linii.append(f"{zasbro}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="19":
            print("Показать - 1. Не показывать - 2")

            vibor4ik = input("Вы хотите прочитать список, где расписаны комнаты и их ID?:")

            if vibor4ik == "1":
                subprocess.Popen(["notepad.exe", "Room - ID.txt"])
            else:

                room = input("Введите номер комнаты:")

                while True:
                    if room.isdigit():
                        if int(room) in [6, 12, 18, 31, 44, 46, 56, 68, 83, 92, 110, 114, 128, 131, 139, 145, 155, 164, 183, 196, 210, 216, 219, 231, 232, 235, 236, 246, 251]:
                            break
                        else:
                            print("Комнаты с таким ID и сохранением нету!")

                try:

                    with open(save, "r", encoding="utf-8") as f:
                        linii = f.readlines()

                    if len(linii) > 0:
                        linii[547] = f"{room}\n"

                    else:
                        linii.append(f"{room}\n")

                    with open(save, "w", encoding="utf-8") as f:
                        f.writelines(linii)
                finally:
                    ("Файл сохранения был перезаписан")

        elif osnova=="21":
            zoloto = input("Введите желаемое количество золота:")

            while True:
                if zoloto.isdigit():
                    if int(zoloto) <= 9999:
                        break
                    else:
                        print("Число должно быть меньше или равно 9999!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[11] = f"{zoloto}\n"

                else:
                    linii.append(f"{zoloto}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="22":
            ybistva = input("Введите количество убитых человеком монстров:")

            while True:
                if ybistva.isdigit():
                    if int(ybistva) <= 12:
                        break
                    else:
                        print("Рекомендуется меньше или равно 12!")
                        break

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[12] = f"{ybistva}\n"

                else:
                    linii.append(f"{ybistva}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="23":

            while True:

                EkOr = input("Введите ID предмета, который будет использоваться в качестве оружия:")

                if EkOr.isdigit():
                    if int(EkOr)<=64:
                        break
                    else:
                        print("Число должно быть меньше или равно 64!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                        linii = f.readlines()

                if len(linii) > 0:
                    linii[28] = f"{EkOr}\n"

                else:
                    linii.append(f"{EkOr}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        elif osnova=="24":

            while True:

                EkBr = input("Введите ID предмета, который будет использоваться в качестве брони:")

                if EkBr.isdigit():
                    if int(EkBr)<=64:
                        break
                    else:
                        print("Число должно быть меньше или равно 64!")

            try:

                with open(save, "r", encoding="utf-8") as f:
                        linii = f.readlines()

                if len(linii) > 0:
                    linii[29] = f"{EkBr}\n"

                else:
                    linii.append(f"{EkBr}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:
                ("Файл сохранения был перезаписан")

        if osnova=="25":
            Vremya = input("Введите количество сыгранного времени (в секундах):")

            try:

                with open(save, "r", encoding="utf-8") as f:
                    linii = f.readlines()

                if len(linii) > 0:
                    linii[548] = f"{Vremya}\n"

                else:
                    linii.append(f"{Vremya}\n")

                with open(save, "w", encoding="utf-8") as f:
                    f.writelines(linii)
            finally:("Файл сохранения был перезаписан")



    elif rezhim == "3":
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

    elif rezhim == "4":
        print("Удалить file0 - 1. Удалить все файлы сохранения - 2.")
        viboritakto = input("Введите номер команды:")

        if viboritakto == "1":
            if os.path.exists("save"):
                os.remove("save")

        elif viboritakto == "2":

            if os.path.exists("save"):
                os.remove("save")
            if os.path.exists("save2"):
                os.remove("save2")
            if os.path.exists("save3"):
                os.remove("save3")
            if os.path.exists("save4"):
                os.remove("save4")