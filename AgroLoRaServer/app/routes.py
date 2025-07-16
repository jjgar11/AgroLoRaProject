from flask import Blueprint, request, jsonify, render_template
from .storage import save_to_csv, get_last_records, read_csv_data

bp = Blueprint("routes", __name__)

@bp.route("/data", methods=["POST"])
def receive_data():
    data = request.get_json()
    
    required_fields = {"id", "ts", "t", "h", "p", "m"}
    if not data or not required_fields.issubset(data):
        return jsonify({"error": "Datos incompletos"}), 400
    
    save_to_csv(data)
    return jsonify({"status": "ok"}), 200

@bp.route("/data", methods=["GET"])
def view_data():
    records = get_last_records(10)
    if records is None:
        return jsonify({"error": "No data available"}), 404
    return jsonify(records)

@bp.route("/view", methods=["GET"])
def view_data_html():
    rows = read_csv_data()
    return render_template("view_data.html", rows=rows)