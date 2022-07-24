import config

def calc_dB_to_times(num_times):
    result = 10 ** (num_times / 10)
    return result


def dB_to_times(times): # функция перевода дБ в разы
    specialChars = ",.-"
    txt = times.text
    for specialChar in specialChars:
        txt = txt.replace(specialChar, '')

    if txt.isdigit():
        num_times = float(times.text)
        result = calc_dB_to_times(num_times)
        config.bot.send_message(times.chat.id, str("%.4f" % result))
    else:
        config.bot.send_message(times.chat.id, "Вы ввели не число")
    config.send_keyboard(times, "Чем могу быть полезен?")
