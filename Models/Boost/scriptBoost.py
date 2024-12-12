import pandas as pd
import numpy as np
import pickle
import xgboost as xgb
from sklearn.preprocessing import StandardScaler
import argparse

# Load and process the dataset
def predict(file_path):
    # Load the dataset
    df = pd.read_csv(file_path, delimiter=",", header=None)

    # Drop the columns we don't need from the data - 0 (name), 12 (empty)
    df.drop(columns=[0, 12], inplace=True)

    # Extract numerical data columns
    numerical_columns = list(range(11))  # First 11 numerical columns
    numerical_data = df.iloc[:, numerical_columns]

    additional_numeric_column = df.iloc[:, 11]

    # Process block frequencies and branch probabilities (columns 14 and 15)
    block_frequencies = df.iloc[:, 12].apply(lambda x: np.array(list(map(float, str(x).split(";")))))
    branch_probabilities = df.iloc[:, 13].apply(lambda x: np.array(list(map(float, str(x).split(";")))))
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


    # Load in scaler used to preprocess data
    with open('scaler.pkl', 'rb') as f:
        loaded_scaler = pickle.load(f)


    scaled_data = loaded_scaler.transform(processed_features.to_numpy())

    # Instantiate the XGBoost model
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

    # Load in pretrained model
    xgb_model.load_model('xgb_model.json')

    return xgb_model.predict(scaled_data)

# Main function to run the script
def main():
    parser = argparse.ArgumentParser(description="Predict using pre-trained XGBoost model")
    parser.add_argument("file_path", type=str, help="Path to input CSV file")
    args = parser.parse_args()

    predictions = predict(args.file_path)
    print(predictions[0] + 1)

if __name__ == "__main__":
    main()
