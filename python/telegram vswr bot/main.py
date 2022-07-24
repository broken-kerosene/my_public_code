import config


if __name__ == '__main__':
    config.bot.message_handler(commands=['start'])

    config.bot.polling(none_stop=True)  # или bot.infinity_polling()
