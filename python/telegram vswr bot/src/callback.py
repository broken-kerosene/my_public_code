import config

from src.times_to_dB import times_to_dB
from src.db_to_times import dB_to_times
from src.dB_to_VSWR import dB_to_VSWR
from src.plot_sparams import prints





def callback_worker(call):
    if call.text == "разы в дБ":
        msg_times = config.bot.send_message(call.chat.id, 'Прошу ввести величину в разах (больше нуля)')
        config.bot.register_next_step_handler(msg_times, times_to_dB)

    elif call.text == "дБ в разы":
        msg_dB = config.bot.send_message(call.chat.id, 'Прошу ввести величину в дБ')
        config.bot.register_next_step_handler(msg_dB, dB_to_times)

    elif call.text == "дБ в КСВН":
        msg_VSWR = config.bot.send_message(call.chat.id, 'Прошу ввести величину в дБ')
        config.bot.register_next_step_handler(msg_VSWR, dB_to_VSWR)

    elif call.text == "Построить график S параметров":
        doc_data = config.bot.send_message(call.chat.id, 'Прошу данные для графика')
        config.bot.register_next_step_handler(doc_data, prints)

    elif call.text == "Завершить":
        config.bot.send_message(call.chat.id, 'Работа окончена! Чтобы снвоа запустить помощника, напишите команду /start')
