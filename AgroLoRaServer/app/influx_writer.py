from influxdb_client import InfluxDBClient, Point, WritePrecision
import time

# Parámetros de conexión
INFLUXDB_URL = "http://localhost:8086"
INFLUXDB_TOKEN = "agrotoken123"
INFLUXDB_ORG = "agrolora-org"
INFLUXDB_BUCKET = "agrolora-bucket"

client = InfluxDBClient(
    url=INFLUXDB_URL,
    token=INFLUXDB_TOKEN,
    org=INFLUXDB_ORG
)

write_api = client.write_api()

def write_to_influx(data):
    point = (
        Point("lectura_sensores")
        .tag("sensor_id", str(data["id"]))
        .field("temperature", float(data["t"]) if data["t"] is not None else 0)
        .field("humidity", float(data["h"]) if data["h"] is not None else 0)
        .field("pressure", float(data["p"]) if data["p"] is not None else 0)
        .field("moisture", int(data["m"]))
        .time(int(time.time()), WritePrecision.S)  # timestamp en segundos
    )
    write_api.write(bucket=INFLUXDB_BUCKET, org=INFLUXDB_ORG, record=point)
