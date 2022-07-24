from src.callback import callback_worker
from src.bot_creating import bot_creating
from telebot import types


bot = bot_creating()

@bot.message_handler(commands=['start'])
def send_keyboard(message, text="Приветствую, чем я могу тебе помочь?"):
    keyboard = types.ReplyKeyboardMarkup(row_width=3)  # наша клавиатура
    times2db = types.KeyboardButton('разы в дБ')  # создадим кнопку
    db2times = types.KeyboardButton('дБ в разы')
    db2vswr= types.KeyboardButton('дБ в КСВН')
    plotSparams = types.KeyboardButton("Построить график S параметров")
    end = types.KeyboardButton('Завершить')

    keyboard.add(times2db)  # первый ряд
    keyboard.add(times2db, db2times, db2vswr)    # первый ряд
    keyboard.add(plotSparams)                    # второй ряд
    keyboard.add(end)  # третий ряд

    # пришлем это все сообщением и запишем выбранный вариант
    call = bot.send_message(message.from_user.id, text=text, reply_markup=keyboard)

    # отправим этот вариант в функцию, которая его обработает
    bot.register_next_step_handler(call, callback_worker)