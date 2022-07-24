import telebot
from src.token_reading import token_reading

def bot_creating():
    TOKEN = token_reading()
    bot = telebot.TeleBot(TOKEN)
    return bot