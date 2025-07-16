from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
import os

# Parámetros de conexión
INFLUXDB_URL = "http://localhost:8086"
INFLUXDB_TOKEN = "s5FGMUKVqUdZMPDvcxkSPmkugEHB6A8hK-_kXEYcpYf169HQqVL3mfPo9gPT_6Q34X6D_bleQUDRUFeo8ksrvg=="
INFLUXDB_ORG = "agrolora-org"
INFLUXDB_BUCKET = "agrolora-bucket"

client = InfluxDBClient(
    url=INFLUXDB_URL,
    token=INFLUXDB_TOKEN,
    org=INFLUXDB_ORG
)

write_api = client.write_api(write_options=SYNCHRONOUS)

def write_to_influx(data):
    point = (
        Point("lectura_sensores")
        .tag("sensor_id", str(data["id"]))
        .field("t", float(data["t"]) if data["t"] is not None else None)
        .field("h", float(data["h"]) if data["h"] is not None else None)
        .field("p", float(data["p"]) if data["p"] is not None else None)
        .field("m", int(data["m"]))
        .time(int(data["ts"]), WritePrecision.MS)
    )
    write_api.write(bucket=INFLUXDB_BUCKET, org=INFLUXDB_ORG, record=point)
