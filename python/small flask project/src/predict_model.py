import pandas as pd
from catboost import CatBoostRegressor


def predict_price(json_data):

    df = pd.read_json(json_data)
    X = df.drop(columns=['Id', 'Alley', 'PoolQC', 'Fence', 'MiscFeature', 'FireplaceQu'], axis=1)

    reg = CatBoostRegressor()
    reg.load_model("houseprice_catboost_model")

    y_pred = reg.predict(X)
    y_pred_json = y_pred.to_json()

    return y_pred_json