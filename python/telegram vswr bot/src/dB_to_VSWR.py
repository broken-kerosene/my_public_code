import config

def dB_to_VSWR(VSWR): # функция вычисляющая КСВН
    specialChars = ",.-"
    txt = VSWR.text
    for specialChar in specialChars:
        txt = txt.replace(specialChar, '')

    if txt.isdigit() and float(VSWR.text) < 0.0:
        num = 10 ** (float(VSWR.text) / 20)
        result = (1 + abs(num)) / (1 - abs(num))
        config.bot.send_message(VSWR.chat.id, str("%.4f" % result))
    else:
        config.bot.send_message(VSWR.chat.id, "Вы ввели не число или число больше нуля")
    config.send_keyboard(VSWR, "Чем могу быть полезен?")
