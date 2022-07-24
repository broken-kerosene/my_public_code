import pandas as pd
from catboost import CatBoostRegressor
# data from https://www.kaggle.com/competitions/house-prices-advanced-regression-techniques/data

if __name__ == '__main__':

    df_train = pd.read_csv("data/train.csv")
    X_train = df_train.drop(columns=['Id', 'Alley', 'PoolQC', 'Fence', 'MiscFeature', 'FireplaceQu'], axis=1)
    X_train = X_train.dropna()
    y_train = X_train['SalePrice']
    X_train = X_train.drop(columns=['SalePrice'])


    cat_feature = ['MSZoning', 'Street',
                   'LotShape', 'LandContour', 'Utilities', 'LotConfig',
                   'LandSlope', 'Neighborhood', 'Condition1', 'Condition2', 'BldgType',
                   'HouseStyle', 'OverallQual', 'OverallCond',
                   'RoofStyle', 'RoofMatl', 'Exterior1st', 'Exterior2nd', 'MasVnrType',
                   'ExterQual', 'ExterCond', 'Foundation', 'BsmtQual',
                   'BsmtCond', 'BsmtExposure', 'BsmtFinType1',
                   'BsmtFinType2', 'Heating',
                   'HeatingQC', 'CentralAir', 'Electrical', 'KitchenQual',
                   'Functional', 'GarageType',
                   'GarageFinish', 'GarageQual',
                   'GarageCond', 'PavedDrive',
                   'SaleType', 'SaleCondition']
    reg = CatBoostRegressor(cat_features=cat_feature)
    reg.fit(X_train, y_train)

    reg.save_model("houseprice_catboost_model", format='cbm')
