import pandas as pd
from scipy.stats import zscore

# Load the CSV file into a DataFrame
file_path = 'results-fnn.csv'  # Replace with the actual path to your CSV file
df = pd.read_csv(file_path)

# Remove outliers using Z-Score
def remove_outliers_zscore(data):
    z_scores = zscore(data, nan_policy='omit')  # Calculate z-scores
    return data[(abs(z_scores) < 3.5)]  # Keep values with z-score < 3

# Initialize a dictionary to store mean values
mean_values = {}

# Process each numeric column
for column in df.columns[1:]:  # Skip the first column ('File')
    numeric_data = pd.to_numeric(df[column], errors='coerce')  # Convert to numeric, handle errors
    filtered_data = remove_outliers_zscore(numeric_data)  # Remove outliers
    mean_values[column] = filtered_data.mean()  # Calculate mean of filtered data

# Display the results
for col, mean in mean_values.items():
    print(f"Mean of {col} (without outliers): {mean}")
