import config
import numpy as np



def times_to_dB(dB): # функция перевода разов в дБ
    if dB.text.isdigit():
        num_dB = float(dB.text)
        result = 10 * np.log10(num_dB)
        config.bot.send_message(dB.chat.id, str("%.4f" % result) + ' дБ')
    else:
        config.bot.send_message(dB.chat.id, "Вы ввели не число или число меньше нуля")
    config.send_keyboard(dB, "Чем еще могу помочь?")
