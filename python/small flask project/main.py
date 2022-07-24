from flask import Flask
from flask import request

from src import predict_model

app = Flask('MyApp')

# curl -v localhost:5002/forward -H "Content-Type":"application/json" -d '{"test": "app"}'



@app.route('/forward', methods=['POST'])
def send_data():
    data_json = request.json

    # if 'test' not in request.json:
    #     return 'bad request', 400

    try:
        result = predict_model(data_json)
        return result, 200
    except:
        return "модель не смогла обработать данные", 403


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5002)