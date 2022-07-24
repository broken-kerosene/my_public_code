import json
from re import L
from flask import Flask
from flask import request, make_response, jsonify
import cv2
import numpy as np

import io


app = Flask('MyApp')


@app.route('/page')
def get_page():
    return jsonify({
        'test': 'ok'
    })


@app.route('/not_page/<int:pk>', methods=['POST'])
def get_no_page(pk):
    print(pk)
    print(request.json)
    if 'test' not in request.json:
        return 'Not test data', 400
    # print(request.get_json())
    return 'ok', 404


@app.route('/photo', methods=['POST'])
def send_photo():
    image_file = request.files['image']
    print(request.files)

    in_memory_file = io.BytesIO()

    image_file.save(in_memory_file)
    data = np.fromstring(in_memory_file.getvalue(), dtype=np.uint8)
    img = cv2.imdecode(data, cv2.IMREAD_COLOR)

    output_img = cv2.resize(img, (1024, 1024))

    retval, buffer = cv2.imencode('.png', output_img)

    response = make_response(buffer.tostring())
    response.headers.set('Content-Type', 'image/png')
    return response

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001)
