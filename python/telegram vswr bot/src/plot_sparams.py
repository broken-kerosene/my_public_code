import config
import matplotlib.pyplot as plt

def plot_sparams(data_list, y_min, y_max, S_param_name): # рисуем график S параметра
    x = []
    y = []
    for i in range(len(data_list)):
        x.append(data_list[i][0])
        y.append(data_list[i][1])

    plt.plot(x, y);
    plt.ylim([y_min, y_max])
    plt.grid('true')
    plt.xlabel('Частота, ГГц')
    plt.ylabel(S_param_name + ' дБ')
    plt.title('Грифк зависимости ' + S_param_name + ' от частоты')
    fig_name = S_param_name
    plt.savefig(fig_name)
    return fig_name

def prints(doc_data):
    if doc_data.content_type != 'document':
        config.bot.send_message(doc_data.chat.id, "Ошибка чтения файла")
        config.send_keyboard(doc_data, "Чем могу быть полезен?")
