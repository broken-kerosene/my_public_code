def token_reading():
    file = open("TOKEN.txt", "r")

    try:
        TOKEN = file.readline()
        print("TOKEN успешно прочитан")
        file.close
        return TOKEN
    except:
        print("TOKEN не прочитан")
        file.close
        exit
