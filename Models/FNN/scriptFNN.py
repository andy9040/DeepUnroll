import pandas as pd
import numpy as np
import pickle
from sklearn.preprocessing import StandardScaler
import argparse
import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

class FFN(nn.Module):
    def __init__(self):
        super(FFN, self).__init__()
        self.fc1 = nn.Linear(24, 128)
        self.relu1 = nn.ReLU()
        self.fc2 = nn.Linear(128, 256)  # Output logits for each class
        self.relu2 = nn.ReLU()
        self.fc3 = nn.Linear(256, 64)  # Output logits for each class
        self.relu3 = nn.ReLU()
        self.fc4 = nn.Linear(64, 8)  # Output logits for each class

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu1(x)
        x = self.fc2(x)
        x = self.relu2(x)
        x = self.fc3(x)
        x = self.relu3(x)
        x = self.fc4(x)
        return x


# Load and process the dataset
def predict(file_path):
    # Load the dataset
    df = pd.read_csv(file_path, delimiter=",", header=None)

    # Drop the filename column (0th index) and the empty column
    df.drop(columns=[0, 12], inplace=True)

    # Extract numerical data columns
    numerical_columns = list(range(11))  # First 11 numerical columns
    numerical_data = df.iloc[:, numerical_columns]

    # Extract additional single numerical column (13th column)
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

    with open('scalerFNN.pkl', 'rb') as f:
        loaded_scaler = pickle.load(f)

    scaled_data = loaded_scaler.transform(processed_features.to_numpy())

    model = FFN()

    model.load_state_dict(torch.load('fnn_model_weights.pth'))

    model.eval()

    return np.argmax(model(torch.Tensor(scaled_data)).detach().numpy()) + 1

# Main function to run the script
def main():
    parser = argparse.ArgumentParser(description="Predict using pre-trained XGBoost model")
    parser.add_argument("file_path", type=str, help="Path to the input CSV file")
    args = parser.parse_args()

    predictions = predict(args.file_path)
    print(predictions)

if __name__ == "__main__":
    main()
