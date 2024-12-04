import pandas as pd
import numpy as np
import pickle
import xgboost as xgb
from sklearn.preprocessing import StandardScaler

# Load and process the dataset
def predict(file_path):
    # Load the dataset
    df = pd.read_csv(file_path, delimiter=",", header=None)

    # Drop the filename column (0th index) and the empty column
    df.drop(columns=[0, 12, 17], inplace=True)

    # Extract numerical data columns
    numerical_columns = list(range(11))  # First 11 numerical columns
    numerical_data = df.iloc[:, numerical_columns]

    # Extract additional single numerical column (13th column)
    additional_numeric_column = df.iloc[:, 11]

    # Process block frequencies and branch probabilities (columns 14 and 15)
    block_frequencies = df.iloc[:, 12].apply(lambda x: np.array(list(map(float, x.split(";")))))
    branch_probabilities = df.iloc[:, 13].apply(lambda x: np.array(list(map(float, x.split(";")))))

    # Compute statistical measures for block frequencies
    block_stats = pd.DataFrame({
        "BlockFreq_Mean": block_frequencies.apply(np.mean),
        "BlockFreq_Max": block_frequencies.apply(np.max),
        "BlockFreq_Min": block_frequencies.apply(np.min),
        "BlockFreq_Std": block_frequencies.apply(np.std),
        "BlockFreq_Sum": block_frequencies.apply(np.sum),
        "BlockFreq_Count": block_frequencies.apply(len),
    })

    # Compute statistical measures for branch probabilities
    branch_stats = pd.DataFrame({
        "BranchProb_Mean": branch_probabilities.apply(np.mean),
        "BranchProb_Max": branch_probabilities.apply(np.max),
        "BranchProb_Min": branch_probabilities.apply(np.min),
        "BranchProb_Std": branch_probabilities.apply(np.std),
        "BranchProb_Sum": branch_probabilities.apply(np.sum),
        "BranchProb_Count": branch_probabilities.apply(len),
    })

    # Combine all features
    processed_features = pd.concat([numerical_data, additional_numeric_column, block_stats, branch_stats], axis=1)

    with open('scaler.pkl', 'rb') as f:
        loaded_scaler = pickle.load(f)

    scaled_data = loaded_scaler.transform(processed_features.to_numpy())

    xgb_model = xgb.XGBClassifier(
        objective="multi:softmax",
        num_class=8,
        max_depth=3,
        eta=0.1,
        reg_alpha=1,
        reg_lambda=1,
        eval_metric="mlogloss",
        random_state=42
    )

    xgb_model.load_model('xgboost_model.json')

    return xgb_model.predict(scaled_data)

print(predict('data.csv'))
