import os
import csv

FILEPATH = "data/sensor_data.csv"
FIELDNAMES = ["id", "ts", "t", "h", "p", "m"]

def save_to_csv(data):
    file_exists = os.path.exists(FILEPATH)
    
    with open(FILEPATH, mode="a", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=FIELDNAMES)
        if not file_exists:
            writer.writeheader()
        writer.writerow(data)

def get_last_records(n=10):
    if not os.path.exists(FILEPATH):
        return None

    with open(FILEPATH, newline="") as f:
        reader = csv.DictReader(f)
        data = list(reader)
        return data[-n:]
